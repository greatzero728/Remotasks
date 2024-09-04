#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace std;

#define TASKNAME "chameleon"

typedef long long ll;
typedef long double ld;

const int MAXN = 1100;

const int    dx[4] = {  1,  0, -1,  0};
const int    dy[4] = {  0,  1,  0, -1};
const char name[4] = {'d','r','u','l'};
const int MAXANS = 5000000;

int n,cur[MAXN][MAXN],need[MAXN][MAXN],curx,cury, basex,basey,ansptr,rev;
char ans[MAXANS+100];

void print(){
    fprintf(stderr,"\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			fprintf(stderr,"%d",cur[i][j]);
		fprintf(stderr,"           ");
		for (int j = 0; j < n; j++)
			fprintf(stderr,"%d",need[i][j]);
	    fprintf(stderr,"\n");
	}
    fprintf(stderr,"\n");
}

void go(int tox,int toy,bool recolor){
	if (tox < 0 || toy < 0 || tox >= n || toy >= n){
		fprintf(stderr,"Can't go to (%d %d)\n",tox,toy);
		assert(false);
	}
	for (int i = 0; i < 4; i++)
		if (curx + dx[i] == tox && cury + dy[i] == toy){
			if (recolor) cur[tox][toy] = cur[curx][cury];
			curx = tox;
			cury = toy;
			if (recolor) ans[ansptr++] = name[i^rev]+'A'-'a';
			else ans[ansptr++] =  name[i^rev];
//			print();
			assert(ansptr <= MAXANS);
			return;
		}
	fprintf(stderr,"Can't go from (%d,%d) to (%d %d)\n",curx,cury,tox,toy);
	assert(false);
}

void findbase(int& basex,int& basey){
    for (int i = 0; i < n && basex == -1; i++)
    	for (int j = 0; j < n-1 && basex == -1; j++)
    		if (need[i][j] == need[i][j+1]){
    			basex = i;
    			basey = j;
    			break;
    		}
}

void _moveTo(int tox,int toy,bool recolor){
	while (curx < tox) go(curx+1,cury,recolor);
	while (curx > tox) go(curx-1,cury,recolor);
	while (cury < toy) go(curx,cury+1,recolor);
	while (cury > toy) go(curx,cury-1,recolor);
}

void moveTo(int tox,int toy){
	_moveTo(tox,toy,false);
}

void colorTo(int tox,int toy){
	_moveTo(tox,toy,true);
}

void Finish(){
	int dlt;
	if (cur[basex][basey] == need[basex][basey])
	    dlt = 1;
	else
		dlt = 0;
	// paint last 3x2 rectangle
	moveTo(basex,basey+dlt);
	if (basex != 0) colorTo(basex-1,basey+1-dlt);
	moveTo(basex,basey+dlt);
	if (basex != n-1) colorTo(basex+1,basey+1-dlt);

	moveTo(basex,basey+1-dlt);
	colorTo(basex,basey+dlt);

	moveTo(basex,basey);

	if (basex != 0 && cur[basex-1][basey] != need[basex-1][basey])
		colorTo(basex-1,basey),moveTo(basex,basey);
	if (basex != n-1 && cur[basex+1][basey] != need[basex+1][basey])
		colorTo(basex+1,basey),moveTo(basex,basey);

	moveTo(basex,basey+1);

	if (basex != 0 && cur[basex-1][basey+1] != need[basex-1][basey+1])
		colorTo(basex-1,basey+1),moveTo(basex,basey+1);
	if (basex != n-1 && cur[basex+1][basey+1] != need[basex+1][basey+1])
		colorTo(basex+1,basey+1),moveTo(basex,basey+1);
}

void Start(){
	//paint base;
	colorTo(basex,basey);
	if (basex >= 2){
		moveTo(basex-2,1);
		colorTo(basex-2,0);
		colorTo(0,0);
		moveTo(basex,basey);
	}

	int t = basex - 1;
	if (t == -1) t = 1;

	if (basey != 0){
		moveTo(basex,basey+1);
		colorTo(t,basey+1);
		colorTo(t,0);
		colorTo(basex,basey-1);
		moveTo(basex,basey);
	}
}

void NearBase(){
	int lx = basex-1;
	int rx = basex+1;

	moveTo(basex,basey+1);
	if (lx >= 0) colorTo(lx,0), colorTo(lx,n-1), moveTo(basex,basey+1);
	if (rx <  n) colorTo(rx,0), colorTo(rx,n-1), moveTo(basex,basey+1);
	moveTo(basex,basey);
	colorTo(basex,0);
	colorTo(basex,n-1);

	for (int i = n-1; i > basey+1; i--){
		if (        need[basex][i] == 0) moveTo(lx >= 0?lx:rx,i-1), colorTo(lx >= 0?lx:rx,i), colorTo(basex,i);
		if (lx >= 0 && need[lx][i] == 1) moveTo(basex,i-1),colorTo(lx,i),moveTo(lx,i-2),colorTo(lx,i-1);
		if (rx <  n && need[rx][i] == 1) moveTo(basex,i-1),colorTo(rx,i),moveTo(rx,i-2),colorTo(rx,i-1);
	}
	
	for (int i = 0; i < basey; i++){
		if (        need[basex][i] == 0) moveTo(lx >= 0?lx:rx,i+1), colorTo(lx >= 0?lx:rx,i), colorTo(basex,i);
		if (lx >= 0 && need[lx][i] == 1) moveTo(basex,i+1),colorTo(lx,i),moveTo(lx,i+2),colorTo(lx,i+1);
		if (rx <  n && need[rx][i] == 1) moveTo(basex,i+1),colorTo(rx,i),moveTo(rx,i+2),colorTo(rx,i+1);
	}

	moveTo(lx >= 0?lx:rx,basey+1);
	colorTo(basex,basey+1);
}

void ColorPointFromBase(int x,int y){
	if (need[x][y] == cur[x][y]) return;
	moveTo(basex,basey + !need[x][y]);
	colorTo(x,y);
}

void ColorLineFromBase(int id){
	for (int j = 0; j < basey; j++)
		ColorPointFromBase(id,j);
	for (int j = n-1; j >= basey+1; j--)
		ColorPointFromBase(id,j);
}

void UpDown(int dlt){
   	moveTo(basex,basey);
    
    if (0 <= basex + 2*dlt && basex + 2*dlt < n){
		colorTo(basex+dlt,0);
	    colorTo(basex+dlt,n-1);
		moveTo(basex + dlt, 0);  
	}

	for (int i = basex + 3*dlt; i+dlt>= -1 && i+dlt <= n; i+=2*dlt){
		if (cury == 0){        
			colorTo(i,0);
			moveTo(i-dlt,1);
			colorTo(i-dlt,0);
			moveTo(i,0);
			colorTo(i,n-1);
		}
		else {                   
			colorTo(i,n-1);
			moveTo(i-dlt,n-2);
			colorTo(i-dlt,n-1);
			moveTo(i,n-1);
			colorTo(i,0);
		}
	}    

    int start = curx;

    if (dlt > 0) moveTo(n-1,cury);
    else moveTo(0,cury);

	for (int i = curx; abs(i - basex) > 1; i-=dlt){
		if ((start - i - 1)%2){
			moveTo(i,0);
			for (int j = 0; j < n; j++)
				if (cur[i][j] != need[i][j]){
					if (curx != i || cur[curx][cury] != need[i][j])
						moveTo(i-dlt,j);
					colorTo(i,j);
				}
				else 
					moveTo(i-dlt,cury);
		} else {
			moveTo(i,n-1);
			for (int j = n-1; j >= 0; j--)
				if (cur[i][j] != need[i][j]){
					if (curx != i || cur[curx][cury] != need[i][j])
						moveTo(i-dlt,j);
					colorTo(i,j);
				}
				else
					moveTo(i-dlt,cury);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("test\\in.txt", "r", stdin);
	freopen("test\\out.txt", "w", stdout);
#else
	freopen("chameleon.in", "r", stdin);
	freopen("chameleon.out", "w", stdout);
#endif
	
    scanf("%d",&n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			char c;
	    	scanf(" %c",&c);
	    	need[i][j] = (c == 'B');
	    	cur[i][j] = !i && !j;
    	}
                      
    basex = basey = -1;        
    findbase(basex,basey);

	if (basex == -1){
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				swap(need[i][j],need[j][i]);
		rev = 1;
	    findbase(basex,basey);
	    if (basex == -1){
	    	fprintf(stderr,"It's a chess board!\n");
	    	assert(false);
	    }
	}

	Start();
	UpDown(1);         
    UpDown(-1);
	NearBase();
	Finish();	

	for (int i = 0; i < n; i++)	
		for (int j = 0; j < n; j++)
			assert(cur[i][j] == need[i][j]);

	fprintf(stderr,"%d moves\n",ansptr);
	ans[ansptr++] = 0;
	puts(ans);      
    return 0;
}