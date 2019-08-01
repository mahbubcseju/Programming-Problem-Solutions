/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
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
template <class T> inline T mdINV(T a, T M)
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
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 1000004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

int INF = 1500000001 ;
struct dinic_maxflow
{

    struct edge
    {
        int a, b, cap, flow ;
        edge(int _a, int _b, int _c, int _d)
        {
            a = _a, b = _b, cap = _c, flow = _d;
        }
    } ;


    int n, s, t, d [ 30001 ], ptr [ 30001 ], q [ 30001 * 10 ] ;
    vector < edge > e ;
    vector < int > g [ 30001 ] ;

    void add_edge ( int a, int b, int cap )
    {
        edge e1 = edge( a, b, cap, 0 ) ;
        edge e2 = edge( b, a, 0, 0 ) ;
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }

    bool bfs ( )
    {
        int qh = 0, qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1, sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 )
        {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i )
            {
                int id = g [ v ] [ i ],
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap )
                {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }

    int dfs ( int v, int flow )
    {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] )
        {
            int id = g [ v ] [ ptr [ v ] ],
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed )
            {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    int dinic ( )
    {
        int flow = 0 ;
        for ( ;; )
        {
            if ( !bfs () )  break ;
            memset ( ptr, 0, sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) )
            {
                flow += pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    dinic_maxflow( int _n, int _s, int _t )
    {
        n = _n;
        s = _s;
        t = _t;
    }
};


int main()
{
    int n,m;
    I2(n,m);
    P a[m+2];


    fr(i,1,m)I2(a[i].x,a[i].y);

   // dinic_maxflow  dm=dinic_maxflow(n+m+2,0,n+m+1) ;


    int lo=0,hi=10000;
    int ans=0;
    while(lo<=hi)
    {

        int mid=(lo+hi)/2;

        dinic_maxflow  dm=dinic_maxflow(n+m+2,0,n+m+1) ;

        for(int i=1; i<=m; i++)
        {
            dm.add_edge(0,n+i,1);
            dm.add_edge(n+i,a[i].x,1);
            dm.add_edge(n+i,a[i].y,1);
        }

        fr(i,1,n)dm.add_edge(i,n+m+1,mid);
        if(dm.dinic()==m)
        {
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;

    }
    PI(ans),NL;

    dinic_maxflow  dm=dinic_maxflow(n+m+2,0,n+m+1) ;

    P ansd[m+2];

    for(int i=1; i<=m; i++)
    {
        dm.add_edge(0,n+i,1);
        ansd[i].x=dm.e.size();
        dm.add_edge(n+i,a[i].x,1);
        ansd[i].y=dm.e.size();
        dm.add_edge(n+i,a[i].y,1);
    }

    fr(i,1,n)dm.add_edge(i,n+m+1,ans);
    int x=dm.dinic();
  //  cerr<<x<<endl;

    fr(i,1,m)
    {

        if(dm.e[ansd[i].x].flow==1)PC("%d %d\n",a[i].x,a[i].y);
        else PC("%d %d\n",a[i].y,a[i].x);
    }






    return 0;
}
