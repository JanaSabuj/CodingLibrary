const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
int fac[maxn], invfac[maxn];

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}
int mul(int a, int b) {
	a *= b;
	if (a >= mod)
		a %= mod;
	return a;
}
int powmod(int x, int p)
{
	int sum = 1;
	for (; p; x = mul(x, x), p >>= 1)
		if (p & 1)
			sum = mul(sum, x);
	return sum;
}
int ncr(int n, int r)
{
	if (r < 0)
		return 0;
	if (r > n)
		return 0;
	return mul(mul(fac[n], invfac[n - r]), invfac[r]);
}
void preprocess() {
	fac[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = mul(fac[i - 1], i);
	}
	invfac[maxn - 1] = powmod(fac[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--)
		invfac[i] = mul(invfac[i + 1], i + 1);
}
--------------------------------------------------------------------------------------------------------------------------------------------
const int lim = 1e6;
const int p = 1e9 + 7;
int fac[lim];

void preprocess() {
	fac[0] = 1;

	for (int i = 1; i < lim; ++i) {
		fac[i] = (fac[i - 1] * i) % p;
	}
}

int power(int a, int b, int m) {
	a = a % m;
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		b /= 2;
	}

	return ans;
}

int inverse(int a, int p) {
	return power(a, p - 2, p);
}

int ncrmodp(int n, int r, int p) {
	// n!
	//-------- mod p
	//r!(n-r)!

	return ( (fac[n] * inverse(fac[r], p)) % p * inverse(fac[n - r], p)) % p;
}

void solve() {
	preprocess();

	int n = 10, r = 2;
	cout << ncrmodp(n, r, p) << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;
	solve();
	return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
int fact[N], invfact[N];

int binpow(int a, int b, int m) {
	// a^b % m
	int res = 1;
	while (b) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b /= 2;
	}

	return res;
}

int modinv(int x) {
	return binpow(x, MOD - 2, MOD);
}

void precompute() {

	fact[0] = fact[1] = 1;
	for (int i = 2; i <= N; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}

	invfact[N - 1] = modinv(fact[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		invfact[i] = invfact[i + 1] * (i + 1);
		invfact[i] %= MOD;
	}
}

int nCr(int x, int y) {
	if (y > x)
		return 0;

	int num = fact[x];
	num %= MOD;
	num *= invfact[y];
	num %= MOD;
	num *= invfact[x - y];
	num %= MOD;

	return num;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	precompute();
	cout << nCr(15, 10);

	return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------
