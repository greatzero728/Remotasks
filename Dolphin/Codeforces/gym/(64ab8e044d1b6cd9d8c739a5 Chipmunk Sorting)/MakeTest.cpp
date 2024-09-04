#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int f[202020];

int main() {
	freopen("in.txt", "w", stdout);
	
	srand(time(0));
	
	int n = 200000;
	printf("%d 1\n", n);
	for(int i = 1; i <= n; i++) f[i] = i;
	
	random_shuffle(f + 1, f + n + 1);
	
	for(int i = 1; i <= n; i++) printf("%d ", f[i]);
	return 0;
}
