
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
#define pi 2.0*acos(0.0)
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
template <class T> inline T MDINV(T a, T M)
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
template <class T>ll ISLEFT ( T a, T b, T c)
{
    return (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) ); //Uporer dike //A,b,c, x okkher ordera sorted
}
#define mx 400000
#define md 1000000007

#define maxp 1000004
typedef pair<ll , ll >P;
typedef vector<int >V;

////////define value/////
double dis(P x, P y)
{
    double  xo = ((x.xx - y.xx) * (x.xx - y.xx) + (x.yy - y.yy) * (x.yy - y.yy));
    double f = xo;
    f = sqrt(f);
    return f;
}
int main()
{
    ll n;
    P x;
    L3(n, x.xx, x.yy);
    P a[n + 2];
    double mx1=0,mi=1e20;
    for (int i = 0; i < n; i++)
    {
        L2(a[i].xx, a[i].yy);
        mx1=max(mx1,dis(x,a[i]));
        mi=min(mi,dis(x,a[i]));

    }
    //cout<<mx1<<" "<<mi<<endl;
    a[n] = a[0];
    for(int i=0;i<n;i++)
    {
        P u=a[i];
        P v=a[(i+1)%n];
        double xo=0.5*fabs((double)ISLEFT(x,u,v));
        double r=dis(x,u);
        double o=dis(u,v);
        double p=dis(x,v);
        double ro=min(r,p);
        double co=max(r,p);

        if(ro*ro+o*o>co*co)
        {
            double ho=(xo*2.0)/o;
           // cout<<i<<" "<<ho<<endl;
            mi=min(mi,(xo*2.0)/o);
        }
    }
    //cout<<mx1<<" "<<mi<<endl;
   // cout<<pi<<endl;
   double xp=pi*(mx1*mx1-mi*mi);
    PC("%.10lf\n",xp);
    return 0;
}

