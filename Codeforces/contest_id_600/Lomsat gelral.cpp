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

typedef pair<int,int> P;

////////define value/////
struct z {
    int st,ed,id,sq;
    bool operator<(const z &p) const {
        if(sq<p.sq)     return true;
        else if(sq==p.sq) {
            if(ed<p.ed) return true;
            else if(ed==p.ed)   return (st<p.st);
        }
        return false;
    }
};

z a[100005];
int n;
int a1[mx+2];
vector<int>v[mx+2];
int ar[mx+2];
int sz;
P ra[mx+2];
void dfs(int i,int pr) {
    ++sz;
    ra[i].x=sz;
    ar[sz]=a1[i];
    for(int j=0; j<v[i].size(); j++) {
        int x=v[i][j];
        if(x==pr)continue;
        dfs(x,i);
    }
    ra[i].y=sz;

}
int maxn;
ll res[mx+2];
ll co[mx+2];
void Add(int num) {
//cout<<num<<endl;
    co[num]++;
    res[co[num]]+=num;
    if(co[num]>maxn)maxn=co[num];



}
void Sub(int num) {
    //cout<<" lol "<<num<<endl;
    res[co[num]]-=num;
    if(res[co[num]]==0&&maxn==co[num])maxn=co[num]-1;
    co[num]--;

}
int main() {

    I(n);
    for(int i=1; i<=n; i++)I(a1[i]);
    sz=0;
    for(int i=1; i<n; i++) {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);
    }
    dfs(1,0);
    int sq=sqrt(n);
    for(int i=1; i<=n; i++) {
        a[i].st=ra[i].x;
        a[i].ed=ra[i].y;
        //a[i].st--;
        a[i].sq=(a[i].st/sq)+(a[i].st%sq!=0);
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    ll ans[n+2];
    int left=0,right=0;
    for(int i=1; i<=n; i++) {
        int L=a[i].st,R=a[i].ed;
        //cout<<"     "<<L<<" "<<R<<endl;
        while(left<L) {
            Sub(ar[left]);
            left++;
        }
        while(left>L) {
            Add(ar[left-1]);
            left--;
        }
        while(right<=R) {
            Add(ar[right]);
            right++;
        }
        while(right-1>R) {
            Sub(ar[right-1]);
            right--;
        }

//        getchar();
//        getchar();

        ans[ a[i].id ]=res[maxn];
    }

    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }




    return 0;
}
