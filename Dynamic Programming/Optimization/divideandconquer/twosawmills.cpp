#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
using ll = long long;
ll sumw[N], total[N]; int best[N], d[N], w[N],  n;

ll cost(int i, int j){
    return total[i] - total[j] - d[j] * (sumw[i] - sumw[j]);
}

ll eval(int i, int j){
    return cost(1, i) + cost(i + 1, j) + cost(j + 1, n + 1);
}

void calc_best(int i, int j, int l, int r){
    if (i > j) return;
    int m = (i + j) >> 1; best[m] = l;
    for (int k = l + 1; k <= r; k++)
        if (eval(m, best[m]) > eval(m, k)) best[m] = k;
    calc_best(i, m - 1, l, best[m]);
    calc_best(m + 1, j, best[m], r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; ll res = LLONG_MAX;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> d[i];
    for (int i = n; i > 0; i--){
        sumw[i] = sumw[i + 1] + w[i]; d[i] += d[i + 1];
        total[i] = total[i + 1] + 1ll * d[i] * w[i];
    }
    calc_best(1, n, 1, n);
    for (int i = 1; i <= n; i++)
        res = min(res, eval(i, best[i]));
    cout << res << '\n';
}