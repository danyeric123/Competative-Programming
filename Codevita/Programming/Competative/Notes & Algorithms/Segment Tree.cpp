using namespace std;
#include<bits/stdc++.h>

const int SIZE=1e7+1;
int Arr[SIZE];
int *Tree,SZ;

void BuildTree(int *Arr,int L,int R,int POS)
{
    if(L==R)
    {
        Tree[POS]=Arr[L];
        return;
    }
    int Mid=(L+R)/2;
    BuildTree(Arr,L,Mid,2*POS+1);
    BuildTree(Arr,Mid+1,R,2*POS+2);

    /** Required Function Here **/
    Tree[POS]=(Tree[POS*2+1]+Tree[POS*2+2]);
}

int Query(int L,int R,int QL,int QR,int POS)
{
    if(QL<=L && QR>=R)  ///Complete Overlap
    return Tree[POS];

    if (QL>R || QR<L)   ///Out of Range
        return 0;

    int Mid=(L+R)/2;    ///Partial Overlap

    /** Required Query Here **/
    return (
            Query(  L,  Mid  , QL,QR ,  2*POS+1)+
            Query(Mid+1 ,R   , QL,QR ,  2*POS+2)
            );
}

void UpdateTree(int L,int R,int QL,int QR,int POS,int VALUE)
{
    if(L>R || QL>R || QR<L) ///Out of Range
        return;

    if(L==R)                ///Increment values from leaf
    {
        Tree[POS]+=VALUE;
        return;
    }

    int Mid=(L+R)/2;
    UpdateTree(L,Mid,QL,QR,2*POS+1,VALUE);
    UpdateTree(Mid+1,R,QL,QR,2*POS+2,VALUE);

    Tree[POS]=(Tree[POS*2+1]+Tree[POS*2+2]);

}
void Construct(int *Arr,int N)
{
    /** Tree Construction **/
    int Height = ceil(log2(N));
    //Max Height of the Tree The Reason it performs operations in log(N)
    SZ = 2*(1<<Height)-1;
    Tree=(int *)calloc(SZ,sizeof(int));
    BuildTree(Arr,0,N-1,0);
    /**-------------------**/
}


int main()
{
    int i,N,Q,QL,QR,VALUE;
    scanf("%d %d",&N,&Q);

    for(i=0;i<N;i++)
        scanf("%d",&Arr[i]);

    Construct(Arr,N);

   while(Q--)
   {
       for(i=0;i<SZ;i++)
        printf("%d ",Tree[i]);
    printf("\n");
    scanf("%d %d %d",&QL,&QR,&VALUE);
    UpdateTree(0,N,QL-1,QR-1,0,VALUE);
   }
    return 0;
}
