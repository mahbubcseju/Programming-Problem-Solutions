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
#define  mx 2000004
#define base 193ll

typedef pair<ll,ll >P;
//////////////////////////
/////////////////////////

int main()
{
    int n;
    I(n);
    int a[n+2];

    int ar[n+2];
    SET(ar);
    fr(i,1,n)
    {
        I(a[i]);
        ar[a[i]]++;
    }

    int st=1;
    vector<int>v;
    for(int i=1; i<=n; i++)
    {
        if(ar[i]==0)v.PB(i);

    }
    int vis[n+2];
    SET(vis);
    int koy=0;
    for(int i=0; i<v.size(); i++)
    {
        while(st<=n)
        {
            if(vis[a[st]]==0&&ar[a[st]]==1)
            {

                vis[a[st]]=1;
                ar[a[st]]--;
                st++;

            }
            else if(vis[a[st]]==1&&ar[a[st]]>=1)
            {
                ar[a[st]]--;
                a[st]=v[i];
                st++;

                break;
            }
            else if(vis[a[st]]==0&&a[st]<v[i])
            {
                vis[a[st]]=1;
                ar[a[st]]--;
                st++;
            }
            else if(vis[a[st]]==0&&a[st]>v[i])
            {
                ar[a[st]]--;
                a[st]=v[i];

                st++;
                break;
            }

        }
    }
    PI((int)v.size()),NL;

    fr(i,1,n)
    {
        if(i>1)PC(" ");
        PI(a[i]);

    }
    NL;



    return 0;
}
