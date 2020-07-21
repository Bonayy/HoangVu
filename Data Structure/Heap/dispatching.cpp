#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
int sz[N], ls[N], rs[N];
int p[N], l[N], val[N];
ll su[N], res = 0;

int merge(int x, int y){
    if (!x || !y) return x | y;
    if (val[x] < val[y]) swap(x, y);
    rs[x] = merge(rs[x], y);
    if (sz[ls[x]] < sz[rs[x]])
        swap(ls[x], rs[x]);
    sz[x] = sz[ls[x]] + sz[rs[x]] + 1;
    su[x] = su[ls[x]] + su[rs[x]] + val[x];
    return x;
}

int pop(int x){
    return merge(ls[x], rs[x]);
}

int main(){

}