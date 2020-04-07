#include <bits/stdc++.h>
using namespace std;

const int N = 105; int n;
using point = complex <double>;
double w[N][N], d[N]; point a[N];
bitset <N> used;

double prim(){
    int cnt = 1; double total = 0;
    used[1] = true; d[1] = 1e20;
    for (int i = 2; i <= n; i++) d[i] = w[1][i];
    while (cnt < n){
        auto pt = min_element(d + 1, d + n + 1);
        total += sqrt(*pt); used[pt - d] = true;
        d[pt - d] = 1e20; cnt++;
        for (int i = 1; i <= n; i++)
            if (!used[i]) d[i] = min(d[i], w[i][pt - d]);
    }
    return total;
}

int main(){
    cin >> n; double x, y;
    for (int i = 1; i <= n; i++){
        cin >> x >> y; a[i] = {x, y};
        for (int j = 1; j <= i; j++)
            w[i][j] = w[j][i] = norm(a[i] - a[j]);
    }
    cout << setprecision(2) << fixed << prim();
}