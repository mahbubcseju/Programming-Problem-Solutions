/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h>
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
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
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
template <class T> inline T MDINV(T a, T M)
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
#define mx 5000000
#define md 10000000000007ll

#define maxp 100000000000000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
int main()
{
    int n;
    I(n);
    P a[2*100+2];
    P co[2*100+2];
    SET(co);
    for(int i=1; i<=2*n; i++)
    {
        I(a[i].xx);
        a[i].yy=i;
        co[a[i].xx].xx++;
        co[a[i].xx].yy=a[i].xx;

    }
    sort(co+1,co+101);
    //reverse(co+1,co+101);
    sort(a+1,a+2*n+1);
    P b[2*n+1];
    int sz1=0;

    for(int j=100; j>=1; j--)
    {
        if(co[j].xx%2)

            for(int i=1; i<=2*n; i++)
            {
                if(co[j].yy==a[i].xx)

                {

                    b[++sz1].xx=a[i].xx;
                    b[sz1].yy=a[i].yy;
                }

            }
    }
     for(int j=100; j>=1; j--)
    {
        if(co[j].xx%2==0)

            for(int i=1; i<=2*n; i++)
            {
                if(co[j].yy==a[i].xx)

                {

                    b[++sz1].xx=a[i].xx;
                    b[sz1].yy=a[i].yy;
                }

            }
    }
//cout<<sz1<<endl;
    int ar[100*2+2];
    SET(ar);
    int br[100*2+2];
    int cr[100*2+2];
    int sz=0;
    int s=0;
    for(int i=1; i<=2*n; i++)
    {
        if(i%2==1)
        {
            ar[b[i].yy]=1;
            br[++sz]=b[i].xx;
        }
        else
        {
            ar[b[i].yy]=2;
            cr[++s]=b[i].xx;
        }
    }
    set<int>st;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int x=br[i]*100+cr[j];
            st.insert(x);
            //  cout<<x<<endl;
        }
    }
    cout<<st.size()<<endl;
    for(int i=1; i<=2*n; i++)
    {
        PC("%d ",ar[i]);
    }

    return 0;
}
