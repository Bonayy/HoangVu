#include <iostream>
#include <map>
using namespace std;

struct seg{
    int mi, ma;
};

const int N = 1e5 + 5;
map <int, int> mp;
seg spt[N][18];
int a[N], pow2[N], log2[N], n;

int get_min(int l, int r){
    return min(spt[l][log2[r - l + 1]].mi, 
            spt[r + 1 - pow2[r - l + 1]][log2[r - l + 1]].mi);
}

int get_max(int l, int r){
    return max(spt[l][log2[r - l + 1]].ma,
            spt[r + 1 - pow2[r - l + 1]][log2[r - l + 1]].ma);
}

void pre_calc(){
    pow2[1] = 1; log2[1] = 0;
    for (int i = 2; i <= n; i++){
        pow2[i] = pow2[i - 1]; log2[i] = log2[i - 1];
        if (!(i & (i - 1))){
            pow2[i] <<= 1; log2[i]++;
        }
    }
    for (int k = 1, p = 1; k < 18; k++, p <<= 1)
        for (int i = 0; i + (p << 1) <= n; i++){
            spt[i][k].mi = min(spt[i][k - 1].mi, spt[i + p][k - 1].mi);
            spt[i][k].ma = max(spt[i][k - 1].ma, spt[i + p][k - 1].ma);
        }
}

int main(){
    freopen("SUDI.inp", "r", stdin);
    freopen("SUDI.out", "w", stdout);
    cin >> n; long long ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i]; mp[a[i]] = -1;
        spt[i][0] = {a[i], a[i]};
    }
    pre_calc(); mp[a[0]] = -1;
    for (int i = 0; i < n; i++) {
        int l = mp[a[i]] + 1, r = i, m;
        int pre, suf;
        while (l <= r) {
            m = (l + r) / 2;
            if (get_min(m, i) == a[i]) {
                pre = m;
                r = m - 1;
            } else l = m + 1;
        }
        l = i;
        r = n - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (get_min(i, m) == a[i]) {
                suf = m;
                l = m + 1;
            } else r = m - 1;
        }
        //cout << pre << ' ' << suf << '\n';
        ans -= 1ll * (suf - i + 1) * (i - pre + 1) * a[i];
        l = mp[a[i]] + 1;
        r = i;
        while (l <= r) {
            m = (l + r) / 2;
            if (get_max(m, i) == a[i]) {
                pre = m;
                r = m - 1;
            } else l = m + 1;
        }
        l = i;
        r = n - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (get_max(i, m) == a[i]) {
                suf = m;
                l = m + 1;
            } else r = m - 1;
        }
        //cout << pre << ' ' << suf << "\n\n";
        ans += 1ll * (suf - i + 1) * (i - pre + 1) * a[i];
        mp[a[i]] = i;
    }
    cout << ans << '\n';
}