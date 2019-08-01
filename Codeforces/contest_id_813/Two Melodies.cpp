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
#define md 1000000007ll
#define mx 100001

#define maxp 2050180000

typedef pair<int ,int > P;

////////define value/////
int ar[5015][8];
//
//int bor[5005];
//int cho[5005];
//set<int>st[100005];
int dp[5015][5015];
int n;
int a[5010+2];
short int bor[5015][5015];
short int cho[5015][5015];
int ara[5010];
inline int Max(int x,int y)
{
    if(x>y)return x;
    else return y;
}

int go(int i,int j) {
    int &ret=dp[i][j];

    if(ret!=-1)return ret;
    ret=0;
    int co=Max(i,j);
    int l=ara[i];
    int l1=ara[j];
    if(ar[co][l]<=n)ret=Max(ret,1+go(ar[co][l],j));
    if(cho[i][co]<=n&&cho[i][co]>=8)ret=Max(ret,1+go(cho[i][co],j));
    if(bor[i][co]<=n&&bor[i][co]>=8)ret=Max(ret,1+go(bor[i][co],j));
    // cout<<i<<"i "<<j<<bor[i][j]<<endl;
    // cout<<i<<" "<<j<<" "<<ret<<endl;
    if(ar[co][l1]<=n)ret=Max(ret,1+go(i,ar[co][l1]));
    if(cho[j][co]<=n&&cho[j][co]>=8)ret=Max(ret,1+go(i,cho[j][co]));
    if(bor[j][co]<=n&&bor[j][co]>=8)ret=Max(ret,1+go(i,bor[j][co]));
    // cout<<i<<" j"<<j<<bor[i][j]<<endl;

    return ret;
}

int st[100005];

int main() {

    SETR(dp);

    I(n);
    int l=n;
    n=0;
    for(int i=1; i<=7; i++)a[++n]=i+i*7;
    for(int i=1; i<=l; i++) {
        int x;
        I(x);
        a[++n]=x;

    }

    int ar1[8];
    for(int i=0; i<=7; i++)ar[n+1][i]=ar1[i]=n+1;

    for(int j=1; j<=n; j++) {
            ara[j]=a[j]%7;
        int co=j;

        for(int k=1; k<=n; k++)st[a[k]]=n+1;

        for(int i=n; i>=8; i--) {
            if(i<=j) {
                cho[i][j]=st[a[i]-1];
                bor[i][j]=st[a[i]+1];
            }
            if(i>j)
                st[a[i]]=i;
        }

    }
    for(int j=n; j>=1; j--) {
        int x=ara[j];
        for(int k=0; k<=7; k++)ar[j][k]=ar1[k];
        ar1[x]=j;
    }


    int res=0;
//  a[0]=0;
//   cout<<go(0,0)<<endl;


    for(int i=1; i<=7; i++) {

        for(int j=1; j<=7; j++) {

            int ans1=go(i,j);
            if(ans1>res)res=ans1;
            //if(i==1&&j==4)cout<<ar1[j]<<" "<<0<<" "<<res<<endl;

        }
    }

    PI(res),NL;

    return 0;
}
