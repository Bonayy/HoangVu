#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("khoihcn.inp", "r", stdin);
    freopen("khoihcn.out", "w", stdout);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > c) swap(a, c);
    if (x > y) swap(x, y);
    if (a <= x && b <= y) puts("CO");
    else puts("KHONG");
}