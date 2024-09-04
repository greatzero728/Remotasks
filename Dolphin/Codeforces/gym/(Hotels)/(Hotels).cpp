#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define scn second
#define frs first

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;

void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
struct abc {
    ll k, b;
    abc() {k = b = 0;}
    abc(ll K, ll B) {
        k = K, b = B;
    }
};
const ll INF = 1000000000000000000ll;

abc line[100010];

struct tree {
    int l, r, last;
    vector<pair<ll, int> > x;
}t[1000000];

inline ll intersect(abc a, abc b) {   
    ll k1 = a.k, k2 = b.k, b1 = a.b, b2 = b.b;                     
    if (k1 == k2) 
        return -INF;    
    return floor((b2 - b1) * 1.0 /((k1 - k2)));           
}

bool cmp(abc a, abc b) {
	return a.k < b.k || (a.k == b.k && a.b < b.b);
}


void build(int v, int l, int r) {
	t[v].l = l, t[v].r = r;
	if (t[v].r - t[v].l == 1) {
		t[v].x.pb(mp(INF, l));
		return;
	}
	int m = (r + l) / 2;
	build(2 * v, l, m);
	build(2 * v + 1, m, r);
	vector<pair<ll, int> > ans;
	vector<int> a, b;
	for (int i = 0; i < t[2 * v].x.size(); ++i)
		a.pb(t[2 * v].x[i].scn);
	for (int i = 0; i < t[2 * v + 1].x.size(); ++i)
		b.pb(t[2 * v + 1].x[i].scn);
	int ya = 0, yb = 0;
	if (cmp(line[a[ya]], line[b[yb]]))
		ans.pb(mp(INF, a[ya++]));
	else
		ans.pb(mp(INF, b[yb++]));	
	for (; ya < a.size() || yb < b.size();) {
		int now = 0;
		if (ya < a.size() && yb < b.size()) {
			if (cmp(line[a[ya]], line[b[yb]]))
				now = a[ya++];
			else
				now = b[yb++];
		}
		else {
			if (ya == a.size())
				now = b[yb++];
			else
				now = a[ya++];		
		}
		while (ans.size() > 0 && intersect(line[ans.back().scn], line[now]) >= ans.back().frs)
			ans.pop_back();
		ans.pb(mp(intersect(line[ans.back().scn], line[now]), now));
	}
	t[v].x = ans;
}


ll get(int v, int l, int r, ll x) {
	if (t[v].l >= r || t[v].r <= l)
		return INF;
	if (t[v].l >= l && t[v].r <= r) {
		int bl = 0, br = t[v].x.size();
		while (br - bl > 1) {
			int bm = (br + bl) / 2;
			if (t[v].x[bm].frs >= x)
				bl = bm;
			else
				br = bm;		
		}
		return line[t[v].x[bl].scn].k * x + line[t[v].x[bl].scn].b;
	}
	return min(get(2 * v, l, r, x), get(2 * v + 1, l, r, x));
}

int n, l, r, k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d%I64d", &line[i].b, &line[i].k);
	int t1;	
	build(1, 0, n);
	scanf("%d", &t1);
	while (t1 --> 0) {
	    scanf("%d%d%d", &l, &r, &k);
	    k--, l--;
	    printf("%I64d\n", get(1, l, r, k));		
	}
	return 0;
}