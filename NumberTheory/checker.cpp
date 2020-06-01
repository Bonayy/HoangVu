#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
string task = "GCDS";

int main(){
    for (int i = 1; i <= 100; i++){
        stringstream ss; string name;
        ss >> name; name = "test" + name;
        ofstream inp(task + ".inp");
        int n = size_t(rng()) % 5000;
        inp << n << '\n';
        for (int i = 1; i <= n; i++)
            inp << size_t(rng()) % 1000001 << ' ';
        inp.close(); system("./solution");
        system(("./" + task).data());
        if (system(("diff " + task + ".out " + task + ".ans").data()))
            return cout << "wrong\n", 0;
    }
    cout << "correct\n";
}