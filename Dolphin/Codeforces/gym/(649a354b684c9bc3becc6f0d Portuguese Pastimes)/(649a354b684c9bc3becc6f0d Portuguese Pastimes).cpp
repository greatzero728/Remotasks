#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int fact[N], invfact[N],p[N];
bool visited[N];
int a[N], dp[N];
const int MOD = 1000000007;
int fastpow(int base, int exp) {
    int ans = 1;
    for (long long p = base; exp > 0; p = p*p % MOD, exp >>= 1)
        if (exp & 1)
            ans = ans*p % MOD;
    return ans;
}

int main()
{
    int N, k;
    scanf("%d %d", &N, &k);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (long long)i * fact[i-1] % MOD;
        invfact[i] = fastpow(fact[i], MOD-2);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < N; i++) {
        int len = 0, cur = i;
        while (!visited[cur]) {
            visited[cur] = true;
            cur = p[cur];
            len++;
        }
        a[len]++;
    }
    if (k == 0) {
        printf("%d\n", a[1] == N ? fact[N] : 0);
        return 0;
    }
    vector<int> divisores;
    for (int i = 1; i*i <= k; i++)
    if (k % i == 0) {
        divisores.push_back(i);
        if (i*i != k)
            divisores.push_back(k/i);
    }
    sort(divisores.begin(), divisores.end());
    int ans = 1;
    for (int x = 1; x <= N; x++) {
        dp[0] = 1;
        for (int m = 1; m <= a[x]; m++) {
            dp[m] = 0;
            for (int l : divisores) {
                if (l > m)
                    break;  
                if (__gcd(l*x, k) != l)
                    continue;
                long long val = (long long)fact[m-1] * invfact[m-l] % MOD;
                val = val * fastpow(x, l-1) % MOD;
                val = val * dp[m-l] % MOD;
                dp[m] += val;
                if (dp[m] >= MOD)
                    dp[m] -= MOD;
            }
        }
        ans = (long long)ans * dp[a[x]] % MOD;
    }
    cout<<ans<<endl;
    return 0;
}