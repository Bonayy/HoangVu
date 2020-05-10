#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
char *seq = "!?.,:;-_’#$%&/=*+(){}[]qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
char s[1000];

struct trie{
    int nxt[N][128], aut[N][128], link[N], sz; bool leaf[N];

    void init(){
        for (int i = 0; i <= sz; i++){
            link[i] = leaf[i] = 0;
            for (int j = 0; seq[j]; j++) nxt[i][seq[j]] = aut[i][seq[j]] = 0;
        }
        sz = 0;
    }

    void insert(char s[]){
        int pt = 0;
        for (int i = 0; s[i]; i++){
            if (!nxt[pt][s[i]]) nxt[pt][s[i]] = ++sz;
            pt = nxt[pt][s[i]];
        }
        leaf[pt] = 1;
    }


    void build_link(){
        queue <int> q; q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (int j = 0; seq[j]; j++){
                if (nxt[u][seq[j]]){
                    link[nxt[u][seq[j]]] = u ? aut[link[u]][seq[j]] : 0;
                    q.push(nxt[u][seq[j]]); aut[u][seq[j]] = nxt[u][seq[j]];
                    leaf[nxt[u][seq[j]]] |= leaf[link[nxt[u][seq[j]]]];
                }
                else aut[u][seq[j]] = aut[link[u]][seq[j]];
            }
        }
    }

    int solve(char s[]){
        int pt = 0, res = 0;
        for (int i = 0; s[i]; i++){
            pt = aut[pt][s[i]]; if (leaf[pt]){pt = 0; res++;}
        }
        return res;
    }
} tt;

bool solve(){
    int n, m; scanf("%d%d", &n, &m);
    if (n + m == 0) return false; tt.init();
    while (n--){gets(s); tt.insert(s);}
    tt.build_link(); int res = 0;
    while (m--){gets(s); res += tt.solve(s);}
    printf("%d\n", res); return true;
}

int main(){
    while(solve());
}