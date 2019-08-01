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
int no[600004];
int a[200003];
void update(int node,int i,int j)
{
    if(i==j)
    {
        no[node]=a[i];
        return ;
    }
    update(node*2,i,(i+j)/2);
    update(node*2+1,(i+j)/2+1,j);
    no[node]=max(no[node*2],no[node*2+1]);
}
int query(int nod,int st,int en,int i,int j)
{
    if(i>=st&&j<=en)return no[nod];
    if(j<st||i>en)return 0;
    return max(query(nod*2,st,en,i,(i+j)/2),query(nod*2+1,st,en,(i+j)/2+1,j));

}
int main()
{
int n,t,c;
cin>>n>>t>>c;
for(int i=1;i<=n;i++){
cin>>a[i];
}
update(1,1,n);
int sum=0;
for(int i=1;i<=(n-c+1);i++){
int l=query(1,i,i+c-1,1,n);
if(l<=t)sum++;

}
cout<<sum<<endl;
    return 0;
}

