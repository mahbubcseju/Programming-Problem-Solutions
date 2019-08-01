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
#include<string.h>
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define PI 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
#define mx 100000
#define md 1000000007
#define maxp 2050180000

typedef pair<long double,long double > P;
template <class T> inline T Circirintersecarea(T d,T r,T R)
{
   long double A;
    if(R<r)swap(R,r);
    if(d>r+R)A=0.0;
    else if(d<=R-r)A=PI*r*r;
    else
    {
        T alpha = acos((r*r+d*d-R*R)/(2.0*r*d))*2.0;
        T beta = acos((R*R+d*d-r*r)/(2.0*R*d))*2.0;
        T a1=0.5*beta *R*R-0.5*R*R*sin(beta);
        T a2=0.5*alpha*r*r-0.5*r*r*sin(alpha);
        A=a1+a2;
    }
    return A;
}
int main()
{

    P a,b;
   long  double r1,r2;
    cin>>a.x>>a.y>>r1>>b.x>>b.y>>r2;
   long  double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 cout<<fixed<<setprecision(10)<<Circirintersecarea(d,r1,r2)<<endl;

    return 0;

}
