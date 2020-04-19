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

using namespace big_integer;
bigint dp[105];

void print(const bigint &a){
    string s = to_string(a);
    if (s.size() <= 10) cout << s << '\n';
    else {
        cout << s[0] << s[1] << s[2] << s[3] << s[4];
        cout << "...";
        cout << s[size(s) - 5] << s[size(s) - 4] << s[size(s) - 3] << s[size(s) - 2] << s[size(s) - 1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("bt1.inp", "r", stdin);
    freopen("bt1.out", "w", stdout);
    dp[0] = big(1); int n;
    for (int i = 1; i <= 100; i++){
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    }
    while (cin >> n) print(dp[n / 2]);
}