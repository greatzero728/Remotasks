#include<bits/stdc++.h>

using namespace std;

const int CC = 26, NN = 101010;

struct competitive_coder {
	string name;
	int number, penalty, last;
	int cnt[CC], time[CC];
	bool accepted[CC];
	void insert(int t, char p, char r) {
		int k = p - 'A';
		if(accepted[k]) return;
		
		cnt[k]++, time[k] = t;
		if(r == '+') {
			number++;
			penalty += t + 20 * (cnt[k] - 1);
			last = t;
			accepted[k] = 1;
		}
		return;
	}
} a[NN];

bool operator < (competitive_coder a, competitive_coder b) {
	if(a.number != b.number) return a.number > b.number;
	if(!a.number) return a.name < b.name;
	if(a.penalty != b.penalty) return a.penalty < b.penalty;
	if(a.last != b.last) return a.last < b.last;
	return a.name < b.name;
}
bool operator == (competitive_coder a, competitive_coder b) {
	return a.number == b.number && a.penalty == b.penalty && a.last == b.last;
}

map<string, int> mp;
int nn, n;

int get(string s) {
	if(mp.find(s) == mp.end()) {
		mp[s] = ++nn;
		a[nn].name = s;
		a[nn].number = a[nn].penalty = a[nn].last = 0;
		for(int i = n; i--; ) a[nn].cnt[i] = a[nn].accepted[i] = a[nn].time[i] = 0;
		return nn;
	}
	return mp[s];
}

int len[CC + 4];

int calc_number_of_digit(int t) {
	if(!t) return 1;
	int ans = 0;
	while(t) t /= 10, ans++;
	return ans;
}

int calc_width(bool accepted, int cnt, int time) {
	int ans = 3;
	int h = time / 60;
	if(h <= 99) ans += 2;
	else if(h <= 999) ans += 3;
	else ans += 4;
	
	if(accepted) ans = max(ans, calc_number_of_digit(cnt - 1) + 1);
	else ans = max(ans, calc_number_of_digit(cnt) + 1);
	return ans;
}

char s[NN];

void update(char *s, int L, int R, string vec) {
	int st = R - L + 1 - vec.size(); st /= 2;
	for(int i = vec.size(); i--; ) s[L + st + i] = vec[i];
	return;
}
void update_left(char *s, int L, int R, string vec) {
	for(int i = vec.size(); i--; ) s[L + 2 + i] = vec[i];
	return;
}
void update_right(char *s, int L, int R, string vec) {
	for(int i = vec.size(); i--; ) s[R - vec.size() - 1 + i] = vec[i];
	return;
}

string tmp;

string int_string(int id) {
	if(!id) return "0";
	string ans;
	while(id) ans += '0' + id % 10, id /= 10;
	reverse(ans.begin(), ans.end());
	return ans;
}

string calc_num(bool accepted, int num) {
	if(accepted) {
		if(num == 1) return "+";
		return "+" + int_string(num - 1);
	}
	if(num) return "-" + int_string(num);
	return "";
}

string calc_time(int t) {
	string ans;
	int x = t / 60;
	if(x <= 9) ans += "0";
	ans += int_string(x) + ":";
	
	x = t % 60;
	if(x <= 9) ans += "0";
	
	return ans + int_string(x);
}

int M;
void init(char c) {
	for(int i = M; i--; ) s[i] = c;
	int ed = 0; s[ed] = '#';
	ed += len[n] + 3, s[ed] = '#';
	ed += len[n + 1] + 3, s[ed] = '#';
	for(int j = 0; j < n; j++) ed += len[j] + 3, s[ed] = '#';
	ed += len[n + 2] + 3, s[ed] = '#';
	ed += len[n + 3] + 3, s[ed] = '#';
	return;
}

void print() {
	for(int i = 0; i < M; i++) putchar(s[i]); puts("");
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int m; scanf("%d %d", &n, &m);
	while(m--) {
		int t; string s; char p, r;
		cin>>t>>s>>p>>r;
		a[get(s)].insert(t, p, r);
	}
	sort(a + 1, a + nn + 1);
	
	for(int i = n + 4; i--; ) len[i] = 1;
	len[n + 1] = 10;
	
	for(int i = 1, j = 1; i <= nn; i = j) {
		for(; j <= nn && a[i] == a[j]; j++);
		if(a[i].number) len[n] = calc_number_of_digit(i);
	}
	for(int i = 1; i <= nn; i++) {
		len[n + 1] = max(len[n + 1], (int)a[i].name.size());
		for(int j = n; j--; ) if(a[i].cnt[j]) {
			len[j] = max(len[j], calc_width(a[i].accepted[j], a[i].cnt[j], a[i].time[j]));
		}
		if(a[i].number > 9) len[n + 2] = 2;
		len[n + 3] = max(len[n + 3], calc_number_of_digit(a[i].penalty));
	}
	
	M = 1;
	for(int i = n + 4; i--; ) M += len[i] + 3;
	
	init('#'), print(), init(' ');
	int ed = len[n] + 3; update(s, ed - len[n] - 3, ed, "R");
	ed += len[n + 1] + 3, update(s, ed - len[n + 1] - 3, ed, "Contestant");
	for(int i = 0; i < n; i++) {
		tmp = "A", tmp.back() += i;
		ed += len[i] + 3, update(s, ed - len[i] - 3, ed, tmp);
	}
	ed += len[n + 2] + 3, update(s, ed - len[n + 2] - 3, ed, "+");
	ed += len[n + 3] + 3, update(s, ed - len[n + 3] - 3, ed, "T");
	print();
	
	for(int i = 1, j = 1, row_id = 3; i <= nn; i = j) {
		for(; j <= nn && a[i] == a[j]; j++, row_id += 3) {
			init('#'), print(), init(' ');
			
			tmp = int_string(i);
			if(!a[j].number) tmp = "";
			
			ed = len[n] + 3, update_right(s, ed - len[n] - 3, ed, tmp);
			ed += len[n + 1] + 3, update_left(s, ed - len[n + 1] - 3, ed, a[j].name);
			
			for(int k = 0; k < n; k++) {
				tmp = calc_num(a[j].accepted[k], a[j].cnt[k]);
				ed += len[k] + 3;
				if(a[j].cnt[k]) update(s, ed - len[k] - 3, ed, tmp);
			}
			ed += len[n + 2] + 3, update_right(s, ed - len[n + 2] - 3, ed, int_string(a[j].number));
			ed += len[n + 3] + 3, update_right(s, ed - len[n + 3] - 3, ed, int_string(a[j].penalty));
			print();
			
			init(' ');
			ed = len[n] + 3;
			ed += len[n + 1] + 3;
			
			for(int k = 0; k < n; k++) {
				tmp = calc_time(a[j].time[k]);
				ed += len[k] + 3;
				if(a[j].cnt[k]) update(s, ed - len[k] - 3, ed, tmp);
			}
			print();
		}
	}
	init('#'), print();
	return 0;
}