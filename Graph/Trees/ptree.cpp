#include <bits/stdc++.h>
using namespace std;

const int N = 201;
const int inf = 0x3f3f3f3f;

bool a[N][N];
int c[N], dp[N][N], trace[N][N];
int n, p;

void visit(int u){
    dp[u][1] = c[u];
    for (int v = 1; v <= n; v++){
        if (a[u][v]){
            a[v][u] = false; visit(v);
            for (int i = p; i > 0; i--)
                for (int j = 1; j < i; j++)
                    if (dp[u][i] < dp[u][j] + dp[v][i - j]){
                        dp[u][i] = dp[u][j] + dp[v][i - j];
                        trace[v][i] = i - j;
                    }
        }
    }
}

void trace_back(int u, int i){
    for (int v = n; v > 0; v--)
        if (a[u][v] && trace[v][i] > 0){
            trace_back(v, trace[v][i]);
            i -= trace[v][i];
        }
    cout << u << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= p; j++)
            dp[i][j] = -inf;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        a[u][v] = a[v][u] = true;
    }
    visit(1); int pos = 1;
    for (int i = 1; i <= n; i++)
        if (dp[i][p] > dp[pos][p]) pos = i;
    trace_back(pos, p); return 0;
}