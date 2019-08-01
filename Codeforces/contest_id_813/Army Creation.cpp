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
int a[mx+2];
struct node{
    int l,r,in;
    node()
    {
        l=r=in=0;
    }
};
node tr[mx*40];
int sz;
void up(int pr,int nw,int s,int e,int in,int val)
{
    if(s==e)
    {
        tr[nw].in=tr[pr].in+val;
        return ;
    }
    int mid=(s+e)/2;
    if(mid>=in){

        tr[nw].l=++sz;
        tr[nw].r=tr[pr].r;
        up(tr[pr].l,tr[nw].l,s,mid,in,val);
    }
    else
    {
        tr[nw].r=++sz;
        tr[nw].l=tr[pr].l;
        up(tr[pr].r,tr[nw].r,mid+1,e,in,val);
    }
    tr[nw].in=tr[tr[nw].l].in+tr[tr[nw].r].in;
}
int qu(int nw,int s,int e,int st,int en)
{
    if(s>=st&&e<=en)return tr[nw].in;

    int mid=(s+e)/2;

    if(mid>=en)return qu(tr[nw].l,s,mid,st,en);
    else if(mid<st)return qu(tr[nw].r,mid+1,e,st,en);
    else
        return qu(tr[nw].l,s,mid,st,mid)+qu(tr[nw].r,mid+1,e,mid+1,en);

}
vector<int>v[100003];
int main()
{

    int n,k;
    I2(n,k);
    int root[n+2];
    SET(root);
    for(int i=1;i<=n;i++)
    {
        int x;
        I(x);
        v[x].PB(i);
        if(v[x].size()<=k)
        {
            root[i]=++sz;
            up(root[i-1],root[i],1,n,i,1);
        }
        else
        {
            int sd=v[x].size();
            int x1=++sz;
            up(root[i-1],x1,1,n,v[x][sd-k-1],-1);
            root[i]=++sz;
            up(x1,root[i],1,n,i,1);

        }
    }

    int q;
    I(q);
    int la=0;
    while(q--)
    {
        int x,y;
        I2(x,y);
        x=((x+la)%n)+1;
        y=((y+la)%n)+1;
        if(x>y)swap(x,y);
      //  cout<<x<<" "<<y<<endl;
        int ans=qu(root[y],1,n,x,y);
        la=ans;
        PI(ans),NL;
    }


    return 0;
}
