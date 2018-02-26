#include<stdio.h>
#include<math.h>


struct heap{
	int size;
	int i;
	int *a;
};

struct heap* create(int s){
	struct heap* h=(struct heap*)malloc(sizeof(struct heap));
	h->a=(int*)malloc(sizeof(int)*s);
	h->size=s;
	h->i=0;
	return h;
}

int getmax(struct heap* h){
	if(h->size<1)
	return -1;
	else return h->a[0];
}

int parent(struct heap* h , int i){
	if(i<=0||i>h->i) return -1;
	int p=(i-1)/2;
	return p;
}

int lchild(struct heap* h,int p){
	int c=2*p+1;
	if(p<0||c>h->i) return -1;
	else return c;
}
int rchild(struct heap* h,int p){
	int c=2*p+2;
	if(p<0||c>h->i) return -1;
	else return c;
}
void swap(int *a,int *b){
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
void insert(struct heap* h,int k){
	if(h->i==h->size) return;
	int c = (h->i);
	h->a[c]=k;
	h->i++;
	int p=parent(h,c);
	while(c>0 && h->a[p] < h->a[c]){
		swap(&h->a[p],&h->a[c]);
		c=p;
		p=parent(h,p);
	}
}
void print(struct heap* h){
	for(int i=0;i<h->i;i++){
            printf("%d ",h->a[i]);
      }
}

void heapify(struct heap* h,int p){
	int lc=lchild(h,p);
	int rc=rchild(h,p);
	int tmp=p;
	if(lc!=-1&&h->a[p]<h->a[lc]){
		tmp=lc;
	}
	if(rc!=-1&&h->a[tmp]<h->a[rc]){
		tmp=rc;
	}
	if(tmp!=p){
		swap(&h->a[p],&h->a[tmp]);
		heapify(h,tmp);
	}


}
void delet(struct heap* h){	//delete max element
	if(h->i-1<=0){
		h->i=0;
		return;
	}
	int last=h->i-1;
	h->a[0]=h->a[last];
	h->i--;
	heapify(h,0);


}


int main()
{
      int i,t,n;
      scanf("%d",&n);
      struct heap* h=create(n);
      for(i=0;i<n;i++){
            scanf("%d",&t);
            insert(h,t);
      }
      print(h);

      for(i=0;i<n;i++){
            printf("\n");
            delet(h);
            print(h);
      }
      return 0;
}
