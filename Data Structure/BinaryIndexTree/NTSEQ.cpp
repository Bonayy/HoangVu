#include <bits/stdc++.h>
using namespace std;

const int mod = int(1e9 + 7);

class sumBit{
    private :
        int n; vector <int> bit;
    public :
        sumBit(int n = 0){
            this->n = n;
            if (n > 0) bit.assign(n + 1, 0);
        }
        void Update(int i, int val){
            for(; i <= n; i += i & -i)
                bit[i] = (bit[i] + val) % mod;
        }
        int Get(int i){
            int res = 0;
            for (; i > 0; i -= i & -i)
                res = (res + bit[i]) % mod;
            return res;
        }
};

class maxBIT{
    private :
        int n; vector <int> bit;
    public :
        maxBIT(int n = 0){
            this->n = n;
            bit.assign(n + 1, 0);
        }
        void Update(int i, int val){
            for(; i <= n; i += i & -i)
                bit[i]  = max(bit[i], val);
        }
        int Get(int i){
            int res = 0;
            for (; i > 0; i -= i & -i)
                res = max(res, bit[i]);
            return res;
        }
};

void compress(int n, int a[]){
    vector <int> vt(a + 1, a + n + 1);
    sort(vt.begin(), vt.end());
    vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(vt.begin(), vt.end(), a[i]) - vt.begin() + 1;
}

void solve(int n, int a[]){
    compress(n, a);
    maxBIT M(n);
    sumBit S(n);
    int lis[n + 1], cnt[n + 1];
    for (int i = 1; i <= n; i++){
        lis[i] = M.Get(a[i] - 1) + 1;
        M.Update(a[i], lis[i]);
    }
    vector <int> haveLis(M.Get(n) + 1);
    for (int i = 1; i <= n; i++)
        haveLis[lis[i]].push_back(i);
}

int main(){
}
