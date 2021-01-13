#include<iostream>
using namespace std;

void quicksort(int a[],int start,int end){
    int n=end;
    int first=start+1;
    while(first<=end){
        if(a[first]<=a[start]){
            first++;
            continue;
        }
        if(a[end]>a[start]){
            end--;
            continue;
        }
        if(a[first]>a[start]&&a[start]>=a[end]){
            swap(a[first],a[end]);
            first++;
            end--;
            continue;
        }
    }
    swap(a[start],a[end]);
    int next=end-start;
    int next2=n-end;
    if(next>1){
        quicksort(a,start,end-1);
    }
    if(next2>1){
        quicksort(a,end+1,n);
    }
}



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


}