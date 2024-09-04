#include<bits/stdc++.h>

using namespace std;
using INT = long long;

int ans[1010101];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	
	int p; scanf("%d", &p);
	for(int i = 0; i < p; i++) ans[i] = -1;
	for(int i = 0; i < p; i++) ans[((INT)i * i) % p] = i;
	
	for(int i = 0; i < p; i++) printf("%d ", ans[i]);
	return 0;
}