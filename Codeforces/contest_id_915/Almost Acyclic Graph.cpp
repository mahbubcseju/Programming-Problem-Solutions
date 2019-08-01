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
#define  mx 200004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007
///////////////////////////
///////////////////////////
////////define value/////


vector<int>v[mx+2];


int vis[504+2];
int cnt;
vector<int>vo;
int par[mx+2];
bool fl=0;
int st[mx+2];
void dfs(int u,int p) {
    par[u]=p;
    vis[u]=cnt;
    int in=0;
    st[u]=1;
    for(int j=0; fl==0&&j<v[u].size(); j++) {
        int x=v[u][j];
        if(vis[x]==cnt&&st[x]==1) {
            in=x;
            fl=1;
            int ke=u;
          //  cerr<<ke<<" "<<x<<endl;
            while(ke!=x) {
                vo.PB(ke);
                ke=par[ke];
            }
            vo.PB(ke);
            break;
        } else if(vis[x]==0) dfs(x,u);
    }
    st[u]=0;
}

bool mark[504][504];

void check(int u,int p) {
    par[u]=p;
    vis[u]=cnt;
    int in=0;
    st[u]=1;
    for(int j=0; fl==0&&j<v[u].size(); j++) {
        int x=v[u][j];
        if(mark[u][x]==1)continue;
        if(vis[x]==cnt&&st[x]==1) {
            in=x;
            fl=1;
            break;
        } else  if(vis[x]==0)check(x,u);
    }
    st[u]=0;
}


int main() {
    int n,m;
    I2(n,m);
    for(int i=1; i<=m; i++) {
        int x,y;
        I2(x,y);
        v[x].PB(y);
    }
    for(int i=1; i<=n&&fl==0; i++) {
        if(vis[i]==0) {
            ++cnt;
            dfs(i,0);
        }
    }
    if(vo.size()>0) {
        reverse(vo.begin(),vo.end());
        //lol;
        for(int i=0; i<vo.size(); i++) {
            int x=vo[i];
            int y=vo[(i+1)%vo.size()];
            mark[x][y]=1;
            SET(vis);
           // cerr<<x<<" "<<y<<Endl;
            fl=0;
            for(int k=1; fl==0&&k<=n; k++) {
                if(vis[k]==0) {
                       // cerr<<k<<" "<<endl;
                    ++cnt;
                    check(k,0);
                }
            }
            mark[x][y]=0;
            if(!fl) {
                PC("YES\n");
                return 0;
            }
        }
        PC("NO\n");
    } else PC("YES\n");
    return 0;
}
