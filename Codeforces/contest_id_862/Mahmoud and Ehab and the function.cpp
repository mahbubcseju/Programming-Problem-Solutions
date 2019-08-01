/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
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
#define pi 2.0*acos(0.0)
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

#define md 1000000007ll
#define  mx 1000004
#define base 193ll

typedef pair<ll,ll >P;
//////////////////////////
/////////////////////////

int main()
{
    int n,m,k;
    I3(n,m,k);
    ll a[n+2];
    fr(i,1,n)L(a[i]);
    ll b[m+2];
    fr(j,1,m)L(b[j]);


    ll bt[n+2];
    ll cum[n+2];
    SET(bt);
    SET(cum);

    bt[0]=-1;
    for(int i=1; i<=n; i++)
    {
        bt[i]=bt[i-1]*-1;
        cum[i]=cum[i-1]+bt[i]*a[i];
    }

    ll ct[m+2];
    ct[0]=1;
    ll cu[m+3];
    SET(cu);
    for(int i=1; i<=m; i++)
    {
        ct[i]=ct[i-1]*-1;
        cu[i]=cu[i-1]+ct[i]*b[i];
    }


    ll br[m-n+10];
    ll ans=2e18;
    for(int i=0; i<=m-n; i++)
    {
        br[i+1]=cum[n];
        int x=1+i;
        ll kop=cu[n+i]-cu[x-1];
        br[i+1]=br[i+1]+kop*ct[x]*(-1);

        ans=min(ans,abs(br[i+1]));
        // cerr<<i<<" "<<br[i+1]<<endl;
    }
    sort(br+1,br+m-n+2);
    // cerr<<zr.x<<" "<<zr.y<<" "<<bzr.x<<" "<<bzr.y<<endl;
    PL(ans),NL;
    ll  res=0;
    while(k--)
    {
        ll l,r,va;
        L3(l,r,va);
        if((l-r+1)%2==0)
        {

        }
        else
        {
            ll nu=va;
            nu=nu*bt[l];
            res+=nu;

        }
        //cerr<<zr.x<<" "<<zr.y<<" "<<bzr.x<<" "<<bzr.y<<endl;
        ll kop=2e18;
        int in=lower_bound(br+1,br+m-n+2,-res)-br;
        for(int j=max(1,in-100); j<=min(m-n+1,in+100); j++)kop=min(kop,abs(br[j]+res));
        PL(kop),NL;
    }


    return 0;
}
