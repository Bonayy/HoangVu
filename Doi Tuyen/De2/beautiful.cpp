#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
long long res = 0, n, s;
long long pow10[13];

void process(int a){
    int ndgt = int(log10(a)) + 1;
    long long t = 0, x = a, rev = 0;
    while (x > 0){
        t += x % 10; 
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    if (2 * t % s == 0 && a * pow10[ndgt] + rev <= n)
    res++;
    x = a / 10; rev = 0;
    while (x > 0){
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    if ((2 * t - a % 10) % s == 0 && a * pow10[ndgt - 1] + rev <= n)
        res++;
}

int main(){
    cin >> n >> s; pow10[0] = 1;
    for (int i = 1; i < 13; i++)
        pow10[i] = pow10[i - 1] * 10;
    for (int i = 1; i <= N; i++)
        process(i);
    cout << res << '\n';
}