#include<bits/stdc++.h>
using namespace::std;



// pattern = "p" , match("pvsmpraveen") -> returns 0 4
struct KMP
{
	string pattern;
	int sz;
	vector<int> Table;
	vector<int> Matches;

	void init(string p){
		pattern = p;
		sz = pattern.size();
		Table.assign(sz+1,-1);
		BuildTable();
	}

	void BuildTable()
	{
		for (int i=1, j=0;i<sz;i++)
	    {
	        while (j >=0 && pattern[i] != pattern[j]) 
	        	j = Table[j];
	        j++;
	        Table[i+1] = j;
	    }
	}

	vector<int> match(string str)
	{
		Matches.clear();
		for (int i=0, j=0;i<str.size();i++)
	    {
	        while (j >=0 && str[i] != pattern[j]) 
	        	j = Table[j];
	        j++;
	        if (j == sz)
	        {
	            Matches.push_back(i+1 - j);
	            j = Table[j];
	        }
	    }
	    return Matches;
	}
};



int main()
{
	KMP p1;
	p1.init("p");
	auto v = p1.match("pvsmpraveen");

	for(auto it = v.begin();it!=v.end();it++){
		cout << *it << endl;
	}
	return 0;
}