#include<bits/stdc++.h>
using namespace std;
int main(){
int m,n;
cin>>m>>n;
int a=0,b=0,c=0;
for(int i=1;i<=6;i++){
if(abs(i-m)>abs(i-n))b++;
else if(abs(i-m)<abs(i-n))a++;
else c++;

}

cout<<a<<" "<<c<<" "<<b<<endl;
return 0;
}
