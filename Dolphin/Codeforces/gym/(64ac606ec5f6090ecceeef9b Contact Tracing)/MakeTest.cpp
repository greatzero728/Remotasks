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
	puts("1000");
	for(int i = 100; i--; ) {
		puts("Alice OTHER");
		puts("Bob Alice");
		puts("Cheryl Alice");
		puts("Darryl Bob");
		puts("Ernie Alice");
		puts("Frank Darryl");
		puts("Greta Darryl");
		puts("Hank Cheryl");
		puts("Irene Bob");
		puts("John Darryl");
	}
	return 0;
}
