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
template <class T> inline T mul(T p, T e, T M)
{
    ll ret = 0;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
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
 
 
template <class T>bool ISLEFT(T a, T b, T c)
{
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
 

#define  mx 200004
#define base 193ll
 
typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  100007
#define md 998244353ll
///////////////////////////
///////////////////////////

void solve() {
    int n;
    I(n);
    char ar[n + 2];
    SC("%s", ar + 1);

    int dp[2][n+2][3];
    SET(dp);
    dp[0][0][0] = dp[1][n + 1][0] = 1;

    for(int i = 1; i <= n; i++){
        if(ar[i] == '1') {
            dp[0][i][2] += dp[0][i - 1][1];
            dp[0][i][2] += dp[0][i - 1][2]; 

            dp[0][i][1] += dp[0][i - 1][0];
        }else if(ar[i] == '0'){
            dp[0][i][2] += dp[0][i - 1][2]; 
            dp[0][i][0] += (dp[0][i - 1][0] + dp[0][i - 1][1] + dp[0][i - 1][2]);
        }

        for(int j = 0; j <= 2; j++){
            dp[0][i][j] %= md;
            cerr<<i<<" "<<dp[0][i][j];
        }
        cerr<<endl;
    }

    for(int i = n; i >= 1; i--){
        if(ar[i] == '1') {
            dp[1][i][2] += dp[1][i + 1][1];
            dp[1][i][2] += dp[1][i + 1][2]; 

            dp[1][i][1] += dp[1][i + 1][0];
        }else if(ar[i] == '0'){
            dp[1][i][2] += dp[1][i + 1][2]; 
            dp[1][i][0] += (dp[1][i + 1][0] + dp[1][i + 1][1] + dp[1][i + 1][2]);
        }

        for(int j = 0; j <= 2; j++){
            dp[1][i][j] %= md;
        }
    }
    

    ll res = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0 && )
            for(int k =0; k < 3; k++){
                res = (res + (ll)dp[0][i][j] * (ll)dp[1][i + 1][k])% md;
                cerr<<i<<" "<<j<<" "<<k<<" "<<dp[0][i][j]<<" "<<dp[1][i + 1][k]<<endl;
            }
        }
    }

    printf("%lld\n", res);

}


int main() {


    int tc;
    I(tc);
    while(tc--) {
        solve();
    }

    return 0;
}