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
    if (((a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y)) == 0)return 0; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 1;
}

#define md 1000000007ll
#define  mx 1000000
#define base 193ll

typedef pair<ll,ll >P;
//////////////////////////
/////////////////////////

int pr[mx+2];
bool vis[mx+2];
int sz;
void seive()
{
    for(int i=2;i<=mx;i++)
    {
        if(vis[i]==0)
        {
           pr[++sz]=i;
           for(int j=i*2;j<=mx;j+=i)
                vis[j]=1;
        }
    }
}
int main()
{
    seive();


    int n,m,k;
    I3(n,m,k);


    int ar[n+2];
    fr(i,1,n)I(ar[i]);
    sort(ar+1,ar+n+1);
    ll cum[n+2];
cum[0]=0;
    int ma=0;
    fr(i,1,n)
    {
        cum[i]=cum[i-1]+ar[i];
        ma=max(ar[i],ma);
    }
    ll ans=2e18;
    for(int i=1;i<=sz;i++)
    {
        ll res=0;
        for(int j=pr[i];j<=ma+pr[i];j+=pr[i])
        {

           int x=upper_bound(ar+1,ar+n+1,j)-ar;
           x--;
           int y=upper_bound(ar+1,ar+n+1,j-pr[i])-ar;
           if(y>x)continue;
           if(y>n)continue;

         //  cerr<<pr[i]<<" "<<j<<x<<" "<<y<<Endl;
           int lo=y,hi=x;
           int pos=x+1;
           while(lo<=hi)
           {
               int mid=(lo+hi)/2;
               int ko=j-ar[mid];
               ll kos=(ll)k*(ll)ko;
               if(kos<=m)
               {
                   hi=mid-1;pos=mid;
               }
               else {
                lo=mid+1;
               }
           }
          // cerr<<pos<<" "<<res<<" ";
           res+=(ll)(pos-y)*(ll)m;
          // cerr<<res<<" ";
           ll kop=(ll)(x-pos+1)*(ll)j;
           ll cu=cum[x]-cum[pos-1];
           res+=(kop-cu)*(ll)k;
          // cerr<<res<<endl;

        }
        ans=min(ans,res);


    }
    PL(ans),NL;




    return 0;
}
