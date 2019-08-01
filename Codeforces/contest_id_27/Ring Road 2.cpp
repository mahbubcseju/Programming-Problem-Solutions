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
#define frv(i,a)  for(int i=0;i<a.size();i++)
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
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define MX 200002ll
#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , int > P;
typedef vector<P> V;
//////////////////////////
/////////////////////////
#define maxn 20002

struct two_sat {

    vector <int> out[maxn];
    vector <int> in[maxn];
    vector <int> stk;
    vector <int> n_com[maxn];

    int   component[maxn];
    bool  vis [maxn];

    int n;

    void init(int n) {
        this->n= n;
        n<<=1;
        for(int i=0; i<=n; i++) {
            out[i].clear();
            in[i].clear();
            n_com[i].clear();
            vis[i]=false;
            //component[i]=-1;
        }
//        SET(component);
        stk.clear();
    }
    // X implies Y ( if X happens , then Y also happens )
    void add_edge(int x,int y) {
        out[x].push_back(y);
        in[y].push_back(x);
    }

    // base = (0 -> present) ,(1->absent)
    // (basex,basey) = (0,0) -> either x or y must be present
    // (basex,basey) = (1,1) -> either x or y must be absent
    // (X|Y) = 1
    void add_or(int x,int basex,int y,int basey) {
        x= x*2+basex;
        y= y*2+basey;
        add_edge(x^1,y);
        add_edge(y^1,x);
    }
    // either x or y should be present
    void add_con_1(int x,int y) {
        add_or(x,0,y,0);
    }
    // if x is present, then no condition on y, but if x is absent y should be absent
    void add_con_2(int x,int y) {
        x *=2;
        y *=2;
        add_edge(x^1,y^1);
        add_edge(y,x);
    }
    //either x or y must be absent.
    void add_con_3(int x,int y) {
        add_or(x,1,y,1);
    }
    // either x or y must be present but not both.
    void add_con_4(int x,int y) {
        add_or(x,0,y,0);
        add_or(x,1,y,1);
    }
    // both may be true
    // (x present | y present ) =true
    void add_con_5(int x,int y) {
        add_or(x,0,y,0);
    }
    // (x present | y absent) = true
    void add_con_6(int x,int y) {
        add_or(x,0,y,1);
    }
    // (x absent | y present) = true  // x in set 2 y in set 1
    void add_con_7(int x,int y) {
        add_or(x,1,y,0);
    }
    // (x absent | y absent) = true
    void add_con_8(int x,int y) {
        add_or(x,1,y,1);
    }
    // if x is present then y must be present
    void add_con_9(int x,int y) {
        add_edge((x<<1) ,(y<<1));
        add_edge((y<<1)+1,(x<<1)+1) ;
    }
    // x must be absent
    void add_con_10(int x) {
        add_edge((x<<1),(x<<1)+1);
    }
    // if x is absent then y must be absent
    void add_con_11(int x,int y) {
        add_edge((x<<1)+1,(y<<1)+1);
        add_edge(y<<1,x<<1);
    }
    // x must be present
    void add_con_12(int x) {
        add_edge((x<<1)+1,(x<<1));
    }
    // remove the last event(Y) that has been implies by (X)
    void remove_edge(int x,int y) {
        out[x].pop_back();
        in[y].pop_back();
    }

    void remove_or(int x,int basex,int y,int basey) {
        x= x*2+basex;
        y= y*2+basey;
        remove_edge(x^1,y);
        remove_edge(y^1,x);
    }

    void dfs1 (int x) {
        vis [x] = true;
        for ( int i=0; i<out[x].size(); ++i ) {
            int &y=out[x][i];
            if ( !vis [ y ] )
                dfs1(y);
        }
        stk.push_back (x);
    }
    void dfs2 (int x, int c) {
        vis [x] = false;
        component [x] = c;
        n_com[c].PB( x );
        for (int i=0; i<in[x].size(); ++i ) {
            int &y = in[x][i];
            if ( vis [y] )
                dfs2 ( y, c);
        }
    }


    bool solve() {
        int n=this->n*2;

        for ( int i = 0; i < n; i++ )
            n_com[i].clear();
        stk.clear();

        for ( int i = 0; i < n; i++ )
            if ( !vis [i] )
                dfs1 (i);

        int c= 0;
        for ( int i = stk.size () - 1; i >= 0; i-- )
            if ( vis [ stk [i] ] )
                dfs2 (stk [i], c++ );

        for (int i=0; i<n; ++i) {
            if ( component[i] == component[i^1] ) {
                return false;
            }
        }
        return true;
    }

    int check[MX];

    void dfs3( int u ,int ss ) {
        for (int i=0; i<n_com[u].size(); ++i) {
            check[ n_com[u][i] ]=ss;
        }
        for (int i=0; i<n_com[u].size(); ++i) {
            if ( check[ n_com[u][i] ^1 ]== -1 )
                dfs3( component[ n_com[u][i] ^1 ] , !ss );
        }
    }


    vector<int> solution() {
        for (int i=0; i<2*n; ++i) {
            check[i] = -1;
        }
        for ( int i = stk.size () - 1; i >= 0; i-- ) {
            if ( check[ stk[i] ] == -1 ) {
                dfs3( component[ stk[i] ], 0 );
            }
        }
        vector<int> ret;
        for (int i=0; i<2*n; i+=2) {
            if ( check[ i ] == 1 ) {
                ret.PB(i/2);
            }
        }
        return ret;
    }

} solver;


int main() {


    int n,m;
    I2(n,m);

    P a[m+2];

    solver.init(m);
    fr(i,1,m) {
        I2(a[i].x,a[i].y);
        if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
    }

    fr(i,1,m) {
        fr(j,i+1,m) {
            if(a[i].x<a[j].x&&a[j].x<a[i].y&&a[i].y<a[j].y)solver.add_con_4(i-1,j-1);
            else if(a[j].x<a[i].x&&a[i].x<a[j].y&&a[j].y<a[i].y)solver.add_con_4(i-1,j-1);
        }
    }


    if(!solver.solve())PC("Impossible\n");
    else {
        vector<int>v =solver.solution();
        for(int i=1; i<=m; i++) {
            bool fl=0;
            for(int j=0; j<v.size(); j++) {
                if(v[j]==i-1)fl=1;
            }

            if(!fl)PC("i");
            else PC("o");

        }
        NL;
    }


    return 0;
}
