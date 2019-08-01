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
#define M    200005
#define MOD  1000000007LL
#define MX   1000005

typedef pair<int,int>P;
#define x first
#define y second


vector<int>v[M+2];
int ar[M+2];
int st[M+2][3];
int ti;
int ke[M*2];
void dfs(int u,int p)
{

    st[u][0]=++ti;
    ke[ti]=u;

    for(int i=0;i<v[u].size();i++)
    {
        int x=v[u][i];
        if(x==p)continue;
        dfs(x,u);
    }

    st[u][1]=ti;

}


int tr[M*4+2];
int lazy[M*4+2];
void build(int no,int s,int e)
{
    if(s==e)
    {
        tr[no]=ar[ke[s]];
        return ;
    }
    int mid=(s+e)>>1;
    build(no*2,s,mid);
    build(no*2+1,mid+1,e);
    tr[no]=tr[no*2]+tr[no*2+1];
}

inline void relax(int node,int ss,int se) {
    int k = lazy[node];
    if(k) {
          tr[node]=(se-ss+1)-tr[node];
         // cerr<<se<<" "<<ss<<" "<<tr[node]<<endl;
        if(ss^se) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
inline void update(int node,int ss,int se,int qs,int qe,int d) {
    relax(node,ss,se);

    if(ss > qe || se < qs || ss > se || qs > qe) return;

    if(ss >= qs && se <= qe) {
        lazy[node] ^= d;
        relax(node,ss,se);
        return;
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    update(p,ss,mid,qs,qe,d);
    update(q,mid+1,se,qs,qe,d);
  tr[node]=tr[node*2]+tr[node*2+1];
}

inline int query(int node,int ss,int se,int qs,int qe) {
    if(ss > qe || se < qs || ss > se || qs > qe) return 0;
    relax(node,ss,se);
    if(ss >= qs && se <= qe) {
        return tr[node];
    }
    int p = (node<<1);
    int q = p|1;
    int mid = (ss+se)>>1;
    int pp = query(p,ss,mid,qs,qe);
    int qq = query(q,mid+1,se,qs,qe);
    return  pp+qq;
}
int main()
{
    int n;
    I(n);

    fr(i,2,n)
    {
        int x;
        I(x);
        v[x].PB(i);
        v[i].PB(x);
    }
    fr(i,1,n)I(ar[i]);
    dfs(1,-1);
build(1,1,ti);

    int q;
    I(q);
    char as[6];
    while(q--)
    {
        SC("%s",as);
        if(as[0]=='g')
        {
            int k;
            I(k);
            PC("%d\n",query(1,1,ti,st[k][0],st[k][1]));
        }
        else
        {
            int k;
            I(k);
            update(1,1,n,st[k][0],st[k][1],1);
        }
    }





    return 0;
}
