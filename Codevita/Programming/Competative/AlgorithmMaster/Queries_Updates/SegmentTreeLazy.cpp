#include<bits/stdc++.h>
using namespace::std;


vector<int> tree;
vector<int> lazy;

void init(int A[],int N){
      tree.assign(8*N,0);
      lazy.assign(8*N,0);
      build(A,1,1,N);
}
void init1(int N){
      tree.assign(8*N,0);
      lazy.assign(8*N,0);
}

void build(int A[],int idx, int a, int b) {
        if(a == b) { tree[idx] = A[a];  return; }
        build(A,idx*2, a, (a+b)/2); build(A,idx*2+1, 1+(a+b)/2, b);
        tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

void update(int idx, int a, int b, int i, int j, int value) {
        if(lazy[idx] != 0) {
            tree[idx] += lazy[idx];
            if(a != b) {
                lazy[idx*2] += lazy[idx];
                    lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(a > b || a > j || b < i)
            return;
        if(a >= i && b <= j) {
                tree[idx] += value;
            if(a != b) {
                lazy[idx*2] += value;
                lazy[idx*2+1] += value;
            }
                return;
        }
        update(idx*2, a, (a+b)/2, i, j, value);
        update(1+idx*2, 1+(a+b)/2, b, i, j, value);
        tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}


int query(int idx, int a, int b, int i, int j) {
        if(a > b || a > j || b < i) return -INT_MAX;
        if(lazy[idx] != 0) {
            tree[idx] += lazy[idx];
            if(a != b) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(a >= i && b <= j)
            return tree[idx];
        int q1 = query(idx*2, a, (a+b)/2, i, j);
        int q2 = query(1+idx*2, 1+(a+b)/2, b, i, j);
        int res = max(q1, q2);
        return res;
}

int main() {
    int T,N,Q;
    int l,r,v;
    int ty;
    int Max = 100025;
    seg.init1(Max);
    cin >> T;

    while(T--){
      cin >> N >> Q;
      for(int i=1;i<=Q;i++){
            cin >> ty;
            if(ty==0){
                  cin >> l >> r >> v;
                  seg.update(1,1,N,l,r,v);
            }
            else{
                  cin >> l >> r;
                  cout << seg.query(1,1,N,l,r) << endl;
            }
      }
    }
    return 0;
}
