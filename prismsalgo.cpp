#include<iostream>
using namespace std;

int main(){
    int edge;
    cin>>edge;

    int** edges=new int*[edge];
    for(int i=0;i<edge;i++){
        edges[i]=new int[edge];
    }

    for(int i=0;i<edge;i++){
        for(int j=0;j<edge;j++){
            edges[i][j]=-1;
        }
    }

    int con;
    cin>>con;
    for(int i=0;i<con;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[s][d]=w;
        edges[d][s]=w;
    }

    bool visited[edge];
    int weight[edge];
    int parent[edge];
    for(int i=0;i<edge;i++){
        visited[i]=false;
        weight[i]=INT32_MAX;
        parent[i]=-1;
    }
    cout<<"enter the node"<<endl;
    int q;
    cin>>q;
    weight[q]=0;
    parent[q]=q;
    int i=0;


    while(i<edge){
        int smallest=INT32_MAX;
        int work;
        for(int index=0;index<edge;index++){
            if(weight[index]<smallest&&!visited[index]){
                smallest=weight[index];
                work=index;
            }
        }
        visited[work]=true;
        for(int j=0;j<edge;j++){
            if(edges[work][j]!=-1&&!visited[j]){
                if(weight[j]>edges[work][j])
                parent[j]=work;
                weight[j]=min(weight[j],edges[work][j]);
                
            }
        }

        i++;
    }

    for( i=0;i<edge;i++){
       
        cout<<parent[i]<<" "<<weight[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<edge;i++){
        delete [] edges[i];
    }
    delete [] edges;


    return 0;
}