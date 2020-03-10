#define pub push_back
#define pob pop_back
#include <bits/stdc++.h>
using namespace std;
int n;
struct pt{
    double x, y;
};

bool cmp(const pt& a, const pt& b){
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(const pt& a, const pt& b, const pt& c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(const pt& a, const pt& b, const pt& c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

vector <pt> convex(const vector <pt>& a){
    deque <pt> up, down;
    pt p1 = a[0], p2 = a.back();
    up.pub(p1); down.pub(p1);
    for (int i = 1; i < a.size(); i++){
        if (i == a.size() - 1 || cw(p1, a[i], p2)){
            while (up.size() > 1 && !cw(up[up.size() - 2], up.back(), a[i])) up.pob();
            up.pub(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)){
            while (down.size() > 1 && !ccw(down[down.size() - 2], down.back(), a[i])) down.pob();
            down.pub(a[i]);
        }
    }
    down.pop_front(); down.pob();
    vector <pt> ans(up.begin(), up.end());
    copy(down.begin(), down.end(), back_inserter(ans));
    return ans;
}

int main(){
    cin >> n;
    vector <pt> a(n);
    double maxx = 0, maxy = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        maxx = max(maxx, a[i].x);
        maxy = max(maxy, a[i].y);
    }
    sort(a.begin(), a.end(), &cmp);
    vector <pt> b = convex(a);
}
