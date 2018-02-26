bool Prime[MAX];

void Sieve()
	{
		memset(Prime,1,sizeof(Prime));
		int i,j;
		Prime[0]=Prime[1]=0;
		for(i=2;i<sqrt(N);i++)
		{
		     if(Prime[i])
		    {
		          for(j=i*i;j<=N;j+=i)
			    Prime[j]=0;
	   }
                       }
}
