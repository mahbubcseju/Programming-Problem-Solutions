/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
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
#define mx 200000ll
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////
vector<P>v[mx+2];
int lev[mx+2];
int n;
int tab[mx+2][22];
void dfs(int u,int p,int l)
{
    lev[u]=l;
    //cout<<lev[u]<<" "<<u<<endl;
    tab[u][0]=p;
    for(int i=0; i<v[u].size(); i++)
    {
        int x=v[u][i].x;
        if(x==p)continue;
        //  cout<<x<<Endl;
        dfs(x,u,l+1);

    }
}
void sparse()
{
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(tab[j][i-1]!=-1)
            {
                tab[j][i]=tab[tab[j][i-1]][i-1];
            }
        }
    }
}
int lca(int x,int y)
{
    // cout<<x<<" "<<y<<endl;
    if(lev[x]>lev[y])swap(x,y);


    for(int i=20; i>=0; i--)
    {
        if(tab[y][i]!=-1&&lev[tab[y][i]]>=lev[x])y=tab[y][i];

    }

    if(x==y)return x;

    for(int i=20; i>=0; i--)
    {
        //   cout<<tab[x][i]<<" lolo "<<tab[y][i]<<" "<<x<<" "<<y<<" "<<lev[x]<<" "<<lev[y]<<endl;
        if(tab[x][i]>-1&&tab[x][i]!=tab[y][i])
        {
            x=tab[x][i];
            y=tab[y][i];
        }
    }
    return tab[x][0];
}
int ar[mx+2];

int ans[mx+2];

void df(int u,int p)
{

    //cout<<u<<" "<<ar[u]<<endl;
    for(int i=0; i<v[u].size(); i++)
    {
        int x=v[u][i].x;
        if(x==p)continue;
        df(x,u);

        ar[u]+=ar[x];

      //  cout<<ar[u]<<" "<<ar[x]<<" "<<x<<" "<<u<<endl;
        ans[v[u][i].y]=ar[x];
    }

}
int main()
{


    I(n);
    fr(i,1,n-1)
    {
        int x,y;
        I2(x,y);
        v[x].PB(mk(y,i));
        v[y].PB(mk(x,i));
    }
    // lol;
    SETR(tab);
    dfs(1,-1,1);
    //lol;

    sparse();
    //lol;

    int q;
    I(q);
    while(q--)
    {
        int x,y;
        I2(x,y);
        int lc=lca(x,y);
         // cout<<lc<<endl;
        ar[x]++;
        ar[y]++;

        ar[lc]--;
        ar[lc]--;

    }
    df(1,-1);

    fr(i,1,n-1)
    {
        if(i>1)PC(" ");
        PI(ans[i]);
        // lol;

    }
    NL;

    return 0;
}
