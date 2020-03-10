#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
char s[maxn]; int n;
int cnt[maxn], pre[maxn];

int main(){
    freopen("cprefix.inp", "rt", stdin);
    freopen("cprefix.out", "wt", stdout);
    scanf("%s", s); n = strlen(s);
    for (int i = 1, j = 0; s[i]; i++){
        while (j && s[i] != s[j]) j = pre[j - 1];
        if (s[i] == s[j]) j++;
        pre[i] = j;
    }
    for (int i = n - 1; i >= 0; i--){
        cnt[i + 1]++; cnt[pre[i]] += cnt[i + 1];
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", cnt[i]);
}
