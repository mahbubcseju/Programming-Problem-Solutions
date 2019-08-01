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
#define M 1000000007
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int n1,m1,l;
LL DP[103][103];
LL dp(int n,int m)
{
    if(n==n1)
    {
        if(m>=1)return 1;
        else return 0;
    }
    if(n>n1)return 0;
    LL &ret=DP[n][m];
    if(ret!=-1)return ret;
    LL sum=0;
    for(int i=1; i<=m1; i++)
    {
        if(i>=l)sum=(sum+dp(n+i,m+1))%M;
        else sum=(sum+dp(n+i,m))%M;
    }
    return DP[n][m]=sum;
}
int main()
{
    cin>>n1>>m1>>l;
    SETR(DP);
    cout<<dp(0,0)<<endl;
   // main();
    return 0;
}

