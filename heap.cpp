#include<iostream>
using namespace std;

int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
int parent(int i){
    return floor((i-1)/2);
}

void minheapify(int a[],int i,int n);
void minheap(int a[],int n,int i){


    int l=left(i);
    int r=right(i);
    if(l>n&&r>n){
        return;
    }

    if(l<=n){
        minheap(a,n,l);
    }
    if(r<=n){
        minheap(a,n,r);
    }
    if(l<=n&&r<=n){
        int index=i;
         if(a[i]>a[l]){
            index=l;
        }
        if(a[index]>a[r]){
            index=r;
        }
        if(index!=i){
        int temp=a[i];
        a[i]=a[index];
        a[index]=temp;
        minheapify(a,index,n);
        }
    }else if(l<=n){
        if(a[i]>a[l]){
            int temp=a[i];
            a[i]=a[l];
            a[l]=temp;
            minheapify(a,l,n);
        }
    }
    return;

}


void minheapiterative(int a[],int n){
    for(int i=n/2;i>=0;i--){
        minheapify(a,i,n);
    }


}
void minheapify(int a[],int i,int n){


    int index=i;
    int l=left(i);
    int r=right(i);
    if(l>n&&r>n){
        return;
    }

    if(l<=n&&r<=n){
        if(a[i]>a[l]){
            index=l;
        }
        if(a[index]>a[r]){
            index=r;
        }
        if(index!=i){
        int temp=a[i];
        a[i]=a[index];
        a[index]=temp;
        minheapify(a,index,n);
        }
       
    }
    else if(l<=n){
        if(a[i]>a[l]){
            int temp=a[i];
            a[i]=a[l];
            a[l]=temp;
            minheapify(a,l,n);
        }
    }

}
int extractmin(int a[],int n){
    int copy=a[0];
    a[0]=a[n];
    a[n]=INT_MAX;
    minheapify(a,0,n-1);
    return copy;
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    minheap(a,n-1,0);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    minheapiterative(a,n-1);
    

    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<extractmin(a,n-1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}