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
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
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
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a,T b,T c) {
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 10000
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;

////////define value/////
vector<int>a[1003];
int n,sz,kd;
int low[mx],ind[mx];
int vis[mx];
stack<int>st;
int kdb[mx];//koto number component er element.
int kda ;// Counting component number;
bool fl=0;
int ans;
void dfs(int u,int p) {
    vis[u]=kd;
    low[u]=ind[u]=++sz;
    st.push(u);
    bool fl1=0;
    for(int j=0; j<a[u].size(); j++) {
        int x=a[u][j];
        if(x==p&&fl1==0)continue;
        if(x==p)fl1=1;
        if(vis[x]==-1) {

            dfs(x,u);
            low[u]=min(low[u],low[x]);

        } else if(kdb[x]==0) {
            low[u]=min(low[u],low[x]);
        }

    }
    if(low[u]==ind[u]) {
        int cnt=0;
        kdb[u]=++kda;
        int y;
        do {
            cnt++;
            // ans++;
            y=st.top();
            kdb[y]=kda;
            st.pop();
        } while(y!=u);
        if(cnt>1)fl=1;
    }

}

void tarjan() {
    kda=0;
    kd=0;
    sz=0;
    SETR(vis);
    dfs(1,0);

    for(int i=1; i<=n; i++) {
        if(vis[i]==-1) {
            fl=1;
        }
    }
}
int main() {

    int tc,cs=0,m;

    I2(n,m);
    for(int i=1; i<=m; i++) {
        int x,y;
        I2(x,y);
        a[x].PB(y);
        a[y].PB(x);
    }
    tarjan();
    if(!fl)PC("yes\n");
    else PC("no\n");

    for(int i=0; i<=n; i++)a[i].clear();

    return 0;
}
