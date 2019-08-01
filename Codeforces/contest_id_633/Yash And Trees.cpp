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

typedef pair<int,int> P;

////////define value/////
bool prv[1002];
int n,m,sz;
bitset<1001>bt;
void seive() {
    prv[1]=1;
    for(int i=2; i<=m; i++) {
        if(prv[i]==0)
            for(int j=i*2; j<=m; j+=i) {
                prv[j]=1;
            }
    }
    for(int i=2; i<m; i++)if(prv[i]==0)bt.set(i);
}


int a[mx+2];
vector<int>v[mx+2];
P ar[mx+2];
int kon[mx+2];
void dfs(int i,int p) {
    ar[i].x=++sz;
    kon[sz]=i;
    for(int j=0; j<v[i].size(); j++) {
        int x=v[i][j];
        if(x==p)continue;
        dfs(x,i);
    }
    ar[i].y=sz;
}
bitset<1001>tr[mx*4];
int lazy[mx*4];
void build(int no,int s,int e) {
    if(s==e) {
        tr[no].set(a[kon[s]]%m);
        return ;

    }
    int mid=(s+e)>>1;
    build(no*2,s,mid);
    build(no*2+1,mid+1,e);
    tr[no]=tr[no*2]|tr[no*2+1];


}
void propagate(bitset<1001>&x,int l) {
    x=((x<<l) )|(x>>(m-l));

}
void update(int no,int s,int e,int st,int en,int val) {

    if(lazy[no]) {
        propagate(tr[no],lazy[no]);
        if(s!=e) {
            lazy[no*2]=(lazy[no*2]+lazy[no])%m;
            lazy[no*2+1]=(lazy[no*2+1]+lazy[no])%m;
        }
        lazy[no]=0;
    }
    if(e<st||s>en)return ;

    if(s>=st&&e<=en) {

        lazy[no]=(lazy[no]+val)%m;
        propagate(tr[no],lazy[no]);
        if(s!=e) {
            lazy[no*2]=(lazy[no*2]+lazy[no])%m;
            lazy[no*2+1]=(lazy[no*2+1]+lazy[no])%m;
        }
        lazy[no]=0;
        return ;

    }
    int mid=(s+e)>>1;

    update(no*2,s,mid,st,en,val);
    update(no*2+1,mid+1,e,st,en,val);

    tr[no]=tr[no*2]|tr[no*2+1];
}
bitset<1001>now;
void query(int no,int s,int e,int st,int en) {
    if(lazy[no]) {
        propagate(tr[no],lazy[no]);
        if(s!=e) {
            lazy[no*2]=(lazy[no*2]+lazy[no])%m;
            lazy[no*2+1]=(lazy[no*2+1]+lazy[no])%m;
        }
        lazy[no]=0;
    }
    if(e<st||s>en)return;
    if(s>=st&&e<=en) {
        now|=tr[no];
        return ;
    }

    int mid=(s+e)>>1;
    query(no*2,s,mid,st,en);
    query(no*2+1,mid+1,e,st,en);

}
int main() {
    //cout<<((2+6)>>1);

    I2(n,m);
    for(int i=1; i<=n; i++)I(a[i]),a[i]%=m;
    seive();

    for(int j=1; j<n; j++) {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);

    }
    dfs(1,0);
    build(1,1,n);
    int q;
    I(q);
    while(q--) {
        int ty;
        I(ty);
        if(ty==1) {
            int x,y;
            I2(x,y);
            y%=m;
            update(1,1,n,ar[x].x,ar[x].y,y);

        } else {
            int x;
            I(x);
            now.reset();
            query(1,1,n,ar[x].x,ar[x].y);
            int ans=(now&bt).count();
            PI(ans);
        }
    }

    return 0;
}
