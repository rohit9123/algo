#include<iostream>
#include<queue>
using namespace std;
bool ans=false;
void dfs(int** graph,int index,int vertices,bool* visited){

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


void bfs(int** graph,int index,int vertix,bool* visited){
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

bool findpath(int** graph,int source,int destination,bool* visited,int vertix,queue<int> path){
    if(source==destination){
        // ans=true;
        return 1;
    }
    int result=0;
    for(int i=0;i<vertix;i++){
        if(graph[source][i]==1&&!visited[i]){
            visited[i]=true;
            result=findpath(graph,i,destination,visited,vertix,path);
            if(result==1){
                path.push(i);
                return 1;
            }
            
            
        }
    }


    return result;

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
   



    bool* visited=new bool[vertices];
    for(int i=0;i<vertices;i++){
        visited[i]=false;
    }


    queue<int> path;
     path.push(0);
    if(findpath(graph,0,5,visited,vertices,path)){
        while (path.size())
        {
            cout<<path.front()<<" ";
            path.pop();
            /* code */
        }
        cout<<endl;
        
    }
    



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