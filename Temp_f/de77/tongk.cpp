#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map <ll, int> mp;

int main(){
    freopen("tongk.inp", "r", stdin);
    freopen("tongk.out", "w", stdout);
    int n, x; ll sum = 0, k; 
    cin >> n >> k; mp[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> x; sum += x;
        if (mp.count(sum - k)){
            cout << i - mp[sum - k] << '\n';
            cout << mp[sum - k] + 1 << ' ' << i << '\n';
            return 0;
        }
        mp[sum] = i;
    }
    cout << "-1\n";
}