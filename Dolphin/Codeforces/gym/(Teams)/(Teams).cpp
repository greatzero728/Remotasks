#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

string s[3][3] = {
	{"Dmitry", "Egor", "Pavel"},
	{"Nikolay", "RomanA", "Vladimir"},
	{"Igor", "RomanB", "Vyacheslav"}
};
int num[3][3];

int update(string ss) {
	for(int i = 3; i--; ) {
		for(int j = 3; j--; ) if(s[i][j] == ss) {
			return num[i][j]++;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
//	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int k = 9 * n; k--; ) {
		string ss; cin>>ss;
		update(ss);
	}
	
	int ans = n;
	for(int i = 3; i--; ) {
		int sum = 0;
		for(int j = 3; j--; ) sum += num[i][j];
		ans = min(ans, sum);
	}
	cout<<ans<<endl;
	return 0;
}