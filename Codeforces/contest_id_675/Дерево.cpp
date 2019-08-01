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
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
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

#define mx 500000
#define md 1000000007ll

#define maxp 100000000000000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////
int tr[mx*5+2];
ll val[mx*5];
int le[mx*2],ri[mx*2];
void update(int no,int s,int e,int in,int val)
{
    if(s==e)
    {
        tr[no]=val;
        return;
    }
    int mid=(s+e)/2;
    if(in<=mid)
        update(no*2,s,mid,in,val);
    else update(no*2+1,mid+1,e,in,val);
    tr[no]=max(tr[no*2],tr[no*2+1]);

}
int query(int no,int s,int e,int st,int en)
{
    // cout<<no<<s<<e<<st<<en<<endl;
    if(s>=st&&e<=en)
    {
        return tr[no];
    }
    int mid=(s+e)/2;
    if(mid>=en)
    {
        int x=query(no*2,s,mid,st,en);
        return x;
    }
    else if(mid<st)
    {
        return query(no*2+1,mid+1,e,st,en);
    }
    else
    {
        int x=query(no*2,s,mid,st,mid);
        //cout<<x<<endl;
        if(x)return x;
        return query(no*2+1,mid+1,e,mid+1,en);
    }
}
int query1(int n,int s,int e,int st,int en)
{
    int lo=st;
    int hi=en;
    int ho=en;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int in=query(1,s,e,st,mid);
        if(in)
        {
            ho=in;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ho;
}
ll koly[mx*5];
int main()
{
    int n;
    I(n);
    P a1[n+2];
    int bolo[n+2];
    for(int i=1; i<=n; i++)
    {
        I(a1[i].xx);
        a1[i].yy=i;
        bolo[i]=a1[i].xx;
    }
    sort(a1+1,a1+n+1);
    P a[n+2];
    for(int i=1; i<=n; i++)a[a1[i].yy].xx=i,bolo[i]=a1[i].xx;
    // for(int i=1;i<=n;i++)cout<<" "<<a[i].xx<<endl;

    int sz=0;
    sz=1;
    val[1]=1;
    sz++;
    val[sz]=2;
    le[sz]=1;
    ri[sz]=a[1].xx-1;
    if(a[1].xx-1>0)
    {
        update(1,1,n,a[1].xx-1,sz);
        //  cout<<a[1].xx-1<<endl;
    }
   koly[sz]=1;

    sz++;
    val[sz]=3;
    ri[sz]=n;
    le[sz]=a[1].xx+1;
    int res[n+3];

    update(1,1,n,n,sz);
    res[1]=1ll;
    koly[sz]=1;
    val[1]=a[1].xx;
    for(int i=2; i<=n; i++)
    {

//cout<<a[i].xx<<" "<<n<<endl;
        int y=query1(1,1,n,a[i].xx,n);
        // cout<<y<<endl;
        int u=le[y];
        int v=ri[y];
        res[i]=bolo[val[koly [y]]];
         val[y]=a[i].xx;
        // cout<<y<<" "<<koly[y]<<" "<<val[koly[y]]<<endl;
//cout<<y<<" "<<u<<" "<<v<<endl;
//cout<<y<<" "<<koly[y];
        //left
        int x1=u;
        int y1=a[i].xx-1;
        if(x1<=y1)
        {
           // val[++sz]=(val[y]*2)%md;
           ++sz;
          // cout<<sz<<endl;
            koly[sz]=y;
            le[sz]=x1;
            ri[sz]=y1;
            //cout<<a[i].xx<<" "<<x1<<y1<<endl;
            update(1,1,n,y1,sz);
        }

        //rightĵ

        x1=a[i].xx+1;
        y1=v;
        if(x1<=y1)
        {
            //val[++sz]=(val[y]*2+1)%md;
            ++sz;
           // cout<<sz<<endl;
            koly[sz]=y;
            le[sz]=x1;
            ri[sz]=y1;
             //cout<<a[i].xx<<" "<<x1<<y1<<endl;
            update(1,1,n,y1,sz);
        }


    }

    for(int i=2; i<=n; i++)
    {
        if(i==2)
            PC("%d",res[i]);
        else PC(" %d",res[i]);
    }
    NL;


    return 0;
}