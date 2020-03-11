#include <bits/stdc++.h>
using namespace std;

map <int, int> trap[2];

int main(){
    int n, h, ans, curr, cnt; 
    cin >> n >> h;
    ans = n + 1; cnt = 0; curr = n / 2;
    for (int i = 0, x; i < n; i++){
        cin >> x; trap[i & 1][x]++;
    }
    for (int i = 1; i <= h; i++){
        if (ans > curr){
            ans = curr; cnt = 1;
        }
        else cnt += ans == curr;
        auto it = trap[0].find(i);
        if (it != trap[0].end())
            curr -= it->second;
        it = trap[1].find(h - i);
        if (it != trap[1].end())
            curr += it->second;
    }
    cout << ans << ' ' << cnt << '\n';
}