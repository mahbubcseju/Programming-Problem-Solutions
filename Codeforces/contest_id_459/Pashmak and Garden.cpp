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
int dis(int a,int b,int c,int d)
{
   return (a-c)*(a-c)+(b-d)*(b-d);

}
int main()
{

    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int a,b,c,d;
    if(x1==x2)
    {
        int l=y2-y1;
        a=x1+l;
        b=y1;
        c=x1+l;
        d=y2;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    }
    else if(y1==y2)
    {
        int l=x2-x1;
        a=x1;
        b=y1+l;
        c=x2;
        d=y1+l;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    else
    {
        a=x1;
        b=y2;
        c=x2;
        d=y1;
        if(dis(x1,y1,x2,y2)==dis(a,b,c,d)&&dis(x1,y1,a,b)==dis(x1,y1,c,d))
         cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        else cout<<"-1"<<endl;

    }
    return 0;
}
