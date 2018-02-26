#include<stdio.h>
int main()
{
	int r,i,n,s=0,t;

	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		s=0;
		scanf("%d",&n);
		while(n>0)
		{
			r=n%10;
			s=s+r;
			n=n/10;
		}
		printf("%d\n",s);
	}
	return 0;
}
