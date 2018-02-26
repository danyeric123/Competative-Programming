#include <bits/stdc++.h>
using namespace::std;

#define TRACE
#define DEBUG

#ifdef TRACE
#define trace(...) cerr  << "(" << __FUNCTION__ << " : " << __LINE__ << ") ";__f(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1 && arg1) { cerr << name << " = " << arg1 << "" << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) { const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...); }
#else
#define trace(...)
#endif

int main(){

	return 0;
}
