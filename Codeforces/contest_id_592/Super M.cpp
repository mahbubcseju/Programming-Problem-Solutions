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
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
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
        if (ch>='0' && ch<='9') break;
    }
    while (1)
    {
        n = n*10 + (ch - '0');
        ch = getchar();
        if (ch<'0' || ch>'9')   break;
    }
    return (ng?-n:n);
}
typedef pair<int,int >P;
#define mx 1000000
#define md 1000000007ll
#define mx1 1000000000000

/////////////////////////////
////////////////////////////
vector<int>v[mx+3];
int vis[mx+2];
int ans2;
int bol[mx+2];
int  dfs(int u,int j)
{
    vis[u]=j;
  //cout<<u<<endl;
  int ro=0;
    for(int i=0; i<v[u].size(); i++)
    {
        int x=v[u][i];

        if(vis[x]==-1)
        {//if(x==2)cout<<vis[x]<<endl;
           // ans2+=2;
           int x1=dfs(x,j+1);
          // if(x==2)
          ro+=x1;
         // cout<<x1<<endl;
           if(x1!=0){ans2+=2;
         //  lol;
          // cout<<" "<<x<<endl;
          // cout<<x1<<endl;
           }
        }
    }
    //if(u==2)cout<<bol[u]<<endl;
    return bol[u]+ro;
}
int main()
{
    ans2=0;
   // SET(ans2);
    int n,m;
    I2(n,m);
    for(int i=1; i<n; i++)
    {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);
    }
    int a[m+2];
    SETR(vis);
    int y=mx,sum=-1;
    for(int i=1; i<=m; i++)
    {
        I(a[i]);
        bol[a[i]]=1;
        if(i==1){
            dfs(a[i],0);

            }
       if(vis[a[i]]>sum)
       {
           sum=vis[a[i]];
           y=a[i];
       }
       else if(vis[a[i]]==sum) y=min(y,a[i]);
    }
    SETR(vis);
    dfs(y,0);

    int ans=0;
    int in=mx;
    sum=-1;
    for(int i=1;i<=m;i++)
    {
        ans+=vis[a[i]]*2;
      //  cout<<vis[a[i]]<<endl;

        if(vis[a[i]]>sum)
        {
            in=a[i];
            sum=vis[a[i]];
        }
        else if(vis[a[i]]==sum) in=min(in,a[i]);
    }
   // cout<<ans2<<endl;
    ans=ans2-vis[in];
   PI(min(y,in));
    PI(ans);


    return 0;
}
