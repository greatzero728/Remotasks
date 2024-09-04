#include<bits/stdc++.h>

using namespace std;

string s, t;
char u[19990728];

int main() {
	for(int i = 77; i--; ) {
		system("run.bat");
		s.clear(), t.clear();
		freopen("out.out", "r", stdin);
		while(gets(u)) s += u;
		freopen("test.out", "r", stdin);
		while(gets(u)) t += u;
		while(s != t) puts("\a\n\nWrong Answer"), exit(0);
	}
	puts("\a\n\nAccepted");
	return 0;
}
