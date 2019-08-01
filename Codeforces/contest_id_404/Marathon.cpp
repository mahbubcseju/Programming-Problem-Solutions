/*
MAHBUBCSEJU
CSE 21
JAHANGIRNAGAR UNIVERSITY
TIMUS:164273FU
UVA>>LIGHTOJ>>HUST:mahbubcseju
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define LL long long int
#define LLR unsigned long long int
#define SC(a) scanf("%d",&a)
#define SCR(a) scanf("%lld",&a)
#define SCD(a,b) scanf("%d%d",&a,&b)
#define PF(t) printf("Case %d: ",t)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
using namespace std;
#define M 99999999
#define eps 1e-5
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int main()
{
    double a,m;
    scanf("%lf%lf",&a,&m);
    int n;
    SC(n);
    double r=a*4.0;
    for(int i=1; i<=n; i++)
    {
        double j,k;
        double x=(double)i*m;
        double  w=x/r;
       // w-=eps;
        LL q=(LL)w;
       //if(q*r!=x)q--;
        double s=x-(r*q);
        if(a*1.0>=s)
        {
            j=s;
            k=0.0;

        }
        else if(a*2.0>=s)
        {
            j=a;
            k=s-1.0*a;
        }
        else if(a*3.0>=s)
        {
            k=a;
            double h=a*3-s;
            j=h;
        }
        else if(a*4>s)
        {
            j=0.0;
            k=a*4.0-s;
        }
        printf("%.10lf %.10lf\n",j-eps,k-eps);
    }
    return 0;

}
