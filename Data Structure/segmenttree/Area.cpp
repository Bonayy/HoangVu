#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    register char c;
    bool nega = 0;
    while((!isdigit(c = getchar())) && (c != '-'));
    if (c == '-'){
        nega = 1;
        c = getchar();
    }
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
    if (nega)
        x = -x;
}
template <typename T>
inline void writep(T x){
    if(x > 9) writep(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x){
    if (x < 0){
        putchar('-');
        x = -x;
    }
    writep(x);
}
template <typename T>
inline void writeln(T x){
    write(x);
    putchar('\n');
}

void init(){
    if (fopen("input.txt", "rt")){
        freopen("input.txt", "rt", stdin);
    }
}

struct data{
    int x, l, r, type;
    bool operator < (const data& o) const {
        return x < o.x || (x == o.x && type < o.type);
    }
};

struct seg{
    int cnt, len;
};

const int N = 30010;
data a[N];
seg node[N << 2];
int lo[N << 2], hi[N << 2];
typedef const int& ci;

void build(ci i, ci low, ci high){
    lo[i] = low; hi[i] = high;
    if (low == high) return;
    int med = (low + high) >> 1;
    build(i << 1, low, med);
    build(i << 1 | 1, med + 1, high);
}

void update(ci i, ci a, ci b, ci type){
    if (a > hi[i] || b < lo[i] || lo[i] > hi[i]) return;
    if (a <= lo[i] && b <= hi[i]){
        node[i].cnt += type;
        if (type == 1) node[i].len += b - a + 1;
        else if (node[i].cnt == 0){
            if (a < b) node[i].len = node[i << 1].len + node[i << 1 | 1].len;
            else node[i].len = 0;
        }
        return;
    }
    update(i << 1, a, b, type);
    update(i << 1 | 1, a, b, type);
    if (node[i].cnt == 0 && a < b)
        node[i].len = node[i << 1].len + node[i << 1 | 1].len;
}

int main(){
    int top = 0;
    int n; cin >> n; int k = 0;
    for (int i = 1, x1, x2, y1, y2; i <= n; i++){
        cin >> x1 >> y1 >> x2 >> y2; k = max(k, y2);
        a[++top] = {x1, y1 + 1, y2, 1};
        a[++top] = {x2, y1 + 1, y2, -1};
    }
    sort(a + 1,a + top + 1);
    build(1, 1, k); long long ans = 0;
    for (int i = 1; i <= top; i++){
        ans += 1ll * node[1].len * (a[i].x - a[i - 1].x);
        update(1, a[i].l, a[i].r, a[i].type);
    }
    cout << ans;
    return 0;
}
