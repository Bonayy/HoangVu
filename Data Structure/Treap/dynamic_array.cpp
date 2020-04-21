#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class dynamic_array{
private:
    class node{
    public:
        T key; int prior, sz = 1; 
        node *l = NULL, *r = NULL;
        
        ~node(){
            delete l; delete r;
        }

        node(T key): key(key), prior(rng()){}
    } *root;

    int size(node *pt){
        return pt ? pt->sz : 0;
    }

    void update(node *pt){
        if (pt) pt->sz = size(pt->l) + size(pt->r) + 1;
    }

    node* merge(node *l, node *r){
        if (!l || !r) return l ? l : r;
        if (l->prior > r->prior)
            return l->r = merge(l->r, r), update(l), l;
        else return r->l = merge(l, r->l), update(r), r;
    }

    void split(node *pt, int pos, node *&l, node *&r, int add = 0){
        if (!pt) return void(l = r = NULL);
        int l_sz = size(pt->l), cur_pos = add + l_sz;
        if (cur_pos < pos) 
            split(pt->r, pos, pt->r, r, add + 1 + l_sz), l = pt;
        else split(pt->l, pos, l, pt->l, add), r = pt;
        update(pt);
    }

public:
    dynamic_array(): root(NULL){}
    
    ~dynamic_array(){
        delete root;
    }

    void insert(int pos, T key){
        node *l, *r; 
        split(root, pos, l, r);
        root = merge(merge(l, new node(key)), r);
    }

    void erase(int pos){
        node *l, *m, *r;
        split(root, pos, l, m);
        split(m, 1, m, r);
        root = merge(l, r);
    }

    void push_back(T key){
        insert(this->size(), key);
    }

    T& operator [] (const int &pos){
        assert(pos < this->size());
        node *l, *m, *r;
        split(root, pos, l, m);
        split(m, 1, m, r);
        T &res = m->key;
        root = merge(merge(l, m), r);
        return res;
    }

    int size() const {
        return root ? root->sz : 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    dynamic_array <string> s;
}