#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair <ll, ll>;
const int N = 1e5 + 5;
struct node{
    ll val; pll lazy;
    node():val(0), lazy({0, 0}) {}
} seg[N << 2];
int lo[N << 2], hi[N << 2];

int main(){

}