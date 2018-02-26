#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>

#define max(a,b) a>b?a:b

#define sf(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define pf(a) printf("%d",a)
#define pfl(a) printf("%lld",a)
#define pn printf("\n")

const int Max = 1e5;
int Arr[100000];
int Tree[4*100000];

void Build(int Arr[],int L,int R,int POS);

void init(int Arr[],int N) {
      Build(Arr,1,N,1);
}

void Build(int Arr[],int L,int R,int POS)
{
	   if(L==R)  {   Tree[POS]=Arr[L]; return; }
	   int Mid=(L+R)/2;
	   Build(Arr,L,Mid,2*POS); Build(Arr,Mid+1,R,2*POS+1);
	   Tree[POS]=max(Tree[POS*2],Tree[POS*2+1]);
	   //Tree[POS]=Tree[POS*2]*Tree[POS*2+1];
}

int Query(int L,int R,int QL,int QR,int POS)
{
    if(QL<=L && QR>=R) return Tree[POS];
    if (QL>R || QR<L)  return 1;
    int Mid=(L+R)/2;

    int Q1 = Query(  L,  Mid  , QL,QR ,  2*POS);
    int Q2 = Query(Mid+1 ,R   , QL,QR ,  2*POS+1);
    int Q = max(Q1,Q2);
    return Q;
}

void Update(int L,int R,int QL,int QR,int POS,int VALUE)
{
    if(L>R || QL>R || QR<L) { return; }  if(L==R)   {Tree[POS]=VALUE; return;  }
    int Mid=(L+R)/2;  Update(L,Mid,QL,QR,2*POS,VALUE);  Update(Mid+1,R,QL,QR,2*POS+1,VALUE);
    Tree[POS]=max(Tree[POS*2],Tree[POS*2+1]);
     // Tree[POS]=Tree[POS*2]*Tree[POS*2+1];
}

int main(){
      int N; int L,R;
      sf(N);
      for(int i=1;i<=N;i++) sf(Arr[i]);
      init(Arr,N);
      int Q;
      sf(Q);
      while(Q--){
            sf(L); sf(R);
            pf(Query(1,N,L,R,1)); pn;

      }
      return 0;
}


