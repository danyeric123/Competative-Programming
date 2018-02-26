struct FenwickTree 
{
	typedef ll T;
	vector<T> v;
	FenwickTree(int n): v(n, 0) {}
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) {	//[left, right)
		return sum(right) - sum(left);
	}
};