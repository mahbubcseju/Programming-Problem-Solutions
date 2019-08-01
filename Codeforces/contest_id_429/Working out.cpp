
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
#define M 99999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+2][m+2];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    int dp1[n+2][m+2];
    SET(dp1);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dp1[i][j]=a[i][j]+max(dp1[i][j-1],dp1[i-1][j]);
        }
    }
    int dp2[n+2][m+2];
    SET(dp2);
    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=1; j--)
        {
            dp2[i][j]=a[i][j]+max(dp2[i][j+1],dp2[i-1][j]);
        }
    }
    int dp3[n+2][m+2];
    SET(dp3);
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=m; j++)
        {
            dp3[i][j]=a[i][j]+max(dp3[i][j-1],dp3[i+1][j]);
        }
    }
    int dp4[n+2][m+2];
    SET(dp4);
    for(int i=n; i>=1; i--)
    {
        for(int j=m; j>=1; j--)
        {
            dp4[i][j]=a[i][j]+max(dp4[i][j+1],dp4[i+1][j]);
        }
    }


    LL sum=0;
    for(int i=2; i<n; i++)
    {
        for(int j=2; j<m; j++)
        {
            LL su =dp1[i-1][j]+dp4[i+1][j]+dp2[i][j+1]+dp3[i][j-1];
            LL s=dp1[i][j-1]+dp4[i][j+1]+dp2[i-1][j]+dp3[i+1][j];
           // cout<<dp2[i][j-1]<<s<<endl;
            sum=max(sum,max(su,s));
        }
    }
    cout<<sum<<endl;
    return 0;
}
