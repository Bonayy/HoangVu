#include <bits/stdc++.h>
using namespace std;

struct node{
    int l, r, val, cnt;
};
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
const int N = 1e5 + 5; 
node seg[N * 4]; int val[N];
pair <char, int> que[N];

void build(int i, int l, int r){
    seg[i] = {l, r, 0, 0};
    if (l == r) return; int m = (l + r) / 2;
    build(i * 2, l, m); build(i * 2 + 1, m + 1, r);
}

void update(int i, int pos, int t){
    if (seg[i].l > pos || seg[i].r < pos) return;
    if (seg[i].l == seg[i].r){
        seg[i].cnt += t;
        if (seg[i].cnt == 0) seg[i].val = 0;
        else seg[i].val = val[pos]; return;
    }
    update(i * 2, pos, t); update(i * 2 + 1, pos, t);
    seg[i].val = __gcd(seg[i * 2].val, seg[i * 2 + 1].val);
    seg[i].cnt = seg[i * 2].cnt + seg[i * 2 + 1].cnt;
}

int main(){
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; vector <int> cmp(n);
    for (int i = 0; i < n; i++){
        cin >> que[i].fi >> que[i].se;
        cmp[i] = que[i].se;
    }
    sort(all(cmp)); build(1, 1, cmp.size());
    cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 0; i < n; i++){
        int order = ub(all(cmp), que[i].se) - cmp.begin();
        val[order] = que[i].se;
        if (que[i].fi == '+') update(1, order, 1);
        else update(1, order, -1);
        if (seg[1].cnt == 0) cout << "1\n";
        else cout << seg[1].val << '\n';
    }
}