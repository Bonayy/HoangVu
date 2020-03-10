#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s1, s2, s;
	cin >> s1 >> s2;
	s = s2 + '.' + s1;
	vector <int> z(s.size());
	int l(0), r(0), n(s.size());
	z[0] = n;
	for (int i = 1; i < n; i++){
		if (z[i - l] < r - i + 1) z[i] = z[i - l];
		else {
			r = max(r, i);
			while (s[r - i] == s[r]) r++;
			z[i] = r - i; r--; l = i;
		}
	}
	for (int i = s2.size(); i < n; i++)
		if (z[i] == s2.size()) cout << i - s2.size() << ' ';
	return 0;
}
