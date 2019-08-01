
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
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
//#define pi 2.0*acos(0.0)
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
template <class T>string NTS(T Number) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber(const string &Text) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT(T a,T b,T c) {
    if(((a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<int,int > P;
typedef vector<int> V;

////////define value/////

int flag[mx];

int main() {

    int n;
    I(n);
    int a[n+2];
    int mi=100;

    fr(i,1,n) {
        I(a[i]);
        mi=min(mi,a[i]);
    }
//    int ar[n+2];
    P ar[10000+2];

    frr(k,mi,1) {

        priority_queue< pair<int,int> >pq;

        fr(j,1,n) {
            pq.push(mk(a[j]-k,j));
        }
        P sa=mk(0,0);
        int sz=0;
        int tot=0;

        while(!pq.empty())
        {
             P x=pq.top();
             pq.pop();
             P y=pq.top();
             pq.pop();
             if(x.x==0)break;
             if(y.x==0)
             {
                 sa=x;
                 break;
             }

             x.x--;
             y.x--;

             ar[++sz]=mk(x.y,y.y);
             flag[sz] = 1;

             pq.push(x);
             pq.push(y);
        }

        //tot = sz;

        for(int i=1; i<=sz &&sa.x ; i++) {
            if(ar[i].x==sa.y||ar[i].y==sa.y)continue;
            else {
                sa.x--;
                flag[i] = 0;
            }
        }

        if(sa.x==0) {

              printf("%d\n",k);
              printf("%d\n",sz);
//              int vis[107];
//              memset(vis,0,sizeof vis);

            for(int i=1; i<=sz; i++) {
                for(int j=1; j<=n; j++) {
                    if(flag[i]==0) {
                        if(j==ar[i].x || ar[i].y==j||j==sa.y) printf("1");
                        else printf("0");
                    } else {
                        if(j==ar[i].x || ar[i].y==j) printf("1");
                        else printf("0");
                    }
                }
                puts("");
            }

            return 0;
        }


    }

    printf("0\n");

    int tot  = 0;

    tot = max( a[1] , a[2] );

    for(int i=3;i<=n;i++) tot += a[i];
    printf("%d\n",tot);
    int l =max(a[1],a[2]);

    for(int i=1; i<=l; i++) {
        printf("11");
        for(int j=3; j<=n; j++) printf("0");
        puts("");
    }

    for(int i=3; i<=n; i++) {
        for(int cnt=1; cnt<=a[i]; cnt++) {
            for(int j=1; j<=n; j++) {
                if(j==i || j==i-1) printf("1");
                else printf("0");
            }
            puts("");
        }
    }











    return 0;
}
