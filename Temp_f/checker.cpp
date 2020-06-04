#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string task = "TREELIS";

int ver[10005];

int main(){
    for (int i = 1; i <= 15; i++){
        stringstream ss; string name;
        ss >> name; name = "test" + name;
        ofstream inp(task + ".inp");
        int n = size_t(rng()) % 105;
        inp << n << '\n';
        iota(ver + 1, ver + n + 1, 1);
        shuffle(ver + 1, ver + n + 1, rng);
        for (int j = 1; j <= n; j++)
            inp << size_t(rng()) % 100001 << " \n"[j == n];
        for (int j = 1; j < n; j++)
            inp << ver[j] << ' ' << ver[j + 1] << '\n';
        inp.close(); system("solution"); system(task.data());
        if (system(("fc " + task + ".out " + task + ".ans").data()))
            return cout << "wrong at test case " << i << '\n', 0;
    }
    cout << "correct\n";
}