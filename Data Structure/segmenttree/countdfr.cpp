#include <bits/stdc++.h>
using namespace std;

int n;

int lte(int p){
	int temp = p, ans = 0;
	while (temp <= n){
		ans += n /temp;
		temp *= p;
	}
	return ans;
}

int main()
{
	/* code */
	cin >> n; bool a[n + 1];
	memset(a, true, sizeof a);
	a[0] = a[1] = 0; long long d = 1;
	for (int i = 2; i <= n; i++) if (a[i])
		for (int j = i * i; j <= n; j += i) a[j] = 0;
	for (int i = 2; i <= n; i++) if (a[i])
		d *= lte(i) + 1;
	cout << d;
	return 0;
}