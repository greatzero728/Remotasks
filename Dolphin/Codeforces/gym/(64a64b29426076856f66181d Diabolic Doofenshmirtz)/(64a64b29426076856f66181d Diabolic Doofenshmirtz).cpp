#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	
	INT t = 1;
	for(; ; t <<= 1) {
		printf("? %I64d\n", t), fflush(stdout);
		INT x; scanf("%I64d", &x);
		if(t ^ x) {
			printf("! %I64d\n", t - x);
			return 0;
		}
	}
	return 0;
}
