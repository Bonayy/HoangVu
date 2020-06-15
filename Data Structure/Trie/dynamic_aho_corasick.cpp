#include <bits/stdc++.h>
using namespace std;

namespace foo{
    template <class T>
    void clear(vector <T> &v){
        v.clear(); v.shrink_to_fit();
    }
}

struct trie{
    struct state{
        int nxt[26], aut[26];
        int link, cnt, leaf;

        state(): link(0), cnt(0), leaf(0){
            memset(nxt, 0, sizeof nxt);
            memset(aut, 0, sizeof aut);
        }
    };

    vector <string> data;
    vector <state> tree;

    trie(){
        tree.push_back(state());
    }

    void clear(){
        foo::clear(data); foo::clear(tree);
        tree.push_back(state());
    }

    int size() const {
        return data.size();
    }

    int& nxt(int u, char c){
        return tree[u].nxt[c - 'a'];
    }

    int& aut(int u, char c){
        return tree[u].aut[c - 'a'];
    }

    int& link(int u){
        return tree[u].link;
    }

    int& cnt(int u){
        return tree[u].cnt;
    }

    int& leaf(int u){
        return tree[u].leaf;
    }

    void insert(const string &s){
        data.push_back(s); int pt = 0;
        for (char c : s){
            if (!nxt(pt, c)){
                nxt(pt, c) = tree.size();
                tree.push_back(state());
            }
            pt = nxt(pt, c);
        }
        leaf(pt)++;
    }

    void automata(){
        queue <int> q; q.push(0);
        while (!q.empty()){
            int u = q.front(); q.pop();
            cnt(u) = leaf(u) + cnt(link(u));
            for (char c = 'a'; c <= 'z'; c++){
                int v = nxt(u, c);
                if (v){
                    link(v) = u ? aut(link(u), c) : 0;
                    q.push(v); aut(u, c) = v;
                }
                else aut(u, c) = aut(link(u), c);
            }
        }
    }

    int count(const string &s){
        int pt = 0, res = 0;
        for (char c : s){
            pt = aut(pt, c); res += cnt(pt);
        }
        return res;
    }
};

struct aho_corasick{
    trie data[31]; int sz = 0, __size = 0;

    void move(trie &src, trie &des){
        for (auto s : src.data) des.insert(s);
        src.clear();
    }

    aho_corasick(): sz(0), __size(0){}

    void insert(const string &s){
        data[sz].insert(s);
        int cur = sz, pw = 1;
        while (sz && data[sz - 1].size() == pw){
            pw *= 2; sz--;
        }
        while (cur > sz){
            move(data[cur], data[sz]); cur--;
        }
        data[sz++].automata(); __size++;
    }

    int count(const string &s){
        int res = 0;
        for (int i = 0; i < sz; i++)
            res += data[i].count(s);
        return res;
    }

    int size() const {
        return __size;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}