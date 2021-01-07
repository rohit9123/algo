#include<iostream>
#include<string>

using namespace std;
int main(){
    string a;
    cin>>a;
    int n=a.size();
    int le=0;
    for(int i=0;i<n;i++){
        int k=i-1,j=i+1,m=i;
        int len=1;
        int men=0;
        while(k>=0&&j<n){
            if(a[k]==a[j]){
                j++;
                k--;
                len+=2;
            }else{
                break;
            }

        }
        k=i-1;
        le=max(le,len);
        while(k>=0&&m<n){
            if(a[k]==a[m]){
                // cout<<a[k]<<" "<<a[m]<<endl;
                // cout<<i<<endl;
                k--;
                m++;
                men+=2;
            }else{
                // cout<<endl;
                break;
            }
        }
        le=max(le,men);
    }
    cout<<le<<endl;
    return 0;

}