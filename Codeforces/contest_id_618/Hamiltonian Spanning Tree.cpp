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
    if(((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y))!=0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000
#define md 1000000007
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
int n,m,k;
vector<int>v[mx+2];
int vis[mx+2];
ll ans=0;
void dfs(int i,int p) {


    for(int j=0; j<v[i].size(); j++) {
        int x=v[i][j];
        if(x==p)continue;
        dfs(x,i);
        vis[i]+=vis[x];
    }
    //cout<<i<<" "<<vis[i]<<endl;
    if(vis[i]>1)
    ans+=(vis[i]-1);
    //if(i==1)cout<<vis[i]<<endl;
    if(i==1&&vis[i]<=1)ans++;
    if(vis[i]>1){
        vis[i]=0;
    }
    else vis[i]=1;
   // cout<<i<<" "<<vis[i]<<endl;


}



int main() {

    I3(n,m,k);
    int con[n+2];
    SET(con);
    bool fl=0;
    for(int i=1; i<n; i++) {
        int x,y;
        I2(x,y);
        v[x].PB(y);

        v[y].PB(x);
        con[x]++;
        con[y]++;
        if(con[x]==n-1||con[y]==n-1)fl=1;

    }

    if(m>=k) {
        if(fl)ans=(ll)(n-2)*(ll)k+(ll)m;
        else ans=(ll)(n-1)*(ll)k;
    } else {
        dfs(1,0);
      // cout<<ans<<endl;
     ans--;
        ans=(ans)*(ll)k+(ll)(n-1-ans)*(ll)m;

    }
    PL(ans);



    return 0;
}
