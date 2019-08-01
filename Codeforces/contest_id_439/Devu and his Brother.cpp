

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
#define M 99999999999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int a[100004],b[100004];
int n,m;
LL call(int h)
{
    LL su=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<h)su+=abs(a[i]-h);
    }
    for(int j=1; j<=m; j++)
    {
        if(b[j]>h)su+=abs(b[j]-h);
    }
    return su;
}
int main()
{

    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int j=1; j<=m; j++)cin>>b[j];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    int lo=a[1];
    int hi=b[m];
    while(hi>lo+6)
    {
        int p=(hi-lo)/3;
        int y=lo+p;
        int y1=hi-p;
        if(call(y)<call(y1))hi=y1;
        else lo=y;
    }
    LL sum=M;
    for(int i=lo; i<=hi+1; i++)
    {
        LL su=call(i);
        if(sum>su)sum=su;
    }
    if(sum==M)sum=0;
    cout<<sum<<endl;
    return 0;
}
