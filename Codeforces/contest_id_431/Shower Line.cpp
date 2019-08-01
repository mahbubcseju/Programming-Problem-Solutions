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
    int g[6][6];
    for(int i=1; i<=5; i++)
        for(int j=1; j<=5; j++)cin>>g[i][j];
    int a[5]= {1,2,3,4,5};
    LL sum=0;
    do
    {
        LL s=g[a[0]][a[1]]+g[a[1]][a[0]]+2*(g[a[2]][a[3]]+g[a[3]][a[2]])+g[a[1]][a[2]]+g[a[2]][a[1]];
        s+=2*(g[a[3]][a[4]]+g[a[4]][a[3]]);
        if(s>sum)sum=s;
    }
    while(next_permutation(a,a+5));
    cout<<sum<<endl;
    return 0;
}

