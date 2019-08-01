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
    if(((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int,int  > P;
typedef vector<int> V;

////////define value/////

int qu(P a[],int l,int co)
{


    int ans=-1;
    if(l<=1)return ans;
    sort(a+1,a+l+1);

    int cum[l+2];
cum[0]=0;
    for(int i=1; i<=l; i++)
    {
        cum[i]=max(cum[i-1],a[i].y);
    }
    for(int i=1; i<=l; i++)
    {
        int c1o=co-a[i].x;
        int f=upper_bound(a+1,a+l+1,mk(c1o,20000000))-a;


        f=min(f-1,i-1);

        if(f<1)continue;
        ans=max(ans,a[i].y+cum[f]);

    }

    return ans;
}
int main()
{
    int n,c,d;
    I3(n,c,d);

    int sum=-1,res=-1;

    P ar[n+2],br[n+2];
    int l=0,l1=0;

   // cout<<n<<endl;
    int x,y;
    char ch[4];
    for(int i=1; i<=n; i++)
    {

       // cout<<i<<" "<<n<<endl;
       I2(x,y);
        SC("%s",ch+1);

       // cout<<x<<" "<<y<<ch[1]<<i<<n<<endl;

        if(ch[1]=='C')
        {
            if(y<=c)
            {
                ar[++l]=mk(y,x);
                sum=max(sum,x);
            }
        }
        else
        {
            if(y<=d)
            {
                res=max(res,x);
                br[++l1]=mk(y,x);
            }
        }

    }


    int ans=0;
    if(sum>-1&&res>-1)ans=sum+res;
    ans=max(ans,qu(ar,l,c));
    ans=max(ans,qu(br,l1,d));
    PI(ans);




    return 0;
}
