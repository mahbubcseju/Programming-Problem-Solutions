#include<bits/stdc++.h>
using namespace std;
int main(){
string a;
cin>>a;
reverse(a.begin(),a.end());
for(int i=0;i<a.size();i++){
if(a[i]=='0')printf("O-|-OOOO\n");
else if(a[i]=='1')printf("O-|O-OOO\n");
else if(a[i]=='2')printf("O-|OO-OO\n");
else if(a[i]=='3')printf("O-|OOO-O\n");
else if(a[i]=='4')printf("O-|OOOO-\n");
else if(a[i]=='5')printf("-O|-OOOO\n");
else if(a[i]=='6')printf("-O|O-OOO\n");
else if(a[i]=='7')printf("-O|OO-OO\n");
else if(a[i]=='8')printf("-O|OOO-O\n");
else if(a[i]=='9')printf("-O|OOOO-\n");


}
return 0;
}
