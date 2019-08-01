#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
int s=b%a;

if(s==0)return a;
else return gcd(s,a);
}
int main()
{
    int n;
    int a[101];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int x=a[0];
    for(int i=1;i<n;i++){
    x=gcd(x,a[i]);
    }
 int   sum=x*n;
    cout<<sum<<endl;

    return 0;
}
