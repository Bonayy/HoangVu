#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int l, r, ma, cnt;
};
using ii = pair <int, int>;
const int N = 1e5 + 5;
node seg[N * 4]; char cmd;
int pos[N], h[N]; ii que[N];

int main(){
    int q, n = 0, x, y; cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> cmd >> x >> y;
        if (cmd == 'A'){
            h[++n] = x; 
        }
    }
}