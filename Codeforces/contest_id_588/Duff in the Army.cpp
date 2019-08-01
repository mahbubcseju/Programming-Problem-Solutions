
/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define D double
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB(a) push_back(a)
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
template<typename T> T in()
{
    char ch;
    T n = 0;
    bool ng = false;
    while (1)
    {
        ch = getchar();
        if (ch == '-')
        {
            ng = true;
            ch = getchar();
            break;
        }
        if (ch >= '0' && ch <= '9') break;
    }
    while (1)
    {
        n = n * 10 + (ch - '0');
        ch = getchar();
        if (ch < '0' || ch > '9')   break;
    }
    return (ng ? -n : n);
}
#define mx 100000ll
#define md 1000000007ll
typedef pair<int, int >P;
typedef vector<int >V;

////////define value/////
V a[mx + 3];
int lev[mx + 3];
int par[mx + 2][23];
int mi[mx + 2][23][50];
bool bl[mx+2];
void dfs(int u, int p, int le)
{
    lev[u] = le + 1;
    par[u][0] = p;
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if(v != p)
        {
            dfs(v, u, le + 1);
        }
    }
}
int lca(int u, int v)
{
    if(lev[u] < lev[v])swap(u, v);
    for(int i = 20; i >= 0; i--)
    {
        if(par[u][i] != -1 && lev[par[u][i]] >= lev[v])
        {
            u = par[u][i];
        }
    }
    if(u == v)return u;
    // cout<<par[5][1]<<par[4][0]<<endl;
    //  cout<<u<<v<<endl;
    for(int i = 20; i >= 0; i--)
    {
        if(par[u][i] != -1 && par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int main()
{
    int n, m, q;
    I3(n, m, q);
    for(int i = 1; i <= n - 1; i++)
    {
        int x, y;
        I2(x, y);
        a[x].PB(y);
        a[y].PB(x);
    }
    SETR(par);
    // dfs(1, -1, 0);
    for(int i = 1; i <= m; i++)
    {
        int x;
        I(x);
        int ho = mi[x][0][0];
        mi[x][0][++ho] = i;
        sort(mi[x][0] + 1, mi[x][0] + ho + 1);
        if(ho > 10)ho = 10;
        mi[x][0][0] = ho;
    }
    dfs(1, -1, 0);
    int s, s1;
    //bool bl[n + 2];
    SET(bl);
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(par[j][i - 1] != -1)
            {
                par[j][i] = par[par[j][i - 1]][i - 1];
                //  if(j==5)cout<<par[5][i]<<"jkfc4e"<<endl;
                s = mi[j][i - 1][0];
                for(int k = 1; k <= s; k++)
                {
                    if(bl[mi[j][i][k]] == 0)
                    {
                        mi[j][i][k] = mi[j][i - 1][k];
                        bl[mi[j][i][k]] = 1;
                    }
                }
                s1 = mi[par[j][i - 1]][i - 1][0];
                for(int k = 1; k <= s1; k++)
                {
                    if(bl[mi[par[j][i - 1]][i - 1][k]] == 0)
                    {
                        mi[j][i][++s] = mi[par[j][i - 1]][i - 1][k];
                    }
                }
                sort(mi[j][i] + 1, mi[j][i] + s + 1);
                for(int k = 1; k <= s; k++)bl[mi[j][i][k]] = 0;
                mi[j][i][0] = min(s, 10);
            }
            else
            {
                s = mi[j][i - 1][0];
                for(int k = 1; k <= s; k++)
                {
                    mi[j][i][k] = mi[j][i - 1][k];
                }
                mi[j][i][0] = s;
            }
        }
    }
    int ans[100];
    for(int i = 1; i <= q; i++)
    {
        int u, v, a1;
        I3(u, v, a1);
        int xo = lca(u, v);
        //cout<<xo<<endl;
        int sz = 0;
        for(int j = 20; j >= 0; j--)
        {
            if(par[u][j] != -1 && lev[par[u][j]] >= lev[xo])
            {
               // lol;
                for(int l = 1; l <= mi[u][j][0]; l++)
                {
                    if(bl[mi[u][j][l]] == 0)
                    {
                        ans[++sz] = mi[u][j][l];
                        bl[mi[u][j][l]] = 1;
                    }
                }
                sort(ans + 1, ans + sz + 1);
                for(int l = 11; l <= sz; l++)
                {
                    bl[ans[l]] = 0;
                }
                if(sz > 10)sz = 10;
                u = par[u][j];
            }
        }
        for(int j = 20; j >= 0; j--)
        {
            if(par[v][j] != -1 && lev[par[v][j]] >= lev[xo])
            {
              //  lol;
                for(int l = 1; l <= mi[v][j][0]; l++)
                {
                    if(bl[mi[v][j][l]] == 0)
                    {
                        ans[++sz] = mi[v][j][l];
                        bl[mi[v][j][l]] = 1;
                    }
                }
                sort(ans + 1, ans + sz + 1);
                for(int l = 11; l <= sz; l++)
                {
                    bl[ans[l]] = 0;
                }
                if(sz > 10)sz = 10;
                v = par[v][j];
            }
        }
       // cout<<sz<<" "<<xo<<endl;
        for(int l = 1; l <= mi[xo][0][0]; l++)
        {
            if(bl[mi[xo][0][l]] == 0)
            {
                ans[++sz] = mi[xo][0][l];
            }
        }
        sort(ans + 1, ans + sz + 1);
        for(int l=1;l<=sz;l++)bl[ans[l]]=0;
        cout<<min(a1,sz)<<endl;
        for(int l = 1; l <= min(a1, sz); l++)
        {
            PC("%d ", ans[l]);
        }
        if(min(a1,sz)!=0)
        NL;
    }
    return 0;
}
