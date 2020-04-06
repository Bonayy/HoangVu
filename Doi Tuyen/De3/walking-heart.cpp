#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> h(n), a(n), st(n), res(n);
    for (int &x : h) cin >> x;
    for (int &x : a) cin >> x;
    reverse(all(h)); reverse(all(a));
    for (int i = 0; i < n; i++){
        while (!st.empty() && st.back() <= h[i])
            st.pop_back();
        if (a[i] > st.size()) res[i] = -1;
        else res[i] = st[st.size() - a[i]];
        st.push_back(h[i]);
    }
    reverse(all(res));
    for (int x : res) cout << ' ' << x;
}