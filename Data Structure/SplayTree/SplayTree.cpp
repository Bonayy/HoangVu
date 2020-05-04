#include <bits/stdc++.h>
using namespace std;

template <class T>
class splay_tree{
private:
    class node{
    public:
        T key; node *p = 0, *l = 0, *r = 0;

        node(int key): key(key){}

        ~node(){
            delete l; delete r;
        }
    } *root;
    int sz = 0;

    void lrot(node *x){
        node *y = x->r;
        if (y){
            x->r = y->l; y->p = x->p;
            if (y->l) y->l->p = x;
        }
        if (!x->p) root = y;
        else if (x == x->p->l) x->p->l = y;
        else x->p->r = y;
        if (y) y->l = x; x->p = y;
    }

    void rrot(node *x){
        node *y = x->l;
        if (y){
            x->l = y->r; y->p = x->p;
            if (y->r) y->r->p = x;
        }
        if (!x->p) root = y;
        else if (x == x->p->l) x->p->l = y;
        else x->p->r = y;
        if (y) y->r = x; x->p = y;
    }

    void splay(node *x){
        while (x->p){
            if (!x->p->p){
                if (x == x->p->l) rrot(x->p);
                else lrot(x->p);
            }
            else {
                if (x == x->p->l){
                    if (x->p == x->p->p->l){
                        rrot(x->p->p); rrot(x->p);
                    }
                    else {
                        rrot(x->p); lrot(x->p);
                    }
                }
                else {
                    if (x->p == x->p->p->l){
                        lrot(x->p); rrot(x->p);
                    }
                    else {
                        lrot(x->p->p); lrot(x->p);
                    }
                }
            }
        }
    }

    void inorder(node *x){
        if (!x) return;
        inorder(x->l);
        cout << x->key << '\n';
        inorder(x->r);
    }

public:
    splay_tree(): root(0){}

    ~splay_tree(){
        delete root;
    }

    int size() const {
        return sz;
    }

    bool find(const T &key){
        node *x = root;
        while (x){
            if (x->key == key) return 1;
            if (x->key < key) x = x->r;
            else x = x->l;
        }
        return 0;
    }

    bool insert(const T &key){
        node *x = root, *y = 0;
        while (x){
            y = x;
            if (x->key == key) return 0;
            if (x->key < key) x = x->r;
            else x = x->l;
        }
        x = new node(key); x->p = y;
        if (!y) root = x;
        else if (x->key < y->key) y->l = x;
        else y->r = x;
        splay(x); sz++; return 1;
    }

    bool erase(const T &key){
        node *x = root;
        while (x){
            if (x->key == key) break;
            if (x->key < key) x = x->r;
            else x = x->l;
        }
        if (!x) return 0; splay(x);
        node *y = x->l;
        if (!y){
            root = x->r; if (root) root->p = 0;
            return 0;
        }
        while (y->r) y = y->r;
        if (x->r){
            y->r = x->r; x->r->p = y->r;
        }
        root = x->l; root->p = 0; return 1;
    }

    void inorder(){
        inorder(root);
    }
};

int main(){
    freopen("SplayTree.inp", "r", stdin);
    freopen("SplayTree.out", "w", stdout);
    splay_tree <int> s;
    for (int i = 1; i <= int(1e3); i++) s.insert(abs(int(rng())));
    s.inorder();
}