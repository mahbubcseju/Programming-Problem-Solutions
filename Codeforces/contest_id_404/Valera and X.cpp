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
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
int main()
{
    int n;
    SC(n);
    char ch[305][305];
    FOR(i,1,n)
    {
        FOR(j,1,n)cin>>ch[i][j];
    }
    char c=ch[1][1];
    int l=0;
    for(int i=1; i<=n; i++)
    {
        if(ch[i][i]!=c)l=1;
        int p=n-i+1;
        if(ch[i][p]!=c)l=1;
    }
   char  c1=ch[1][2];
    if(c==c1)l=1;
    FOR(i,1,n)
    {
        int t=n-i+1;
        FOR(j,1,n)
        {
            if(i==j)continue;
            if(j==t)continue;
            if(ch[i][j]!=c1)l=1;
        }
    }
    if(l==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
//main();
    return 0;
}
