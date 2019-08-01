
/*
MAHBUBCSEJU
CSE 22
JAHANGIRNAGAR UNIVERSITY
TIMUS:164273FU
UVA>>LIGHTOJ>>HUST:mahbubcseju
*/
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
#define LL long long int
#define LLR unsigned long long int
#define SC(a) scanf("%d",&a)
#define SCR(a) scanf("%lld",&a)
#define SCD(a,b) scanf("%I64d%I64d",&a,&b)
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
#define M 9999999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
struct data
{
    int x,y;
    data()
    {
    }
    data(int _x,int _y)
    {
        x=_x,y=_y;
    }
};

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<data>a[45009];
    //SET(a);
    int l=(m*n)/k;
    int b[45009];
    b[1]=l+((m*n)-(k*l));
   for(int i=2; i<=k; i++)b[i]=l;
    int g=1,s=0;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
            for(int j=1; j<=m; j++)
            {
                a[g].PB(data(i,j));
                s++;
                if(s==b[g])
                {
                    g++;
                    s=0;
                }
            }
        else for(int j=m; j>=1; j--)
            {
                a[g].PB(data(i,j));
                s++;
                if(s==b[g])
                {
                    g++;
                    s=0;
                }
            }
    }
    for(int p=1; p<=k; p++)
    {
        int e=l;
        if(p==1)e=b[1];
        printf("%d",e);
        for(int j=0; j<e; j++)
        {
            if(j==e-1)printf(" %d %d\n",a[p][j].x,a[p][j].y);
            else printf(" %d %d",a[p][j].x,a[p][j].y);
        }
    }
    return 0;
}
