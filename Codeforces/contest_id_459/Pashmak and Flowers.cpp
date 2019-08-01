
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
#define MD  100000007
#define eps 1e-6
/////////////////////////////
////////////////////////////
////Function Area Start////
int main()
{
    int n;
    cin>>n;
    int a[n+3];
    for(int t=1; t<=n; t++)cin>>a[t];
    sort(a+1,a+n+1);
    int l=a[1];
    int k=1;
    for(int i=2; i<=n; i++)
    {
        if(a[i]!=l)break;
        else k++;
    }
    LL ma=0;
    LL res=0;
    //cout<<a[1]<<k<<endl;
    for(int i=2; i<=n; i++)
    {
        if(a[1]==a[i])continue;
        int h=a[i]-a[1];
        if(h>ma)
        {
            ma=(LL)h;
            res=(LL)k;
        }
        else if(h==ma)res+=(LL)k;
    }
    if(ma==0)
    {
        LL n1=(LL)(n-1);
        res=(n1*(n1+1))/2;
    }
    cout<<ma<<" "<<res<<endl;
    // main();
    return 0;
}
