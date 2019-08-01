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
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define mx 200004ll
#define md 1717171769ll
typedef pair<int, int >P;
typedef vector<ll>V;

///////////////////
////////////////////

struct node
{
    int in,l,r;
    node()
    {
        in=0,l=r=0;
    }
};
node tr[2][mx*4][4];

int a[mx+2];
bool fl;
void doit(int no,int s,int e,bool op)
{
    tr[op][no][0].in=tr[op][no*2][0].in+tr[op][no*2+1][0].in;
    tr[op][no][0].l=s,tr[op][no][0].r=e;

    if(tr[op][no*2+1][1].in>(tr[op][no*2+1][0].in+tr[op][no*2][1].in))
    {
        tr[op][no][1]=tr[op][no*2+1][1];
    }
    else
    {
        tr[op][no][1].in=(tr[op][no*2+1][0].in+tr[op][no*2][1].in);
        tr[op][no][1].r=e;
        tr[op][no][1].l=tr[op][no*2][1].l;
    }

    if(tr[op][no*2][2].in>(tr[op][no*2][0].in+tr[op][no*2+1][2].in))
    {
        tr[op][no][2]=tr[op][no*2][2];
    }
    else
    {
        tr[op][no][2].in=tr[op][no*2][0].in+tr[op][no*2+1][2].in;
        tr[op][no][2].r=tr[op][no*2+1][2].r;
        tr[op][no][2].l=s;
    }
    tr[op][no][3]=tr[op][no*2][3];
    if(tr[op][no*2+1][3].in>tr[op][no][3].in)tr[op][no][3]=tr[op][no*2+1][3];

    if(tr[op][no*2][1].in+tr[op][no*2+1][2].in>tr[op][no][3].in)
    {
        tr[op][no][3].in=tr[op][no*2][1].in+tr[op][no*2+1][2].in;
        tr[op][no][3].l=tr[op][no*2][1].l;
        tr[op][no][3].r=tr[op][no*2+1][2].r;
    }


}
void build(int no,int s,int e)
{
    if(s==e)
    {
        fr(i,0,3)
        {
            tr[0][no][i].in=a[s];
            tr[1][no][i].in=-a[s];
            tr[0][no][i].l=tr[1][no][i].l=s;
            tr[0][no][i].r=tr[1][no][i].r=e;
        }
        return ;
    }
    int mid=(s+e)>>1;
    build(no*2,s,mid);
    build(no*2+1,mid+1,e);
    doit(no,s,e,0);
    doit(no,s,e,1);

}
int lazy[mx*4];
inline void relax(int node,int ss,int se)
{
    int k = lazy[node];
    if(k)
    {
        fr(i,0,3)swap(tr[0][node][i],tr[1][node][i]);
        if(ss^se)
        {
            lazy[node*2]^=lazy[node];
            lazy[node*2+1]^=lazy[node];
        }
        lazy[node]^=1;
    }
}
void update(int no,int s,int e,int st,int en,int val)
{
    relax(no,s,e);
    if(s>en||e<st||s>e||st>en)return;
    if(s>=st&&e<=en)
    {
        if(fl==1)
        {
            lazy[no]^=1;
            relax(no,s,e);
        }
        else
        {
            a[s]=val;
            fr(i,0,3)
            {
                tr[0][no][i].in=a[s];
                tr[1][no][i].in=-a[s];
                tr[0][no][i].l=tr[1][no][i].l=s;
                tr[0][no][i].r=tr[1][no][i].r=e;
            }
        }
        return ;
    }
    int mid=(s+e)>>1;
    update(no*2,s,mid,st,en,val);
    update(no*2+1,mid+1,e,st,en,val);
    doit(no,s,e,0);
    doit(no,s,e,1);
}
node ans[mx*4][4];
int sz;

void cover(int no ,int no2,int no21)
{
    ans[no][0].in=ans[no2][0].in+ans[no21][0].in;
    ans[no][0].l=ans[no2][0].l,ans[no][0].r=ans[no21][0].r;

    if(ans[no21][1].in>(ans[no21][0].in+ans[no2][1].in))
    {
        ans[no][1]=ans[no21][1];
    }
    else
    {
        ans[no][1].in=(ans[no21][0].in+ans[no2][1].in);
        ans[no][1].r=ans[no21][1].r;
        ans[no][1].l=ans[no2][1].l;
    }

    if(ans[no2][2].in>(ans[no2][0].in+ans[no21][2].in))
    {
        ans[no][2]=ans[no2][2];
    }
    else
    {
        ans[no][2].in=ans[no2][0].in+ans[no21][2].in;
        ans[no][2].r=ans[no21][2].r;
        ans[no][2].l=ans[no2][1].l;
    }
    ans[no][3]=ans[no2][3];
    if(ans[no21][3].in>ans[no][3].in)ans[no][3]=ans[no21][3];

    if(ans[no2][1].in+ans[no21][2].in>ans[no][3].in)
    {
        ans[no][3].in=ans[no2][1].in+ans[no21][2].in;
        ans[no][3].l=ans[no2][1].l;
        ans[no][3].r=ans[no21][2].r;
    }


}
void query(int no,int s,int e,int st,int en,int ind)
{
    relax(no,s,e);
    if(s>=st&&e<=en)
    {

        fr(i,0,3)ans[ind][i]=tr[0][no][i];
        return ;
    }
    int mid=(s+e)>>1;
    if(mid>=en)
    {
        int el=++sz;
        query(no*2,s,mid,st,en,el);
        fr(i,0,3)
        {
            ans[ind][i]=ans[el][i];
            ans[el][i].in=ans[el][i].l=ans[el][i].r=0;
        }
    }
    else if(st>mid)
    {
        int el=++sz;
        query(no*2+1,mid+1,e,st,en,el);
        fr(i,0,3)
        {
            ans[ind][i]=ans[el][i];
            ans[el][i].in=ans[el][i].l=ans[el][i].r=0;
        }
    }
    else
    {
        int el=++sz;
        query(no*2,s,mid,st,mid,el);
        int el1=++sz;
        query(no*2+1,mid+1,e,mid+1,en,el1);
        cover(ind,el,el1);
        fr(i,0,3)
        {
            ans[el][i].in=ans[el][i].l=ans[el][i].r=0;
            ans[el1][i].in=ans[el1][i].l=ans[el1][i].r=0;
        }

    }
//    cerr<<no<<" where "<<s<<" where"<<e<<endl;
//
//    for(int i=0;i<=3;i++)cerr<<ans[ind][i].in<<" "<<ans[ind][i].l<<" "<<ans[ind][i].r<<endl;


}

int main()
{
    int n;
    I(n);

    fr(i,1,n)I(a[i]);
    build(1,1,n);
    int q;
    I(q);
    P ara[100];
    while(q--)
    {
        int t;
        I(t);
        if(t==1)
        {
            int l,r,k;
            I3(l,r,k);
            int res=0;
            int koy=0;
            fr(i1,1,k)
            {
                fl=1;
                sz=1;
                query(1,1,n,l,r,1);
                for(int i=1; i<=3; i++)if(ans[1][i].in>ans[1][0].in)ans[1][0]=ans[1][i];
                // cout<<ans[1][0].in<<Endl;
                if(ans[1][0].in>0)
                {
                    res+=ans[1][0].in;
                    update(1,1,n,ans[1][0].l,ans[1][0].r,0);
                    // cout<<ans[1][0].l<<" "<<ans[1][0].r<<endl;
                    // cout<<tr[1][0].l<<" "<<tr[1][0].r<<endl;
//                     getchar();
//                     getchar();
                    ara[++koy]=mk(ans[1][0].l,ans[1][0].r);

                }
                fr(j,0,3)ans[1][j].in=ans[1][j].l=ans[1][j].r=0;
            }
            fr(i,1,koy)
            {
                //cout<<ara[i].x<<" "<<ara[i].y<<Endl;
                update(1,1,n,ara[i].x,ara[i].y,0);
            }
            PI(res),NL;

        }
        else
        {
            int l,val;
            I2(l,val);
            fl=0;
            update(1,1,n,l,l,val);
        }
    }





    return 0;
}
