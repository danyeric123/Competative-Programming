typedef long long ll;

class FenwickTree
{
    ll *Bit1,*Bit2,Size;

public:
    FenwickTree(int N)
    {
        Size = N+1;
        Bit1 = (ll *)calloc(Size,sizeof(ll));
        Bit2 = (ll *)calloc(Size,sizeof(ll));
    }

    ll Query(ll *Bit,int x)
    {
        ll Sum=0;
        while(x>0)
        {
            Sum += Bit[x];
            x -= (x & -x);
        }
        return Sum;
    }

    ll Query(int x)
    {
        return Query(Bit1,x)*x - Query(Bit2,x);
    }

    ll Range_Query(int x,int y)
    {
        return Query(y)-Query(x-1);
    }

    void Update(ll *Bit,int Idx,ll Val)
    {
        while(Idx <= Size)
        {
            Bit[Idx]+=Val;
            Idx += (Idx & -Idx);
        }
    }

    void Range_Update(int x,int y,ll Val)
    {
        Update(Bit1,x,Val);
        Update(Bit1,y+1,-Val);
        Update(Bit2,x,Val*(x-1));
        Update(Bit2,y+1,-Val*y);
    }

};
