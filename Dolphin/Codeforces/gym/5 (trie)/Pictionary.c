#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

typedef struct bitset {
    uint64_t* data;
    int size; // number of bits in bitset
} bitset_t;

bitset_t* bitset_create(int n) {
    bitset_t* b = malloc(sizeof(bitset_t));
    if(!b) return NULL;
    
    b->data = calloc(2, sizeof(uint64_t));
    if(!b->data) {free(b); return NULL;}
    b->size = n;
    return b;
}
void bitset_set(bitset_t* b, int i) {
    b->data[i / 64] |= 1ULL << (i % 64);
}
bool bitset_get(bitset_t* b, int i) {
    return (b->data[i / 64] & (1ULL << (i % 64))) != 0;
}

#define NN 2000020
#define CC 26

int S;
bitset_t *flag[NN];

struct trie {
	int nxt[NN][CC], nc, rt;
} tr;

int make() {
	flag[tr.nc] = bitset_create(S);
	int i = CC; while(i--) tr.nxt[tr.nc][i] = 0;
	return tr.nc++;
}
void init() {
    scanf("%d", &S);
    tr.nc = 0, tr.rt = make();
}

int q[NN], qb;
char T[NN], s[NN];
int len[100010];

void insert(int n, int id) {
	qb = 0;
	for(int u = tr.rt, i = 0, c; i < n; i++) {
		c = s[i] - 'a';
		if(!tr.nxt[u][c]) tr.nxt[u][c] = make();
		u = tr.nxt[u][c];
		q[qb++] = u;
	}
	while(qb--) bitset_set(flag[q[qb]], id);
}

int st[100], ed[100], id[100];
char a[NN], b[NN];

int cmp(int u, int v) {
	for(int i = st[u]; i < ed[u]; i++) a[i - st[u]] = T[i]; a[ed[u] - st[u]] = 0;
	for(int i = st[v]; i < ed[v]; i++) b[i - st[v]] = T[i]; b[ed[v] - st[v]] = 0;
	return strcmp(a, b);
}

void print(int u) {
	for(int i = st[u]; i < ed[u]; i++) putchar(T[i]);
}
void bubble_sort(int n) {
	for(int i = 0, x, j; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(cmp(id[i], id[j]) > 0) x = id[i], id[i] = id[j], id[j] = x;
		}
	}
}

int calc(char *s) {
	int u = tr.rt, c, i = 0;
	for(; s[i]; i++) {
		c = s[i] - 'a';
		if(c < 0 || c >= CC) return puts("0");
		
		u = tr.nxt[u][c];
		if(!u) return puts("0");
	}
	
	int N = 0;
	for(int i = S; i--; ) if(bitset_get(flag[u], i)) {
		st[N] = len[i], ed[N] = len[i + 1], id[N] = N, N++;
	}
	
	bubble_sort(N);
	
	int n = 0;
	for(int i = 0, j; i < N; i = j, n++) {
		for(j = i; j < N && !cmp(id[i], id[j]); j++);
	}
	
	printf("%d", n);
	for(int i = 0, j; i < N; i = j) {
		for(j = i; j < N && !cmp(id[i], id[j]); j++);
		putchar(' '), print(id[i]);
	}
	
	return puts("");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
	
    init();
    for(int i = 0; i < S; i++) {
        int n; scanf("%d %s", &n, T + len[i]);
        len[i + 1] = len[i] + strlen(T + len[i]);
        while(n--) {
            scanf("%s", s);
            int len = strlen(s);
            if(len > 400000) len = 400000;
            insert(len, i);
        }
    }
	
    int m; scanf("%d", &m);
    while(m--) scanf("%s", s), calc(s);
    return 0;
}