#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int a[10000];
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>a[i];
    }
    int b=0,c=0;

    for(int i=1; i<=t; i++)
    {
        if(a[i]==5)b++;
        else c++;
    }

    int l=0,k=0;
    if(c!=0)
    {
        for(int i=b; i>=1; i--)
        {
            if(i*5%9==0)
            {
                k=i;
                l=1;break;

            }

        }
        if(k>0)
        {
            for(int i=1; i<=k; i++)
            {
                cout<<"5";
            }
            for(int k=1; k<=c; k++)
            {
                cout<<"0";

            }
            cout<<endl;
        }
    }
   else if(c==0)
    {

        cout<<"-1"<<endl;
    }
    if(l==0&&c!=0)cout<<"0"<<endl;
   // else if(l==0&&c==0)cout<<"-1"<<endl;

    return 0;
}
