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

int trace(int arg_count, ...){
	int Count = 0; va_list args; va_start(args, arg_count);
	for (int i = 0; i < arg_count; i++){
		printf("%d ",va_arg(args, int));
	}
	va_end(args);
	return Count;
}

int main(){
      int N;


      return 0;
}
