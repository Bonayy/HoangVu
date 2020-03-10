#define x real()
#define y imag()
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
using namespace std;

typedef complex <double> point;

double mdist = 1E20;
const int maxn = 1e5 + 10;

bool cmp_x(const point& a,const point& b){
    return a.x < b.x;
}

bool cmp_y(const point& a,const point& b){
    return a.y < b.y;
}

void Update(const point& a, const point& b){
    mdist = min(mdist, abs(a - b));
}

point a[maxn];
static point t[maxn];
void Find(int l, int r){
    if (r <= l) return;
    if (r == l + 1){
        Update(a[l], a[r]);
        if (!cmp_y(a[l], a[r])) swap(a[l], a[r]);
        return;
    }
    int m = (l + r) / 2;
    int midx = a[m].x;
    Find(l, m); Find(m + 1, r);
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, cmp_y);
    copy(t, t + r - l + 1, a + l);
    int top = 0;
    for (int i = l; i <= r; i++)
        if (abs(midx - a[i].x) < mdist){
            for (int j = top - 1; j >= 0 && t[j].y - a[i].y + mdist > 0; j--)
                Update(t[j], a[i]);
            t[top++] = a[i];
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(3);
    fixed(cout);
    double real, imag;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> real >> imag;
        a[i] = {real, imag};
    }
    sort(a, a + n, cmp_x);
    Find(0, n - 1);
    cout << mdist;
}
