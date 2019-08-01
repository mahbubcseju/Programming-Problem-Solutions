#include<bits/stdc++.h>
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


template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 100004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

#define max_node 6004

int ar[100];
int sz;
ll DP[100][11][1050][2];
ll go(int i,int di,int musk,bool fl)
{
    if(i==0)
    {
        if(musk==0)return 1;
        return 0;
    }

    ll &ret=DP[i][di][musk][fl];
    if(ret!=-1)return ret;


    ret=0;
    int lo=0;
    if(!fl)lo=1;
    for(int j=lo;j<=di;j++)
    {
        ret+=go(i-1,di,musk^(1<<j),1);
    }

    return ret;

}
ll dp(int b)
{

    if(sz==0)return 0;
    ll res=0;
    reverse(ar+1,ar+sz+1);
    ll dp[100];
    dp[0]=1;
    ll ans=0;
    for(ll k=1;k<sz;k++)
    {
        ans+=go(k,b-1,0,0);
    }
    int mu=0;

    for(int k=1;k<=sz;k++)
    {
       // if(ar[k]==0)continue;
        int lo=0;
        if(k==1)lo=1;
        for(int l=lo;l<ar[k];l++)
        {

            int y=mu^(1<<l);
            ans+=go(sz-k,b-1,y,1);

        }
        mu^=(1<<ar[k]);

       // cerr<<ar[k]<<" "<<sz<<Endl;
    }
    //cout<<Endl;

    if(mu==0)ans++;

    return ans;

}
int main()
{
    SETR(DP);
    int tc;
    I(tc);
    while(tc--)
    {
        int b;
        I(b);

        ll n,m;
        L2(n,m);
        sz=0;

        while(m)
        {
            ar[++sz]=m%b;
            m/=b;

        }
        ll kop=dp(b);

        sz=0;
        n--;
        while(n)
        {

            ar[++sz]=n%b;
            n/=b;
        }
      // cerr<<kop<<Endl;
        kop-=dp(b);
        PL(kop),NL;



    }

    return 0;
}
