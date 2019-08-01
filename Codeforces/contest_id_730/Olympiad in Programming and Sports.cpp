// ==========================================================================
//
//                Starting by the name of Almighty Allah
//
// ==========================================================================

#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>

using namespace std;

#define LL                          long long
#define ULL                         unsigned long long
// I/O
#define SS(s)                       scanf("%s",s)

#define I(X)                        scanf("%d",     &(X))
#define II(X, Y)                    scanf("%d%d",   &(X), &(Y))
#define III(X, Y, Z)                scanf("%d%d%d", &(X), &(Y), &(Z))

#define IL(X)                       scanf("%lld", &X)
#define IIL(X,Y )                   scanf("%lld%lld", &X,&Y)
#define IIIL(X,Y,Z)                 scanf("%lld%lld%lld", &X,&Y,&Z)

#define ID(x)                       scanf("%lf",&x)
#define IID(x,y)                    scanf("%lf%lf",&x,&y)
#define IIID(x,y,z)                 scanf("%lf%lf%lf",&x,&y,&z)

#define DI(X)         int X;        I(X);
#define DII(X, Y)     int X, Y;     II(X,Y)
#define DIII(X, Y, Z) int X, Y, Z;  III(X,Y,Z);

#define DIL(X)        LL X;         IL(X)
#define DIIL(X,Y)     LL X,Y;       IIL(X,Y)
#define DIIIL(X,Y,Z)  LL X,Y,Z;     IIIL(X,Y,Z)

#define DDI(x)        double x;     ID(x);
#define DDII(x,y)     double x,y;   IID(x,y);
#define DDDII(x,y,z)  double x,y,z; IIID(x,y,z);

#define PI(x)                       printf("%d\n",      x)
#define PII(x,y)                    printf("%d %d\n",   x,y)
#define PIII(x,y,z)                 printf("%d %d %d\n",x,y,z)

#define PIL(x)                      printf("%lld\n",          x)
#define PIIL(x,y)                   printf("%lld %lld\n",     x,y)
#define PIIIL(x,y,z)                printf("%lld %lld %lld\n",x,y,z)

// LOOP
#define rep(i,a,b)                  for(int i=a;i<=b;i++)
#define rev(i,a,b)                  for(int i=a;i>=b;i--)
#define repv(i,a)                   for(int i=0;i<(int)a.size();i++)
#define revv(i,a)                   for(int i=((int)a.size())-1;i>=0;i--)

#define FS(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)                       for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PV(a)                       for(int i=0;i<(int)a.size();i++) printf("%d%c",a[i],(i+1==(int)a.size() ? '\n': ' '));
// array initialization
#define MEM(a,val)                  memset(a,val,sizeof(a));
#define SET(a)                      memset(a,-1,sizeof a)
#define CLR(a)                      memset(a,0,sizeof a)
// min-max
#define Max(a,b)                    (a>b?a:b)
#define Min(a,b)                    (a<b?a:b)
#define _Max(a,b,c)                 Max(a,Max(b,c))
#define _Min(a,b,c)                 Min(a,Min(b,c))
#define MAXV(a)                      (*max_element(all(a)))
#define MINV(a)                      (*min_element(all(a)))

#define FastMax(x,y)                ((((y-x)>>(32-1))&(x^y))^y)
#define FastMin(x,y)                ((((y-x)>>(32-1))&(x^y))^x)

#define SQR(n)          ((n)*(n))

#define all(a)          a.begin(),a.end()
#define PB              push_back
#define NL              puts("");
#define pline           cout << "_________________________" << endl;
// pair
#define X               first
#define Y               second
// binary search
#define LB(a,x)         (lower_bound(all(a),x)-a.begin()) // Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
#define UB(a,x)         (upper_bound(all(a),x)-a.begin()) // Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
template<typename T> T  In()   {  char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }
#define SI(X)           X=In<int>()
#define SII(X,Y)        X=In<int>(),Y=In<int>()
#define SIII(X,Y,Z)     X=In<int>(),Y=In<int>(),Z=In<int>()
#define SL(X)           X=In<LL>()
#define SLL(X,Y)        X=In<LL>(),Y=In<LL>()
#define SLLL(X,Y,Z)     X=In<LL>(),Y=In<LL>(),Z=In<LL>()
// segment_tree
#define SEG             int mid=(s+e)>>1,l=(idx<<1),r=(l|1)
#define lchild          l,s,mid
#define rchild          r,mid+1,e
#define in(l,x,r)       ( l<=x && x<=r )
#define in2(r,c,x,y)    ( in(1,x,r) && in(1,y,c) )
// Bitwise-operation
#define countbit(x)     __builtin_popcount(x)
template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }
// mathematics
template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> T GCD(T a,T b)                     { if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T EUCLIDE(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}
LL Bigmod(LL base,LL power,LL _MOD)                      { LL ret=1;while(power){if(power & 1)ret=(ret*base)%_MOD;base=(base*base)%_MOD;power>>=1;}return ret;}
LL ModInverse(LL number,LL _MOD)                         { return Bigmod(number,_MOD-2LL,_MOD); }
// geometry
template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }
// Degree and Radian
const double PI = 2 * acos(0);
double DEG(double x) { return (180.0*x)/(PI*1.0);}
double RAD(double x) { return (x*(PI*1.0))/(180.0);}
// debug
void P_ARR(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<class T> inline void make_unique_vec( vector<T> &vec ){ sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); }
template<class T> inline void make_unique_arr( T *ar,int &n)   { sort(ar + 1, ar + n + 1); n = unique(ar + 1, ar + n + 1) - ar - 1; }
// for (map<int, int>::iterator it = mp.begin() , int cnt=0; it != mp.end(); it++) {  mp[it->first] = cnt++; }
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};                                    /// month
//int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };                                  /// 4 Direction
//int dir[9][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};       /// 8 direction
//int dir[9][2] = { {0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };    /// Knight Direction
//int dir[8][2] = { {0,0},{2,0},{1,1},{-1,1} ,{-2,0} , {-1,-1} ,{1,-1} };               /// Hexagonal Direction
// dir[][0] = x value, dir[][1] = y value
/// ======================================================================================================
#define  debug  0
#define  AA     if(debug)
#define  eps     (1e-7)
#define  pi      (2.0*acos(0.0)) //#define PI acos(-1.0)
// IO
#define  READ   freopen("C:\\Users\\PCNAME\\Desktop\\input.txt","r",stdin)
#define  WRITE  freopen("C:\\Users\\PCNAME\\Desktop\\output.txt","w",stdout)
#define  _cin   ios_base::sync_with_stdio(0); cin.tie(0);
//#define  FF      fflush(stdout) // use after printf (for interactive problem)
//#define  FFF     cout << flush  // use after cout (for interactive problem)
//              0123456789
#define  MX     100007
#define  MOD    1000000007LL
#define  inf    2000000007


#define maxn 6007
#define maxe 300007

struct  MinCostMaxFlow
{
    struct node
    {
        int from,to,next,cap;
        int cst;
    }
    edge[maxe];

    int  head[maxn];
    int  q[maxn],front,rear,avail,vn;
    int  in[maxn],pre[maxn];
    int  cost[maxn];
    bool vis[maxn];

    void init(int maxnode)
    {
        avail=0;
        vn=maxnode;
        memset(head,-1,sizeof(head));
    }

    void insert(int from,int to,int cap,int cst)
    {
        edge[avail].from=from;
        edge[avail].to=to;
        edge[avail].cap=cap;
        edge[avail].cst=cst;
        edge[avail].next=head[from];
        head[from]=avail++;

        edge[avail].from=to;
        edge[avail].to=from;
        edge[avail].cap=0;
        edge[avail].cst=-cst;
        edge[avail].next=head[to];
        head[to]=avail++;
    }

    bool spfa(int src,int des)
    {
        for(int i=0; i<=vn; i++) cost[i]=INT_MAX;

        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));

        cost[src]=0;
        pre[src]=-1;

        front=0,rear=1;
        q[front]=src;

        vis[src]=true;
        in[src]++;

        while(front!=rear)
        {
            int u=q[front++],v;
            front%=maxn;
            vis[u]=false;
            for(int i=head[u]; i!=-1; i=edge[i].next)
            {
                v=edge[i].to;
                if(edge[i].cap>0&&cost[v]>cost[u]+edge[i].cst)
                {
                    cost[v]=cost[u]+edge[i].cst;
                    pre[v]=i;
                    if(!vis[v])
                    {
                        q[rear++]=v;
                        rear%=maxn;
                        vis[v]=true;
                        in[v]++;
                        if(in[v]>vn) return false;
                    }
                }
            }
        }

        if(cost[des]<INT_MAX) return true;
        else return false;
    }


    pair<LL,LL> mincostmaxflow(int src,int des)
    {
        LL mincost=0,maxflow=0;
        int i,j;

        while( spfa(src,des) )
        {
            int flow=INT_MAX;

            for(i=pre[des]; i!=-1; i=pre[edge[i].from])
            {
                flow=min(flow,edge[i].cap);
            }

            maxflow+=flow;

            for(i=pre[des]; i!=-1; i=pre[edge[i].from])
            {
                edge[i].cap-=flow;
                edge[i^1].cap+=flow;
            }

            mincost+=((LL)cost[des]*(LL)flow);
        }

        return make_pair(mincost,maxflow);
    }

    void print(int src,int n) {
        int u=src,v;
        int flag = 0;
        for(int i=head[u]; i!=-1; i=edge[i].next) {

            int v   = edge[i].to;
            int cst = edge[i].cst;
            int cap = edge[i].cap;

            if(cap==1 && v>=n+1 && v<=n+n)
            {
                if(flag) printf(" "); flag = 1;
                printf("%d",v-n);
            }
        }
        NL;
    }


} MCMF;

int ar[MX];
int br[MX];



int main()
{
    DI(n);
    DI(p);
    DI(s);

    rep(i,1,n) I(ar[i]);
    rep(i,1,n) I(br[i]);

    int pool_p = n+n+1;
    int pool_s = n+n+2;
    int src = n+n+3;
    int des = n+n+4;

    MCMF.init(des);

    rep(i,1,n)
    {
        int s = i ;
        int e = i+n;
        MCMF.insert(s,e,1,0);

        MCMF.insert(e,pool_p,1,-1*ar[i]);
        MCMF.insert(e,pool_s,1,-1*br[i]);
        MCMF.insert(src,s,1,0);
    }

    MCMF.insert(pool_p,des,p,0);
    MCMF.insert(pool_s,des,s,0);

    pair<LL,LL> res = MCMF.mincostmaxflow(src,des);

    LL ret = res.first * -1;

    PIL(ret);

    MCMF.print(pool_p,n);
    MCMF.print(pool_s,n);











    return 0;
}
