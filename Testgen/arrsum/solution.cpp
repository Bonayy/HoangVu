#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("arrsum.inp", "r", stdin);
    freopen("arrsum.out", "w", stdout);
    int n, x; cin >> n;
    long long res = 0;
    while (n--){
        cin >> x; res += x;
    }
    cout << res << '\n';
}