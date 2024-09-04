#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 101010;

char s[NN], t[NN];

INT getId(int y, int m, int d) {
	return 1461 * (y + 4800 + (m - 14) / 12) / 4 +
			367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
			3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 + d - 32075;
}

INT input_time() {
	gets(t);
	
	int y, m, d, hh, mm;
	for(int i = 0, j = 0, nn = 0; t[i]; i = j) {
		int s = 0;
		for(; t[j] && isdigit(t[i]) == isdigit(t[j]); j++) {
			s = s * 10 + t[j] - '0';
		}
		if(!isdigit(t[i])) continue;
		if(++nn == 1) d = s;
		else if(nn == 2) m = s;
		else if(nn == 3) y = s;
		else if(nn == 4) hh = s;
		else mm = s;
	}
	return (getId(y, m, d) * 24 + hh) * 60 + mm;
}

string check_state() {
	int num = 0;
	for(int i = 0, j = 0; s[i]; i = j) {
		bool all_up = 1;
		for(; s[j] && (s[i] == ' ') == (s[j] == ' '); j++) {
			if('a' <= s[j] && s[j] <= 'z') all_up = 0;
		}
		if(s[i] ^ ' ') {
			if(all_up) {
				for(int k = i; k < j; k++) if(s[k] == 'C') num++;
			}
			else if(s[i] == 'c' || s[i] == 'C') num++;
		}
	}
	if(num == 0) return "boring";
	if(num == 1) return "interesting";
	return "must coding!";
}

using pss = pair<string, string>;
using piss = pair<INT, pss>;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	INT t = input_time();
	int n; scanf("%d ", &n);
	
	vector<piss> ans;
	while(n--) {
		gets(s);
		INT st = input_time(), ed = input_time();
		if(t >= ed) continue;
		
		piss p; p.x = st;
		if(st <= t) p.y.y = "Running ";
		else p.y.y = "Coming soon ";
		p.y.x = s;
		p.y.y += p.y.x + " (" + check_state() + ")";
		ans.push_back(p);
	}
	sort(ans.begin(), ans.end());
	for(piss p : ans) printf("%s\n", p.y.y.c_str());
	return 0;
}
