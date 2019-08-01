
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
int main()
{
    LL n,m;
    cin>>n;
    LL a[n+1];
    SET(a);
    FL(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    LL sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    LL ans=sum;
    if(n>2){
    for(LL i=1;i<=n-2;i++){
        sum-=a[i];
        ans+=sum;
        ans+=a[i];
    }
    }
    ans+=a[n-1];
    ans+=a[n];
    if(n==1)cout<<a[1]<<endl;
    else
    cout<<ans<<endl;
    return 0;
}
