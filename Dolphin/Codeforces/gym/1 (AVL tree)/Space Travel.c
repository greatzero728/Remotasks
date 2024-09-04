#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

int get_balance(Node *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node *new_node(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node *right_rotate(Node *y) {
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *left_rotate(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *node, int value) {
    if (node == NULL) {
        return new_node(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = get_balance(node);

    if (balance > 1 && value < node->left->value) {
        return right_rotate(node);
    }

    if (balance < -1 && value > node->right->value) {
        return left_rotate(node);
    }

    if (balance > 1 && value > node->left->value) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void insert_value(Node **root, int value) {
    *root = insert(*root, value);
}

Node *get_min(Node *node) {
    if (node->left == NULL) return node;
    return get_min(node->left);
}

Node* Delete(Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = Delete(root->left, value);
    }
    else if (value > root->value) {
        root->right = Delete(root->right, value);
    }
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = get_min(root->right);
        root->value = temp->value;
        root->right = Delete(root->right, temp->value);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = get_balance(root);

    if (balance > 1 && get_balance(root->left) >= 0){
        return right_rotate(root);
    }
    if (balance > 1 && get_balance(root->left) <0){
        root->left =  left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance < -1 && get_balance(root->right) <= 0){
        return left_rotate(root);
    }
    if (balance < -1 && get_balance(root->right) > 0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}


#define NN 101010
#define MM 202020

int head[NN], nxt[MM], to[MM], E;
int flag[NN], ans[NN], nn;

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) head[i] = -1;
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	
    Node *root = NULL;
    insert_value(&root, 1);
	while(root != NULL) {
		Node *min_node = get_min(root);
		int u = min_node->value;
		
		ans[++nn] = u, flag[u] = 1;
		root = Delete(root, u);
		for(int e = head[u]; ~e; e = nxt[e]) {
			int v = to[e];
			if(!flag[v]) insert_value(&root, v);
		}
	}
	
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
