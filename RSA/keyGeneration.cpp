#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
long long gcd(long long m, long long n){
if(m%n==0){
return n;}
else {
return gcd(n,m%n);}
}
long long inverse(long long a,long long b){
long long j,k,m,l,i;
i=b;
if(gcd(a,b)==1){
j=1;
m=0;
while(b!=1){
l=a;
a=b;
b=l%b;
l=a/b;
m+=-j*l;
l=m;
m=j;
j=l;
}
if(m>0)return m%i;
else return i+(m%i);
}
else return 0;
}
long long exp(long long a,long long b,long long c){
if(b==0)return 1;
if(b%2==1)return ((a%c)*exp((a*a)%c,b/2,c))%c;
if((b%2)==0)return exp((a*a)%c,b/2,c)%c;
return 0;
} 
int encryptionKey(){
int dummy=rand()%1000;
if(dummy%5==0)return 3;
if(dummy%5==1)return 5;
if(dummy%5==2)return 17;
if(dummy%5==3)return 257;
return 65537;
}
long long prime(){
long long n,d,s=0;
n=rand()%1000;
for(int i=2;i<50;i++)if(n%i==0)return prime();
d=n-1;
while(d%2==0){
s++;
d/=2;
}
bool b=0;
int a=rand()%1000;
while(a>=n){
 a=rand()%500;}
 if(exp(a,d,n)==1)b=1;
 for(int i=0;i<=s-1;i++){
 if(exp(a,pow(2,i)*d,n)==-1){
 b=1;break;
 }
 }
 if(b==1)return n;
 return prime();
 }
int main(){
srand(time(NULL));
long long p=prime();
long long q=prime();
long long n=p*q,f=(p-1)*(q-1);
int e=encryptionKey();
long long d=inverse(e,f);
while(d==0){
e=encryptionKey();
d=inverse(e,f);
}
cout<<"n :"<<n<<"\te : "<<e<<"\td :"<<d<<endl;
}

