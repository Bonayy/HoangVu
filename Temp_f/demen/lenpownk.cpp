#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lenpownk.inp", "r", stdin);
    freopen("lenpownk.out", "w", stdout);
    long long n, k; cin >> n >> k;
    cout << floor(double(k) * log10(n)) + 1 << '\n';
}