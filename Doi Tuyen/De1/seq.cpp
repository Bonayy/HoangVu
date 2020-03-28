#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
struct node{
    int l, r, v;
} seg[N << 2];
int a[N], n, q; ll s[N];

void build(int i, int l, int r){
    seg[i].l = l; seg[i].r = r;
    if (l == r){
        seg[i].v = a[l]; return;
    }
    int m = (l + r) >> 1; build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    seg[i].v = min(seg[i << 1].v, seg[i << 1 | 1].v);
}

int get_min(int i, int l, int r){
    if (seg[i].l > r || seg[i].r < l) return inf;
    if (seg[i].l >= l && seg[i].r <= r) return seg[i].v;
    return min(get_min(i << 1, l, r), get_min(i << 1 | 1, l, r)); 
}

ll get_weight(int l, int r){
    if (l <= r) return (s[r] - s[l - 1]) * get_min(1, l, r);
    return (s[n] - s[l - 1] + s[r]) * min(get_min(1, l, n), get_min(1, 1, r));
}

int main(){
    freopen("seq.inp", "r", stdin);
    freopen("seq.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n >> q; 
    for (int i = 1; i <= n; i++){
        cin >> a[i]; s[i] = s[i - 1] + a[i];
    }
    ll ans = LLONG_MIN; build(1, 1, n);
    while (q--){
        int l, r; cin >> l >> r;
        ans = max(ans, get_weight(l, r));
    }
    cout << ans << '\n';
}