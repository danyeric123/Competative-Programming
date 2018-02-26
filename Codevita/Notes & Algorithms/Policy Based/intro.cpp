#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace::std;
int main()
{
    tree<int, size_t> ch;
    for(int i=0;i<10;i++){
        ch.insert(i);
    }

    for(auto it=ch.begin();it!=ch.end();it++){
        cout << *it << endl;
    }


    return 0;
}
