#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL


struct node{
    int key;
    struct node *left, *right;
};

struct node *createNode(int item){
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insertNode(struct node* node, int key){
    if (node == NULL) return createNode(key);
    if (key < node->key)
        node->left  = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    return node;
}

int dfs(node *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    if(root->left == NULL || root->right == NULL)
        return dfs(root->left)+dfs(root->right);
    return 2*dfs(root->left)*dfs(root->right);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N,x;
        cin >> N;
        node *root = NULL;
        for(int i=0;i<N;i++){
            cin >> x;
            root = insertNode(root,x);
        }
        cout << dfs(root) << endl;
    }

}
