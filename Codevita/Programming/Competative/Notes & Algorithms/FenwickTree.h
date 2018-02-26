/** This is a basic Fenwick Tree Supporting
    1. Range Query
    2. Point Update
**/

typedef long long ll;

class FenwickTree
{
    ll *Tree,Size;

public:
    FenwickTree(int N)
    {
        Size = N+1;
        Tree = (ll *)calloc(Size,sizeof(ll));
    }

    ll Sum(int x)
    {
        ll Res = 0;
        int Idx=x;
        while(Idx>0)
        {
            Res += Tree[Idx];
            Idx -= (Idx & -Idx);
        }
        return Res;
    }

    ll Sum(int a,int b)
    {
        return Sum(b)-Sum(a-1);
    }

    void Update(int i,int Add)   //Point Update
    {
        int Idx = i+1;
        while(Idx <= Size)
        {
            Tree[Idx]+=Add;
            Idx += (Idx & -Idx);
        }
    }
    void InitArray(int *Arr,int N)
    {
        for(int i=0;i<N;i++)
        {
            int Idx = i+1;
            while(Idx <= Size)
            {
                Tree[Idx] += Arr[i];
                Idx += (Idx & -Idx);
            }
        }
    }
    void PrintTree()
    {
        for(int i=0;i<Size;i++)
            printf("%lld ",Tree[i]);
    }
};
