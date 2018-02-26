Set a bit
 Use the bitwise OR (|) operator.
 number |= 1 << x; // Sets bit x

Clear a bit
 Use the bitwise AND (&) and NOT (~) operators.
 number &= ~(1 << x); // Clears bit x
 number &= !(1 << x); // Also works

Toggle a bit
 Use the bitwise XOR (^) operator.
 number ^= 1 << x; // Toggles bit x

Check a bit
 Use the bitwise AND (&) operator.
 bit = number & (1 << x); // Store value of bit x

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(x, N) ((x) & (N - 1))   // returns x % N, where N is a power of 2
#define isPowerOfTwo(x) ((x & (x - 1)) == 0)
#define nearestPowerOfTwo(x) ((int)pow(2.0, (int)((log((double)x) / log(2.0)) + 0.5)))