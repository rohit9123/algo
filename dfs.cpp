#include<iostream>
using namespace std;

void bfs(int** graph,int index,int vertices,int* visited){

    cout<<index<<endl;
    for(int i=0;i<vertices;i++){
        if(i==index){
            continue;
        }
        if(graph[index][i]&&!visited[i]){
            visited[i]=true;
            bfs(graph,i,vertices,visited);
        }

    }


}



int main(){
    int vertices;
    cin>>vertices;
    int** graph=new int*[vertices];
    for(int i=0;i<vertices;i++){
        graph[i]=new int[vertices];
    }


    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            graph[i][j]=0;
        }
    }
    int edge;
    cin>>edge;
    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int* visited=new int[vertices];
    for(int i=0;i<vertices;i++){
        visited[i]=false;
    }
    visited[0]=true;
    bfs(graph,0,vertices,visited);
    delete [] visited;
    for(int i=0;i<vertices;i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;

}