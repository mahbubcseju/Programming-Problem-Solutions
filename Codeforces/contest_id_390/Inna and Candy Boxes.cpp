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
#define mx 100000
#define md 1000000007
#define maxp 2050180000

typedef pair<double ,double> P;

////////define value/////
int main() {
    int n,m,k;
    I3(n,m,k);
    char ch[n+2];
    SC("%s",ch+1);

    int cum[n+2];
    cum[0]=0;
    for(int i=1; i<=n; i++) {
        cum[i]=cum[i-1]+(ch[i]-'0');

    }
    int ar[m+2][n+2];
    int dp[m+2][n+2];
    SET(dp);
    int arr[m+2];
    SET(arr);
    SET(ar);
    int cnt[n+2];
    int cnt1[m+2];
    SET(cnt1);
    for(int j=1; j<=n; j++) {

        cnt[j]=j%m;
        if(cnt[j]==0)cnt[j]=m;
       // cout<<cnt[j]<<" ";
        if(ch[j]=='1')arr[cnt[j]]++;
           cnt1[cnt[j]]++;
        for(int i=1;i<=m;i++){ar[i][j]=arr[i];dp[i][j]=cnt1[i];}


    }
    NL;
    while(k--)
    {
        int st,en;
        I2(st,en);
        int st1=st+m-1;

        int num=dp[cnt[st1]][en]-dp[cnt[st1]][st-1];
        int ache=ar[cnt[st1]][en]-ar[cnt[st1]][st-1];
        int res=num-ache;
        //cout<<num<<" "<<ache<<endl;
       int dor=(cum[en]-cum[st-1])-ache;
      // cout<<dor<<endl;
       int ans=res+dor;
        PI(ans);
    }




    return 0;
}
