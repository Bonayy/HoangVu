#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const long maxv = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    freopen("BIT.inp", "w", stdout);
    srand(time(NULL));
    int n = rand() % N + 1000;
    cout << n << ' ';
    for (int i = 0; i < n; i++) cout << (rand() % 2 ? -(rand() % maxv) : rand() % maxv) << ' ';
    cout << '\n';
    int t = rand() % 300000;
    cout << t << '\n';
    while (t--){
        if (rand() % 2){
            cout << "q ";
            cout << rand() % n + 1 << ' ' << rand() % n + 1 << '\n';
        }
        else{
            cout << "u ";
            cout << rand() % n + 1 << ' ' << rand() % maxv << '\n';
        }
    }
}
