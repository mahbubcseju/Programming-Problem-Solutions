/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<bits/stdc++.h>
#include<string.h>
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
#define mx 3000004ll
#define md 2000000000000000000ll
typedef pair<int, int >P;
typedef vector<ll>V;

////////define value/////
char a[mx];
int node[mx*4];
void  seg(int no,int le,int ri,int in,int val)
{
    if(le==in&&ri==in)
    {
        node[no]=val;
        return ;
    }
    int mid=(le+ri)/2;
    if(mid>=in)
        seg(no*2,le,mid,in,val);
    else seg(no*2+1,mid+1,ri,in,val);
    node[no]=node[no*2]+node[no*2+1];
}

int main()
{

    int n,m;
    SL2(n,m);
    scanf("%s",a+1);
    int len=strlen(a+1);
    a[len+1]='a';
    a[len+2]='a';
    a[0]='a';
    for(int i=1; i<=len; i++)
    {
        if(a[i]=='.'&&a[i+1]=='.')seg(1,1,n,i,1);
        else seg(1,1,n,i,0);
    }
    int x;
    char ch;
    for(int i=1; i<=m; i++)
    {
        SC("%d %c",&x,&ch);
        if(ch=='.')
        {

            if(a[x-1]=='.'&&x-1!=0)
            {
                seg(1,1,n,x-1,1);
                
            }
            if(a[x+1]=='.')seg(1,1,n,x,1);

        }
        else
        {

            if(a[x]=='.'&&a[x-1]=='.')seg(1,1,n,x-1,0);
            if(a[x]=='.'&&a[x+1]=='.')seg(1,1,n,x,0);

            //seg(1,1,n,x,0);

        }
        a[x]=ch;
        PL(node[1]);
    }

    return 0;
}
