/***************************************
    codeforces = topcoder = sahedsohel
    IIT,Jahangirnagar University(42)
****************************************/
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define inf (INT_MAX/10)
#define linf (LLONG_MAX)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define fl(c,i,n) for(i=c;i<n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define pb push_back
#define pp pop_back()
#define aov(a) a.begin(),a.end()
#define mpr make_pair
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define xx first
#define yy second
#define mxv(a) *max_element(aov(a))
#define mnv(a) *min_element(aov(a))
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define pii pair< int , int >
#define pll pair< ll , ll >
#define pcs(a) printf("Case %d: ", a)
#define nl puts("")
#define endl '\n'
#define dbg(x) cout<<#x<<" : "<<x<<endl

template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}

int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int toLlint(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}


///int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,+1,0,1,0,-1}; // Hexagonal Direction   **
///int dy[]={-1,+1,1,0,-1,0}; //                       *#*
///                                                     **
///const double eps=1e-9;
///int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction

/*****************************************************************/
/// ////////////////////   GET SET GO    ////////////////////// ///
/*****************************************************************/

#define M 2000005
#define MD 1000000007LL
#define MX 2000012LL

int ts,kk=1;

#define intx(i,j,k,l) ((a[i]*b[j]-b[i]*a[j])*(a[k]-a[l])-(a[i]-a[j])*(a[k]*b[l]-b[k]*a[l]))/((a[i]-a[j])*(b[k]-b[l])-(b[i]-b[j])*(a[k]-a[l]))
#define inty(i,j,k,l) ((a[i]*b[j]-b[i]*a[j])*(b[k]-b[l])-(b[i]-b[j])*(a[k]*b[l]-b[k]*a[l]))/((a[i]-a[j])*(b[k]-b[l])-(b[i]-b[j])*(a[k]-a[l]))
#define dst(u,v,x,y) sqrt((x*1.0-u*1.0)*(x*1.0-u*1.0)+(y*1.0-v*1.0)*(y*1.0-v*1.0))
#define area(i,j,k) ((ll)x[i]*y[j]+(ll)x[j]*y[k]+(ll)x[k]*y[i]-(ll)y[i]*x[j]-(ll)y[j]*x[k]-(ll)y[k]*x[i])

ll n;
vector< pll >rs;

ll chk2(ll x,ll y)
{
    ull q;
    q=(x*x-x)*(2LL*x-1LL);
    q/=6LL;

    q-=((x+y)*(x*x-x))/2LL;

    q+=x*x*y;
//    cout<<x<<" "<<y<<" "<<q<<endl;
    return (ll)q;
}

bool chk(ll x)
{
    if(x*x>n)return 0;
    ll lo,hi,md,q;


    lo=x;
    hi=linf/(x*x);

    while(lo<=hi)
    {
        md=(lo+hi)/2LL;
        q=chk2(x,md);
        if(q==n)
        {
            rs.pb(pll(x,md));
            if(md==x)return 1;
            rs.pb(pll(md,x));
            return 1;
        }
        if(q<n)
            lo=md+1;
        else
            hi=md-1;
    }
    return 0;
}

int main()
{
    int t,i,j,k;



    scanf("%lld",&n);
    if(n==1LL)
    {
        printf("1\n1 1\n");
        return 0;
    }

    rs.pb(pll(1LL,n));
    rs.pb(pll(n,1LL));
    for(i=2;i<M;i++)
    {
        chk(i);
    }
    sort(aov(rs));
    printf("%d\n",(int)rs.size());
    f(i,rs.size())printf("%lld %lld\n",rs[i].xx,rs[i].yy);

    return 0;
}
