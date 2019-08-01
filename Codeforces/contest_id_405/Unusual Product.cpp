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
    int n,m;
    SC(n);
    int a[n+1][n+1];
    int sum=0;
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            SC(a[i][j]);
            if(i==j)
            {
                if(a[i][j]==1)sum++;
            }
        }
    }
    int q;
    SC(q);

    FOR(j,1,q)
    {
        int w,p;
        SC(w);
        if(w==1)
        {
            int t;
            SC(t);
            if(a[t][t]==1)
            {
                a[t][t]=0;
                sum--;
            }
            else
            {
                a[t][t]=1;
                sum++;
            }
        }
        else if(w==2)
        {
            int t;
            SC(t);
            if(a[t][t]==1)
            {
                a[t][t]=0;
                sum--;
            }
            else
            {
                a[t][t]=1;
                sum++;
            }

        }
        else if(w==3)
        {

            if(sum%2==1)
            {
                cout<<1;
            }
            else cout<<0;
        }

    }
    cout<<endl;
    return 0;
}
