#include<stdio.h>
int ConvertInt(char *str){
      if(str==NULL)
            return -1;
      int len=0;
      for(len=0;str[len];len++);
      if(len>=31) return -1;
      if(!len) return -1;

      int Res = 0,Idx = 1;
      for(int i=len-1;i>=0;i--){
            if(str[i]!='0' && str[i]!='1')
                  return -1;
            if(str[i]=='1')
                  Res = Res + Idx;
            Idx = Idx*2;
      }
      return Res;
}

int ConvertIntRecur(char *str){
       static int Idx = 1;
      if(str==NULL ||  *str=='\0'){
            Idx = Idx*2;
            return str[0]=='1';
      }

      return ConvertIntRecur(++str) + Idx*(str[0]=='1');


}
int main(){
      char st[] = "111111111111111111111111111111";
      printf("%d ",ConvertInt(st));
      printf("%d ",ConvertIntRecur(st));
}
