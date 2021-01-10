#include<iostream>
using namespace std;


void movetoend(int a[],int n,int k);

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    movetoend(a,n,k);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void movetoend(int a[],int n,int k){
    int front=0;
    int back=n-1;
    while(back>front){
        if(a[back]==k){
            back=back-1;
            continue;
        }
        if(a[front]==k){
            swap(a[front],a[back]);
            continue;
        }

       front++;


    }

}