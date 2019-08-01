#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int m,n;
    cin>>m>>n;
    int a=0,b=0,c=m;
    while(1)
    {
        a+=m%n;
        int u=m/n;
        b+=u;
        m=u+a;
        a=0;
        if(m<n)break;
    }
    b+=c;
    cout<<b<<endl;
    return 0;
}
