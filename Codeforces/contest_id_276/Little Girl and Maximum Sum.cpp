#include<bits/stdc++.h>
using namespace std;
long long arr[200010],n,m,fin[200010],tree[800010],l,r;
void build(long long nd,long long s,long long e,long long i,long long j)
{
    if(s>=i&&e<=j)
    {
        tree[nd]++;
        return;
    }
    if(e<i||s>j)return;
    long long mid=(s+e)/2;
    if(tree[nd])
    {
        tree[2*nd]+=tree[nd];
        tree[2*nd+1]+=tree[nd];
        tree[nd]=0;
    }
    build(nd*2,s,mid,i,j);
    build(nd*2+1,mid+1,e,i,j);
}

void update(long long nd,long long s,long long e)
{
    if(s==e)
    {
        fin[s]=tree[nd];
        return ;
    }
    long long mid=(s+e)/2;
    if(tree[nd])
    {
        tree[2*nd]+=tree[nd];
        tree[2*nd+1]+=tree[nd];
        tree[nd]=0;
    }
    update(nd*2,s,mid);

    update(nd*2+1,mid+1,e);

}
int  main()
{

    scanf("%lld%lld",&n,&m);
    for(long long i=1; i<=n; i++)scanf("%lld",&arr[i]);
    for(long long i=1; i<=m; i++)
    {
      scanf("%lld%lld",&l,&r);
        build(1,1,n,l,r);

    }
    long long ret;
    update(1,1,n);
    sort(fin+1,fin+n+1);
    sort(arr+1,arr+n+1);
    ret=0;
    for(long long i=n; i>0; i--)
    {
        ret+=(fin[i]*arr[i]);
    }
    cout<<ret<<endl;
    return 0;
}

