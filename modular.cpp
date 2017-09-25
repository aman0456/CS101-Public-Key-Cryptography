#include<iostream>
#include<string>
using namespace std;
long long p=1;
long long mod (string a,long long c,long long p){
if (a.length()==0) return 0;
return (mod(a.substr(0,a.length()-1),c,(p*10)%c)+((a[a.length()-1]-48)*p)%c)%c;
 }
int main(){
cout<<"press 1 for modular addition 2 for subtraction 3 for multiplication"<<endl;
int command;cin>>command;
if(command==1){
cout<<"enter a,b,c ";
string a,b;
cin>>a>>b;
long long c;
cin>>c;
cout<<(mod(a,c,p)+mod(b,c,p))%c<<endl;
}
if(command==2){
cout<<"enter a,b,c ";
string a,b;
cin>>a>>b;
long long c;
cin>>c;
cout<<(mod(a,c,p)-mod(b,c,p))%c<<endl;
}
if(command==3){
cout<<"enter a,b,c ";
string a,b;
cin>>a>>b;
long long c;
cin>>c;
cout<<((mod(a,c,p))%c*(mod(b,c,p)%c))%c<<endl;
}
}