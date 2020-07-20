#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int r[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector <int> a(n), st;
    for (int &x : a) cin >> x;
    st.push_back(n);
    for (int i = n - 1; ~i; i--){
        while (st.back() < n &&
        a[st.back()] >= a[i])
            st.pop_back();
        r[i] = st.back();
        st.push_back(i);
    }
    int cur = 0; long long res = 0;
    for (int i = 0; i < n; i++){
        cout << cur << '\n';
        int nxt = min(i + k, r[i]);
        res += 1ll * a[i] * min(nxt - i, k - cur);
        cur += min(nxt - i, k - cur); cur--;
    }
    //cout << res << '\n';
}
