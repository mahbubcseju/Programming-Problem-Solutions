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
#define  mx 2000004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007
///////////////////////////
///////////////////////////

#define mx 500004
#define md 2000000000000000000ll
typedef pair<int, int >P;
typedef vector<ll>V;

////////define value/////
V a[mx];
int n,sz,kd;
int low[mx],ind[mx];
int vis[mx];
stack<int>st;
int kdb[mx];//koto number component er element.
int kda ;// Counting component number;

int kar[mx+2];
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
        int cnt=0;
        int y;
        do {
            y=st.top();
            kdb[y]=kda;
            cnt++;
            st.pop();
        } while(y!=u);
        kar[kda]=cnt;
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
int m;

int vi[mx+2][2];
int mad[mx+2][2];

int main() {
    I2(n,m);
    for(int i=1; i<=n; i++) {
        int x;
        I(x);
        for(int j=1; j<=x; j++) {
            int y;
            I(y);
            a[i].PB(y);
        }
    }
    int s;
    I(s);
    tarjan();
    vi[s][0]=1;
    queue<P>q;
    q.push(mk(s,0));
    while(!q.empty()) {
        P f=q.front();
        q.pop();
        for(int i=0; i<a[f.x].size(); i++) {
            int u=a[f.x][i];
            int fo=f.y^1;
            if(vi[u][fo]==0) {
                vi[u][fo]=1;
                mad[u][fo]=f.x;
                q.push(mk(u,fo));
            }
        }
    }
    bool fl=0;
    int ans=0;
    SET(vis);
    bool cl=0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<a[i].size(); j++) {
            if(kdb[i]!=kdb[a[i][j]])vis[kdb[i]]=1;
        }
    }
    for(int i=1; i<=n; i++) {
        if(a[i].size()==0&&kar[kdb[i]]==1&&vi[i][1]==1) {
            fl=1;
            ans=i;
            break;
        }
        if(kar[kdb[i]]>1) {
            if(vi[i][0]==1||vi[i][1]==1) {
                cl=1;
            }
        }
    }
    if(fl==1) {
            PC("Win\n");
        vector<int>kol;
        kol.PB(ans);
        while(!(ans==s&&fl==0)) {
            ans=mad[ans][fl];
            fl^=1;
            kol.PB(ans);
        }
        reverse(kol.begin(),kol.end());
        for(int i=0; i<kol.size(); i++) {
            if(i>0)PC(" ");
            PC("%d",kol[i]);
        }
        NL;
    } else if(cl)PC("Draw\n");
    else PC("Lose\n");
    return 0;
}