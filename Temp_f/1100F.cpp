#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

struct gauss{
    int basis[21];

    void insert(int x){
        for (int i = 20; ~i; i--){
            if (!(x >> i & 1)) continue;
            if (!basis[i]) basis[i] = x;
            x ^= basis[i];
        }
    }

    void get_max(){
        int x = 0;
        for (int i = 20; ~i; i--)
            chkmax(x, x ^ basis[i]);
        return x;
    }
};

gauss merge(const gauss &a, const gauss &b){
    gauss res = a;
    for (int i = 20; ~i; i--)
        res.insert(b.basis[i]);
}

int main(){
    
}