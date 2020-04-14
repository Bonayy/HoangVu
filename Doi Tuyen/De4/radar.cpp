#include <bits/stdc++.h>
using namespace std;

#define x real()
#define y imag()
using point = complex <double>;

struct circle{
    point center; double radius; int id;
    bool is_cont(point pt){
        return abs(pt - center) <= radius;
    }
};

bitset <1005> used;
circle cc[1005]; point a[1005];

bool solve(){
    double r; int n, ans = 0; 
    cin >> n >> r; used.reset();
    if (n == 0) return false;
    for (int i = 1; i <= n; i++){
        double re, im; cin >> re >> im;
        a[i] = {re, im}; cc[i].id = i; cc[i].radius = r;
        cc[i].center = {re + sqrt(r * r - im * im)};
    }
    sort(cc + 1, cc + n + 1, [](const circle &p, const circle &q){
        return p.center.x < q.center.x;
    });
    for (int i = 1; i <= n; i++){
        bool flag = false;
        for (int j = 1; j <= n; j++)
            if (cc[i].is_cont(a[j]) && !used[j]){
                used[j] = true; flag = true;
            }
        ans += flag;
    }
    if (used.count() != n) return puts("-1\n"), 1;
    cout << ans << '\n'; return true;
}

int main(){
    freopen("radar.inp", "r", stdin);
    freopen("radar.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); while (solve());
}