
/*********************************
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
#define D double
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
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
typedef pair<ll, ll >P;
typedef vector<int>V;
#define mx 100000
#define md 1000000000000007ll
#define mx1 (1<<25)
#define mx2 (1<<15)

/////////////////////////////
////////////////////////////
int main()
{


    int n,m;
    I2(n,m);
    int a[n+2][n+2];
    SET(a);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        I2(x,y);
        a[x][y]=1;
        a[y][x]=1;
    }
    int res[n+2];
    int vis[n+2];
    for(int i=1;i<=n;i++)res[i]=vis[i]=mx*1000;

    res[1]=0;
    int bol[n+2];
    SET(bol);
    queue<int>q;
    q.push(1);
    bol[1]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(i==f)continue;
            if(a[i][f]==1&&bol[i]==0)
            {
                bol[i]=1;
                res[i]=min(res[i],res[f]+1);
                q.push(i);
            }
        }

    }
    q.push(1);
    SET(bol);
    bol[1]=1;
    vis[1]=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(i==f)continue;
            if(a[i][f]==0&&bol[i]==0)
            {
                bol[i]=1;
                vis[i]=min(vis[i],vis[f]+1);
                q.push(i);
            }
        }

    }
    if(vis[n]==mx*1000||res[n]==mx*1000)PI(-1);
    else PC("%d\n",max(vis[n],res[n]));

    return 0;
}
