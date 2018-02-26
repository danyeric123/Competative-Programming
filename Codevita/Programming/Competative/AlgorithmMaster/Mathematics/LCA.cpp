#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

#define true 1
#define false 0
#define MAX(a,b)  (a < b ? b : a)

Node *createNode(int value){
	Node * newNode =  (Node *)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right= NULL;
	newNode->left = NULL;

	return newNode;
}
Node *addNode(Node *node, int value){
	if(!node){
		return createNode(value);
	}
	if (node->value > value)
		node->left = addNode(node->left, value);
	else
		node->right = addNode(node->right, value);

	return node;
}

unsigned int eulerTraversalStore[100];
unsigned int depth[100];
unsigned int firstVisit[100];
unsigned int depthAlready[100];
int k = 0;
int l = 0;
int currentDepth = 0;

void eulerTraversal(Node * root){
	if(!root) return;

	eulerTraversalStore[k++] = root->value;

	if(!firstVisit[root->value]){
		firstVisit[root->value] = k-1;
	}

	if(depthAlready[root->value]){
		depth[l++] = depthAlready[root->value];
		currentDepth = depthAlready[root->value];
	}
	else{
		depth[l++]  = ++currentDepth;
		depthAlready[root->value] = currentDepth;
	}
	if(root->left) {
		eulerTraversal(root->left);
		eulerTraversalStore[k++] = root->value;

		if(depthAlready[root->value]){
			depth[l++] = depthAlready[root->value];
			currentDepth = depthAlready[root->value];
		}
		else{
			depth[l++]  = ++currentDepth;
			depthAlready[root->value] = currentDepth;
		}
	}
	if(root->right) eulerTraversal(root->right);

	return;
}

int M[100][100];

void preprocess(unsigned a[], int size)
{
	int i,j;
	for (i=0; i<size; i++)
		M[i][i] = i;

	for (i=0; i<size; i++){
		for (j=i+1; j<size; j++){
			if (a[M[i][j - 1]] < a[j])
				M[i][j] = M[i][j - 1];
			else
				M[i][j] = j;
		}
	}
}

int rmq(int start, int end){
	return M[start][end];
}

int LCA( int u, int v){

	if(u > v){
		int temp = u;
		u = v;
		v= temp;
	}
	int index = rmq(firstVisit[u], firstVisit[v]);

	return eulerTraversalStore[index];
}
/* Driver program for the function written above */

int Justice[MAX];
int main(){
      scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
            cin >> Justice[i];
      }
      for(int i=2;i<=n;i++){
            cin >> x;
            G[i].pb(x);
            G[x].pb(i);
      }
	Node *root = NULL;
	//Creating a binary tree
	root = addNode(root, 30);
	root = addNode(root, 20);
	root = addNode(root, 15);
	root = addNode(root, 25);
	root = addNode(root, 40);
	root = addNode(root, 38);
	root = addNode(root, 39);
	root = addNode(root, 45);
	root = addNode(root, 47);
	root = addNode(root, 49);

	for(int i=0; i<100; i++){
		firstVisit[i]   = 0;
		depthAlready[i] = 0;
	}
	eulerTraversal(root);

	int size = sizeof(depth)/sizeof(depth[0]);
	preprocess(depth, size);

	printf("\n Lowest common ancestor : %d", LCA(15,25));

	return 0;
}
