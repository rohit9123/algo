#include<iostream>
#include<queue>
using namespace std;

void dfs(int** graph,int index,int vertices,int* visited){

    cout<<index<<endl;
    for(int i=0;i<vertices;i++){
        if(i==index){
            continue;
        }
        if(graph[index][i]&&!visited[i]){
            visited[i]=true;
            dfs(graph,i,vertices,visited);
        }

    }


}

void bfs(int** graph,int index,int vertix,int* visited){
    queue<int> help;
    help.push(index);
    // int visited[vertix];
    // for(int i=0;i<vertix;i++){
    //     visited[i]=false;
    // }
    // visited[index]=true;
    while(help.size()){
        cout<<help.front()<<endl;
        int workingvertex=help.front();
        help.pop();
        for(int i=0;i<vertix;i++){
            if(graph[workingvertex][i]==1&&!visited[i]){
                help.push(i);
                visited[i]=true;
            }
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
    // visited[0]=true;
    cout<<"dfs"<<endl;
    for(int i=0;i<vertices;i++){
    if (!visited[i]){
    visited[i]=true;
    dfs(graph,i,vertices,visited);
    };
    }
    
    cout<<"bfs"<<endl;
    for(int i=0;i<vertices;i++){
        visited[i]=false;
    }
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            visited[i]=true;
            bfs(graph,i,vertices,visited);
        }
    }
    
    delete [] visited;
    for(int i=0;i<vertices;i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;

}