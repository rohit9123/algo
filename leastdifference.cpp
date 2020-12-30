#include<iostream>
using namespace std;

int main(){
int n,m;
cin>>n>>m;
int a[n],b[m];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int j=0;j<m;j++){
    cin>>b[j];
}
sort(a,a+n);
sort(b,b+n);

int diff=INT32_MAX,i=0,j=0,first=0,second=0;
while(i<n&&j<m){
    int dif=abs(a[i]-b[j]);
    if(diff>dif){
        first=a[i];
        second=b[j];
        diff=dif;
    }
    if(a[i]>b[j]){
        j++;
    }
    if(a[i]==b[i]){
        cout<<0<<" "<<a[i]<<" "<<b[i]<<endl;
        return 0;
    }
    if(a[i]<b[j]){
        i++;
    }
}
cout<<first<<" "<<second<<" "<<diff<<endl;

return 0;



}