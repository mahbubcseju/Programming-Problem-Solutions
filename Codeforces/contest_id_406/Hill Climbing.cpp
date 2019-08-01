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
#define I int
#define ll long long int
#define ull unsigned long long int
#define D double
#define SL(a) scanf("%d",&a)
#define SL2(a,b) scanf("%d%d",&a,&b)
#define SL3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define S(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld%lld",&a,&b)
#define S3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PL(a) printf("%d\n",a)
#define P(a) printf("%lld\n",a)
#define PT(t) printf("Case %lld: ",t)
#define FL(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FLR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define F(J,a,b) for(long long J=a;J<=b;J++)
#define FR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T MDINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
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
typedef pair<ll , ll >P;

////////define value/////
#define MD 1000000007ll
ll n;
P a[100006];
ll lev[100006];
ll tab[100006][23];
ll res(P x,P y,P z)
{

    return   (x.xx*y.yy-x.yy*y.xx)+(y.xx*z.yy-y.yy*z.xx)+(z.xx*x.yy-z.yy*x.xx);
}
int lca(int a,int b)
{
    if(lev[a]>lev[b])swap(a,b);
    for(int i=20; i>=0; i--)
    {
        if(lev[b]-(1<<i)>=lev[a]&&lev[b]>=(1<<i))
        {
            b=tab[b][i];
        }
    }
    if(a==b)return a;
    for(int i=20; i>=0; i--)
    {
        if(tab[a][i]!=-1&&tab[a][i]!=tab[b][i])
        {
            a=tab[a][i],b=tab[b][i];

        }
    }
    return tab[a][0];
}
int main()
{

    S(n);
    for(ll i=1; i<=n; i++)
    {
        S2(a[i].xx,a[i].yy);
    }

    stack<ll>st;
    SETR(tab);
    ll l=0;
    for(ll i=n; i>=1; i--)
    {

        while(1)
        {
            //cout<<l<<endl;
            if(l<=1)
            {
                lev[i]=l+1;
                tab[i][0]=(l==0?-1:st.top());
                st.push(i);
                l++;
                break;
            }
            else
            {
              //  lol;

                ll fi=st.top();
                st.pop();
                l--;
                ll sc=st.top();
                ll re=res(a[i],a[fi],a[sc]);
             //  cout<<re<<" "<<i<<" "<<fi<<" "<<sc<<endl;
                if(re<=0)
                {

                    st.push(fi);
                    l++;
                    lev[i]=lev[fi]+1;
                    tab[i][0]=fi;
                    st.push(i);
                    l++;
                    break;
                }

            }
        }
    }

    for(int i=1; i<=20; i++)
        for(int j=1; j<=n; j++)
        {
            if(tab[j][i-1]!=-1) tab[j][i]=tab[tab[j][i-1]][i-1];
        }



    ll m;
    S(m);
    for(ll i=1; i<=m; i++)
    {
        ll x,y;
        cin>>x>>y;
        ll lc=lca(x,y);
        cout<<lc<<" ";
    }

    return 0;
}
