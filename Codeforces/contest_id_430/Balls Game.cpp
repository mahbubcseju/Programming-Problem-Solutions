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
    int n,m,p;
    SC(n);
    SC(m);
    SC(p);
    int a[n+1];
    FOR(i,1,n)SC(a[i]);
    int b[n+1];
    vector<int>v;
    v.push_back(a[1]);
    b[0]=1;
    for(int i=2; i<=n; i++)
    {
        if(a[i]==a[i-1])
        {
            b[SZ(v)-1]++;
        }
        else
        {
            v.push_back(a[i]);
            b[SZ(v)-1]=1;
        }
    }
    int sum=0;
    for(int k=0; k<SZ(v); k++)
    {
        if(b[k]>=2&&v[k]==p)
        {
            int su=b[k];
            int l=k-1;
            int l1=k+1;
            while(1)
            {
                if(l>=0&&l1<SZ(v)&&v[l]==v[l1]&&b[l]+b[l1]>=3)
                {
                    su+=b[l]+b[l1];

                    l--;
                    l1++;
                }
                else break;

            }
            sum=max(su,sum);

        }

    }
    cout<<sum<<endl;
    return 0;
}
