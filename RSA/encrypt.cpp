#include<iostream>
#include<string>
using namespace std;
long long exp(long long a,long long b,long long c){
if(b==0)return 1;
if(b%2==1)return ((a%c)*exp((a*a)%c,b/2,c))%c;
if((b%2)==0)return exp((a*a)%c,b/2,c)%c;
return 0;
} 
long long bits(long long n){
if(n==0)return 0;
return 1+bits(n/2);
}
int main(){
string s;
cout<<"Enter message\n";
getline(cin,s);
int len=s.length();
bool message[8*len];
for(int i=0;i<len;i++){
for(int j=7;j>=0;j--){
message[8*i+j]=s[i]%2;
s[i]/=2;
}
}
long long n,e;
cout<<"Enter n,e ";cin>>n>>e;
long long b;
b=bits(n);
long long groups=8*len/(b-1),last=(8*len)%(b-1);
if(!(last==0))groups++;
bool code[b*groups];
for(int i=0;i<groups;i++){
long long power=1,sum=0,x;
long long j=b-2;
if(i==groups-1&&last!=0)j=last-1;
for(;j>=0;j--){
sum+=message[(b-1)*i+j]*power;
power*=2;
}
x=exp(sum,e,n);
for(int j=b-1;j>=0;j--){
code[i*b+j]=x%2;
x/=2;
}
}
for(long long q=0;q<b*groups;q++){
cout<<code[q];
}
cout<<endl;
}  
