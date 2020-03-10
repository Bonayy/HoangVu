#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
int Compress(vector <int>& a, vector <int>& b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <int> tmp(a.size() + b.size());
    merge(all(a), all(b), tmp.begin());
    for (auto &x : a)
        x = lower_bound(all(tmp), x) - tmp.begin() + 1;
    for (auto &x : b)
        x = lower_bound(all(tmp), x) - tmp.begin() + 1;
    return tmp.back();
}

class Bit{
    private :
        vector <int> bit; int n;
    public :
        Bit(int n = 0){
            this->n = n;
            bit.assign(n + 1, 0);
        }
        void Update(int i){
            for (; i <= n; i += (i & -i))
                bit[i]++;
        }
        int Get(int i){
            int res = 0;
            for (; i > 0; i -= (i & -i))
                res += bit[i];
            return res;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    Bit F(Compress(a, b));
    for (auto x : b) F.Update(x + 1);
    int cnt = 0;
    for (auto x : a) cnt += F.Get(x);
    cout << cnt;
}
