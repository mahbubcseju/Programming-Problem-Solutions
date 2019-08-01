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
#define S(a) scanf("%d",&a)
#define SD(a,b) scanf("%d%d",&a,&b)
#define SL(a) scanf("%lld",&a)
#define SLD(a,b) scanf("%lld%lld",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PC(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
using namespace std;
#define MX 100000000000000LL
#define MD 10000007
#define eps 1e-9
/////////////////////////////
////////////////////////////
////Function Area Start////

int main()
{
    int n;

    S(n);
    int  a[n+2];
    for(int i=1; i<=n; i++)
    {

        int y;
        S(a[i]);
    }
    int d[n+1];
    d[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(a[i]>a[i-1])
        {
            d[i]=d[i-1]+1;
        }
        else d[i]=1;
    }
    int f[n+2];
    f[n]=1;
    for(int j=n-1; j>=1; j--)
    {
        if(a[j]<a[j+1])
        {
            f[j]=f[j+1]+1;
        }
        else f[j]=1;
    }
    int sum=0;
    d[0]=0;
    f[0]=0;
    f[n+1]=0;
    d[n+1]=0;
    a[0]=1;
    a[n+1]=999999999;
    for(int i=1; i<=n; i++)
    {
        sum=max(sum,d[i-1]+1);
        sum=max(sum,f[i+1]+1);
        if(a[i-1]<(a[i+1]-1))
        {
           // cout<<d[i-1]<<f[i+1]<<endl;
            sum=max(sum,d[i-1]+f[i+1]+1);

        }
    }
    cout<<sum<<endl;
    return 0;

}
/*122345*/
