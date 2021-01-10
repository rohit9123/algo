
#include<iostream>
using namespace std;

int dijkstras(int** mat,int n,int source,int dest){
    int distance[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        distance[i]=INT32_MAX;
        visited[i]=false;
    }
    distance[source]=0;
    for(int i=0;i<n;i++){
        int small=INT32_MAX;
        int index;
        for(int j=0;j<n;j++){
            if(small>distance[j]&&!visited[j]){
                index=j;
                small=distance[j];
            }
        }
        visited[index]=true;
        if(visited[dest]){
            return distance[dest];
        }
        for(int j=0;j<n;j++){
            if(mat[index][j]!=-1&&!visited[j]){
                if(distance[j]>distance[index]+mat[index][j]){
                    distance[j]=distance[index]+mat[index][j];
                }
            }
        }

    }
    return distance[dest];

}



int main(){
    int n;
    cin>>n;
    int** mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         mat[i][j]=-1;   
        }
    }
    int edge;
    cin>>edge;
    for(int i=0;i<edge;i++){
        int s,d,w;
        cin>>s>>d>>w;
        mat[s][d]=w;
        mat[d][s]=w;
    }

    int source,dest;
    cin>>source>>dest;
    cout<<dijkstras(mat,n,source,dest)<<endl;

    for(int i=0;i<n;i++){
        delete [] mat[i];
    }
    delete [] mat;

    return 0;

}