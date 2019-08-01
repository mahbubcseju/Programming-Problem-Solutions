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
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}


template <class T>bool ISLEFT(T a, T b, T c) {
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 2100000007ll
#define  mx 200004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
int a[mx+2];

int n,m,k;

int fr[mx+2];
ll res;
void add(int in)
{
    res+=fr[in];
    fr[in]++;
}
void del(int in)
{
    fr[in]--;
    res-=fr[in];
}
ll vis[50][mx+2];
void hishab(ll s,ll e,ll x,ll y)
{
    if(s>e)
    {
        return;
    }
    ll mid=(s+e)/2;
    ll fl=mid;
    ll  ret=2e18;

    for(int j=mid+1;j<=e;j++)del(a[j]);

    for(ll i=x; i<=min(mid-1,y); i++)
    {
        del(a[i]);
        ll res1=res+vis[k][i];
        //if(i==1&&mid==2)cerr<<res1<<" "<<res<<x<<" "<<mid<<Endl;
        if(res1<ret)
        {
            ret=res1;
            fl=i;
        }
    }

    if(fl==0)cerr<<s<<" "<<e<<"x "<<x<<" "<<y<<Endl;
    vis[k+1][mid]=ret;
    for(int j=x;j<=min(mid-1,y);j++){
      add(a[j]);
    }
    del(a[mid]);
    hishab(s,mid-1,x,fl);

    for(int j=mid;j<=e;j++)add(a[j]);

    for(int j=x;j<=fl-1;j++)del(a[j]);

    hishab(mid+1,e,fl,y);

    for(int j=x;j<=fl-1;j++)add(a[j]);
}


int main()
{
    I2(n,m);

    fr(i,1,n)
    I(a[i]);



    fr(i,1,n)
    {
        add(a[i]);
        vis[1][i]=res;
       // cerr<<res<<Endl;
    }


    for(int j=2;j<=m;j++)
    {
        k=j-1;
        hishab(1,n,1,n);
    }

    PL(vis[m][n]),NL;


    return 0;
}
