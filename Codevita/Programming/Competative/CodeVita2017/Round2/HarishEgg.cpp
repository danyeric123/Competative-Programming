#include<stdio.h>
int main()
{
     int m,x,i=0,j,sum=0,a,k;
     int arr[1000];
     int brr[1000];
    scanf("%d %d",&m,&x);
    k=m;
    while(m!=0)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
        brr[i] = arr[i];
        i++;
        m--;
    }

    if(x>=sum)
    {
        x = sum-1;
        printf("Sorry, we can only supply %d eggs",x);
    }
    else
    {
        printf("Thank you, your order for %d eggs is accepted\n",x);
    }
    int index[k+1];
    for(int i=0;i<k;i++)
        index[i] = i;
    for(i=0;i< k;i++)
      {
        for(j=i+1;j< k;j++)
        {
            if(arr[i]< arr[j])
            {
                a =arr[i];
                arr[i]  =arr[j];
                arr[j]  = a;
                a = index[i];
                index[i] = index[j];
                index[j] = a;

            }
            else if(arr[i] == arr[j] && index[i] > index[j]){
                a = index[i];
                index[i] = index[j];
                index[j] = a;
            }
        }
       }


    for(i=0;i<k;i++){

        if(x >= arr[index[i]]){
            x -= arr[i];
            arr[i] = 0;
        }
        else{
            arr[i] = x;
            break;
        }
    }


    for(int i=0;i<k;i++){
        printf("%d %d %d\n",brr[i],brr[i])
    }
return 0;
}

