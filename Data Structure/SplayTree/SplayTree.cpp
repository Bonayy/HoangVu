#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
struct Node{
    int key;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int key) : key(key){}
};

Node* root;
//build tree from sorted array
Node* buildTree(int lo, int hi, Node* parent){
    if (lo > hi) return nullptr;
    int mi = lo + (hi - lo) / 2;
    Node *node = new Node(a[mi]);
    node -> parent = parent;
    node -> left = buildTree(lo, mi - 1, node);
    node -> right = buildTree(mi + 1, hi, node);
    return node;
}

//just find, not splay
Node* findOnly(Node* node, const int& key){
    if (node == nullptr) return nullptr;
    if (key < node -> key)
        return findOnly(node -> left, key);
    if (key > node -> key)
        return findOnly(node -> right, key);
    return node;
}

//find node include min value
Node* minVal(){
    Node* curr = root;
    while (curr -> left != nullptr) curr = curr -> left;
    return curr;
}

//just insert, not splay
Node* insertOnly(Node* node, const int& key){
    if (key == node -> key) return node;
    else if (key > node -> key){
        if (node -> right == nullptr){
            Node* temp = new Node(key);
            node -> right = temp;
            temp -> parent = node;
            return temp;
        }
        else return insertOnly(node -> right, key);
    }
    else{
        if (node -> left == nullptr){
            Node* temp = new Node(key);
            node -> left = temp;
            temp -> parent = node;
            return temp;
        }
        else return insertOnly(node -> left, key);
    }
}

//right rotation at y
void rightRotate(Node* y){
    Node* x = y -> left;
    Node* w = y -> parent;
    Node* z = x -> right;
    if (w != nullptr){
        if (w -> left != nullptr && w -> left -> key == y -> key){
            w -> left = x;
        }
        else w -> right = x;
    }
    if (z != nullptr) z -> parent = y;
    y -> left = z;
    x -> parent = w;
    x -> right = y;
    y -> parent = x;
}

//left rotation at x
void leftRotate(Node* x){
    Node* y = x -> right;
    Node* w = x -> parent;
    Node* z = y -> left;
    if (w != nullptr){
        if (w -> left != nullptr && w -> left -> key == x -> key){
            w -> left = y;
        }
        else{
            w -> right = y;
        }
    }
    if (z != nullptr) z -> parent = x;
    x -> right = z;
    y -> left = x;
    y -> parent = w;
    x -> parent = y;
}

//right roller coaster at x
void rightRoller(Node* x){
    Node* y = x -> left;
    rightRotate(x);
    rightRotate(y);
}

//left roller coaster at x
void leftRoller(Node* x){
    Node* y = x -> right;
    leftRotate(x);
    leftRotate(y);
}

//right zigzag at x
void rightZigzag(Node* x){
    Node* y = x -> right;
    rightRotate(y);
    leftRotate(x);
}

//left zigzag at x
void leftZigzag(Node* x){
    Node* y = x -> left;
    leftRotate(y);
    rightRotate(x);
}

//main action : splay the tree
void splay(Node* x){
    if (x -> parent == nullptr) return;
    Node* y = x -> parent;
    if (y -> parent == nullptr){
        if (y -> left != nullptr && y -> left -> key == x -> key)
            rightRotate(y);
        else leftRotate(y);
    }
    else{
        Node* z = y -> parent;
        if (z -> left != nullptr && z -> left -> key == y -> key){
            if (y -> left != nullptr && y -> left -> key == x -> key)
                rightRoller(z);
            else leftZigzag(z);
        }
        else{
            if (y -> right != nullptr && y -> right -> key == x -> key)
                leftRoller(z);
            else rightZigzag(z);
        }
    }
    splay(x);
}

//insert a node and splay
void insertNode(const int& key){
    Node* temp = insertOnly(root, key);
    splay(temp);
    root = temp;
}

//delete a node and splay
void deleteNode(const int& key){
    if (findOnly(root, key) == nullptr) return;
    root = findOnly(root, key);
    Node* y = root -> left;
    y -> parent = nullptr;
    if (y -> right != nullptr){
        Node* w = y -> right;
        while(w -> right != nullptr) w = w -> right;
        splay(w);
        w -> right = root -> right;
        if (root -> right != nullptr) root -> right -> parent = w;
        root = w;
    }
    else{
        y -> right = root -> right;
        if (root -> right != nullptr) root -> right -> parent = y;
        root = y;
    }
}

void preoder(Node* node){
    if (node == nullptr) return;
    cout << node -> key << ' ';
    preoder(node -> left);
    preoder(node -> right);
}

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        root = buildTree(0, n - 1, nullptr);
        int x;
        while (m--){
            cin >> x;
            if (findOnly(root, x) == nullptr) cout << "NO\n";
            else{
                cout << "YES\n"; deleteNode(x);
            }
        }
    }
    return 0;
}

