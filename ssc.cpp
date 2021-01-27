#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void bfs(vector<vector<int> >graph,bool visited[],stack<int>&` order,int node){
        // cout<<node<<" ";
    visited[node]=true;
    for(int a:graph[node]){
        if(!visited[a]){
            bfs(graph,visited,order,a);
        }
    }
    order.push(node);

}
void bfs2(vector<vector<int> > reve,int node,bool visited[],vector<int>& ans){
    visited[node]=true; 
    ans.push_back(node);
    for(int i:reve[node]){
        if(!visited[i]){
            bfs2(reve,i,visited,ans);
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> >graph(n);
    vector<vector<int> >reve(n);
    int connection;
    cin>>connection;
    for(int i=0;i<connection;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        reve[b].push_back(a);
    }

    // for(int i=0;i<n;i++){
    //     for(int j:graph[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    stack<int> order;
    // cout<<order.size()<<endl;
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(graph,visited,order,i);
        }
    }
    // cout<<order.size()<<endl;
    // while(order.size()){
    //     cout<<order.top()<<" ";
    //     order.pop();
    // }
    vector<vector<int> >ssc;
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    while(order.size())
    {
        int node=order.top();
        // cout<<node<<endl;
        order.pop();
        if(visited[node]){
            continue;
        }
        vector<int> ans;
        bfs2(reve,node,visited,ans);
        ssc.push_back(ans);
    }

    for(int i=0;i<ssc.size();i++){
        for(int j:ssc[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}