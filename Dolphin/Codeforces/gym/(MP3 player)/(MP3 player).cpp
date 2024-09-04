#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int ans, n, dp[N], mod;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
    freopen("mp3.in", "r", stdin);
    freopen("mp3.out", "w", stdout);
#endif
	
    ios_base::sync_with_stdio(0);
    cin >> n >> mod;
    n--;
    dp[0] = dp[1] = 1 % mod;
    for (int i = 2;i <= n;i++) dp[i] = ((1ll * dp[i - 1] * i) % mod + (1ll * (i - 1) * dp[i - 2]) % mod) % mod;
    cout << dp[n];
    return 0;
}