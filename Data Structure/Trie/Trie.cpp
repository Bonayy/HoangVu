#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;

struct Trie{
    struct Node{
        bool hasStr = false;
        Node* Child[26];
        Node(){
            for (auto &c : Child)
                c = NULL;
        }
    };
    Node* root = new Node();
    void Insert(const string& s){
        Node* p = root;
        for (auto c : s){
            int t = c - 'a';
            if (p->Child[t] == NULL)
                p->Child[t] = new Node();
            p = p->Child[t];
        }
        p->hasStr = true;
    }
    bool Find(const string& s){
        Node* p = root;
        for (auto c : s){
            int t = c - 'a';
            if (p->Child[t] == NULL) return false;
            p = p->Child[t];
        }
        return p->hasStr;
    }
    int getLong(Node* p, int cnt){
        cnt += p->hasStr;
        int res = cnt;
        for (auto c : p->Child)
            if (c != NULL)
                res = max(res, getLong(c, cnt));
        return res;
    }
    int getLong(){
        return getLong(root, 0);
    }
} T;

int main(){
    int n, m; cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        T.Insert(s);
    }
    cout << T.getLong() << '\n';
}
