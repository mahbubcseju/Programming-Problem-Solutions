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
int n;
int a[mx+2],b[mx+2];
int tr[2][mx*5];
void seg(int no,int s,int e) {
    if(s==e) {
        tr[0][no]=b[s];
        tr[1][no]=a[s];
        return ;
    }
    int mid=(s+e)>>1;
    seg(no*2,s,mid);
    seg(no*2+1,mid+1,e);
    tr[0][no]=min(tr[0][no*2],tr[0][no*2+1]);
    tr[1][no]=max(tr[1][no*2],tr[1][no*2+1]);

}
P query(int no,int s,int e,int st,int en) {
    P x,y;
    if(s>=st&&e<=en) {
        x=mk(tr[0][no],tr[1][no]);
        return x;
    }
    int mid=(s+e)>>1;
    if(mid>=en)return query(no*2,s,mid,st,en);
    else if(st>mid)return query(no*2+1,mid+1,e,st,en);
    else {
        x=query(no*2,s,mid,st,mid);
        y=query(no*2+1,mid+1,e,mid+1,en);
        x.x=min(x.x,y.x);
        x.y=max(x.y,y.y);
        return x;
    }
}
int main() {
    I(n);
    fr(i,1,n)I(a[i]);
    fr(i,1,n)I(b[i]);
    seg(1,1,n);

    ll res=0;
    for(int i=1; i<=n; i++) {
        int lo=i;
        int hi=n;
        bool fl=0;
        int in1;
        while(lo<=hi) {
            int mid=(lo+hi)/2;

            P x=query(1,1,n,i,mid);
            //if(3==i)cout<<i<<" "<<mid<<" "<<x.x<<" "<<x.y<<endl;
            if(x.x<=x.y) {
                hi=mid-1;
                if(x.x==x.y) {
                    in1=mid;
                    fl=1;
                }
            } else lo=mid+1;
        }
        // cout<<" "<<i<<endl;
        if(fl) {
           // cout<<i<<" "<<in<<endl;
            lo=in1,hi=n;
            int st=in1;
            fl=0;
            while(lo<=hi) {
                int mid=(lo+hi)/2;
                P x=query(1,1,n,i,mid);
              //  cout<<i<<" "<<mid<<" "<<x.x<<" "<<x.y<<endl;
                if(x.x==x.y) {
                    lo=mid+1;
                    st=mid;
                } else hi=mid-1;
            }
           // cout<<st<<endl;
        //cout<<i<<" "<<in1<<" "<<st<<endl;
            res+=(ll)(st-in1+1);
        }

    }
    PL(res);



    return 0;
}
