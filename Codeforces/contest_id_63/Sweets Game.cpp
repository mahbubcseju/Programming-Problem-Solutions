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
int dir[][3]= {1,20,4,
               2,20,5,
               20,20,6,
               4,0,8,
               5,1,9,
               6,2,10,
               20,20,11,
               8,3,12,
               9,4,13,
               10,5,14,
               11,6,15,
               20,20,20,
               13,8,16,
               14,9,17,
               15,10,18,
               20,11,20,
               17,13,20,
               18,14,20,
               20,15,20
              };

int musk[(1<<19)+2];

int go(int mus) {
    if(mus==0)return 0;
    int &ret=musk[mus];
    if(ret!=-1)return ret;
    ret=0;
    for(int j=0; j<19; j++) {
            for(int l=0; l<=2; l++) {
                    int ans=mus;
                for(int i=j; i<19&&(mus&(1<<i)); i=dir[i][l]) {
                    ans=ans^(1<<i);
                      if(go(ans)==0)return ret=1;
                }
            }
    }
    return ret=0;

}
int main() {
    int mu=0;
    char ch[10];
    int st=-1;
    for(int st=0;st<19;st++)
    {
        char a;
        cin>>a;
        if(a=='O') {
                mu=mu|(1<<st);
            }

    }
//    for(int i=1; i<=5; i++) {
//        SC("%s",ch+1);
//        for(int j=1; j<=strlen(ch+1); j++) {
//            ++st;
//            if(ch[j]=='0') {
//                mu=mu|(1<<st);
//            }
//        }
//    }
    SETR(musk);
int l=go(mu);
if(l==1)PC("Karlsson\n");
else PC("Lillebror\n");

    return 0;
}
