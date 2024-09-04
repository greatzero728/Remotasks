#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MOD = 1e9+7;
const int N = 1e6;

int fact[N+1], rfct[N+1];
vector<vi> possible_path;

int rev(int a, int m = MOD) {
    return a == 1 ? 1 : m - (ll)m*rev(m%a, a)/a;
}

array<int, 9> get_pair_count(const string& s) {
    array<int, 9> res;
    fill(res.begin(), res.end(), 0);

    for (int i = 0; i + 1 < (int)s.size(); ++i) {
        res[3*(s[i] - 'a') + s[i+1] - 'a']++;
    }

    return res;
}

bool check(const array<int, 9> m) {
    vector<int> deg(3);

    for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
        deg[i] += m[3*i+j];
        deg[j] -= m[3*i+j];
    }

    if (deg[0] + deg[1] + deg[2] != 0) return false;

    if (abs(deg[0]) > 1) return false;
    if (abs(deg[1]) > 1) return false;
    if (abs(deg[2]) > 1) return false;

    if (deg[0]) return deg[1] == 0 || deg[2] == 0;
    if (deg[1]) return deg[0] == 0 || deg[2] == 0;
    if (deg[2]) return deg[0] == 0 || deg[1] == 0;
    return true;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (ll)fact[n]*rfct[k]%MOD*rfct[n-k]%MOD;
}

int multi(int a, int b, int c, int d) {
    return (ll)fact[a+b+c+d]*rfct[a]%MOD*rfct[b]%MOD*rfct[c]%MOD*rfct[d]%MOD;
}

int mpow(int a, int n) {
    int res = 1;

    for (; n != 0; n >>= 1, a = (ll)a*a%MOD) {
        if (n&1) res = (ll)res*a%MOD;
    }

    return res;
}

int get_count(array<int, 9> m) {
    vector<int> deg0(3);

    for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
        deg0[i] += m[3*i+j];
        deg0[j] -= m[3*i+j];
    }

    int ans = 0;

    for (auto path : possible_path) {
        vector<int> cnt(3);
        auto deg = deg0;
        deg[path.front()]--;
        deg[path.back()]++;
        if (deg[0] || deg[1] || deg[2]) continue;

        cnt[path.front()] = 1;
        for (int i = 0; i < 9; ++i) cnt[i%3] += m[i];

        bool ok = true;
        for (int i = 0; i + 1 < (int)path.size(); ++i) {
            if (m[3*path[i] + path[i+1]] == 0) ok = false;
        }
        if (!ok) continue;

        int mul = 1;
        for (int i = 0; i < 3; ++i) {
            if (m[4*i] == 0) continue;
            mul = (ll)mul*C(cnt[i]-1, m[4*i])%MOD;
        }
        if (mul == 0) continue;

        for (int i = 0; i + 1 < (int)path.size(); ++i) {
            m[3*path[i] + path[i+1]]--;
        }

        const int a = path.front();
        const int b = a == 0 ? 1 : 0;
        const int c = 3 ^ a ^ b;

        const int AB = min(m[3*a+b], m[3*b+a]);
        const int AC = min(m[3*a+c], m[3*c+a]);
        const int BC = min(m[3*b+c], m[3*c+b]);

        const int CF = min({m[3*a+b]-AB, m[3*b+c]-BC, m[3*c+a]-AC});
        const int CR = min({m[3*b+a]-AB, m[3*c+b]-BC, m[3*a+c]-AC});

        assert(CF == 0 || CR == 0);
        const int Q = min({AB,AC,BC});
        const int P = CF + CR;
        const int w = path.size() == 1 ? 0 : 1;

        int cur = 0;

        const int S = w+P+AB+AC;
        for (int K = 0; K <= Q; ++K) {
            const int M = multi(K, P+K, AB-K, AC-K);

            if (BC == K) {
                cur += M;
                if (cur >= MOD) cur -= MOD;
            } else {
                cur = (cur + (ll)M*C(S+BC-K-1, BC-K)) % MOD;
            }
        }

        ans = (ans + (ll)cur*mul)%MOD;

        for (int i = 0; i + 1 < (int)path.size(); ++i) {
            m[3*path[i] + path[i+1]]++;
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	
    ios::sync_with_stdio(0); cin.tie(0);
    
    int g; cin >> g;

    fact[0] = 1;
    for (int i = 1; i <= N; ++i) fact[i] = (ll)fact[i-1]*i%MOD;
    rfct[N] = rev(fact[N]);
    for (int i = N; i >= 1; --i) rfct[i-1] = (ll)rfct[i]*i%MOD;

    for (int a = 0; a < 3; ++a) {
        possible_path.push_back(vi { a });
        for (int b = 0; b < 3; ++b) {
            if (a == b) continue;
            possible_path.push_back(vi { a, b });
            for (int c = 0; c < 3; ++c) {
                if (a != c && b != c) possible_path.push_back(vi { a, b, c});
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        auto m = get_pair_count(s);
        int res = get_count(m);
        cout << res << '\n';
    }
}