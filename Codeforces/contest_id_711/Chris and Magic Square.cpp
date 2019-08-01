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
#define Endl "\n"
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
#define mx 2000000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
int main()
{
    ll n,m;
    L(n);
    ll ar[n+2][n+2];
    fr(i,1,n)
    fr(j,1,n)L(ar[i][j]);
    vector<ll >v[3];
    ll res=0;
    ll ans=0,fl2=0;
    ll an=0,fl3=0;
    fr(i,1,n)
    {

        ll sum=0,su=0;
        bool fl=0,fl1=0;
        fr(j,1,n)
        {
            sum+=ar[i][j];
            su+=ar[j][i];
            if(ar[i][j]==0)fl=1;
            if(ar[j][i]==0)fl1=1;
        }
        ans+=ar[i][i];
        if(ar[i][i]==0)fl2=1;
        an+=ar[i][n-i+1];
        if(ar[i][n-i+1]==0)fl3=1;
        v[0].PB(sum);
        v[1].PB(fl);
        v[0].PB(su);
        v[1].PB(fl1);
        res=max(res,sum);
        res=max(res,su);

    }
    v[0].PB(ans);
    v[1].PB(fl2);
    res=max(res,ans);
    v[0].PB(an);
    v[1].PB(fl3);
    res=max(res,an);
    ll ans1=0;
    fr(i,0,SZ(v[0])){
    if(v[1][i]==1){
        ans1=res-v[0][i];
        break;
    }
    }
    bool kl=0;
    fr(i,0,SZ(v[0])){
    if(v[1][i]==0){
        if(v[0][i]!=res)kl=1;
        }
        else
        {
            if(v[0][i]+ans1!=res)kl=1;
        }
    }
    if(n==1)PI(1);
    else if(!kl&&ans1>=1)PC("%lld\n",ans1);
    else PI(-1);

    return 0;
}
