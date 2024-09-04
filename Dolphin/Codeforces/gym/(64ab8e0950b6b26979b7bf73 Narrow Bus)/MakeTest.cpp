#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("in.txt", "w", stdout);
	
	srand(time(0));
	int n = 100000;
	printf("%d\n", n);
	for(int i = 1; i <= 80000; i++) {
		if(rnd & 1) puts("F");
		else puts("B");
	}
	for(int i = 1; i <= 20000; i++) {
		printf("O %d\n", i * 2);
	}
	return 0;
}
