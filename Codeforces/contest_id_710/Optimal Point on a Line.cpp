
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
#define mx 400000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
ll ar[mx+2];
ll sum[mx+2];
int main()
{
    int n;
    I(n);


    sum[0]=0;
    fr(i,1,n)
    {
        L(ar[i]);

    }
    sort(ar+1,ar+n+1);
    fr(i,1,n)
    {
     sum[i]=sum[i-1]+ar[i];
    }
    if(n==1)PL(ar[1]);
    else
    {
        ll res=2e18;
        ll d=ar[1];
        fr(i,1,n-1)
        {
            ll lo=ar[i];
            ll hi=ar[i+1];
            ll ans=sum[n]-sum[i];
            ll an=2e18;
            fr(j,1,100)
            {

                ll mid1=lo+(hi-lo)/3;
                ll mid2=(hi-(hi-lo)/3);
                if(mid2<mid1)break;
                ll qu1=i*mid1-sum[i]+ans-(n-i)*mid1;
                ll qu2=i*mid2-sum[i]+ans-(n-i)*mid2;
                if(qu1<=qu2)
                {
                    hi=mid2;
                }
                else lo=mid1;
            }
            for(ll j=max(ar[i],lo-100);j<=min(ar[i+1],hi+100);j++)
            {
                ll so=i*j-sum[i]+ans-(n-i)*j;
                if(res>so){
                    res=so;
                    d=j;
                   // cout<<so<<d<<endl;
                }
            }
        }
        PL(d);
    }




    return 0;
}
