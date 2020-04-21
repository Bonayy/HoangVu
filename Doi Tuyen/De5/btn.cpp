#include <bits/stdc++.h>
using namespace std;

namespace big_integer{  
    using bigint = vector <int>;
    using cb = const bigint&;
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
            os << setw(3) << setfill('0') << a[i];
        return os;
    }

    istream& operator >> (istream& is, bigint &a){
        string s; is >> s; a = big(s); return is;
    }

    string to_string (const bigint &a){
        if (a.empty()) return "0";
        stringstream ss; ss << a.back();
        for (int i = a.size() - 2; i >= 0; i--)
            ss << setw(3) << setfill('0') << a[i];
        return ss.str();
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

#define fi first
#define se second
using namespace big_integer;
using iii = tuple <int, int, int>;

char op[] = "([{", cl[] = ")]}", s[205];
map <iii, bigint> dp;

bigint calc(int l, int r, int k){
    if (k < 0) return big(0);
    if (k == 0) return big(l > r);
    if (l > r) return big(k == 0);
    if (k > (r - l + 1) / 2) return big(0);
    if (dp.count(make_tuple(l, r, k))) 
        return dp[make_tuple(l, r, k)];
    dp[make_tuple(l, r, k)] = big(0);
    auto it = dp.find(make_tuple(l, r, k));
    for (int m = l + 1; m <= r; m += 2)
        for (int t = 0; t < 3; t++)
            if (s[l] == op[t] || s[l] == '?')
                if (s[m] == cl[t] || s[m] == '?'){
                    for (int nk = 0; nk < k; nk++)
                        it->se += calc(l + 1, m - 1, k - 1) * calc(m + 1, r, nk);
                    for (int nk = 0; nk < k - 1; nk++)
                        it->se += calc(l + 1, m - 1, nk) * calc(m + 1, r, k);
                    it->se += calc(l + 1, m - 1, k - 1) * calc(m + 1, r, k);
                }
    return it->se;
}

int main(){
    freopen("btn.inp", "r", stdin);
    freopen("btn.out", "w", stdout);
    int n, k; cin >> n >> k >> s;
    cout << calc(0, n - 1, k) << '\n';
}