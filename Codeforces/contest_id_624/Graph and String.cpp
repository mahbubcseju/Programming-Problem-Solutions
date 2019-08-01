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
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 100000
#define md 1000000007
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
bool ch1(char a,char b) {

    if(abs(a-b)<=1)return 1;
    else return 0;
}
int main() {
    int n,m;
    I2(n,m);
    int a[n+2][n+2];
    SET(a);
    set<int>st;
    int arr[n+2];
    SET(arr);
    for(int i=1; i<=m; i++) {
        int x,y;
        I2(x,y);
        a[x][y]++;
        a[y][x]++;
        arr[x]++;
        arr[y]++;
    }
    for(int i=1;i<=n;i++)a[i][i]=1;
    char ch[n+2];
    SET(ch);
    bool chc=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i][j]==0&&chc==0) {
                chc=1;
                ch[j]='c';
                for(int l=1; l<=n; l++) {
                    if(a[i][l]==0&&a[j][l]==1) {
                        ch[l]='c';
                    }
                }


            }
            for(int k=1; k<=n; k++) {
                if(a[i][j]==1&&a[i][k]==1&&a[j][k]==0) {
                    ch[i]='b';

                }

            }


        }
    }
    for(int i=1; i<=n; i++) {
        if(ch[i]==0)ch[i]='a';
    }
    ch[n+1]='\0';
//cout<<(ch+1)<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j)continue;
            if(ch1(ch[i],ch[j])&&!a[i][j]) {

                PC("No\n");
                return 0;

            } else if(!ch1(ch[i],ch[j])&&a[i][j]) {
                PC("No\n");
                return 0;
            }

        }
    }
    PC("Yes\n");
    PC("%s\n",ch+1);


    return 0;
}
