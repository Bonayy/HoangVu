#include <bits/stdc++.h>
using namespace std;

int main(){
    string cmd; long double n;
    fixed(cout); cout.precision(15);
    while (cin >> cmd){
        if (cmd == "[END]") return 0;
        cin >> n; long double m = 5.0 * n;
        double a = m * (m - 1) * (m - 2) * (m - 3) * (m - 4) / 120;
        double k = 125.0 * (n - 1) * n + 125.0 * (n - 1) * n * (n - 2) + n;
        cout << k / a << '\n';
    }
}
