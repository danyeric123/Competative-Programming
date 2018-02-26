vector<string> makeStringTokens (string s, string div) {
  vector<string> items; ///vector<int> items; for integers ex : "1,2,3,4"
  int i=0, j;
  ///items.push_back(atoi(s.substr(i, j-i).c_str()));  //for integers.
  for (i=s.find_first_not_of(div, i); i!=-1; i=s.find_first_not_of(div, i=j)) {
    j = s.find_first_of(div, i);
    items.push_back(s.substr(i, j-i));
  }
  return items;
}

//Big Integer
import java.util.Scanner; // inside package java.util
import java.math.BigInteger; // inside package java.math
class Main { /* UVa 10925 - Krakovia */
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int caseNo = 1;
	while (true) {
		int N = sc.nextInt(), F = sc.nextInt(); // N bills, F friends
		if (N == 0 && F == 0) break;
		BigInteger sum = BigInteger.ZERO; // BigInteger has this constant
		for (int i = 0; i < N; i++) { // sum the N large bills
			BigInteger V = sc.nextBigInteger(); // for reading next BigInteger!
			sum = sum.add(V); // this is BigInteger addition
			}
		System.out.println("Bill #" + (caseNo++) + " costs " + 
		sum +": each friend should pay " + sum.divide(BigInteger.valueOf(F)));
		System.out.println(); // the line above is BigInteger division
		} // divide the large sum to F friends
	}
}

//Base number conversion

class Main { /* UVa 10551 - Basic Remains */
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

while (true) {

int b = sc.nextInt();

if (b == 0) break; // special class’s constructor!

BigInteger p = new BigInteger(sc.next(), b); // the second parameter

BigInteger m = new BigInteger(sc.next(), b); // is the base

System.out.println((p.mod(m)).toString(b)); // can output in any base

} } }stdout.write(str(Seg.Query(1,1,n,x,y))+" ")


//parallel and same lines

bool areParallel(line l1, line l2) { // check coefficients a & b

return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) { // also check coefficient c

return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);}

//intersection point of two lines

// returns true (+ intersection point) if two lines are intersect

bool areIntersect(line l1, line l2, point &p) {

if (areParallel(l1, l2)) return false; // no intersection

// solve system of 2 linear algebraic equations with 2 unknowns

p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

// special case: test for vertical line to avoid division by zero

if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);

else p.y = -(l2.a * p.x + l2.c);

return true; }

//distance between line and point

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by

// two points a and b (a and b must be different)

// the closest point is stored in the 4th parameter (byref)

double distToLine(point p, point a, point b, point &c) {

// formula: c = a + u * ab

vec ap = toVec(a, p), ab = toVec(a, b);

double u = dot(ap, ab) / norm_sq(ab);

c = translate(a, scale(ab, u)); // translate a to c

return dist(p, c); } // Euclidean distance between p and c

//distance between point and line segment

// returns the distance from p to the line segment ab defined by

// two points a and b (still OK if a == b)

// the closest point is stored in the 4th parameter (byref)

12

double distToLineSegment(point p, point a, point b, point &c) {

vec ap = toVec(a, p), ab = toVec(a, b);

double u = dot(ap, ab) / norm_sq(ab);

if (u < 0.0) { c = point(a.x, a.y); // closer to a

return dist(p, a); } // Euclidean distance between p and a

if (u > 1.0) { c = point(b.x, b.y); // closer to b

return dist(p, b); } // Euclidean distance between p and b

return distToLine(p, a, b, c); } // run distToLine as above

//Intersection of line segments

// line segment from c to d

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {

if (LinesCollinear(a, b, c, d)) {

if (dist2(a, c) < EPS || dist2(a, d) < EPS ||dist2(b, c) < EPS || dist2(b, d) < EPS)

return true;

if (dot(c‐a, c‐b) > 0 && dot(d‐a, d‐b) > 0 && dot(c‐b, d‐b) > 0)

return false;

return true;

}

if (cross(d‐a, b‐a) * cross(c‐a, b‐a) > 0) return false;

if (cross(a‐c, d‐c) * cross(b‐c, d‐c) > 0) return false;

return true;

}

//point inside, outside or on the circle

int insideCircle(point_i p, point_i c, int r) { // all integer version

int dx = p.x - c.x, dy = p.y - c.y;

int Euc = dx * dx + dy * dy, rSq = r * r; // all integer

return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } //inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point &c) {

double d2 = (p1.x - p2.x) * (p1.x - p2.x) +(p1.y - p2.y) * (p1.y - p2.y);

double det = r * r / d2 - 0.25;

if (det < 0.0) return false;

double h = sqrt(det);

c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;

c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;

return true; } // to get the other center, reverse p1 and p2

//incircle of triangle

double rInCircle(double ab, double bc, double ca) {

return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }

double rInCircle(point a, point b, point c) {

return rInCircle(dist(a, b), dist(b, c), dist(c, a)); }

//circumcirlce of triangle

double rCircumCircle(double ab, double bc, double ca) {

return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

double rCircumCircle(point a, point b, point c) {

return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

13

//Area of polygon

// returns the area, which is half the determinant

double area(const vector<point> &P) {

double result = 0.0, x1, y1, x2, y2;

for (int i = 0; i < (int)P.size()-1; i++) {

x1 = P[i].x; x2 = P[i+1].x;

y1 = P[i].y; y2 = P[i+1].y;

result += (x1 * y2 - x2 * y1);

}

return fabs(result) / 2.0; }

//point inside or outside polygon

// returns true if point p is in either convex/concave polygon P

bool inPolygon(point pt, const vector<point> &P) {

if ((int)P.size() == 0) return false;

double sum = 0; // assume the first vertex is equal to the last vertex

for (int i = 0; i < (int)P.size()-1; i++) {

if (ccw(pt, P[i], P[i+1]))

sum += angle(P[i], pt, P[i+1]); // left turn/ccw

else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw

return fabs(fabs(sum) - 2*PI) < EPS; }

//Pollard-rho Integer factorization algorithm

#define abs_val(a) (((a)>0)?(a):-(a))

typedef long long ll;

ll mulmod(ll a, ll b, ll c) { // returns (a * b) % c, and minimize overflow

ll x = 0, y = a % c;

while (b > 0) {

if (b % 2 == 1) x = (x + y) % c;

y = (y * 2) % c;

b /= 2;

}

return x % c;

}

ll gcd(ll a,ll b) { return !b ? a : gcd(b, a % b); } // standard gcd

ll pollard_rho(ll n) {

int i = 0, k = 2;

ll x = 3, y = 3; // random seed = 3, other values possible

while (1) {

i++;

x = (mulmod(x, x, n) + n - 1) % n; // generating function

ll d = gcd(abs_val(y - x), n); // the key insight

if (d != 1 && d != n) return d; // found one non-trivial factor

if (i == k) y = x, k *= 2;

} }

int main() {

ll n = 2063512844981574047LL; // we assume that n is not a large prime

ll ans = pollard_rho(n); // break n into two non trivial factors

if (ans > n / ans) ans = n / ans; // make ans the smaller factor

printf("%lld %lld\n", ans, n / ans); // should be: 1112041493 1855607779} // return 0;

14

//Convex Hull

#define REMOVE_REDUNDANT

typedef double T;

const T EPS = 1e‐7;

struct PT {

T x, y;

PT() {}

PT(T x, T y) : x(x), y(y) {}

bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }

bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }

};

T cross(PT p, PT q) { return p.x*q.y‐p.y*q.x; }

T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT

bool between(const PT &a, const PT &b, const PT &c) {

return (fabs(area2(a,b,c)) < EPS && (a.x‐b.x)*(c.x‐b.x) <= 0 && (a.y‐b.y)*(c.y‐b.y) <= 0);

}

#endif

void ConvexHull(vector<PT> &pts) {

sort(pts.begin(), pts.end());

pts.erase(unique(pts.begin(), pts.end()), pts.end());

vector<PT> up, dn;

for (int i = 0; i < pts.size(); i++) {

while (up.size() > 1 && area2(up[up.size()‐2], up.back(), pts[i]) >= 0) up.pop_back();

while (dn.size() > 1 && area2(dn[dn.size()‐2], dn.back(), pts[i]) <= 0) dn.pop_back();

up.push_back(pts[i]);

dn.push_back(pts[i]);

}

pts = dn;

for (int i = (int) up.size() ‐ 2; i >= 1; i‐‐) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT

if (pts.size() <= 2) return;

dn.clear();

dn.push_back(pts[0]);

dn.push_back(pts[1]);

for (int i = 2; i < pts.size(); i++) {

if (between(dn[dn.size()‐2], dn[dn.size()‐1], pts[i])) dn.pop_back();

dn.push_back(pts[i]);

}

if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {

dn[0] = dn.back();

dn.pop_back();

}

pts = dn;

#endif

}

// compute intersection of circle centered at a with rad r with circle centered at b with radius R

vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {

vector<PT> ret; double d = sqrt(dist2(a, b));

15

if (d > r+R || d+min(r, R) < max(r, R)) return ret;

double x = (d*d‐R*R+r*r)/(2*d);

double y = sqrt(r*r‐x*x);

PT v = (b‐a)/d;

ret.push_back(a+v*x + RotateCCW90(v)*y);

if (y > 0)

ret.push_back(a+v*x ‐ RotateCCW90(v)*y);

return ret;

}

//Centroid of polygon

PT ComputeCentroid(const vector<PT> &p) {

PT c(0,0);

double scale = 6.0 * ComputeSignedArea(p);

for (int i = 0; i < p.size(); i++){

int j = (i+1) % p.size();

c = c + (p[i]+p[j])*(p[i].x*p[j].y ‐ p[j].x*p[i].y);

}

return c / scale;

}


//point inside or outside polygon

// returns true if point p is in either convex/concave polygon P

bool inPolygon(point pt, const vector<point> &P) {
	if ((int)P.size() == 0) return false;
	double sum = 0; // assume the first vertex is equal to the last vertex
	for (int i = 0; i < (int)P.size()-1; i++) {
	if (ccw(pt, P[i], P[i+1]))
	sum += angle(P[i], pt, P[i+1]); // left turn/ccw
	else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
return fabs(fabs(sum) - 2*PI) < EPS; }