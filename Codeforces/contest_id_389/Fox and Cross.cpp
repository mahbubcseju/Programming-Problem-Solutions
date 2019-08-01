#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    char ch[102][102];
    for(int i=1; i<=t; i++)
    {
        for(int j=1; j<=t; j++)
        {
            cin>>ch[i][j];
        }

    }
    for(int i=2; i<t; i++)
    {
        for(int j=2; j<t; j++)
        {
            if(ch[i][j]=='#'&&ch[i-1][j]=='#'&&ch[i+1][j]=='#'&&ch[i][j-1]=='#'&&ch[i][j+1]=='#')
            {
                ch[i][j]='k';
                ch[i-1][j]='k';
                ch[i+1][j]='k';
                ch[i][j-1]='k';
                ch[i][j+1]='k';
            }
        }

    }
    int h=0;
    for(int i=1; i<=t; i++)
    {
        for(int j=1; j<=t; j++)
        {
            if(ch[i][j]=='#')
            {
                h=1;
                //cout<<i<<j<<endl;
                break;
            }
        }

    }
    if(h==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

