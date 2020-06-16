#include <bits/stdc++.h>
using namespace std;

vector <int> len;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand_range(int l, int r){
    return uniform_int_distribution <int> (l, r)(rng);
}

int main(){
    freopen("aho.inp", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); int total = 0;
    while (total < int(1e6)){
        len.push_back(rand_range(1, 100000));
        total += len.back();
    }
    cout << len.size() << '\n';
    for (auto l : len){
        int cmd = rand_range(0, 1);
        cout << cmd << ' ';
        for (int i = 0; i < l; i++)
            cout << char(rand_range('a', 'z'));
        cout << '\n';
    }
}