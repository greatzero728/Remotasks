#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

vector<int> wh;
vector<int> p;
vector<int> res;
vector<int> is_unsure;;
int cmps;
int n;
map<PII, int> memo;
const int H = 3e5;;
int Ask(int a, int b) {
  if (memo.count({a, b})) { return memo[{a, b}]; }
  if (memo.count({b, a})) { return -memo[{b, a}]; }
  cmps++;
  cout<<"C "<<a<<" "<<b<<endl;
  int r;
  cin>>r;
  return memo[{a, b}] = r;
}
set<int> unsure;
int dep;
void Go(int L, int R, vector<int> poses) {
  dep++;
  if (L > R) {
    dep--;
    return;
  }
  
  for (auto u : unsure) {
    int typomi = (u - 1) * 100 / 99 + 1;
    int typoma = u * 100 / 99;
    if (R - L <= 7 && typomi <= R && typoma >= L) {
      int should_be_u = 0;
      FOR (i, L, R) {
        if (100 * (i - u) <= i) {
        } else {
          should_be_u++;
        }
      }
      int here = 0;
      for (auto x : poses) {
        here += Ask(x, wh[u]);
      }
      if (here != should_be_u) {
        swap(wh[u - 1], wh[u]);
        swap(res[wh[u - 1]], res[wh[u]]);
      }
      is_unsure[u] = 0;
      is_unsure[u - 1] = 0;
      unsure.erase(u);
      break;
    }
  }
  if (L == R) {
    wh[L] = poses[0];
    res[poses[0]] = L;
    dep--;
    return;
  }
  if (L + 1 == R && R % 100 == 0) {
    wh[L] = poses[0];
    wh[R] = poses[1];
    res[wh[L]] = L;
    res[wh[R]] = R;
    is_unsure[L] = 1;
    is_unsure[R] = 1;
    unsure.insert(R);
    dep--;
    return;
  }
  int pivot = -1;
  if ((LD)R / L < 1.03) {
    int ktos = (R + L) / 2 * 0.99;
    mini(ktos, L - 1);
    function<int(int)> Quality = [&](int a) {
      int typo = 100 * a / 99;
      if (typo < L || typo >= R) { return (int)1e18; }
      return 2 * abs((typo - L + 1) - (R - typo)) + 100 * is_unsure[a];
    };
    while (Quality(ktos + 1) < Quality(ktos) && ktos + 1 < L) {
      ktos++;
    }
    while (ktos - 1 >= 1 && Quality(ktos - 1) < Quality(ktos)) {
      ktos--;
    }
    if (ktos - 2 >= 1 && Quality(ktos - 2) < Quality(ktos)) {
      ktos -= 2;
    }
    if (Quality(ktos) < 1e17) {
      pivot = wh[ktos];
    }
  }
  if (pivot == -1) {
    while (1) {
      pivot = poses[rand() % SZ(poses)];
      if (R - L > 1000) { break; }
      int mi = 1;
      int ma = -1;
      REP (tr, 5) {
        int a = Ask(poses[rand() % SZ(poses)], pivot);
        mini(mi, a);
        maxi(ma, a);
      }
      if (mi != ma) {
        break;
      }
    }
  }
    
  vector<int> left, mid, right;
  for (int i = 0; i < SZ(poses); i++) {
    if (poses[i] == pivot) {
      mid.PB(pivot);
      continue;
    }
    int a = Ask(poses[i], pivot);
    if (a == -1) {
      left.PB(poses[i]);
    } else if (a == 0) {
      mid.PB(poses[i]);
    } else {
      right.PB(poses[i]);
    }
  }
  Go(L, L + SZ(left) - 1, left);
  Go(L + SZ(left), L + SZ(left) + SZ(mid) - 1, mid);
  Go(L + SZ(left) + SZ(mid), R, right);
  dep--;
}
int ok;
int Swap(int a, int b) {
	cmps++;
	
	cout<<"S "<<a<<" "<<b<<endl;
	int x;
	cin>>x;
	if(x) exit(0);
	return 0;
}

int32_t main() {

	ios_base::sync_with_stdio(0);
	
	cin>>n;
	int cl = 1;
	debug(cl);
	srand(cl);
	
	Swap(1, 1);
	is_unsure.resize(n + 2);
	res.resize(n + 1);
	wh.resize(n + 2);
	VI poses;
	RE (i, n) {
		poses.PB(i);
	}
	Go(1, n, poses);
	debug(cmps);
	RE (i, n) {
		if (wh[i] != i) {
			Swap(i, wh[i]);
			int r = res[i];
			swap(res[i], res[wh[i]]);
			swap(wh[r], wh[i]);
		}
	}
	debug(ok);
	debug(unsure);
	assert(SZ(unsure) >= 1);
	int A = *unsure.begin();
	Swap(A, A - 1);
	assert(SZ(unsure) >= 2);
	int B = *next(unsure.begin());
	Swap(B, B - 1);
	Swap(A, A - 1);
	return 0;
}