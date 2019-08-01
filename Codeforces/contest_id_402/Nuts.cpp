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
using namespace std;
#define M 9999999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//

int main()
{
    int k,a,b,v;
    SC(k);
    SC(a);
    SC(b);
    SC(v);
    int sum=0;
    while(1)
    {

        int l=min(k-1,b);

        if((l+1)*v>=a)
        {
            sum++;
            cout<<sum<<endl;
            return 0;
        }
        sum++;
        a-=(l+1)*v;
        b-=l;

    }
    // main();


    return 0;
}


