#define forn(i, j, k) for (int i = j; i < k; i++)
#define ford(i, j, k) for (int i = j; i > k; i--)
#define taskname "ptcc"
#define x real()
#define y imag()
#define emp emplace_back
#include <bits/stdc++.h>
using namespace std;
typedef complex <double> pt;
int n, k;

vector <pt> a;
vector <vector <double> > dis;

int getpoints(int i, double r){
    vector <pair<double, bool> > angles;
    forn(j, 0, n) if (j != i && dis[i][j] <= 2 * r){
        double b1 = acos(dis[i][j] / (2 * r));
        double a1 = arg(a[j] - a[i]);
        double al = a1 - b1;
        double be = a1 + b1;
        angles.emp(make_pair(al, true));
        angles.emp(make_pair(be, false));
    }
    sort(angles.begin(), angles.end());
    int c = 1, res = 1;
    for (auto i = angles.begin(); i != angles.end(); i++){
        if ((*i).second) c++;
        else c--;
        if (c > res) res = c;
    }
    return res;
}

bool avail(double r){
    int res = 1;
    forn(i, 0, n){
        res = max(res, getpoints(i, r));
    }
    return res >= k;
}

int main(){
    cout.precision(8    );
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> n >> k; a.resize(n);
    double real, imag;
    dis.resize(n, vector <double> (n));
    forn(i, 0, n){
        cin >> real >> imag;
        a[i] = {real, imag};
    }
    forn(i, 0, n) forn(j, i + 1, n){
        dis[i][j] = dis[j][i] = abs(a[i] - a[j]);
    }
    double l = 0, r = 1e9, m;
    double ans = 0;
    while (r - l > 1e-5){
        m = l + (r - l) / 2;
        if (avail(m)){
            ans =  m; r = m - 1e-5;
        }
        else l = m + 1e-5;
    }
    cout << ans;
}
