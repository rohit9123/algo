#include<iostream>
using namespace std;
int left(int i){
    return i*2+1;
}
int right(int i){
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}
void makeheapify(int a[],int i,int n);
void make_heap(int a[],int n);
void sortedarray(int a[],int i,int n);

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    make_heap(a,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    sortedarray(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}


void sortedarray(int a[],int i,int n){

while(n>i){
    cout<<n<<" ";
    swap(a[i],a[n--]);
    
    makeheapify(a,0,n);
}
cout<<endl;

}

void make_heap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        makeheapify(a,i,n);
    }
}
void makeheapify(int a[],int i,int n){
    int l=left(i);
    int r=right(i);
    if(l>n&&r>n){
        return;
    }
    if(l<=n&&r<=n){
        int index=i;
        if(a[i]<a[l]){
            index=l;
        }
        if(a[index]<a[r]){
            index=r;
        }
        if(index!=i){
        swap(a[i],a[index]);
        makeheapify(a,index,n);}
    }
    else if(l<=n){
            if(a[l]>a[i]){
            swap(a[l],a[i]);
            makeheapify(a,l,n);};
        }
    


}