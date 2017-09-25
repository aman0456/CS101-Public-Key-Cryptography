#include<iostream>
using namespace std;
long long exp(long long a,long long b,long long c){
if(b==0)return 1;
if(b%2==1)return ((a%c)*exp((a*a)%c,b/2,c))%c;
if((b%2)==0)return exp((a*a)%c,b/2,c)%c;
return 0;
} 
int main(){
long long int a,b,c;
cin>>a>>b>>c;
cout<<exp(a,b,c)<<endl;
}
