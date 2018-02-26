#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Tree
{
    int Key;
    struct Tree *Left,*Right;
};

struct Tree *NewNode(int Val)
{
    struct Tree *NewNode=(struct Tree *)calloc(1,sizeof(struct Tree));

    NewNode->Key=Val;
    NewNode->Left=NULL;
    NewNode->Right=NULL;
};

struct Tree *Insert(struct Tree *SubTree,int Val)
{
    if(SubTree==NULL) return NewNode(Val);

    if(Val < SubTree->Key)
        SubTree->Left = Insert(SubTree->Left,Val);
    else if(Val > SubTree->Key)
        SubTree->Right = Insert(SubTree->Right,Val);
    return SubTree;

};

void PreOrder(struct Tree *SubTree)
{
    if(SubTree) printf("%d ",SubTree->Key);
    if(SubTree->Left) PreOrder(SubTree->Left);
    if(SubTree->Right) PreOrder(SubTree->Right);
}
void InOrder(struct Tree *SubTree)
{
    if(SubTree->Left) InOrder(SubTree->Left);
    if(SubTree) printf("%d ",SubTree->Key);
    if(SubTree->Right) InOrder(SubTree->Right);
}
void PostOrder(struct Tree *SubTree)
{
    if(SubTree->Left) PostOrder(SubTree->Left);
    if(SubTree->Right) PostOrder(SubTree->Right);
    if(SubTree) printf("%d ",SubTree->Key);
}

int main()
{
    struct Tree *Root=NULL;

    int i,N,ele;
    printf("No of Nodes to Insert : ");
    scanf("%d",&N);

    printf("Enter %d Nodes : ",N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&ele);
        Root=Insert(Root,ele);
    }

    printf("\nPreOrder Traversal :");  PreOrder(Root);
    printf("\nInOrder Traversal :");   InOrder(Root);
    printf("\nPostOrder Traversal :"); PostOrder(Root);

    getch();
    return 0;
}
