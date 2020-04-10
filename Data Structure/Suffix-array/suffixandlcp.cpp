#include <bits/stdc++.h>
using namespace std;

struct suffix_array{
    string s; vector <int> sa, lcp;
    suffix_array(const string &inp){
        s = inp + '$'; 
        sa.resize(s.size());
        lcp.resize(s.size());
    }
    
};

int main(){

}