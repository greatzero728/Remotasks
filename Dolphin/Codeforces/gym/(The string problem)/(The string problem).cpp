#include <bits/stdc++.h>
using namespace std;
string s;
int was[100001][27];
int l,r,m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("minimal.in","r",stdin);
	freopen("minimal.out","w",stdout);
#endif
	
	cin >> s;
	was[1][s[0]-'a'] = 1;
	for (int i = 2; i <= s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			was[i][j] = was[i-1][j];
		}
		was[i][s[i-1]-'a'] = i;
	}
	
	cin >> m;
	while(m--) {
		cin >> l >> r;
		long long ans = 0;
		long long index = l;
		
		for(int i = 0; i < 26; i++) if(was[r][i] != was[l-1][i]) {
			if(was[index][i] == was[l-1][i] || (was[index][i] == index && was[index-1][i] == was[l-1][i])) {
				ans += was[r][i] - index;
				index = was[r][i];
			}
			else{
				ans += (r - index + 1) + was[index][i] - l;
				index = was[index][i];
			}
		}
	    cout << ans << endl;
	}	
}