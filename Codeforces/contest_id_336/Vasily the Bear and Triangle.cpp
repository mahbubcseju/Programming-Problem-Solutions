
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<map>
#define pi 2*acos(0.0)
#include<algorithm>
using namespace std;
int main(){
long long i,j;
while(cin>>i>>j){
if(i>0&&j>0){
    cout<<"0 "<<i+j<<" "<<i+j<<" 0"<<endl;

}
else if(i<0&&j>0){
        i=-i;
   cout<<"-"<<i+j<<" "<<"0"<<" "<<"0"<<" "<<i+j<<endl;

}
else if(i<0&&j<0){
   i=-i;
   j=-j;
   cout<<"-"<<i+j<<" "<<"0"<<" "<<"0"<<" "<<"-"<<i+j<<endl;


}
else if(i>0&&j<0){j=-j;
cout<<"0"<<" "<<"-"<<i+j<<" "<<i+j<<" "<<"0"<<endl;

}
}


return 0;
}
