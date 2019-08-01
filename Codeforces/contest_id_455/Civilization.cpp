#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define LL long long
#define ULL unsigned long long

#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define SC scanf
#define PC printf
//#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define SS(s)                       scanf("%s",s)

#define I(X )                       scanf("%d",&X)
#define II(X, Y)                    scanf("%d%d",&X,&Y)
#define III(X, Y, Z)                scanf("%d%d%d",&X,&Y,&Z)
#define DI(X)                       int X;        I(X);
#define DII(X, Y)                   int X, Y;     II(X,Y)
#define DIII(X, Y, Z)               int X, Y, Z;  III(X,Y,Z);

#define IL(X )                       scanf("%lld",&X)
#define IIL(X, Y)                    scanf("%lld%lld",&X,&Y)
#define IIIL(X, Y, Z)                scanf("%lld%lld%lld",&X,&Y,&Z)

#define DIL(X)                       LL X;        IL(X);
#define DIIL(X, Y)                   LL X, Y;     IIL(X,Y)
#define DIIIL(X, Y, Z)               LL X, Y, Z;  IIIL(X,Y,Z);

#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define rep(i,a,b)                  for(int i=a;i<=b;i++)
#define rev(i,a,b)                  for(int i=a;i>=b;i--)
#define repv(i,a)                   for(int i=0;i<(int)a.size();i++)
#define revv(i,a)                   for(int i=((int)a.size())-1;i>=0;i--)

#define mk make_pair
#define MP make_pair
#define pb push_back
#define PB push_back
#define aov(a) a.begin(),a.end()
#define all(a)                      a.begin(),a.end()

#define endl '\n'
#define Endl '\n'
#define nl puts("")
#define NL printf("\n")

#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)

#define dbg(x) cerr<<#x<<" : "<<x<<endl
#define lol cerr<<"BUG\n";
#define pline                       cerr << "_________________________" << endl;
#define T(a)                        cerr << #a << ": " << a << endl;
#define TT(a,b)                     cerr << #a << ": " << a << " | " << #b << ": " << b << endl;

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T bpow(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}   /// M is prime
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

///int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,+1,0,1,0,-1}; // Hexagonal Direction   **
///int dy[]={-1,+1,1,0,-1,0}; //                       *#*
///                                                     **
///const double eps=1e-9;

/// 	   0123456789ABCDEF
#define Base1   10000019ULL
#define Base2   10000079ULL
#define Base3   10000103ULL
#define MOD1    1000000007ULL
#define MOD2    1000000009ULL
#define MOD3    1000000021ULL
///          0123456789ABCDEF
#define M    300005
#define MOD  1000000007LL
#define MX   1000005

typedef pair<int,int>P;
#define x first
#define y second
///////////////////////
///////////////////////

vector<int>v[M+2];

int vis[M+2];
queue<P>q;
int cnt=0;
int dis(int s,bool fl)
{

   ++cnt;
    q.push(mk(s,0));
    vis[s]=cnt;
    int ma=0;
    int in=0;
    while(!q.empty())
    {
        P f=q.front();
        q.pop();

        for(int i=0; i<v[f.x].size(); i++)
        {
            int u=v[f.x][i];
            if(vis[u]!=cnt)
            {
                vis[u]=cnt;
                if(ma<f.y+1)ma=f.y+1,in=u;
                q.push(mk(u,f.y+1));
            }
        }
    }
  //  cerr<<ma<<" "<<s<<endl;
    if(fl==0)return dis(in,1);
    else return ma;
}
int par[M+3];
int fin(int u)
{
    //  cerr<<u<<endl;
    if(par[u]==u)return u;
    return par[u]=fin(par[u]);
}

int root[M*3+2];
int main()
{
    int n,m,q;
    I3(n,m,q);
    for(int i=1; i<=n; i++)par[i]=i;
    fr(i,1,m)
    {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);
        int fx=fin(x);
        int fy=fin(y);
        if(fx!=fy)par[fx]=fy;


    }
    memset(vis,0,sizeof vis);
    for(int i=1; i<=n; i++)
    {
        int x=fin(i);

        if(vis[i]==0)
        {
            root[x]=dis(x,0);
           // cerr<<i<<" "<<x<<" "<<root[x]<<endl;
        }

    }

    while(q--)
    {

        int t;
        I(t);
        if(t==1)
        {
            int x;
            I(x);
            int f=fin(x);
            PC("%d\n",root[f]);

        }
        else
        {
            int x,y;
            I2(x,y);
            int fx=fin(x);
            int fy=fin(y);
            if(fx!=fy)
            {
                int ans=(root[fx]+1)/2;
                int ans1=(root[fy]+1)/2;
                ans+=ans1;
                ans++;
                ans=max(ans,root[fx]);
                ans=max(ans,root[fy]);
                par[fx]=fy;
                root[fy]=ans;
            }

        }

    }

    return 0;
}
/*
10 6 7
1 2
2 3
1 4
3 5
1 6
5 7
1 1
2 8 10
1 10
2 9 5
1 7
1 4
2 1 9

5
1
5
5
*/
