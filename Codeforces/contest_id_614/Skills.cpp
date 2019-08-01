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
#define mx 100000
#define md 1000000007ll

#define maxp 1000004
typedef pair<ll , ll >P;
typedef vector<int >V;

////////define value/////
int main()
{

    ll n,m,k,p,co;
    L2(n,m);
    L(p);
    L2(k,co);
    P a[n+2];
    ll num[n+2];
    for(ll i=1; i<=n; i++)
    {
        L(a[i].xx);
        a[i].yy=i;
        num[i]=a[i].xx;
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)num[i]=a[i].xx;
    //sort(num+1,num+n+1);

    ll ar[n+2];
    ll sz=0;
    ar[0]=0;
    for(ll i=n; i>=1; i--)
    {
        ++sz;
        ar[sz]=ar[sz-1];
        ar[sz]+=(m-a[i].xx);
    }
    ll cum[n+2];
    cum[0]=0;
    for(ll i=1; i<=n; i++)
    {
        cum[i]=cum[i-1]+num[i];
    }
    ll res=0;
    ll boro=0;
    ll choto=0;
    for(ll i=0; i<=n; i++)
    {
        ll x=co-ar[i];
        if(x<0)continue;
        //cout<<i<<" "<<x<<endl;
        ll lo=0;
        ll hi=m;
        ll sum=0;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            //if(i==1)cout<<mid<<"lool ";
            ll ok=lower_bound(num+1,num+n+1,mid)-num;
            ok--;
            ll cop=n-i;
            ok=min(ok,cop);
            //  ll cop=n-i;
            //if(n==i)cout<<num[1]<<endl;
            ll xo=(ok)*mid-cum[ok];
            // if(i==1) cout<<ok<<" "<<xo<<endl;
            if(xo<=x)
            {
                lo=mid+1;
                sum=max(mid,sum);
            }
            else hi=mid-1;
        }
        // cout<<p<<"lool "<<sum<<endl;
        if(i*p+sum*k>=res)
        {

            res=i*p+sum*k;
            boro=i;
            choto=sum;
        }


    }
    cout<<res<<endl;
    // cout<<boro<<choto<<endl;
    sz=0;
    for(ll i=n; i>=1; i--)
    {
        ++sz;
        if(sz<=boro)a[i].xx=m;
    }
    sz=0;
    for(ll i=1; i<=n; i++)
    {
        sz++;
        //if(sz>choto)break;
        if(a[i].xx<choto)a[i].xx=choto;
    }
    for(int i=1; i<=n; i++)
    {
        num[a[i].yy]=a[i].xx;
    }
    for(int i=1; i<=n; i++)
    {
        if(i==1)cout<<num[i];
        else cout<<" "<<num[i];
    }
    NL;
    // cout<<res<<boro<<choto<<endl;
    return 0;
}
