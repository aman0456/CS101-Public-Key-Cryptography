#include<iostream>
using namespace std;
long long gcd(long long &m, long long &n){
if(m%n==0){
return n;}
else {
long long p=m%n;
return gcd(n,p);}
}
long long inverse(const long long &p,const long long &i){
long long j,k,m,n,l,b,a=p;
b=i;
if(gcd(a,b)==1){
j=1;
k=-a/b;
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
long long expo(const long long &a,const long long &b,const long long &n){
long long p=b,k=a%n,ans=1;
while(p!=0){
if(p%2==1)ans=(ans*k)%n;
k=(k*k)%n;
p/=2;
}
return ans;
}
long long find(const long long &p,const long long &m,const long long alpha[],long long &b,const long long &n){
for(long long i=0;i<m;i++){
for(long long j=0;j<m;j++){
if(alpha[j]==b)return i*m+j;
}
b=(b*p)%n;
}
return 0;
}
int main(){
long long n,a,b,p;
    cout<<"Enter a,b,n such that b=a^(x)(mod n):";
cin>>n>>a>>b;
p=1;
long long m=0,alpha[n];
while(m*m<n){
alpha[m]=p;
p=(p*(a%n))%n;
m++;
}
p=expo(a,m,n);
p=inverse(p,n);
p=find(p,m,alpha,b,n);
cout<<p;
}
