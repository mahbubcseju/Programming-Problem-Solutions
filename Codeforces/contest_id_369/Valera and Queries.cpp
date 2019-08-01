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
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
#define pi 2.0*acos(0.0)
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


template <class T>bool ISLEFT(T a, T b, T c) {
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
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

#define md 1000000007ll
#define  mx 2000004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

struct da {

    int l,r,info;
    da() {
        l=r=info=0;
    }


};

int sz;

da  tr[mx*20+2];

int  update(int pr,int s,int e,int in) {
    int no=++sz;
    tr[no]=tr[pr];
    if(s==e) {
        tr[no].info+=1;
        return no;
    }
    int  mid=(s+e)>>1;
    if(mid>=in)tr[no].l=update(tr[pr].l,s,mid,in);
    else
        tr[no].r=update(tr[pr].r,mid+1,e,in);

    tr[no].info=tr[tr[no].l].info+tr[tr[no].r].info;
    return no;
}

int qu(int no,int s,int e,int st,int en)
{
   //cerr<<s<<" "<<e<<" "<<st<<" "<<en<<endl;
    if(s>=st&&e<=en)return tr[no].info;

    int mid=(s+e)>>1;

    if(mid>=en)return qu(tr[no].l,s,mid,st,en);
    else if(mid<st)return qu(tr[no].r,mid+1,e,st,en);
    else return qu(tr[no].l,s,mid,st,mid)+qu(tr[no].r,mid+1,e,mid+1,en);
}

vector<int>v[mx+2];


int root[mx+2];
int nl=1000000;
    int ar[mx+2];
int main() {
    int n,m;
    I2(n,m);
    fr(i,1,n) {
        int x,y;
        I2(x,y);
        v[y].PB(x);
    }
    for(int i=1;i<=mx;i++)
    {
        root[i]=root[i-1];
        for(int j=0;j<v[i].size();j++)
        {
            root[i]=update(root[i],1,nl,v[i][j]);
        }
    }

    while(m--)
    {

        int q;
        I(q);

        for(int i=1;i<=q;i++)
        {
            I(ar[i]);
        }
        ar[0]=0;
        ar[++q]=nl+1;
        int ans=0;
        for(int j=1;j<=q;j++)
        {
            if(ar[j-1]+1<=ar[j]-1)
              ans+=qu(root[ar[j]-1],1,nl,ar[j-1]+1,ar[j]-1);
        }
        //cerr<<ans<<endl;

        PI(n-ans),NL;
    }

    return 0;
}
