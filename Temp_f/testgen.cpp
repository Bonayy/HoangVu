#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    freopen("101628K.inp", "w", stdout);
    cout << 1000 << '\n'; int total = 0;
    for (int i = 1; i <= 1000; i++){
        for (int j = 0; j < 100; j++)
            cout << char(rng() % 26 + 'a');
        cout << '\n';
    }
    cout << 100 << '\n';
    for (int i = 1; i <= 100; i++){
        cout << 1 << ' ' << rng() % 1000 << ' ';
        for (int j = 0; j < 100; j++)
            cout << char(rng() % 26 + 'a');
        cout << '\n';
    }
}