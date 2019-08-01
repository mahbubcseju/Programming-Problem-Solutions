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
#define  mx 200000
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////
int n,m;
int a[mx+2], k;
double vis[52][mx+2];
double sum[mx+3],pro[mx+3],ans[mx+3];
void hishab(int s,int e,int x,int y)
{
    if(s>e)
    {
        return;
    }
    int mid=(s+e)/2;
    int  fl=0;
    double  ret=2e18;
    for(ll i=x; i<=min(mid-1,y); i++)
    {
        double cer=sum[i];
     //   if(i==1&&mid==4)cerr<<cer<<endl;
        cer=(cer*(pro[mid]-pro[i]));
        cer=(ans[mid]-ans[i])-cer;
        double res=cer+vis[k][i];

      //  if(i==1&&mid==4)cerr<<cer<<endl;
        if(res<=ret)
        {
            ret=res;
            fl=i;
        }
    }
   // cerr<<fl<<" "<<mid<<ret<<endl;
    vis[k+1][mid]=ret;
    if(s==e)return ;
    hishab(s,mid-1,x,fl);
    hishab(mid+1,e,fl,y);
}
int main()
{

    I2(n,m);
    fr(i,1,n){I(a[i]);
    sum[i]=sum[i-1]+a[i];
    pro[i]=pro[i-1]+1.0/((double)a[i]);
    }
    for(int i=1;i<=n;i++){

     ans[i]=ans[i-1]+sum[i]*(1.0/((double)a[i]));
     vis[1][i]=ans[i];
  //  cerr<<vis[1][i]<<endl;
    }

    for(int i=2;i<=m;i++)
    {
        k=i-1;
        hishab(1,n,1,n);

    }

    PC("%.10lf\n",vis[m][n]);



    return 0;
}
