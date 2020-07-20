#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 4e5 + 5;
int a[N], l[N]; ll dp[N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, h, s, d;
    cin >> n >> h >> s >> d;
    vector <int> st; st.push_back(0);
    for (int i = 1; i <= n; i++){
        while (st.back() && a[st.back()] <= a[i])
            st.pop_back()l
        l[i] = st.back() + 1; st.push_back(i);
    }

}
