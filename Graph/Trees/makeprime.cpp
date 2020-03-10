#include <bits/stdc++.h>
using namespace std;
int pow(int a, int b){
    int res = 1;
    for (; b > 0; b >>= 1){
        if (b & 1) res = res * a;
        a = a * a;
    }
    return res;
}

const int N = 1e6 + 5;
int pre[N]; 

int sumdiv(int n){
    int res = 1;
    while (n > 1){
        int t = pre[n], cnt = 0;
        while (n % t == 0){
            cnt++; n /= t;
        }
        res *= (pow(t, cnt + 1) - 1) / (t - 1);
    }
    return res;
}

int makePrime(int n)
{
    for (int i = 2; i < N; i++)
        pre[i] = i;
    for (int i = 2; i * i < N; i++)
        if (pre[i] == i)
            for (int j = i * i; j < N; j += i)
                if (pre[j] == j) pre[j] = i;
    while (pre[n] != n){
        //cout << sumdiv(n) << '\n';
        int t = sumdiv(n);
        if (n == t - 1 - n) return -1;
        n = t - 1 - n;
    }
    return n;
}

int main(){
    for (int i = 2; i < N; i++)
        pre[i] = i;
    for (int i = 2; i * i < N; i++)
        if (pre[i] == i)
            for (int j = i * i; j < N; j += i)
                if (pre[j] == j) pre[j] = i;
    cout << makePrime(12) << '\n';
}