
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
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200009
#define md 1000000007

#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
int a[mx + 2];
vector<int>v[mx + 2];
int lev[mx + 2];
P in[mx + 2];
int sz;
void dfs(int i, int p, int le)
{
    in[i].xx = ++sz;
    lev[sz] = le;
    for (int j = 0; j < v[i].size(); j++)
    {
        int x = v[i][j];
        if (x != p)
        {
            dfs(x, i, le + 1);
        }
    }
    in[i].yy = sz;
}
int ans[mx + 2];
int op[mx + 2];
int main()
{
    sz = -1;
    int n, m;
    I2(n, m);
    for (int i = 0; i < n; i++)I(a[i]);
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        I2(x, y);
        x--;
        y--;
        v[x].PB(y);
        v[y].PB(x);
    }
    dfs(0, -1, 1);
    int s = int(sqrt(n + .0)) + 1;
    for (int i = 0; i < n; i++)
    {
        int x = in[i].xx;
        //ans[x / s] += a[i];
        op[x]=a[i];
    }
    while (m--)
    {
        int x;
        I(x);
        if (x == 1)
        {
            int u, v;
            I2(u, v);
            int xx = in[u - 1].xx;
            if (lev[xx] % 2 == 0)v *= -1;
            int st = in[u - 1].xx;
            int en = in[u - 1].yy;
            int nl = st / s;
            int nr = en / s;
            if (nl == nr)
            {
                for (int i = st; i <= en; i++)op[i] += ((lev[i] % 2 == 1 ? 1 : -1) * v);
                continue;
            }
            for (int i = st, j = (nl + 1) * s - 1; i <= j; i++)op[i] += (lev[i] % 2 == 1 ? 1 : -1) * v;
            for (int i = nl + 1; i < nr ; i++)
            {
                ans[i] += v;
            }
            for (int i = nr * s; i <= en; i++)op[i] += (lev[i] % 2 == 1 ? 1 : -1) * v;
        }
        else
        {
            int y;
            I(y);
            int xx=in[y-1].xx;
            int re=op[xx]+ans[xx/s]*((lev[xx]%2==1)?1:-1);
            PI(re);
        }
    }
    return 0;
}
