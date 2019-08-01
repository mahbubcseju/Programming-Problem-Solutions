/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
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
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 100000
//#define md 1000000007ll
#define maxp 2050180000

typedef pair<ll ,ll> P;
typedef vector<int> V;

////////define value/////
string s[2][mx+2];
int sz[mx+2];
bool check(int i,int j,int k)
{
    int x=min(sz[i-1],sz[i]);

    fr(l,0,x-1)
    {
        if(s[j][i-1][l]<s[k][i][l])return true;
        if(s[j][i-1][l]>s[k][i][l])return false;

    }

    if(sz[i-1]<=sz[i])return true;
    else return false;
}
int main()
{

    int n;
    I(n);
    ll a[n+2];
    fr(i,1,n)L(a[i]);

    fr(i,1,n)cin>>s[0][i];

    fr(i,1,n)
    {
        s[1][i]=s[0][i];
        sz[i]=s[1][i].size();
        reverse(s[1][i].begin(),s[1][i].end());
    }
    ll dp[2][n+2];
    ll kol=2e18;
    fr(i,0,n)dp[0][i]=dp[1][i]=kol;
    dp[0][1]=0;
    dp[1][1]=a[1];
    fr(i,2,n)
    {
        fr(j,0,1)
        {
            fr(k,0,1)
            {
                ll re=0;
                if(k==1)re=a[i];
                bool fl=check(i,j,k);
               // cout<<fl<<endl;
               // if(j==1&&k==0)cout<<fl<<" "<<re<<" "<<dp[j][i-1]<<endl;
                if(fl)
                dp[k][i]=min(dp[k][i],re+dp[j][i-1]);
            }
        }
    }
    ll res=min(dp[0][n],dp[1][n]);
    if(res==kol)res=-1;
    PL(res);




    return 0;
}
