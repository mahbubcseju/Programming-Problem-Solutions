/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define D double
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
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
template<typename T> T in()
{
    char ch;
    T n = 0;
    bool ng = false;
    while (1)
    {
        ch = getchar();
        if (ch == '-')
        {
            ng = true;
            ch = getchar();
            break;
        }
        if (ch>='0' && ch<='9') break;
    }
    while (1)
    {
        n = n*10 + (ch - '0');
        ch = getchar();
        if (ch<'0' || ch>'9')   break;
    }
    return (ng?-n:n);
}
#define mx 103
#define md 1000000007ll
typedef pair<int, int >P;
typedef vector<int >V;

////////define value/////
int n,k;
int b[27];
char a[4][mx];
P c[mx];
int vis[4][mx][mx*10];
bool check(int st,int i,int j)
{
    bool fl=1;
    for(int l=1; l<=26; l++)
    {
        if(c[l].xx==i)
        {
            //  cout<<l<<endl;
            int u=c[l].yy-(st-1)*2;
            int v=u+b[l]-1;
            if((j)>=u&&(j)<=v)
            {
                fl=0;
            }


        }
    }
    return fl;

}
bool dp(int i,int j,int st)
{
    if(j==n)
    {
        return 1;
    }
    int &ret=vis[i][j][st];
    if(ret!=-1)return ret;
    ret=0;

    if(check(st,i,j+1)&&check(st+1,i,j+1))
    {
        ret=ret|dp(i,j+1,st+1);

    }
    if(i-1>=1&&check(st,i,j+1)&&check(st,i-1,j+1)&&check(st+1,i-1,j+1))
    {
        ret=ret|dp(i-1,j+1,st+1);
    }
    if(i+1<=3&&check(st,i+1,j+1)&&check(st+1,i+1,j+1)&&check(st,i,j+1))ret=ret|dp(i+1,j+1,st+1);
    return ret;

}
int main()
{

    int tc;
    I(tc);
    while(tc--)
    {
        I2(n,k);
        SETR(vis);
        int u,v;
        SET(b);
        SET(c);
        for(int i=1; i<=3; i++)
        {
            SC("%s",a[i]+1);



            for(int j=1; j<=n; j++)
            {
                if(a[i][j]>='A'&&a[i][j]<='Z')
                {
                    b[a[i][j]-64]++;
                    if(c[a[i][j]-64]==mk(0,0))
                    {
                        c[a[i][j]-64]=mk(i,j);
                        // cout<<i<<j<<endl;
                    }
                }
                if(a[i][j]=='s')
                {
                    u=i,v=j;
                }
            }
        }
        // cout<<b[1]<<endl;

        bool fl=dp(u,v,1);
        if(fl==0)PC("NO\n");
        else PC("YES\n");


    }
    return 0;
}
