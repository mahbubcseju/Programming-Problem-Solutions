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
#define mx 200000
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;
typedef vector<int> V;

////////define value/////
int main() {
    int n,k;
    I2(n,k);
    P a[n+2];
    set<int>s;
    fr(i,1,n) {
        I2(a[i].x,a[i].y);
        s.insert(a[i].x);
        s.insert(a[i].y);
    }

    map<int,int>mp;

    set<int>::iterator it;
    int sz=0;
    int ans[n*2+2];
    for(it=s.begin(); it!=s.end(); ++it) {
        int x=*it;
        //cout<<x<<endl;
        mp[x]=++sz;
        ans[sz]=x;
    }
    P ar[n*2+3];
    SET(ar);
    fr(i,1,n){ar[mp[a[i].x]].y--,ar[mp[a[i].y]].x++;

    }
    int st=sz;

   // cout<<st<<endl;
    int l=0;
    P num[n*2+2];
    int sr=0;
    for(int i=st; i>=1; i--) {
        int x=l+ar[i].x;
        if(l<k&&x>=k) {
            num[++sr]=mk(0,ans[i]);
        }
        l=x;
        x+=ar[i].y;
        if(x<k&&l>=k)num[sr].x=ans[i];

            l=x;

    }
    sort(num+1,num+sr+1);
    cout<<sr<<endl;
    for(int i=1;i<=sr;i++)
    {
        PC("%d %d\n",num[i].x,num[i].y);
    }
    return 0;

}
