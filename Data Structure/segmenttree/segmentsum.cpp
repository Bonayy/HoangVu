#define ci const int&
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int a[maxn]; int node[maxn << 2];
int n, m; int q;

void fastin(int& x){
	x = 0; bool neg = false;
	register int c = getchar();
	if (c == '-'){
		c = getchar(); neg = true;
	}
	for (; c > 47 && c < 58; c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}

void build(ci i, ci lo, ci hi){
	if (lo > hi) return;
	if (lo == hi){
		node[i] = a[lo]; return;
	}
	int mi = (lo + hi) >> 1;
	build(i << 1, lo, mi);
	build((i << 1) + 1, mi + 1, hi);
	node[i] = node[i << 1] + node[(i << 1) + 1];
}

void update(ci i, ci lo, ci hi, ci pos, ci val){
	if (lo > hi || pos < lo || pos > hi) return;
	if (lo == hi){
		if (lo == pos){
			node[i] = val; a[lo] = val;
		}
		return;
	}
	int mi = (lo + hi) / 2;
	update(i << 1, lo, mi, pos, val);
	update((i << 1) + 1, mi + 1, hi, pos, val);
	node[i] = node[i << 1] + node[(i << 1) + 1];
}

int get(ci i, ci lo, ci hi, ci a, ci b){
	if (lo > hi || a > hi || b < lo) return 0;
	if (a <= lo && b >= hi) return node[i];
	int mi = (lo + hi) >> 1;
	return get(i << 1, lo, mi, a, b) + get((i << 1) + 1, mi + 1, hi, a, b);
}

int main(){
    freopen("segment.inp", "r", stdin);
    freopen("segment.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
	fastin(n); fastin(m);
	for (int i = 1; i <= n; i++) fastin(a[i]);
	build(1, 1, n);
	while (m--){
		fastin(q);
		if (q == 2){
            int a, b;
            fastin(a); fastin(b);
            cout << get(1, 1, n, a, b) << '\n';
		}
		else if (q == 1){
            int pos, val;
            fastin(pos); fastin(val);
            update(1, 1, n, pos, val);
		}
	}
	return 0;
}
