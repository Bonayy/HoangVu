#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int cnta[1000], cnt[1000], a[N], b[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, c; cin >> n; vector <int> ans;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> c; deque <int> dq; 
    for (int i = 1; i <= c; i++) cin >> b[i];
    sort(b + 1, b + c + 1);
    for (int i = 1; i <= c; i++) cnt[b[i]]++;
    for (int i = 1; i < c; i++){
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        cnta[a[i]]++; dq.push_back(i);
    }
    for (int i = c; i <= n; i++){
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        cnta[a[i]]++; dq.push_back(i);
        int dif = a[dq.front()] - b[1];
        bool flag = true;
        for (int j = 1; j <= c; j++)
            if (b[j] + dif < 0 || cnta[b[j] + dif] != cnt[b[j]])
                flag = false;
        if (flag) ans.push_back(i - c + 1);
        cnta[a[i - c + 1]]--;
        while (!dq.empty() && dq.front() <= i - c + 1)
            dq.pop_front();
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}