#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct square{
    double x, y; int id;
} que[N];

struct node{
    int l, r, x, lz;
} seg[N << 2];

int ans[N];

void build(int i, int l, int r){
    seg[i] = {l, r, 0, 0};
    if (l == r) return;
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
}

void lazy_down(int i){
    if (seg[i].lz == 0) return;
    seg[i].x = seg[i].lz;
    if (seg[i].l != seg[i].r)
        seg[i << 1].lz = seg[i << 1 | 1].lz = seg[i].lz;
    seg[i].lz = 0;
}

void update(int i, int l, int r, int x){
    lazy_down(i);
    if (seg[i].l > r || seg[i].r < l) return;
    if (seg[i].l >= l && seg[i].r <= r){
        seg[i].x = x; 
        if (seg[i].l != seg[i].r)
            seg[i << 1].lz = seg[i << 1 | 1].lz = x;
        return;
    }
    update(i << 1, l, r, x); update(i << 1 | 1, l, r, x);
    seg[i].x = max(seg[i << 1].x, seg[i << 1 | 1].x);
}

int get_x(int i, int pos){
    lazy_down(i);
    if (seg[i].l == seg[i].r) return seg[i].x;
    if (seg[i << 1].l <= pos && seg[i << 1].r >= pos)
        return get_x(i << 1, pos);
    return get_x(i << 1 | 1, pos);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("nongtrai.inp", "r", stdin);
    freopen("nongtrai.out", "w", stdout);
    int w, h, n; cin >> w >> h >> n; build(1, 0, h);
    for (int i = 1; i <= n; i++){
        cin >> que[i].x >> que[i].y;
        que[i].id = i;
    }
    sort(que + 1, que + n + 1, [](const square &a, const square &b){
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    for (int i = 1; i <= n; i++){
        int x = get_x(1, ceil(que[i].y));
        double t = que[i].x - x; ans[que[i].id] = floor(2 * t);
        update(1, floor(que[i].y - t), floor(que[i].y + t), que[i].x + t);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}