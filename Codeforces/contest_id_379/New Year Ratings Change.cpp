#include<bits/stdc++.h>
using namespace std;
int mai=3*100001;
struct dt
{
    int v,id;
    void set(int _v,int _id)
    {
        v=_v,id=_id;
    }
    bool operator<(const dt& p)const
    {
        return v<p.v;
    }

} ma[3*100001];
int main()
{
    int n;
    cin >>n;
    for(int i=1; i<=n; i++)
    {
        int v;
        cin>>v;
        ma[i].set(v,i);

    }
    sort(ma+1,ma+n+1);
    int ans[n];
    int tem=ma[1].id;
    ans[tem]=ma[1].v;
    tem=ma[1].v;
    for(int i=2; i<=n; i++)
    {
        int j=ma[i].v;
        int k=ma[i].id;

        ans[k]=max(tem+1,j);
        tem=ans[k];
    }
    cout<<ans[1];
    for(int i=2; i<=n; i++)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}
