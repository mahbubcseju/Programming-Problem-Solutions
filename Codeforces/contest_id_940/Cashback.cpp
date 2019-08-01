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
template <class T> inline T mul(T p, T e, T M) {
    ll ret = 0;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
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

#define md 1000000007ll
#define  mx 2000004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////
 int ar[mx+2];
int tr[mx*2];
void up(int no,int s,int e)
{
   if(s==e){
    tr[no]=ar[s];
    return ;
   }
   int mid=(s+e)>>1;
   up(no*2,s,mid);
   up(no*2+1,mid+1,e);
   tr[no]=min(tr[no*2],tr[no*2+1]);
}
int qu(int no,int s,int e,int st,int en)
{
    if(s>=st&&e<=en)return tr[no];

    int mid=(s+e)>>1;

    if(mid>=en)return qu(no*2,s,mid,st,en);
    else if(mid<st)return qu(no*2+1,mid+1,e,st,en);
    else
    {

        return min(qu(no*2,s,mid,st,mid),qu(no*2+1,mid+1,e,mid+1,en));
    }
}
int main() {
    int n,m;
    I2(n,m);


    ll cum[n+2];
    ll cnt=0;
    cum[0]=0;
    for(int i=1;i<=n;i++)
    {
        I(ar[i]);
      cum[i]=cum[i-1]+ar[i];
//        for(int j=i;j<=n;j+=m)
//        {
//            cnt++;
//        }
    }
//    cerr<<cnt<<endl;

    ll DP[n+2];
    up(1,1,n);
    DP[0]=0;
    for(int i=1;i<=n;i++)
    {
        DP[i]=DP[i-1]+ar[i];
        if(i>=m)
        {
           DP[i]=min(DP[i],DP[i-m]+cum[i]-cum[i-m]-qu(1,1,n,i-m+1,i));
        }
    }
    PC("%lld\n",DP[n]);


    return 0;
}
