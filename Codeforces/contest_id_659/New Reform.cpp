
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
#define mx 100000
#define md 1000000007ll

#define maxp 1000004
typedef pair<int, int>P;
typedef vector<int >V;

////////define value/////
vector<int>v[mx + 3];
int up[mx + 3];
int lo[mx + 3];
stack<int>st;
int sz;
int vis[mx + 3];
int res;
void func(int n, int p)
{
    st.push(n);
    up[n] = lo[n] = ++sz;
    vis[n] = sz;
    for (int j = 0; j < v[n].size(); j++)
    {
        int x = v[n][j];
        if (x == p)continue;
        if (vis[x] == 0)
        {
            func(x, n);
            up[n] = min(up[n], up[x]);
        }
        else
        {
            up[n] = min(up[n], up[x]);
        }
    }
    //cout<<up[n]<<" "<<lo[n]<<endl;
    if (up[n] == lo[n])
    {
        int x1 = 0;
        int xo = 0;
        do
        {
            x1 = st.top();
           // cout<<x1<<" ";
            st.pop();
            xo++;
        }

        while (x1 != n);
        //cout<<endl;
        res = max(res, xo);
    }
}
int main()
{
    sz = 0;
    int n, m;
    I2(n, m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        I2(x, y);
        v[x].PB(y);
        v[y].PB(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            res = 0;
            func(i, 0);
            if (res ==1)ans++;
        }
    }
    PI(ans);
    return 0;
}
