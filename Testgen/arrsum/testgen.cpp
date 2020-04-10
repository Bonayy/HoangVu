#include <bits/stdc++.h>
using namespace std;

const int ele_limit = 1e9;
const int num_limit = 1e3;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution rng_range(1, ele_limit);
string task = "arrsum";

int main(){
    const int ntest = 20;
    for (int i = 1; i <= ntest; i++){
        stringstream ss; string name;
        ss << setw(int(log10(ntest)) + 1) << setfill('0') << i << "\n";
        ss >> name; name = "test" + name;
        ofstream inp(task + ".inp");
        
        system(("mkdir -p " + name).c_str());
        inp.close(); system("./solution");
        system(("mv " + task + ".inp " + name).c_str());
        system(("mv " + task + ".out " + name).c_str());
    }
}