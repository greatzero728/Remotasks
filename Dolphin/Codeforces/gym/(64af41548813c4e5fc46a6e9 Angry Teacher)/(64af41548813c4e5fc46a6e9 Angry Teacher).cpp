#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

struct Int {
	static const int len = 255, all = 1e8; // max_len = 8 * len
	int a[len], n, t;
	void c() {
		while(n && !a[n - 1]) n--;
		if(!n) t = 1;
	}
	void resize(int N) {n = N; while(N--) a[N] = 0;}
	Int(INT x) {
		n = 0, t = 1; if(x < 0) x = -x, t = -1;
		while(x) a[n++] = x % all, x /= all;
		c();
	}
	Int() : t(1) {n = 0;}
	Int(string s) {
		n = 0, t = 1;
		int L = 0, x = 0, b = 1, i = s.size();
		if(!s.empty() && s[0] == 45) L = 1, t = -1;
		while(i-- > L) {
			x += (s[i] - 48) * b, b *= 10;
			if(b >= all) a[n++] = x, x = 0, b = 1;
		}
		if(x) a[n++] = x;
		else c();
	}
	void pt() const {
		if(!n) {puts("0"); return;}
		if(!~t) putchar(45);
		printf("%d", a[n - 1]);
		for(int i = n - 1; i--; ) printf("%.8d", a[i]);
		putchar(10);
	}
	int solve(int n) const {
		int ans = 0;
		while(n) ans += (n % 10) * (n % 10), n /= 10;
		return ans;
	}
	int calc() const {
		if(!n) return 0;
		int ans = solve(a[n - 1]);
		for(int i = n - 1; i--; ) ans += solve(a[i]);
		return ans;
	}
	int cp(const Int &b) const {
		if(t ^ b.t) return t - b.t;
		if(!~t) return -(-*this).cp(-b);
		if(n ^ b.n) return n - b.n;
		for(int i = n; i--; ) if(a[i] ^ b.a[i]) {
			return a[i] - b.a[i];
		}
		return 0;
	}
	bool operator < (const Int &b) const {return cp(b) < 0;}
	bool operator > (const Int &b) const {return cp(b) > 0;}
	bool operator <= (const Int &b) const {return cp(b) <= 0;}
	bool operator >= (const Int &b) const {return cp(b) >= 0;}
	bool operator == (const Int &b) const {return !cp(b);}
	bool operator != (const Int &b) const {return cp(b);}
	Int operator - () const {
		Int r = *this; if(r.n) r.t = -r.t;
		return r;
	}
	Int operator + (const Int &b) const {
		if(!~t) return -(-*this + -b);
		if(!~b.t) return *this - -b;
		int N = max(n, b.n); Int r; r.resize(N + 1);
		for(int i = 0; i < N; i++) {
			if(i < n) r.a[i] += a[i];
			if(i < b.n) r.a[i] += b.a[i];
			if(r.a[i] >= all) r.a[i] -= all, r.a[i + 1]++;
		}
		return r.c(), r;
	}
	Int operator - (const Int &b) const {
		if(!~t) return -(-*this - -b);
		if(!~b.t) return *this + -b;
		if(*this < b) return -(b - *this);
		Int r; r.resize(n);
		for(int i = 0; i < n; i++) {
			r.a[i] += a[i];
			if(i < b.n) r.a[i] -= b.a[i];
			if(r.a[i] < 0) r.a[i] += all, r.a[i + 1]--;
		}
		return r.c(), r;
	}
	Int operator * (const Int &b) {
		Int r; INT c, up = 0; r.resize(n + b.n + 1);
		for(int i = 0, j; i < r.n; i++) {
			c = up, up = 0, j = max(0, i - b.n + 1);
			for(; j < n && j <= i; j++) {
				c += (INT)a[j] * b.a[i - j];
				if(c > 9999999999999999) up += c / all, c %= all;
			}
			up += c / all, r.a[i] = c %= all;
		}
		return r.t = t * b.t, r.c(), r;
	}
	Int operator / (const Int &b) {
		if(n < b.n) return 0;
		Int r, x = b; r.resize(n - b.n + 1);
		int f = t, i = r.n, d, m, u;
		for(t = x.t = 1; i--; ) {
			for(d = 0, u = all - 1; d < u; ) {
				m = r.a[i] = d + u + 1 >> 1;
				if(r * x > *this) u = m - 1;
				else d = m;
			}
			r.a[i] = d;
		}
		return t = f, r.t = t * b.t, r.c(), r;
	}
	Int operator % (const Int &b) {
		return *this - *this / b * b;
	}
};

char s[1010];

Int a[12], mod = 1;
int n;

Int calc(Int x) {
	Int ans = 0, mul = 1;
	for(int i = 0; i <= n; i++) {
		ans = (ans + a[i] * mul) % mod;
		mul = mul * x;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
#endif
	
	int k, m; scanf("%d %s %d %d", &n, s, &k, &m);
	Int l = Int(s);
	while(m--) mod = mod * 10;
	
	for(int i = n; i >= 0; i--) {
		scanf("%s", s), a[i] = Int(s);
	}
	
	for(Int x = l, ed = l + k; x < ed; x = x + 1) {
		printf("%d\n", calc(x % mod).calc());
	}
	return 0;
}