#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int cnt[N][2], f[N];
int child[N][2];

void dfs(int u){
    if (f[u] != -1){
        cnt[u][f[u]] = 1;
        return;
    }
    
}

int main(){

}