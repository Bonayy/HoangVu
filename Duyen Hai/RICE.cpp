#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, n, k; cin >> m >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1); 
    int res = 0; int bd = 1;
    for (int i = 1; i <= n; i++){
        if (a[i] - a[bd] >= k){
            res += min(k, a[i - 1] - a[bd - 1]); bd = i;
        }
    }
    res += min(k, a[n] - a[bd - 1]);
    cout << res << '\n';
}