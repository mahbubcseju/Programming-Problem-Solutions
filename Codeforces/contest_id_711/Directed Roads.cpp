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
#define mx 200003
#define md 1000000007ll
#define maxp 205018000000000ll

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
V a[mx];
int n,sz,kd;
int low[mx],ind[mx];
int vis[mx];
stack<int>st;
int kdb[mx];//koto number component er element.
int kda ;// Counting component number;
ll res=1;
int ed;
void dfs(int u,int p)
{
    vis[u]=kd;
    low[u]=ind[u]=++sz;
    st.push(u);
    bool fl=0;
    for(int j=0; j<a[u].size(); j++)
    {
        int x=a[u][j];
        if(fl==0&&x==p)
        {
            fl=1;
            continue;
        }
        if(vis[x]==-1)
        {

            dfs(x,u);
            low[u]=min(low[u],low[x]);

        }
        else if(kdb[x]==0)
        {
            low[u]=min(low[u],ind[x]);
        }

    }
    ll ans=0;
    if(low[u]==ind[u])
    {
        kdb[u]=++kda;
        int y;
        do
        {
            y=st.top();
            kdb[y]=kda;
            st.pop();
        }
        while(y!=u);
    }



}

void tarjan()
{
    kda=0;
    kd=0;
    sz=0;
    SETR(vis);
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==-1)
        {
            ++kd;
            dfs(i,-1);
        }
    }
}
int main()
{
    I(n);
    int ho=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        I(x);
        ho++;
        a[i].PB(x);
        a[x].PB(i);
    }
    tarjan();
    int cou[kda+2];
    SET(cou);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<a[i].size(); j++)
        {
            int x=a[i][j];
            if(kdb[i]==kdb[x])
            {
                cou[kdb[i]]++;
            }
        }

    }
    int kol=0;
    fr(i,1,kda)kol+=(cou[i]/2);
    ll res=BM(2ll,(ll)n-kol,md);
    fr(i,1,kda)
    {
        if(cou[i]==0)continue;
        ll x=BM(2ll,(ll)cou[i]/2,md)-2;
        if(x<0)x+=md;
        res=(res*x)%md;


    }
    PL(res);
    for(int i=0; i<=n; i++)a[i].clear();


    return 0;
}
