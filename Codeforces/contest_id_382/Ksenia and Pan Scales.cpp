#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s,a,b;
    cin>>s;
    int d=0;
    for(int i=0; s[i]!='|'; i++)
    {

        a+=s[i];
        d++;
    }
    for(int i=d+1; i<s.size(); i++)
    {
        b+=s[i];
    }
    string h;
    cin>>h;int k=a.size();
    int g=-1,l=b.size();
    int p=abs(k-l);
//cout<<k<<l<<endl;
    if(k>l)
    {
        for(int i=0; i<p&&i<h.size(); i++)
        {
            b+=h[i];g=i;
        }

    }

    else if(l>k)
    {
        for(int i=0; i<p&&i<h.size(); i++)
        {
            a+=h[i];
            g=i;
          // cout<<g<<endl;
        }
    }
//cout<<a<<b<<endl;
    for(int i=g+1; i<h.size(); i++)
    {//cout<<g<<endl;
        if(i%2==0)
        {
            a+=h[i];
        }
        else b+=h[i];

    }
   // cout<<a<<b<<endl;
    if(a.size()!=b.size())cout<<"Impossible"<<endl;
    else cout<<a<<'|'<<b<<endl;

    return 0;
}
