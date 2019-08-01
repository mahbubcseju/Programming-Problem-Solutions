
/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000ll
#define md 1000000007
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////
int main()
{
//    ll n;
//    L(n);
//    ll a[n + 2];
//    ll sum = 0;
//    fr(i, 1, n)
//    {
//        L(a[i]);
//        sum += a[i];
//    }
//    sort(a + 1, a + n + 1);
//    ll res=a[n]*n-sum;
//    PL(res);
//    NL;
    ll n, m, c, x, y;
    L2(n, m);
    L3(c, x, y);
    ll ar[n + 2][m + 2];
    SET(ar);
    if (n == 1)
    {
        ll x1 = c / m;
        ll b = x1;
        if (c % m != 0)b++;
        PC("%lld %lld %lld\n", b, x1, (y <= c % m) ? b : x1);
        return 0;
    }
    else if (n == 2)
    {
        ll x1 = c / (n * m);
        ll b = x1;
        if (c % (n * m) != 0)b++;
        ll cop = (x - 1) * m + y;
        //cout<<cop<<Endl;
        PC("%lld %lld %lld\n", b, x1, (cop <= c % (n * m)) ? b : x1);
        return 0;
    }


    for (ll i = 1; i <= min(m, c); i++)ar[1][i]++;
    ll  res = c - min(m, c);
    ll ko = m * 2 + (n - 2) * m * 2;
    ll kop = res / ko;
    for (ll i = 1; i <= n; i++)
    {
        fr(j, 1, m)
        {
            if (i == 1 || i == n)ar[i][j] += kop;
            else ar[i][j] += (2 * kop);
        }
    }
    res %= ko;
    for (ll i = 2; i <= n; i++)
    {
        fr(j, 1, m)
        {
            if (res)
            {
                ar[i][j]++;
                res--;
            }
        }
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (res)
            {
                ar[i][j]++;
                res--;
            }
        }
    }
    ll ma = 0;
    ll mi = 2e18;
    fr(i, 1, n)fr(j, 1, m)
    {
        ma = max(ma, ar[i][j]);
        mi = min(mi, ar[i][j]);
    }
    PC("%lld %lld %lld\n", ma, mi, ar[x][y]);
    return 0;
}
