#include <bits/stdc++.h>
using namespace std;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

//* divide sequence into <= [sqrt(n)] + 2 blocks
//* each block have size [sqrt(n)]
class sqrt_blocks{
private:
    int n, bl_size, bl_cnt;
    vector <int> values, blocks;
public:
    sqrt_blocks(int n){
        this->n = n; bl_size = (int)sqrt(n);
        bl_cnt = (n - 1) / bl_size + 1;
        values.resize(n, 0);
        blocks.resize(bl_cnt, INT_MAX);
    }
    void enter(){
        for (int i = 0; i < n; i++)
            cin >> values[i];
    }
    void init(){
        for (int i = 0; i < n; i++)
            chkmin(blocks[i / bl_size], values[i]);
    }
    void update(int pos, int val){
        values[pos] = val;
        pos = pos - pos % bl_size;
        for (int i = pos; i < pos + bl_size && i < n; i++)
            chkmin(blocks[i / bl_size], values[i]);
    }
    int get_max(int l, int r){
        int res = min(values[l], values[r]);
        while (l <= r && l % bl_size != 0) 
            chkmin(res, values[l++]);
        while (r >= l && (r + 1) % bl_size != 0)
            chkmin(res, values[r--]);
        for (; l <= r; l += bl_size)
            chkmin(res, blocks[l / bl_size]);
        return res;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, l, r; cin >> n;
    sqrt_blocks T(n);
    T.enter(); T.init();
    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << T.get_max(l, r) << '\n';
    }
    return 0;
}