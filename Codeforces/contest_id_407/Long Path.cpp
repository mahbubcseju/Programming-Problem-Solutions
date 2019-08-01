
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
#define I int
#define LL long long int
#define UL unsigned long long int
#define S(a) scanf("%d",&a)
#define SD(a,b) scanf("%d%d",&a,&b)
#define SL(a) scanf("%I64d",&a)
#define SLD(a,b) scanf("%I64d%I64d",&a,&b)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%I64d\n",a)
#define PC(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
using namespace std;
#define MX 99999999999
#define MD 1000000007
#define eps 1e-9
/////////////////////////////
////////////////////////////
////Function Area Start////
I a[1004];
I n;
LL DP[1004][4];
/*
LL dp(int i,int j)
{
    if(i==n+1)return 0;
    int &ret=DP[i][j];
    if(ret!=-1)return ret;
    if(j==1)
    {
        j=0;
        ret=(1+dp(a[i],j))%MD;
    }
    else
    {
        ret=(1+dp(i+1,1))%MD;
    }
        return ret;
}
*/
int main()
{

    S(n);
    F(t,1,n)
    {
        S(a[t]);
    }
    //SETR(DP);
    DP[1][1]=0;
    DP[1][2]=1;
    for(int i=2;i<=n;i++){
        DP[i][1]=(DP[i-1][2]+1)%MD;
        DP[i][2]=(((DP[i][1]+1)%MD+DP[i][1])%MD-DP[a[i]][1]);
        DP[i][2]=(DP[i][2]+MD)%MD;

    }

    P((DP[n][2]+1)%MD);
    return 0;
}
