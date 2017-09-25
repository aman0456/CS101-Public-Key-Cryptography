#include<iostream>
#include<string>
using namespace std;
char add(char &c,char &d){
    if(c==d)return '0';
    else return '1';
    return 0;
}
struct field{
    long long m;
    string s="";
    field operator+(const field &x){
        field a;a.m=m;long long i;
        for(i=0;i<=m;i++){
            if(s[i]==x.s[i])a.s+="0";
            else a.s+="1";
                }
        
        return a;
    }
    field mult(field &x,const field &c){field d;d.m=m;d.s=s;
        field a;a.m=m;string q="";
        for(long long p=0;p<=m;p++)q=q+"0";a.s=q;
        for(long long j=0;j<=m;j++){
            if(d.s==q||x.s==q)break;
            if(d.s[m-j]=='1'){
                a=a+x;
            }
            if(x.s[0]=='1'){
                x=x+c;
            }
            for(long long i=0;i<m;i++){
                x.s[i]=x.s[i+1];
            }
            x.s[m]='0';
            d.s[m-j]='0';
        }
        return a;
    }
};
int main(){int z;
    cout<<"For addition press 1 & for multiplication press 2";cin>>z;
    long long n;string s;
    cin>>n>>s;
    if(s.length()!=n+1){cout<<"wrong input";return 0;}
    field f1;
    f1.m=n;f1.s=s;
    cin>>s;
    if(s.length()!=n+1){cout<<"wrong input";return 0;}
    field f2;
    f2.m=n;f2.s=s;
    field f3=f1+f2;if(z==1)cout<<f3.s;
    re;  re.m=n;cin>>re.s;if(re.s.length()!=n+1){cout<<"wrong input";return 0;}
  
    field f4=f1.mult(f2,re);if(z==2)cout<<endl<<f4.s;
    return 0;
}
