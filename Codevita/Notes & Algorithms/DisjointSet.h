/**
    First Call MakeSet(a) MakeSet(b) Then Union(a,b) , Find(a) and Find(b) gives same address
*/

struct DisjointNode
{
    int Rank,Sz;
    struct DisjointNode *Parent;
    struct DisjointNode *Child[10001];
};

void MakeSet(struct DisjointNode &x)
{
    x.Parent=&x;
    x.Rank=0;
    x.Sz=0;
}

struct DisjointNode* Find(struct DisjointNode &x)
{
    if(&x == x.Parent)
         return x.Parent;
    Find(*x.Parent);

};

void Link(struct DisjointNode *x,struct DisjointNode *y)
{
    y->Parent = x;
    x->Child[(x->Sz)++] = y;
}

void Union(struct DisjointNode &x,struct DisjointNode &y)
{
   Link(&x,&y);
}
