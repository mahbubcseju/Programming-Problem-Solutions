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
#define mx 400007
#define md 1000000007

#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
int sq;
bool cmp(pair<P, int> x, pair<P, int>  y)
{
    if(x.xx.xx / sq == y.xx.xx / sq)
    {
        return x.xx.yy < y.xx.yy;
    }
    else return (x.xx.xx / sq) < (y.xx.xx / sq);
}
ll mp[2046577];
ll res;
int k;
void add(int x)
{
    int h = x ^ k;

    res +=(ll) mp[h];
     mp[x]++;

}
void del(int x)
{
    int h = x ^ k;
     mp[x]--;
    res -= (ll)mp[h];

}

int main()
{
    //mp[0]=1;
    int n, m;
    I3(n, m, k);
    int ar[n + 22];
    int dp[n + 2];
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        I(ar[i]);
        dp[i] = dp[i - 1] ^ ar[i];
        // cout<<" "<<dp[i];
    }
    //  NL;
    pair< P, int> a[m + 2];
    sq = sqrt(n) + 1;
    for(int i = 1; i <= m; i++)
    {
        I2(a[i].xx.xx, a[i].xx.yy);
        a[i].yy = i;
    }
    sort(a + 1, a + m + 1, cmp);
    ll ans[m + 2];
//    int st =a[1].xx.xx;
//    int en=a[1].xx.yy;
//    for(int i=st;i<=en;i++)
//    {
//        add(dp[i]);
//    }
//    ans[a[1].yy]=res;
//    //cout<<res<<endl;
    int st, en;
    st = en = 0 ;
    mp[0]++;
    // add(0);
    for(int i = 1; i <= m; i++)
    {
        int x = a[i].xx.xx;
        int y = a[i].xx.yy;
        x--;
      //  cout<<x<<y<<endl;
        while(x < st)
        {
            st--;
            add(dp[st]);
        }
        while(x > st)
        {
            del(dp[st]);
            st++;
        }
        while(y < en)
        {
            del(dp[en]);
            en--;
        }
        while(y > en)
        {
            en++;
            add(dp[en]);
        }
        ans[a[i].yy] = res;
    }
    for(int i = 1; i <= m; i++)cout << ans[i] << endl;
    return 0;
}
