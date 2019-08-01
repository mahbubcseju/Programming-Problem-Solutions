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
#define mx 3000000
#define md 1000000007ll

#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
struct da
{
    int x,y,z;
    da()
    {

    }
    da(int _x,int _y,int _z)
    {
        x=_x,y=_y,z=_z;
    }
    bool operator<(const da &p)const
    {
        return z>p.z;
    }


};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
    int n,m;
    I2(n,m);
    char a[n+2][m+2];
    for(int i=1; i<=n; i++)
    {
        SC("%s",a[i]+1);
    }

    ll res[4][4];
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)res[i][j]=md;
    }
    //SETR(vis);
    priority_queue<da> q;


        ll vis[n+2][m+2];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='2')
            {
                vis[i][j]=0;
                q.push(da(i,j,0));
            }
            else vis[i][j]=md;
        }
    }
    int ho=md;
    while(!q.empty())
    {
        da p=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.x+dx[i];
            int y=p.y+dy[i];
            if(x>=1&&x<=n&&y>=1&&y<=m)
            {
                if(a[x][y]=='3')
                {
                    res[2][3]=min(res[2][3],vis[p.x][p.y]);
                }
                else if(a[x][y]=='1')
                {
                      res[2][1]=min(res[2][1],vis[p.x][p.y]);
                }
                else if(a[x][y]=='.')
                {
                    if(vis[x][y]>vis[p.x][p.y]+1)
                    {
                        vis[x][y]=vis[p.x][p.y]+1;
                        q.push(da(x,y,vis[x][y]));
                    }
                }
            }
        }

    }


        ll vis1[n+2][m+2];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='1')
            {
                vis1[i][j]=0;
                q.push(da(i,j,0));
            }
            else vis1[i][j]=md;
        }
    }
    while(!q.empty())
    {
        da p=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.x+dx[i];
            int y=p.y+dy[i];
            if(x>=1&&x<=n&&y>=1&&y<=m)
            {
                if(a[x][y]=='3')
                {
                    res[1][3]=min(res[1][3],vis1[p.x][p.y]);
                }
                else if(a[x][y]=='2')
                {
                      res[1][2]=min(res[1][2],vis1[p.x][p.y]);
                }
                else if(a[x][y]=='.')
                {
                    if(vis1[x][y]>vis1[p.x][p.y]+1)
                    {
                        vis1[x][y]=vis1[p.x][p.y]+1;
                        q.push(da(x,y,vis1[x][y]));
                    }
                }
            }
        }

    }

        ll vis2[n+2][m+2];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='3')
            {
                vis2[i][j]=0;
                q.push(da(i,j,0));
            }
            else vis2[i][j]=md;
        }
    }

    while(!q.empty())
    {
        da p=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.x+dx[i];
            int y=p.y+dy[i];
            if(x>=1&&x<=n&&y>=1&&y<=m)
            {
                if(a[x][y]=='2')
                {
                    res[3][2]=min(res[3][2],vis2[p.x][p.y]);
                }
                else if(a[x][y]=='1')
                {
                      res[3][1]=min(res[3][1],vis2[p.x][p.y]);
                }
                else if(a[x][y]=='.')
                {
                    if(vis2[x][y]>vis2[p.x][p.y]+1)
                    {
                        vis2[x][y]=vis2[p.x][p.y]+1;
                        q.push(da(x,y,vis2[x][y]));
                    }
                }
            }
        }

    }
    ll ans=md;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='.')
            {
                ans=min(ans,vis[i][j]+vis1[i][j]+vis2[i][j]-2);
            }
            else if(a[i][j]=='1')
            {
                ans=min(ans,res[1][2]+res[1][3]);
            }
            else if(a[i][j]=='2')
            {
                ans=min(ans,res[2][1]+res[2][3]);
            }
            else if(a[i][j]=='3')
            {
                ans=min(ans,res[3][1]+res[3][2]);
            }
        }
    }
    if(ans>=md)ans=-1;
PI(ans);
//    int ho1=md;
//    while(!q.empty())
//    {
//        da p=q.top();
//        q.pop();
//        for(int i=0;i<4;i++)
//        {
//            int x=p.x+dx[i];
//            int y=p.y+dy[i];
//            if(x>=1&&x<=n&&y>=1&&y<=m)
//            {
//                if(a[x][y]=='3'||a[x][y]=='2')
//                {
//                    ho1=min(ho1,vis[p.x][p.y]);
//                }
//                else if(a[x][y]=='.')
//                {
//                    if(vis[x][y]>vis[p.x][p.y]+1)
//                    {
//                        vis[x][y]=vis[p.x][p.y]+1;
//                        q.push(da(x,y,vis[x][y]));
//                    }
//                }
//            }
//        }
//
//    }
//if(ho==md||ho1==md)PI(-1);
//else PI(ho+ho1);



    return 0;
}
