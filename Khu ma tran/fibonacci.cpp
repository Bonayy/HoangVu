#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const int base = 1e7 + 9;
long long f[maxn];

long long cal(int n){
    if (f[n] > 0) return f[n];
    int k = n >> 1;
    if (n & 1) return f[n] = (cal(k) * cal(k + 1) + cal(k) * cal(k - 1)) % base;
    return f[n] = (cal(k) * cal(k) + cal(k - 1) * cal(k - 1)) % base;
}

int main(){
    f[0] = f[1] = 1;
    int t, n; cin >> t;
    while (t--){
        cin >> n;
        cout << cal(n) << '\n';
    }
}
