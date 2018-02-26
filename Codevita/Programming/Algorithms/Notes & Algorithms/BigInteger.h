int Ch2Di(char Ch){	return Ch-'0'; }
char Di2Ch(int Di){	return Di+'0'; }

string BigIntAdd(string Num1,string Num2)
{
    int len1=Num1.length(),len2=Num2.length();
    int Diff = abs(len1-len2);
    string Add = len1>len2?Num1:Num2;
    if(len1>len2)
        Num2.insert(0,Diff,'0');
    else
        Num1.insert(0,Diff,'0');
    int i,Len = max(len1,len2),Carry=0;
    for(i=Len-1;i>=0;i--)
    {
        Add[i]=Di2Ch(Carry+Ch2Di(Num1[i])+Ch2Di(Num2[i]));
        if(i!=0)
        {
            if(Add[i] > '9')
            {
                Add[i]-=10;
                Carry=1;
            }
            else
                Carry=0;
        }
    }
    if(Add[0] > '9')
    {
        Add[0]-=10;
        Add.insert(0,1,'1');
    }
    return Add;
}

string BigIntSub(string Num1,string Num2)
{
    int i,len1=Num1.length(),len2=Num2.length(),Diff=abs(len1-len2);
    string Sub;
    int len=max(len1,len2);
    if(len1>len2)
        Sub=Num1;
    else if(len2<len1)
    {
        swap(Num1,Num2);
        swap(len1,len2);
        Sub=Num1;
    }
    else
    {
           len=len1;
           for(i=0;i<len;i++)
                if(Num1[i]!=Num2[i])
                    break;
            if(Num1[i]==Num2[i])
            {
                Sub.push_back('0');
                return Sub;
            }
            if(Num2[i]>Num1[i]){
                swap(len1,len2);
                swap(Num1,Num2);
            }
            Sub=Num1;
    }

    Num2.insert(0,Diff,'0');
    for(i=len-1;i>=0;i--)
    {
        if(Num1[i] < Num2[i])
        {
            Num1[i]+=10;
            Num1[i-1]--;
        }
        Sub[i]=Di2Ch(Ch2Di(Num1[i])-Ch2Di(Num2[i]));
    }
    while(Sub[0]=='0' && Sub.length()!=1)
        Sub.erase(0,1);
    return Sub;
}

string BigIntDiv(string A,int N) //N must be a digit only!
{
    int len=A.length();
    int i=1,Carry=0,Temp;
    int NextDig = Ch2Di(A[0]);
    string Res;
    if(NextDig/N) Res.push_back(Di2Ch(NextDig/N));
    while(i<len)
    {
        Temp = NextDig%N;
        NextDig = Temp*10+Ch2Di(A[i]);
        Res.push_back(Di2Ch(NextDig/N));
        i++;
    }
    if(!Res.size()) Res.push_back('0');
    return Res;
}
