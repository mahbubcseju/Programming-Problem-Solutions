
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

typedef pair<int,int > P;
typedef vector<int> V;

////////define value/////
int main() {
    int n,m;
    I2(n,m);
    vector<int>a[n+2];
    fr(i,1,m) {
        int x,y;
        I2(x,y);
        a[x].PB(y);
        a[y].PB(x);
    }
    int w;
    I(w);
    vector< pair<int,P> >v;
    fr(i,1,w) {
        int x,y,z;
        I3(x,y,z);
        v.PB(mk(z,mk(x,y)));
    }
   // lol;
    sort(v.begin(),v.end());
    int q;
    I(q);
    int vis[n+2];
    int qu[n+2];
    int qf,qs;
    int l=v.size();
    while(q--) {
        int x,y,z;
        I3(x,y,z);
        SETR(vis);
        qf=qs=0;
        qu[qs++]=x;
        vis[x]=0;
       // lol;
        while(qf<qs) {
            int f=qu[qf++];
            for(int j=0; j<a[f].size(); j++) {
                int u=a[f][j];
                if(vis[u]==-1) {
                    vis[u]=vis[f]+1;
                    qu[qs++]=u;
                }
            }
        }
        //lol;
        int lo=0;
        int hi=n+2;
        int res=n+2;
        while(lo<=hi) {
            int mid=(lo+hi)/2;
            //
            int ans=z;
            int ko=y;
            bool fl=0;
            for(int i=0; i<l; i++) {
                int x=v[i].yx;
                if(vis[x]>-1&&vis[x]<=mid) {
                    int mi=min(v[i].yy,ko);
                    mi=min(mi,ans/v[i].x);
                    ans-=mi*v[i].x;
                    ko-=mi;
                }
                if(!ko) {
                    fl=1;
                    break;
                }
            }
            //
            if(fl) {
                hi=mid-1;
                res=mid;
            } else lo=mid+1;
        }
      //  cout<<q<<" "<<res<<Endl;
        if(res>n)PI(-1);
        else PI(res);
    }
    return 0;
}
