
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
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
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
template <class T>string NTS(T Number) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber(const string &Text) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT(T a,T b,T c) {
    if(((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<ll,ll > P;
typedef vector<int> V;

////////define value/////
int main() {
    int n;
    I(n);
    P a[n+2];
    fr(i,1,n)L2(a[i].x,a[i].y);
    P ar[n+2];
    P br[n+2];
    SET(ar);
    SET(br);
    br[0]=mk(0,0);
    fr(i,1,n) {
        sort(br+1,br+i);
        bool fl=0;
        fr(j,1,i-1) {
            // cout<<br[j].x<<" "<<br[j].y<<" "<<a[i].x<<" "<<a[i].y<<Endl;
            ll x=a[i].x,y=a[i].x+a[i].y-1;
            if(x>=br[j].x&&x<=br[j].y||y>=br[j].x&&y<=br[j].y
                    ||br[j].x>=x&&br[j].x<=y||br[j].x>=x&&br[j].x<=y) {
                fl=1;
                break;
            }
        }
        // cout<<fl<<Endl;
        if(fl==0) {
            a[i].y=a[i].x+a[i].y-1;
            // cout<<a[i].x<<" "<<a[i].y<<endl;
            ar[i]=a[i],br[i]=a[i];
        } else {
            ll l=1;
            br[i]=mk(1e15,1215);
          //  cout<<i<<Endl;
            fr(j,1,i) {
                if(br[j-1].y+a[i].y<br[j].x) {
                    ar[i]=mk(br[j-1].y+1,br[j-1].y+a[i].y);
                    br[i]=ar[i];
                    break;
                }
            }
        }
    }
    fr(i,1,n)PC("%lld %lld\n",ar[i].x,ar[i].y);
    return 0;
}
