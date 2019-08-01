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

typedef pair<ll,ll> P;

////////define value/////
char ch[]= {'+','-','|','^','>','<','v','L','R','U','D','*'};
int ar[12][4]= {
    1,1,1,1,
    1,0,1,0,
    0,1,0,1,
    0,1,0,0,
    0,0,1,0,
    1,0,0,0,
    0,0,0,1,
    0,1,1,1,
    1,1,0,1,
    1,0,1,1,
    1,1,1,0,
    0,0,0,0

};
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int main() {

    int n,m;
    I2(n,m);
    char a[n+2][m+2];
    for(int i=1; i<=n; i++) {
        SC("%s",a[i]+1);

    }
    int u,v,x,y;
    I2(u,v);
    I2(x,y);
    int vis[4][n+2][m+2];
    SET(vis);
    vis[0][u][v]=1;
    queue<int>q;
    q.push(u);
    q.push(v);
    q.push(0);
    q.push(0);
    while(!q.empty()) {
        int x1=q.front();
        q.pop();
        int y1=q.front();
        q.pop();
        int op=q.front();
        q.pop();
        int cost=q.front();
        q.pop();
        if(x1==x&&y1==y) {
            PI(cost);
            return 0;
        }
        for(int i=0; i<=3; i++) {
            int x2=x1+dx[i];
            int y2=y1+dy[i];
            if(x2>=1&&x2<=n&&y2>=1&&y2<=m&&vis[op][x2][y2]==0) {
                int ko,bo;
                for(int k=0; k<12; k++) {
                    if(a[x2][y2]==ch[k])ko=k;
                    if(a[x1][y1]==ch[k])bo=k;
                }
                int arr[4],brr[4];
                SET(arr);
                SET(brr);
              //  cout<<ko<<" "<<bo<<endl;
                for(int k=0; k<=3; k++) {
                    if(ar[ko][k]==1)arr[(k+op)%4]=1;
                    if(ar[bo][k]==1)brr[(k+op)%4]=1;
                }
                if(brr[i]==arr[(i+2)%4]&&brr[i]==1) {
                        //cout<<x2<<y2<<op<<endl;
                    vis[op][x2][y2]=1;
                    q.push(x2);
                    q.push(y2);
                    q.push(op);
                    q.push(cost+1);
                }
            }


        }

        if(vis[(op+1)%4][x1][y1]==0) {
            vis[(op+1)%4][x1][y1]=1;
            q.push(x1);
            q.push(y1);
            q.push((op+1)%4);
            q.push(cost+1);
        }
    }

    PI(-1);
    return 0;
}