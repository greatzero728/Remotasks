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
	puts("14.07.2023 16:32");
	int n = 100;
	printf("%d\n", n);
	while(n--) {
		printf("ACM ICPC contest World final %d\n", 2000 + n);
		int a = rnd % 20 + 2000; int b = rnd% 40 + 2000;
		if(a > b) swap(a, b);
		printf("14.06.%d 16:35\n", a);
		printf("14.06.%d 16:36\n", b);
	}
	return 0;
}
