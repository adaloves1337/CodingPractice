#include <bits/stdc++.h>
using namespace std;
#define out(x) cerr << #x << " = " << x << " "; 
#define outln(x) cerr << #x << " = " << x << endl; 
#define outarr(a,l,r) cerr << #a << "[" << l << "," << r << "] = ";  for (int _i = l; _i <= r; ++_i) cerr << a[_i] << " "; cerr << endl;
#define Siz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define ls (p<<1)
#define rs (p<<1|1)
#define mid ((l+r)>>1)
template<class T> void read(T &x)
{
	x = 0; int f = 0;
	char c = getchar();
	while (c < 0 || c > 9) f |= (c == -), c = getchar();
	while (c >=0 && c <=9) x = (x << 1) + (x << 3) + (c^48), c = getchar();
	if (f) x = -x;
}
const int N = 1e6+5 , mod = 998244353;
template<class T> bool umax(T &x , T y) {return y>x ? x=y, 1: 0; }
template<class T> bool umin(T &x , T y) {return y<x ? x=y, 1: 0; }
template<class T> void uadd(T &x , T y) {x = (x + y) % mod; }
template<class T> void umul(T &x , T y) {x = (x * y) % mod; }
int qpow(int x , int y = mod-2)
{
	int res = 1;
	for (int i = 0; (y>>i) > 0; ++i, x = 1ll*x*x%mod)
	 if (y>>i&1) res = 1ll * res * x % mod;
	return res;
}
int pi[N],iv[N];
void init(int n)
{
	pi[0] = 1;
	for (int i = 1; i <= n; ++i) pi[i] = 1ll * pi[i-1] * i % mod;
	iv[n] = qpow(pi[n]);
	for (int i = n-1; i >= 0; --i) iv[i] = 1ll * iv[i+1] * (i+1) % mod;
}
int C(int n,int m)
{
	if (m > n || m < 0) return 0;
	return 1ll * pi[n] * iv[m] % mod * iv[n-m] % mod;
}
int n;
ll a[N],b[N];
ll calc(int i) { return (a[i]+b[i])/(b[i]+1); }
 
void rmain()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) b[i] = 0;
	ll sum, ans ;
	sum = ans = 0;
	for (int i = 1 ; i <= n; ++i) {
		ll lst = a[i];
		for (int j = i-1; j >= 1; --j) {
			if (calc(j)-lst > 0) {
				uadd(sum, mod - 1ll*b[j]*j%mod);
				b[j] = a[j]/lst-1;
				umax(b[j],0ll);
				b[j] += (calc(j) > lst);
				b[j] += (calc(j) > lst);
				lst = a[j]/(b[j]+1);
				uadd(sum, 1ll*b[j]*j%mod);
			}
			else {
				break;
			}
		}
		uadd(ans,sum);
	}
	cout << (ans+mod)%mod << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--) rmain();
	return 0; 
}
