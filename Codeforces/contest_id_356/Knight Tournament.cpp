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
#define LL long long int
#define UL unsigned long long int
#define D double
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
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
#define STN(a) stringtonumber<LL>(a)
using namespace std;
template <class T> inline T BM(T p,T e,T M)
{
    LL ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T MDINV(T a,T M)
{
    return BM(a,M-2,M);
}
template <class T> inline T PW(T p,T e)
{
    LL ret = 1;
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
typedef pair<int ,int >P;
////////define value//////////
#define MX 300000
#define MD 100000007
int a[MX*4];
int pos[MX+3];
void build(int no,int i,int j)
{
    if(i==j)
    {
        a[no]=1;
        pos[i]=0;
        return ;
    }
    build(no*2,i,(i+j)/2);
    build(no*2+1,(i+j)/2+1,j);
    a[no]=a[no*2]+a[no*2+1];
}
void query(int no,int i,int j,int x,int y,int val)
{
    if(x>j||y<i)return ;
    if(i==j)
    {
        if(val!=i&&pos[i]==0)
        {
            a[no]=0;
            pos[i]=val;

        }
        return ;
    }

    int mi=(i+j)/2;

    if(x>mi)
    {
        if(a[no*2+1]>0)
            query(no*2+1,(mi+1),j,x,y,val);
    }
    else if(y<=mi)
    {
        if(a[no*2]>0)
            query(no*2,i,mi,x,y,val);
    }
    else
    {
        if(a[no*2+1]>0)
            query(no*2+1,(mi+1),j,mi+1,y,val);
        if(a[no*2]>0)
            query(no*2,i,mi,x,mi,val);
    }
    a[no]=a[no*2]+a[no*2+1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    SET(a);
     build(1,1,n);
    for(int i=1; i<=m; i++)
    {
        int x,y,z;
        S3(x,y,z);
        query(1,1,n,x,y,z);
//        for(int i=1;i<=n;i++)cout<<pos[i]<<" ";
//        NL;
    }
    for(int i=1; i<=n; i++)
    {
        if(i<n)
            cout<<pos[i]<<" ";
        else
            cout<<pos[n]<<endl;
    }


    return 0;
}
