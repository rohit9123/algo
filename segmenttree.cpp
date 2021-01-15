#include<iostream>
using namespace std;
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}

void update(int* segmentree,int start,int end,int index,int difference,int position){
    // if(start<=index&&end>=index){
    //     segmentree[position]=segmentree[position]+difference;
    //     return;
    // }
    // cout<<start<<" "<<end;

    if(start>index||index>end){
        return;
    }
     segmentree[position]=segmentree[position]+difference;
     if(start!=end){
    int mid=(end+start)/2;
    update(segmentree,start,mid,index,difference,left(position));
    update(segmentree,mid+1,end,index,difference,right(position));
     }

}

int getsum(int* segmentree,int start,int end,int querystart,int queryend,int position){
    if(start>=querystart&&end<=queryend){
        return segmentree[position];
    }
    if(start>queryend||end<querystart){
        return 0;
    }

    int mid=(start+end)/2;
    return getsum(segmentree,start,mid,querystart,queryend,left(position))+getsum(segmentree,mid+1,end,querystart,queryend,right(position));
}


int buildsegmenttree(int* segmentree,int a[],int front,int back,int i){
    // if(front>back){
    //     return 0;
    // }
    if(front==back){
        segmentree[i]=a[front];
        return segmentree[i];
    }

   
        int divide=front+((back-front)/2);
        // if(back-front%2==1)
       return segmentree[i]= buildsegmenttree(segmentree,a,front,divide,left(i))+buildsegmenttree(segmentree,a,divide+1,back,right(i));

    //    else
       
    


    
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int* segmenttree=new int [4*n];
    int k=0;
    buildsegmenttree(segmenttree,a,0,n-1,0);
    for(int i=0;i<4*n;i++){
        cout<<segmenttree[i]<<" ";
    }
    int z,x;
    cin>>z>>x;
    cout<<getsum(segmenttree,0,n-1,z,x,0)<<endl;;
    update(segmenttree,0,n-1,2,-10,0);
     for(int i=0;i<4*n;i++){
        cout<<segmenttree[i]<<" ";
    }
    delete []segmenttree;
    return 0;

}