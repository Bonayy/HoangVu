#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("ZEZE.inp", "r", stdin);
    freopen("ZEZE.out", "w", stdout);
    int cnt2, cnt5, n, x;
    cnt2 = cnt5 = 0; cin >> n;
    while (n--){
        cin >> x;
        cnt2 += __builtin_ctzll(x);
        while (x % 5 == 0){
            cnt5++; x /= 5;
        }
    }
    cout << min(cnt2, cnt5) << '\n';
}