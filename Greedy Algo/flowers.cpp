#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

struct data{
    int t, d;
    bool operator < (const data& pr) const{
        return t * pr.d < d * pr.t;
    }
};

ostream& operator << (ostream& os, const data& pr){
    return os << pr.t << ' ' << pr.d << '\n';
}

istream& operator >> (istream& is, data& pr){
    return is >> ws >> pr.t >> pr.d;
}

data a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); long long time, total;
    int n; cin >> n; time = total = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        total += time * a[i].d;
        time += 2 * a[i].t;
    }
    cout << total;
}
