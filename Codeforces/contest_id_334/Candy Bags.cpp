#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main(){
int i;
cin>>i;
int k=i*i;int r=1;
for(int j=1;j<=i;j++){int f=0;
        for(int t=1;t<=i/2;t++){f++;
if(f==1)cout<<r<<" "<<k;
else cout<<" "<<r<<" "<<k;

r++;k--;
        }cout<<"\n";

}

return 0;
}
