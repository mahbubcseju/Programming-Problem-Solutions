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

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
pair<P,int>ar[102];
pair<P,int> a[100+2];
int n;
int DP[102][20003];
int dp(int i,int j)
{
    if(i>n)
    {
        return 0;
    }

    int &ret=DP[i][j];
    if(ret!=-1)return ret;
    ret=0;
    ret=max(ret,dp(i+1,j));

    int x=a[i].y;

    if(j<=a[i].xy)
        ret=max(ret,ar[x].y+dp(i+1,j+ar[x].xx));
    return ret;
}
vector<int>v;
void print(int i,int j,int ans)
{
    if(i>n)return;
    if(ans==dp(i+1,j))
        print(i+1,j,ans);
    else
    {
        int x=a[i].y;
        ans-=ar[x].y;
        v.PB(a[i].y);
        print(i+1,j+ar[x].xx,ans);

    }


}
int main()
{


    I(n);


    fr(i,1,n)
    {
        I3(ar[i].xx,ar[i].xy,ar[i].y);
        a[i]=mk(mk(ar[i].xy,ar[i].xy-1-ar[i].xx),i);
    }
    sort(a+1,a+n+1);
    //fr(i,1,n)cerr<<a[i],.y<<" "<<i<<Endl;
    SETR(DP);

    int ans=dp(1,0);
    PI(ans),NL;
    print(1,0,ans);
    int l=v.size();
    PI(l),NL;

    for(int i=0; i<l; i++)
    {
        if(i>0)PC(" ");
        PI(v[i]);
    }
    if(l>0)
        NL;


    return 0;
}
