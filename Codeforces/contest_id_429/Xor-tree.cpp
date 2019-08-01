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
vector<int>a[100004];
int b[100004],c[100004];
vector<int>v;
struct da
{
    int x,y;
};
da t[100004];
void dfs(int s,int p)
{
    int l=t[s].x;
    if(t[s].x%2==1)
    {
        b[s]=(b[s]+1)%2;
    }
    if(b[s]!=c[s])
    {
        b[s]=c[s];
        v.PB(s);
        l++;
    }
    for(int i=0; i<a[s].size(); i++)
    {
        int l1=a[s][i];
        if(l1!=p)
        {
            t[l1].y=l;
            t[l1].x=t[s].y;
            dfs(l1,s);

        }
    }

}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].PB(y);
        a[y].PB(x);
    }
    for(int j=1; j<=n; j++)
    {
        cin>>b[j];
    }
    for(int k=1; k<=n; k++)
    {
        cin>>c[k];
    }
    dfs(1,0);
    cout<<v.size()<<endl;
    for(int i=0;i<SZ(v);i++)cout<<v[i]<<endl;
    return 0;
}
