#include<iostream>
using namespace std;


int po[100]={0};
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(po[b]!=0){
        return po[b];
    }

    if(b%2==0){
        po[b]= power(a,b/2)*power(a,b/2);
        return po[b];
    }else{
        po[b]= a*power(a,b/2)*power(a,b/2);
        return po[b];
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    int ans=1;

    cout<<power(a,b)<<endl;
    while(b!=0){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b=b>>1;
    }
    cout<<ans<<endl;
    return 0;
}