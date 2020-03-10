#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

vector <int> g[N];
int path[N];

int get_path(int u){
    if (path[u] != 0) return path[u];
    path[u] = 1;
    for (auto v : g[u])
        chkmax(path[u], get_path(v) + 1);
    return path[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    unordered_map <string, int> pos;
    int n; cin >> n;
    vector <string> words(n);
    for (int i = 0; i < n; i++){
        cin >> words[i]; pos[words[i]] = i;
    }
    for (auto s : words){
        for (int i = 0; i < static_cast <int> (s.size()); i++){
            auto it = pos.find(s.substr(0, i) + s.substr(i + 1));
            if (it != pos.end())
                g[it->second].emplace_back(i);
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, get_path(i));
    cout << ans;
}