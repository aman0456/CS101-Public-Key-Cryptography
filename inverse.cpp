#include<iostream>
using namespace std;
long long gcd(long long m, long long n){
if(m%n==0){
return n;}
else {
return gcd(n,m%n);}
}
long long inverse(long long &a,long long &b){
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
int main(){
    int n;long long a,b;
    cout<<"Press 1 for gcd and 2 for inverse";
    cin>>n;
    if(n==1){
        cin>>a>>b;
        cout<<gcd(a,b);
        
    }
    if(n==2){
        cin>>a>>b;
        cout<<inverse(a,b);
    }
}
