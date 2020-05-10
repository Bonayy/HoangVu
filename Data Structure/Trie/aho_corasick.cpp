#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

class trie{
private:
    class node{
    public:
        int nxt[26], link, aut[26];

        node(): link(0){
            memset(nxt, 0, sizeof nxt);
            memset(aut, 0, sizeof aut);
        }
    };

    node data[N]; int sz;

public:
    trie(): sz(0){}

    void insert(const string &s){
        int pt = 0;
        for (char c : s){
            if (!data[pt].nxt[c - 'a'])
                data[pt].nxt[c - 'a'] = ++sz;
            pt = data[pt].nxt[c - 'a'];
        }
    }

    void build_kmp(){
        queue <int> q; q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (int c = 0; c < 26; c++){
                int v = data[u].nxt[c];
                if (v){
                    data[v].link = u ? 
                        data[data[u].link].aut[c] : 0;
                    q.push(v);
                }
                data[u].aut[c] = v ? v : 
                    data[data[u].link].aut[c];
            }
        }
    }
};

int main(){

}