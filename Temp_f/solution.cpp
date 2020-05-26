#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int l[N], r[N], a[N], maxj, maxi[N];
vector <int> rev[N]; set <int> s;

int main(){
    freopen("boundseq.inp", "r", stdin);
    freopen("boundseq.ans", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; vector <int> st;
    for (int i = 1; i <= n; cin >> a[i++]);
    st.push_back(0); int res = 0;
    for (int i = 1; i <= n; i++){
        while (st.back() && a[st.back()] <= a[i])
            st.pop_back();
        l[i] = st.back() + 1; st.push_back(i);
    }
    st.clear(); st.push_back(n + 1);
    for (int i = n; i > 0; i--){
        while (st.back() <= n && a[st.back()] >= a[i])
            st.pop_back();
        r[i] = st.back() - 1; st.push_back(i);
    }
    for (int i = 1; i <= n; i++) rev[l[i]].push_back(i);
    for (int i = 1; i <= n; i++){
        for (int x : rev[i]) s.insert(x);
        auto it = s.upper_bound(r[i]);
        if (it != s.begin())
            res = max(res, *(--it) - i + 1);
    }
    if (res < 2) cout << "-1\n";
    else cout << res << '\n';
}