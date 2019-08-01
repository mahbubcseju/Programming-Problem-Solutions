#include<bits/stdc++.h>


using namespace std;
#define sc scanf
#define ll long long

#define mx 100000



int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0);


      ll n,k;
      cin>>n>>k;
      ll ar[n+2];
      for(int i=1;i<=n;i++)
      {
          cin>>ar[i];
      }
      ll br[n+2];
      for(int i=1;i<=n;i++)cin>>br[i];


        ll lo=0,hi=2e12;

      ll res=-1;
      ll car[n+2];
      ll cbr[n+2];
      while(lo<=hi)
      {
            ll mid=(lo+hi)/2;

            priority_queue<pair<ll,ll> >pq;

            for(int i=1;i<=n;i++){

                car[i]=ar[i];
                cbr[i]=br[i];
                pq.push(make_pair(-ar[i]/br[i],i));
            }
            bool fl=0;
            for(int i=0;i<k;i++)
            {
                pair<ll,ll>f=pq.top();
                pq.pop();
              //  cout<<f.first<<endl;
                if(-f.first<i){
                    fl=1;
                    break;
                }
                if(-f.first>k)continue;
                int f1=f.second;
                car[f1]+=mid;
                pq.push(make_pair(-car[f1]/cbr[f1],f1));

            }
           // cout<<fl<<endl;
            if(fl==0)
            {
                hi=mid-1;
                res=mid;
            }
            else lo=mid+1;


            //break;
      }
      cout<<res<<endl;





    return 0;
}