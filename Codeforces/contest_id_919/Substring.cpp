#include<bits/stdc++.h>
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
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T mul(T p, T e, T M) {
    ll ret = 0;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}


template <class T>bool ISLEFT(T a, T b, T c) {
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 300004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////
typedef vector<int>V;

////////define value/////
vector<int> a[mx];
int n,sz,kd;
int low[mx],ind[mx];
int vis[mx];
stack<int>st;
int kdb[mx];//koto number component er element.
int kda ;// Counting component number;
bool fl=0;
void dfs(int u) {
    vis[u]=kd;
    low[u]=ind[u]=++sz;
    st.push(u);
    for(int j=0; j<a[u].size(); j++) {
        int x=a[u][j];
        if(vis[x]==-1) {
            dfs(x);
            low[u]=min(low[u],low[x]);
        } else if(kdb[x]==0) {
            low[u]=min(low[u],low[x]);
        }
    }
    if(low[u]==ind[u]) {
        kdb[u]=++kda;
        int y;
        int cnt=0;
        do {
            y=st.top();
            kdb[y]=kda;
            st.pop();
            cnt++;
        } while(y!=u);
        if(cnt>1)fl=1;
    }
}

void tarjan() {
    kda=0;
    kd=0;
    sz=0;
    SETR(vis);
    for(int i=1; i<=n; i++) {
        if(vis[i]==-1) {
            ++kd;
            dfs(i);
        }
    }
}

vector<int >v;

void dfs1(int u) {
    vis[u]=1;
    for(int i=0; i<a[u].size(); i++) {
        int u1=a[u][i];
        if(vis[u1]==0) {
            dfs1(u1);
        }
    }
    v.PB(u);
}

int ans[mx][27];
int main() {
    int m;
    I2(n,m);
    char ar[n+2];
    SC("%s",ar+1);
    fr(i,1,m) {
        int x,y;
        I2(x,y);
        if(x==y)fl=1;
        a[x].PB(y);
    }
    tarjan();
    if(fl)PI(-1),NL;
    else {
        SET(vis);
        for(int i=1; i<=n; i++) {
            if(vis[i]==0)
                dfs1(i);
        }
        reverse(v.begin(),v.end());
        int res=0;
        for(int i=0; i<v.size(); i++) {
            ans[v[i]][ar[v[i]]-'a'+1]++;
            for(int j=1; j<=26; j++)res=max(res,ans[v[i]][j]);
            int u=v[i];
            for(int j=0; j<a[u].size(); j++) {
                int k=a[u][j];
                for(int l=1; l<=26; l++)ans[k][l]=max(ans[k][l],ans[u][l]);
            }
        }
        PI(res),NL;
    }
    return 0;
}
