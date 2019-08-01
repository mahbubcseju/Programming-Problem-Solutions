#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll  n,k,x;
    scanf("%lld %lld %lld",&n,&k,&x);
    long long  a[n+2];
    for(long long i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    ll res[n+2];
    ll ant[n+2];
    res[0]=0;
    ant[n+1]=0;
    for(ll i=1; i<=n; i++)
        res[i]=res[i-1]|a[i];
    for(ll i=n; i>=1; i--)
        ant[i]=ant[i+1]|a[i];
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        ll ko=a[i];
        for(ll  j=1; j<=k; j++)
        {
            ko*=x;
        }
        ll re=res[i-1]|ko;
        re=re|ant[i+1];
        ans=max(ans,re);
    }
    printf("%lld\n",ans);
    return 0;
}
