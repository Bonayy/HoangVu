#include <bits/stdc++.h>
using namespace std;

namespace big_integer{
    typedef vector <int> bigint;
    typedef const bigint& cb;
    const int base = 1000;

    bigint& fix(bigint& a){
        a.push_back(0);
        for (int i = 0; i < (int)a.size() - 1; i++){
            a[i + 1] += a[i] / base; a[i] %= base;
            if (a[i] < 0) a[i] += base, a[i + 1]--;
        }
        while (!a.empty() && a.back() == 0) a.pop_back();
        return a;
    }

    bigint big(int x){
        bigint res;
        while (x > 0){
            res.push_back(x % base);
            x /= base;
        }
        return fix(res), res;
    }

    bigint big(const string& s){
        bigint res(s.size() / 3 + 1);
        for (int i = 0, pos; s[i]; i++){
            pos = (s.size() - i - 1) / 3;
            res[pos] = res[pos] * 10 + s[i] - '0';
        }
        return fix(res), res;
    }

    int comp(cb a, cb b){
        if (a.size() != b.size())
            return (int)a.size() - (int)b.size();
        for (int i = (int)a.size() - 1; i >= 0; i--)
            if (a[i] != b[i]) return a[i] - b[i];
        return 0;
    }

    ostream& operator << (ostream& os, const bigint& a){
        if (a.empty()) return os << 0;
        os << a.back();
        for (int i = a.size() - 2; i >= 0; i--)
            cout << setw(3) << setfill('0') << a[i];
        return os;
    }

    #define def_operator(x) bool operator x (cb a, cb b){return comp(a, b) x 0;}
    def_operator(==)
    def_operator(>)
    def_operator(<)
    def_operator(<=)
    def_operator(>=)
    def_operator(!=)

    void operator += (bigint& a, cb b){
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < (int)b.size(); i++)
            a[i] += b[i];
        fix(a);
    }

    bigint operator + (bigint a, cb b){
        a += b; return a;
    }

    void operator -= (bigint& a, cb b){
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < (int)b.size(); i++)
            a[i] -= b[i];
        fix(a);
    }

    bigint operator - (bigint a, cb b){
        a -= b; return a;
    }

    bigint operator * (cb a, cb b){
        bigint res(a.size() + b.size());
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < (int)b.size(); j++)
                res[i + j] += a[i] * b[j];
        return fix(res), res;
    }

    void operator *= (bigint& a, cb b){
        a = a * b;
    }
}

using namespace big_integer;

const int N = 1005;
char s[N]; int n; 
bigint dp[N][N]; 
bool used[N][N];

bigint calc(int l, int r){
    if (used[l][r]) return dp[l][r];
    if (l == r) return dp[l][r] = big(1);
    if (l == r - 1){
        if (s[l] == s[r]) dp[l][r] = big(1);
        dp[l][r] += big(2); used[l][r] = true;
        return dp[l][r];
    }
    dp[l][r] = calc(l, r - 1) + calc(l + 1, r);
    if (s[l] == s[r]) dp[l][r] += big(1);
    else dp[l][r] -= calc(l + 1, r - 1);
    used[l][r] = true; return dp[l][r];
}

int main(){
    scanf("%s", s + 1); n = strlen(s + 1);
    cout << calc(1, n) << '\n';
}