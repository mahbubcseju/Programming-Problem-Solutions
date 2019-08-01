#include<bits/stdc++.h>
using namespace std;
int a[301];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    int k=0,l=1;
    int y=0;
    while(1)
    {
        k++;
        for(int i=1; i<=n; i++)
        {
            if(mp[i]==a[i])
            {
                if(i<n)
                    cout<<"R";
            }
            else
            {


                if(k>1&&i==1)cout<<"R";
                else if(i!=n)
                    {cout<<"PR";mp[i]++;}
                else {cout<<"P";mp[i]++;}

                if(mp[i]!=a[i])y++;
            }
        }
        //cout<<"efer"<<endl;
        if(y==0)
        {
            cout<<endl;
            break;
        }
        y=0;
        for(int i=n; i>=1; i--)
        {

            if(mp[i]==a[i])
            {
                if(i>1)
                    cout<<"L";
            }
            else
            {

                if(i==n)cout<<"L";
                else    if(i!=1)
                    {cout<<"PL";mp[i]++;}
                else {cout<<"P";mp[i]++;}

                if(mp[i]!=a[i])y++;
            }
        }
       // cout<<y<<endl;
        if(y==0)
        {
            // if(mp[n]==a[n])
            cout<<endl;
            break;
        }
        y=0;
    }

    return 0;
}
