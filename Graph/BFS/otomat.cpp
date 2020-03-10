#include <bits/stdc++.h>
using namespace std;

int& flip_bit(int& x, const int& pos){
    return x = x ^ (1ll << pos);
}

bool get_bit(const int& x, const int& pos){
    return x >> pos & 1;
}

int to[2][8], par[256];
char cont[256];
bool used[256];
queue <int> q;

int main(){
    /// initialize
    to[0][0] = to[0][3] = 5;
    to[1][0] = to[0][1] = 3;
    to[1][1] = to[0][2] = 4;
    to[1][2] = to[1][4] = 7;
    to[1][3] = to[0][4] = 6;
    to[0][5] = to[0][6] = to[0][7] = 8;
    to[1][5] = to[1][6] = to[1][7] = 8;
    /// read data
    string s, t; cin >> s >> t;
    int a, b; a = b = 0;
    /// prepare
    for (auto pt = s.rbegin(); pt != s.rend(); pt++)
        a = (a << 1) + *pt - '0';
    for (auto pt = t.rbegin(); pt != t.rend(); pt++)
        b = (b << 1) + *pt - '0';
    if (a == b) return cout << 0, 0;
    q.push(a); int x, y; used[a] = true;
    while (!q.empty()){
        x = q.front(); q.pop();
        for (int i = 0; i < 3; i++){
            int y = x;
            for (int j = i; j < 8; ){
                flip_bit(y, j);
                j = to[get_bit(y, j) ^ 1][j];
            }
            if (!used[y]){
                used[y] = true; q.push(y);
                cont[y] = i + 'A'; par[y] = x;
            }
            if (y == b){
                string ans;
                while (cont[y] != 0){
                    ans += cont[y]; y = par[y];
                }
                for (auto it = ans.rbegin(); it != ans.rend(); it++)
                    cout << *it;
                return 0;
            }
        }
    }
    return cout << -1, 0;
}
