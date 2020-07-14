#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int a[N][N], h[N], d[N];
deque <int> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == 1) h[j] = 1;
            else {
                if (a[i][j] - a[i - 1][j] == h[j]) h[j]++;
                else {
                    h[j] = 2; d[j] = a[i][j] - a[i - 1][j];
                }
            }
        }
        dq.clear();
        for (int j = 1; j <= m; j++){
            
        }
    }
}