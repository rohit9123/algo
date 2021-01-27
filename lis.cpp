#include<iostream>
using namespace std;
int findind(int b[],int start,int end,int no){
    while(start<end)
    { int mid=(start+end)/2;
        if(b[mid]>=no){
            end=mid;
        }
        else
            start=mid+1;

    }
    return end;


}

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=0;
    }

    int length=0;
    b[0]=a[0];
    length++;
    for(int i=1;i<n;i++){
        if(a[i]>b[length-1])
        {
            b[length]=a[i];
            length++;
        }else{
            int c=findind(b,0,length-1,a[i]);
            b[c]=a[i];
        }
    }
    cout<<length<<endl;

}