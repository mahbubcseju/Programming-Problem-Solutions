/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
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
template <class T> inline T MDINV(T a, T M)
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
#define mx 100000
#define md 1000000007

#define maxp 1000004
typedef pair<ll , ll >P;
typedef vector<int >V;

////////define value/////
ll d[2 * mx + 2];
ll h[2 * mx + 3];
ll sum[2 * mx + 3];
pair<P, ll>tr[mx * 8 + 3];
void build(ll no, ll s, ll e)
{
    if (s == e)
    {
        tr[no] = mk(mk(2 * h[s] - sum[s - 1], 2 * h[s] + sum[s - 1]), 0);
        return ;
    }
    ll mid = (s + e) / 2;
    build(no * 2, s, mid);
    build(no * 2 + 1, mid + 1, e);
    tr[no].xx.xx = max(tr[no * 2].xx.xx, tr[no * 2 + 1].xx.xx);
    tr[no].xx.yy = max(tr[no * 2].xx.yy, tr[no * 2 + 1].xx.yy);
    tr[no].yy = max(tr[no * 2].xx.xx + tr[no * 2 + 1].xx.yy, max(tr[no * 2].yy, tr[no * 2 + 1].yy));
}

pair<P, ll>query(ll no, ll s, ll e, ll st, ll en)
{
    if (s >= st && e <= en)
    {
        return tr[no];
    }
    ll mid = (s + e) / 2;
    if (mid >= en)
    {
        return query(no * 2, s, mid, st, en);
    }
    else if (mid < st)
    {
        return query(no * 2 + 1, mid + 1, e, st, en);
    }
    else
    {
        pair<P, ll> x = query(no * 2, s, mid, st, mid);
        pair<P, ll> y = query(no * 2 + 1, mid + 1, e, mid+1, en);
        pair<P, ll>xy;
        xy.xx.xx = max(x.xx.xx, y.xx.xx);
        xy.xx.yy = max(x.xx.yy, y.xx.yy);
        xy.yy = max(x.xx.xx + y.xx.yy, max(x.yy, y.yy));
        return xy;
    }
}

int main()
{
    int n,m;
    I2(n,m);
    for (ll i = 1; i <= n; i++)
    {
        L(d[i]);
        d[i + n] = d[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        L(h[i]);
        h[i + n] = h[i];
    }
    for (ll i = 1; i <= 2 * n; i++)
    {
        sum[i] = sum[i - 1] + d[i];
    }
    build(1,1,2*n);
    while(m--)
    {
        ll a,b;
        L2(a,b);
        if(a>b)PL(query(1,1,2*n,b+1,a-1).yy);
        else
        {
            PL(query(1,1,2*n,b+1,a+n-1).yy);
        }
    }

    return 0;
}


