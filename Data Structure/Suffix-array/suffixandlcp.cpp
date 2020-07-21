#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

namespace suffixarray{
    int cnt[N], sa[N], x[N], y[N], lcp[N], n;
    void build(string s){
        s += char(1); n = s.size();
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        for (int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; ~i; i--) sa[--cnt[s[i]]] = i;
        for (int i = 1; i < n; i++){
            x[sa[i]] = x[sa[i - 1]]; 
            if (s[sa[i]] != s[sa[i - 1]]) x[sa[i]]++;
        }
        for (int j = 1; j < n; j <<= 1){
            fill_n(cnt, n, 0);
            for (int i = 0; i < n; i++) cnt[x[i]]++;
            for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; ~i; i--){
                int prev = (sa[i] - j + n) % n;
                y[--cnt[x[prev]]] = prev;
            } 
            swap(sa, y); y[sa[0]] = 0;
            for (int i = 1; i < n; i++){
                y[sa[i]] = y[sa[i - 1]];
                if (x[sa[i]] != x[sa[i - 1]]) y[sa[i]]++;
                else {
                    int p = sa[i] + j, q = sa[i - 1] + j;
                    if (x[p % n] != x[q % n]) y[sa[i]]++;
                }
            }
            swap(x, y);
        }
        rotate(sa, sa + 1, sa + n); n--;
        for (int i = 0; i < n; i++) x[sa[i]] = i;
        for (int i = 0, k = 0; i < n; i++, k ? k-- : 0){
            if (x[i] == n - 1){
                k = 0; continue;
            }
            int j = sa[x[i] + 1];
            while (max(i, j) + k < n && s[i + k] == s[j + k]) k++;
            lcp[x[i]] = k;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    using namespace suffixarray;
    string s; cin >> s; build(s);
    cout << 1ll * n * (n + 1) / 2 -
            accumulate(lcp, lcp + n, 0ll) << '\n';
}