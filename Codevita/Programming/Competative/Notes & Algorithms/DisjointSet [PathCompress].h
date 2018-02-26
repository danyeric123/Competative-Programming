/**
    First Call MakeSet(a) MakeSet(b) Then Union(a,b) , Find(a) and Find(b) gives same address
*/

struct DisjointNode
{
    int Rank;
    struct DisjointNode *Parent;
};

void MakeSet(struct DisjointNode &x)
{
    x.Parent=&x;
    x.Rank=0;
}

struct DisjointNode* Find(struct DisjointNode &x)
{
    if(&x != x.Parent)
    {
        x.Parent = Find(*x.Parent);
    }
    return x.Parent;
};

void Link(struct DisjointNode *x,struct DisjointNode *y)
{
    if(x->Rank > y->Rank)
        y->Parent = x;
    else
    {
        x->Parent = y;
        if(x->Rank == y->Rank)
            y->Rank = y->Rank + 1;
    }
}

void Union(struct DisjointNode &x,struct DisjointNode &y)
{
   Link(Find(x),Find(y));
}
