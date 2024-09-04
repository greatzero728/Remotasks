#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> lint;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define y1 trololoy
const int base = 1e8;
const int T = 600;
int cmp(lint a, lint b) {
	if (a.size() > b.size()) return 1;
	if (a.size() < b.size()) return -1;
	for(int i = (int)a.size() - 1; i >= 0; i--)
	if (a[i] > b[i]) return 1;
	else if (a[i] < b[i]) return -1;
	return 0;
}

lint convert(int x) {
	lint res;
	res.pb(x);
	return res;
}

lint read() {
	string s;
	cin >> s;
	while (s.size() % 8) s = "0" + s;
	int len = s.size() / 8;
	lint a;
	for (int i = 0; i < len; ++i) {
		int res = 0;
		for (int j = 8 * i; j < 8 * (i + 1); ++j)
		res = res * 10 + s[j] - '0';
		a.pb(res);
	}
	reverse(a.begin(), a.end());
	return a;
}

void write(lint a) {
	if (!a.size()) cout << 0;
	else {
		cout << a.back();
		for(int i = (int)a.size() - 2; i >= 0; i--) printf("%08d", a[i]);
	}
	cout << endl;
}

lint mul(lint a, lint b) {
	lint c(a.size() + b.size());
	for(int i = 0; i < (int)a.size(); i++)
	for(int j = 0, carry = 0; j < (int)b.size() || carry; j++) {
		ll cur = c[i + j] + 1ll * a[i] * (j < (int)b.size() ? b[j] : 0) + carry;
		c[i + j] = cur % base;
		carry = cur / base;
	}
	while(c.size() > 1 && c.back() == 0)
	c.pop_back();
	return c;
}

lint sub(lint a, lint b) {
	for(int i = 0, carry = 0; i < (int)b.size() || carry; i++) {
		a[i] -= (i < (int)b.size() ? b[i] : 0) + carry;
		carry = (a[i] < 0);
		if (carry) a[i] += base;
	}
	while(a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

lint sum(lint a, lint b) {
	for(int i = 0, carry = 0; i < (int)max(a.size(), b.size()) || carry; i++) {
		if ((int)a.size() == i) a.pb(0);
		a[i] += (i < (int)b.size() ? b[i] : 0) + carry;
		carry = (a[i] >= base);
		if (carry) a[i] -= base;
	}
	return a;
}

lint div(lint a, ll b) {
	for(int i = (int)a.size() - 1, carry = 0; i >= 0; i--) {
		ll cur = a[i] + 1LL * base * carry;
		a[i] = cur / b;
		carry = cur % b;
	}
	while(a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

lint z;
int C(lint n, int k) {
	lint res = convert(1);
	for (int i = 1; i <= k; ++i) {
		res = div(mul(res, sub(n, convert(k - i))), i);
		if (cmp(res, z) == 1) return 1;
	}
	return cmp(res, z);
}

lint copy(lint a) {
	lint b;
	for (int i = 0; i < a.size(); ++i) b.pb(a[i]);
	return b;
}

int main(){
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#else
	freopen("discuss.in", "r", stdin);
	freopen("discuss.out", "w", stdout);
#endif
	z = read();
	if (convert(1) == z) {
		cout << 1;
		return 0;
	}
	
	lint limit = z;
	lint res = z;
	for (int k = 2; k <= T; k += 2) {
		lint l = convert(k), r = limit, m;
		if (C(l, k / 2) == 1) break;
		while (cmp(l, r) == -1) {
			m = div(sum(l, r), 2);
			if (C(m, k / 2) == -1) l = sum(m, convert(1));
			else r = m;
		}
		if (C(l, k / 2) == 0  && cmp(l, res) == -1) res = l;
		limit = l;
	}
	write(res);
	return 0;
}