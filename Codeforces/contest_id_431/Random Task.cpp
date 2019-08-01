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
LL n,m;
LL val,k1;
LL D[65][65][3];
LL s[65][65][3];
LL dp(LL b,LL on,LL ch)
{
    if(b==-1)
    {
        if(on==m)return 1;
        else return 0;
    }
    LL &ret=D[b][on][ch];
    if(s[b][on][ch]==k1)return ret;
    s[b][on][ch]=k1;
    LL sum=0;
    if(ch)
    {
        sum+=dp(b-1,on+1,ch);
        sum+=dp(b-1,on,ch);
    }
    else
    {
        if((val&(1LL<<b))==0)
        {
            sum+=dp(b-1,on,ch);
        }
        else
        {
            sum+=dp(b-1,on+1,ch);
            sum+=dp(b-1,on,1);
        }

    }
    return ret=sum;
}
LL bs(LL lo,LL hi)
{
    LL be;
    LL his=0;
    while(lo<=hi)
    {
        //coute"<<endl
        his++;
        LL mid=(lo/2)+(hi/2);
        if(lo%2==1&&hi%2==1)mid++;
        val=2*mid;
        k1++;
        LL su=dp(62,0,0);
        //cout<<mid<<endl;
        val=mid;
        k1++;
        su-=dp(62,0,0);
        if(su>=n)
        {
            hi=mid-1;
            be=mid;
        }
        else lo=mid+1;


    }
    return be;
}
int main()
{
    cin>>n>>m;
    k1=9;
    LL res=bs(1LL,1000000000000000000LL);
    cout<<res<<endl;
    return 0;
}
