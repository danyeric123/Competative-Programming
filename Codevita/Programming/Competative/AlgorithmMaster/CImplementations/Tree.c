#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>

typedef struct Node{
      int data;
      struct Node *left,*right;
}Node;

Node * CreateNode(int data){
      Node *temp = (struct Node *)calloc(1,sizeof(Node));
      temp->data = data;
      temp->left = NULL;
      temp->right = NULL;
      return temp;
}

struct Node * InsertNode(struct Node *root, int data){
      if (root == NULL) return CreateNode(data);
      if (data < root->data)
            root->left = InsertNode(root->left, data);
      else if (data > root->data)
            root->right = InsertNode(root->right, data);
      return root;
}

void PrintTree(Node *Tree){
      if(Tree==NULL) return;
      printf("%d ",Tree->data);
      PrintTree(Tree->left);

      PrintTree(Tree->right);
      return;
}

int main(){
      int N,x;
      Node *root = NULL;
      scanf("%d",&N);
      for(int i=0;i<N;i++){
            scanf("%d",&x);
            root = InsertNode(root,x);
      }
      PrintTree(root);
}
