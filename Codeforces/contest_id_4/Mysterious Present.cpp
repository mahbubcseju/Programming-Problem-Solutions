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
#define mx 1000000ll
#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]

typedef pair<int ,int > P;
typedef vector<int> V;



int main()
{
    int n,m,k;
    I3(n,m,k);

    pair<P,int> a[n+2];
    fr(i,1,n)I2(a[i].xx,a[i].xy),a[i].y=i;
    sort(a+1,a+n+1);
    a[0]=mk(mk(m,k),0);

    int dp[n+2];
    fr(i,0,n)dp[i]=-2e9;

    dp[0]=0;
    int ans[n+2];
    SET(ans);
    int res=0,in;
    fr(i,0,n)
    {
        fr(j,i+1,n)
        {
           // cout<<a[i].xx<<" "<<a[i].xy<<" "<<a[j].xx<<" "<<a[j].xy<<endl;
            if(a[j].xx>a[i].xx&&a[j].xy>a[i].xy)
            {
                int x=dp[i]+1;

                if(x>dp[j])
                {
                    dp[j]=x;

                  //  cout<<j<<" "<<x<<endl;
                    if(dp[j]>res)
                    {
                        res=dp[j];
                        in=j;
                    }
                    ans[j]=i;
                }
            }
        }
    }
    PI(res);
    vector<int>v;
    while(in>0)
    {
        v.PB(a[in].y);
        in=ans[in];
    }
    reverse(v.begin(),v.end());
 fr(i,0,res-1)
 {
     if(i!=0)PC(" ");
     PC("%d",v[i]);
 }
 NL;


    return 0;
}
