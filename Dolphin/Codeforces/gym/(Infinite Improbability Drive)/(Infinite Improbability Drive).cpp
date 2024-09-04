#include <iostream>

const int N = (1 << 22) + 100;


char a[N];
int bb[N];
int sz = 0;
int n;
int k = 2;
void dfs(int t, int p) {
    if (t > n) {
        if (n % p == 0) {
            for (int i = 1; i < p + 1; ++i) {
                a[sz++] = bb[i];
            }
        }
    } else {
        bb[t] = bb[t - p];
        dfs(t + 1, p);
        for (int i = bb[t - p] + 1; i < k; ++i) {
            bb[t] = i;
            dfs(t + 1, t);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
    freopen("infinite.in", "r", stdin);
    freopen("infinite.out", "w", stdout);
#endif
	
    scanf("%d", &n);
    dfs(1, 1);  
    int needed_len = (1 << n) + n - 1;
    needed_len -= sz;
    for (int i = 0; i < sz; ++i) {
        printf("%d", a[i]);
    }
    for (int j = 0; j < needed_len; ++j) {
        printf("%d", a[j]);
    }
}