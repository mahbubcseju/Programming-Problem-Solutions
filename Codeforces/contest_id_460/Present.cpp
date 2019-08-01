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
#define MX 10000000000000;
#define MD  100000007
#define eps 1e-6
/////////////////////////////
////////////////////////////
////Function Area Start////
LL a[100004],d[200004];
LL n,m,w;
int func(LL n1)
{
    SET(d);
    LL s=0;
    for(LL i=1; i<=n; i++)
    {
        if((d[i]+d[i-1]+a[i])<n1)
        {
            LL h=(n1-d[i]-d[i-1]-a[i]);
            //cout<<h<<endl;
            d[i]+=h;
            d[i]+=d[i-1];
            d[i+w]-=h;
            s+=h;
        }
        else d[i]+=d[i-1];

    }
    if(s<=m)return true;
    else return false ;
}


int main()
{


    cin>>n>>m>>w;
    for(LL i=1; i<=n; i++)
    {
        SL(a[i]);
    }
    LL lo=1;
    LL hi=MX;
    LL ans=0;
    while(lo<=hi)
    {
        SET(d);
        LL mid=(lo+hi)/2;
      if(func(mid)==true)
        {
            ans=max(ans,mid);
            lo=mid+1;
        }
       // if(mid==10)lo=mid+1;
        else hi=mid-1;

    }
    cout<<ans<<endl;
   // main();

    return 0;
}
