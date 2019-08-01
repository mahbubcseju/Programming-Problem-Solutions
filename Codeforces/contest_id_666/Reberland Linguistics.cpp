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
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
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

typedef pair<int,int> P;

////////define value/////
char ch[mx+4];
int main() {
    SC("%s",ch+1);
    int len=strlen(ch+1);
    int dp[len+2][2];
    SET(dp);
    ch[len+1]='1';
    ch[len+2]='2';
    ch[len+3]='3';
    set<string>s;
    dp[len+1][0]=1;
    dp[len+1][1]=1;
    for(int i=len; i>1+4; i--) {
        if(i+2<=len+1) {
            if(dp[i+2][0]==1&&!(ch[i]==ch[i+2]&&ch[i+1]==ch[i+3]))dp[i][0]=1;
            //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
            if(dp[i+2][1]==1)dp[i][0]=1;
        }
        if(i+3<=len+1) {
            if(dp[i+3][0]==1)dp[i][1]=1;
            if(dp[i+3][1]==1&&!(ch[i]==ch[i+3]&&ch[i+1]==ch[i+4]&&ch[i+2]==ch[i+5]))dp[i][1]=1;
        }
        string s1;
        s1+=ch[i];
        s1+=ch[i+1];

        if(dp[i][0]==1) {
            s.insert(s1);
        }
        if(dp[i][1]==1) {
            s1+=ch[i+2];
            s.insert(s1);
        }
    }
    cout<<s.size()<<endl;
    set<string>::iterator it;
    for(it=s.begin(); it!=s.end(); it++) {
        cout<<(*it)<<endl;
    }

    return 0;
}
