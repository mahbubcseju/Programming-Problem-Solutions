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
#define  mx 7000000
#define base 193ll

typedef pair<ll,ll >P;
//////////////////////////
/////////////////////////

int ar[mx+2];
   int ara[70000+2][100];
int main()
{
   int n;
   I(n);



   int sz=0;

   char a[12];
   for(int i=1;i<=n;i++)
   {
       SC("%s",a+1);

       for(int i1=1;i1<=9;i1++)
       {
           int su=1;
           for(int j=i1;j<=9;j++)
           {
               su=su*10+a[j]-'0';
               ara[i][++ara[i][0]]=su;
               ar[++sz]=su;
           }
       }
       sort(ara[i]+1,ara[i]+ara[i][0]+1);
   }
   sort(ar+1,ar+sz+1);
int arb[12];
   for(int i=1;i<=n;i++)
   {
       int nu=2e9;
       for(int j=1;j<=ara[i][0];j++)
       {
           int koy=upper_bound(ar+1,ar+sz+1,ara[i][j])-lower_bound(ar+1,ar+sz+1,ara[i][j]);
           int boy=upper_bound(ara[i]+1,ara[i]+ara[i][0]+1,ara[i][j])-lower_bound(ara[i]+1,ara[i]+ara[i][0]+1,ara[i][j]);

           if(boy==koy)
           {
               nu=min(nu,ara[i][j]);
           }
       }
       int ho=0;
       int k=0;
       while(nu>9)
       {
           arb[++k]=nu%10;
           nu/=10;
       }

       frr(j,k,1)PI(arb[j]);
       NL;
   }

    return 0;
}
