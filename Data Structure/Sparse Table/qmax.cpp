#include <bits/stdc++.h>
using namespace std;
 
template <class T, class _T> 
bool chkmax(T& a, const _T& b){
	return a < b ? a = b, true : false; 
}
 
template <class T, class _T> 
bool chkmin(T& a, const _T& b){
	return a > b ? a = b, true : false; 
}
 
const int N = 5e4 + 5;
int a[N], spt[N][17], n, m, q, loga[N];
 
void input(){
    cin >> n >> m;
    for (int i = 0, u, v, k; i < m; i++){
        cin >> u >> v >> k;
        a[u] += k; a[v + 1] -= k;
    }
}
 
void prepare(){
    for (int i = 1; i <= n; i++)
        spt[i][0] = a[i] + spt[i - 1][0];
    for (int i = 1; i <= n; i++)
        for (int j = 16; j >= 0; j--)
            if ((1ll << j) <= i){
                loga[i] = j; break;
            }
    for (int k = 1; k <= 16; k++)
        for (int i = 1; i <= n; i++){
            spt[i][k] = spt[i][k - 1];
            if (i + (1ll << (k - 1)) <= n) 
                chkmax(spt[i][k], spt[i + (1ll << (k - 1))][k - 1]);
        }
}
 
void query(){
    cin >> q; int l, r;
    while (q--){
        cin >> l >> r;
        cout << max(spt[l][loga[r - l + 1]], 
        spt[r + 1 - (1ll << loga[r - l + 1])][loga[r - l + 1]]) << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    input(); prepare(); query();
    return 0;
} 