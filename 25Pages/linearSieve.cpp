vector<int> primes;
vector<int> smallestPrimeFactor;

void linearSieve(int n) {
	if(n < 1) n = 1;
	if((int)smallestPrimeFactor.size() >= n + 1) return;
	int primePiBound = n < 20 ? n - 1 : (int)(n / (log(n * 1.) - 2) + 2);
	primes.assign(primePiBound + 1, numeric_limits<int>::max());
	int P = 0;
	smallestPrimeFactor.assign(n + 1, 0);
	smallestPrimeFactor[1] = 1;
	int n2 = n / 2, n3 = n / 3, n5 = n / 5;
	if(n >= 2)
		primes[P ++] = 2;
	if(n >= 3)
		primes[P ++] = 3;
	for(int q = 2; q <= n; q += 2)
		smallestPrimeFactor[q] = 2;
	for(int q = 3; q <= n; q += 6)
		smallestPrimeFactor[q] = 3;
	for(int q = 5; q <= n5; q += 2) {
		if(smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
		int bound = smallestPrimeFactor[q];
		for(int i = 2; ; ++ i) {
			int p = primes[i];
			if(p > bound) break;
			int pq = p * q;
			if(pq > n) break;
			smallestPrimeFactor[pq] = p;
		}
	}
	for(int q = (n5 + 1) | 1; q <= n; q += 2) {
		if(smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
	}
	primes.resize(P);
}