#include<bits/stdc++.h>
#define pii pair<ll, ll>
#define ll long long	
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz size
using namespace std;
ll n;
const ll maxn = 300100;
pii p[maxn];
pii o[maxn];
pii sm = mp((ll)(1e9) + 7, (ll)(1e9) + 7);
ll pos;
stack<pii> q;
ll orient(pii p, pii q, pii r) {
	pii vec1 = mp(r.f - q.f, r.s - q.s);
	pii vec2 = mp(q.f - p.f, q.s - p.s);
	ll ss = vec1.f*vec2.s-vec1.s*vec2.f;
	if (ss < 0) { //counter
		return 0;
	} else if (ss > 0) {
		return 1;
	} else {
		return 2;
	}
}
bool cmd(pii p1, pii p2) {
	if (!orient(sm, p1, p2) || (orient(sm, p1, p2) == 2 && sqrt(((p1.f-sm.f)*(p1.f - sm.f)) + ((p1.s-sm.s)*(p1.s-sm.s))) >= sqrt(((p2.f-sm.f)*(p2.f-sm.f)) + ((p2.s-sm.s)*(p2.s-sm.s))))) {
		return true;		                       
	} else {
		return false;
	}
}
pii be() {
	pii ls = q.top();
	q.pop();
	pii lx = q.top();
	q.push(ls);
	return lx;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("convex.in", "r", stdin);
	freopen("convex.out", "w", stdout);
#endif
	
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> p[i].f >> p[i].s;
		if (p[i].f < sm.f || (p[i].f == sm.f && p[i].s < sm.s)) {
			sm = p[i];
			pos = i;
		}
	}               
	swap(p[0], p[pos]);
	sort(p + 1, p + n, cmd);
	q.push(p[0]);               
	q.push(p[1]);
	for (ll i = 2; i < n; i++) {
		while (orient(be(), q.top(), p[i]) == 1) {
			q.pop();
		}
		q.push(p[i]);
	}
	ll tr = 0;
	while (!q.empty()) {
		o[tr++] = q.top();
		q.pop();	
	}
	ll s = 0, k = 0;
	o[tr] = o[0];
	for(ll i = 0; i < tr; ++i){
		s += o[i].f * o[i + 1].s - o[i + 1].f * o[i].s;
		k += __gcd(abs(o[i].f - o[i + 1].f), abs(o[i].s - o[i + 1].s));
	}
	ll ans = (abs(s) - k + 2) / 2;
	cout << ans;
	return 0;
}