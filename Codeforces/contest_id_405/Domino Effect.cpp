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
    int tc;
    SC(tc);
    char a[3001];
    FOR(i,1,tc)cin>>a[i];
    int l=0,r=0,d=0;
    int  u1=0,u2=0,u3=0;
    int sum=0;
    FOR(i,1,tc)
    {
        r=0;
        l=0;
        if(a[i]=='.')
        {
            for(int j=i-1; j>=1; j--)
            {
                if(a[j]=='L')
                {
                    break;
                }
                else    if(a[j]=='R')
                {
                    r=i-j;
                }
            }
            for(int k=i+1; k<=tc; k++)
            {
                if(a[k]=='R')
                {
                    break;
                }
                else if(a[k]=='L')
                {
                    l=k-i;
                }

            }

if(r==l)sum++;
        }

    }

cout<<sum<<endl;
//main();
    return 0;
}
