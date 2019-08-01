#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[101];
    memset(a,0,sizeof(a));
    for(int i=1; i<=n; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u]-=c;
        a[v]+=c;



    }
    int sum=0;
    for(int i=1; i<=m; i++)
    {
        if(a[i]>0)sum+=a[i];

    }
    cout<<sum<<endl;







    return 0;
}


