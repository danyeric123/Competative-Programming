#include<bits/stdc++.h>
using namespace::std;
char name[1004], mail[1004];
char small(char ch){
      if(ch>='a' && ch<='z') return ch;
      else return ch-'A'+'a';
}
bool Check(char *name,char *email,int st,int Len){
      int k=0;
      for(int i=st;i<Len;i++){
            if(small(name[k++]) != small(email[i]))
                  return false;
      }
      return true;
}
bool CheckEmail(char *em,int len){
      if(len <= 4) return false;
      if(em[0] =='@') return false;
      if(em[len-4]!='.') return false;
      for(int i=0;i<len;i++) if(em[i]=='@') return true;
      return false;
}
int isValidEmail(char *email)
{
	if (email==NULL)
		return -1;
	int len = 0,i=0;
	for (i = 0; email[i]; i++){
		if (email[i] == '[' || email[i] == ']') return -1;
		if (email[i] == '(' || email[i] == ')') return -1;
		if (email[i] == ':' || email[i] == ';') return -1;
		if (email[i] == '<' || email[i] == '>') return -1;
		if (email[i] == ',' || email[i] == '\\') return -1;
	}
	len = i;
	for(int i=0;i<=len;i++) mail[i]=name[i]='\0';

	int emailLen=0,nameLen=0;
	int k=0,x;
	for (int i = len-1; i >= 0; i--){
            if(email[i]==' '){
                  for(int x=i+1;x<len;x++){
                        mail[k++] = email[x];
                  }
                  mail[k] = '\0';
                  break;
            }
	}
	emailLen = k;
	k=0;
	for(int i=0;i<len;i++){
            if(email[i]==' ') break;
            name[k++] = email[i];
	}
	name[k]='\0';
	nameLen = k;

      int dot = 0;
      for(int i=emailLen;i>=0;i--)
      if(mail[i]=='.'){
            dot = i;
            break;
      }

      if(nameLen >= emailLen)
            return -1;

      bool ok1 = Check(name,mail,0,nameLen);
      bool ok2 = Check(name,mail,dot-nameLen,nameLen);
      if(dot-emailLen==0){
            ok1=false;
            ok2=false;
      }
      bool em = CheckEmail(mail,emailLen);
      //cout << name << mail << endl;
      //cout << name << " " <<  mail << endl;
      // cout << email << em << endl;
      if(em && (ok1 ||ok2) ) return 2;
      if(em) return 1;
      return 0;
}

int main(){
      cout << isValidEmail("abc abc.com");
}
