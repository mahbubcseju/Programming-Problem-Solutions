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
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
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
template <class T> inline T mdINV(T a, T M)
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
#define mx 200000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
vector< int >v[mx+2];
ll vis[2][mx+2];
bool com[mx+2];
priority_queue<pair<ll,int> >pq;
int cur[mx+2];
int cost[1002][1002];
bool c[1002][1002];
void dis(int s,int fl)
{
    fr(i,0,1000)
    {
        com[i]=0;
        vis[fl][i]=2e18;
    }

    vis[fl][s]=0;

    pq.push(mk(0ll,s));
    com[s]=1;
    while(!pq.empty())
    {
        pair<ll,int> t=pq.top();
        pq.pop();
        int u=t.y;
        com[u]=0;
        ll co=-t.x;
        for(int j=0; j<v[u].size(); j++)
        {
            int x=v[u][j];
            int y=cost[u][x];
            if(vis[fl][u]+y<vis[fl][x])
            {
                vis[fl][x]=vis[fl][u]+y;
                cur[x]=u;
                if(com[x]==0)
                {
                    com[x]=1;

                    pq.push(mk(-vis[fl][x],x));
                }
            }

        }
    }

}
int main()
{

    ll n,m,l,s,t;
    L2(n,m);
    L3(l,s,t);
    fr(i,1,m)
    {
        ll x,y,z;
        L3(x,y,z);
        int ho=z;
        if(z==0)ho=1;
        c[y][x]=c[x][y]=(z==0?0:1);
        cost[x][y]=cost[y][x]=ho;
        v[x].PB(y);
        v[y].PB(x);
    }
    int arr[n+2][n+2];
    SET(arr);
    dis(s,0);
    if(vis[0][t]<l)
    {
        int en=t;
        while(en!=s)
        {
            int x=cur[en];
            arr[x][en]=1;
            arr[en][x]=1;
            en=x;
        }
        fr(i,1,n)
        fr(j,1,n)
        {
            if(!arr[i][j]&&c[i][j]==0)
            {
                c[i][j]=1;
                c[j][i]=1;
                cost[i][j]=cost[j][i]=l+1;
            }
        }
    }
    fr(i,1,n)
    {
        dis(s,0);
        int en=t;
        bool fl=0;

        if(vis[0][t]>=l)break;
        while(en!=s)
        {
            if(fl)break;

            int x=en;
            int y=cur[en];
            if(c[en][y]==0)
            {
                c[en][y]=c[y][en]=1;
                if(fl==0&&(l-vis[0][t])>=0)
                {
                    cost[en][y]=cost[y][en]=1+(l-vis[0][t]);

                    fl=1;
                    break;

                }
            }
            en=y;
            if(fl)break;
        }

    }
    int ar[n+2][n+2];
    SET(ar);
    dis(s,0);
    if(vis[0][t]!=l)PC("NO\n");
    else
    {

        PC("YES\n");
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<v[j].size(); k++)
            {
                //if(v[j][k].y==0)continue;
                int x=v[j][k];
                if(ar[j][x]||ar[x][j])continue;
                ar[j][x]=1;
                PC("%d %d %d\n",j,v[j][k],cost[j][x]);
            }
        }
    }

    return 0;
}
