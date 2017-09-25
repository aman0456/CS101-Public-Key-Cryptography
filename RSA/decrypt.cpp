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
string code;
cout<<"Enter Code ";
cin>>code;
long long n,d;
cout<<"Enter n,d ";
cin>>n>>d;
long long b,len=code.length();
b=bits(n);
long long groups=len/b;
bool message[(b-1)*groups];
for(long long i=0;i<groups;i++){
long long power=1,sum=0,x;
for(long long j=b-1;j>=0;j--){
sum+=(code[b*i+j]-48)*power;
power*=2;
}
x=exp(sum,d,n);
for(long long j=b-2;j>=0;j--){
message[i*(b-1)+j]=x%2;
x/=2;
}
}
long long last=8-((groups-1)*(b-1))%8,no=groups*(b-1),count=0;
while(b-1-last-count*8>8){ 
if((message[no-1-last-count*0]==0)&&(message[no-1-last-count*1]==0)&&(message[no-1-last-count*2]==0)&&(message[no-1-last-count*3]==0)&&(message[no-1-last-count*4]==0)&&(message[no-1-last-count*5]==0)&&(message[no-1-last-count*6]==0)&&(message[no-1-last-count*7]==0))
break;
count++;
}
for(int q=0;q<last+8*count;q++){
message[(groups-1)*(b-1)+q]=message[(groups-1)*(b-1)+q+b-1-(last+count*8)];
}
char s[((groups-1)*(b-1)+last)/8+count];
for(long long i=0;i<((groups-1)*(b-1)+last)/8+count;i++){
s[i]=0;int power=1;
for(int j=7;j>=0;j--){
s[i]+=message[i*8+j]*power;
power*=2;
}
cout<<s[i];
}
cout<<endl;
}