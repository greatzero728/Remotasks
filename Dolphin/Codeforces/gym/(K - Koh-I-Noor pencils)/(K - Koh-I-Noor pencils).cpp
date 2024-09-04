#pragma comment(linker, "/STACK:268435456")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 2017;
const int sz = 50;

int Bpow(int x, int p) {
    int res = 1;
    while (p) {
        if (p % 2 == 1)
            res = (res * x) % mod;
        p >>= 1;
        x = (x * x) % mod;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
    freopen("kohinoor.in", "r", stdin);
    freopen("kohinoor.out", "w", stdout);
#endif
	
    vector<vector<int>> c(sz, vector<int>(sz));
    c[0][0] = 1;
    for (int i = 1; i < sz; i++) {
        c[i][0] = 1;
        for (int j = 1; j < sz; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    vector<int> fact(sz);
    vector<int> inv_fact(sz);
    fact[0] = 1;
    for (int i = 1; i < sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv_fact[sz - 1] = Bpow(fact[sz - 1], mod - 2);

    for (int i = sz - 1; i > 0; i--) {
        inv_fact[i - 1] = (inv_fact[i] * i) % mod;
    }

    int test_cnt;
    cin >> test_cnt;
    for (int test = 0; test < test_cnt; test++) {
        int n, k;
        cin >> n >> k;
        ll ans = 0;

        for (int i = 0; i <= k; i++) {
            if (i % 2) {
                ans -= (c[k][i] * Bpow(k - i, n)) % mod;
                ans %= mod;
            }
            else {
                ans += (c[k][i] * Bpow(k - i, n)) % mod;
                ans %= mod;
            }
        }

        ans = (ans * inv_fact[k]) % mod;
        if (ans < 0)
            ans += mod;
        cout << ans << '\n';
    }
    return 0;
}