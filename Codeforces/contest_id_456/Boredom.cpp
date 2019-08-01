/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
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
#define SL(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define PB(a) push_back(a)
#define FI first
#define SD second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
using namespace std;
typedef pair<I,I>P;
#define MX 1.73205080756887720000
#define MD 1000000007
#define eps 1e-6
/////////////////////////////
////////////////////////////
////Function Area Start////[7
int a[100008],m;
LL D1[100008];
LL dp(int i)
{
    if(i>m)return 0;
    LL &ret=D1[i];
    if(ret!=-1)return ret;
    ret=max(ret,(LL)a[i]*i+dp(i+2));
    ret=max(ret,dp(i+1));
    return ret;
}
int main()
{
    int n,p=1000000;
    S(n);
    SETR(D1);m=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        S(x);
        a[x]++;
        if(x<p)p=x;
        if(x>m)m=x;
    }
    cout<<dp(p)<<endl;

    return 0;
}
