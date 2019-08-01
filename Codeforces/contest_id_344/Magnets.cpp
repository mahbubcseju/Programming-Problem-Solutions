
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
int main()
{
    long long int i;
    cin>>i;
    string a[100000];
    for(int t=0;t<i;t++){

    cin>>a[t];


    }
    int sum=1;
    for(int t=1;t<i;t++){
    if(a[t-1][1]==a[t][0])sum++;


    }
    cout<<sum<<endl;


    return 0;
}





