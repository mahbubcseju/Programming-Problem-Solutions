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
bool check(int x,int y)
{
    return (bool)(x&(1<<y));
}
queue<int>q[100004];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int l=i;
        int sum=0;
        for(int j=0;; j++)
        {
            if(check(l,j)==1)
            {
                sum=pow(2,j);
                break;
            }
        }
        // cout<<sum<<endl;
        q[sum].push(i);
    }
    vector<int>v;
    for(int i=30; i>=0; i--)
    {
        if(check(n,i)==1)
        {
            int l=pow(2,i);
            for(int j=l; l>0&&j; j=j/2)
            {
                if(q[j].size()>0)
                {
                    while(!q[j].empty()&&l>0)
                    {
                        int y=q[j].front();
                        v.PB(y);
                        l-=j;
                        q[j].pop();
                    }
                }
            }
            if(l!=0)
            {
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    cout<<SZ(v)<<endl;
    for(int i=0; i<SZ(v); i++)
    {
        if(i==0)cout<<v[i];
        else cout<<" "<<v[i];

    }
    cout<<endl;
    return 0;
}

