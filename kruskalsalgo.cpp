#include<iostream>
#include<vector>

using namespace std;
struct edge{
    int source;
    int dest;
    int weight;
};

bool mycompare(struct edge& a,struct edge& b){
    return a.weight<b.weight;
}
int findparent(int parent[],int child){
    if(parent[child]==child){
        return child;
    }

    while(parent[child]!=child){
        child=parent[child];
    }
    return child;
}

int main(){
    int n,e;
    cin>>n>>e;

    struct edge* edges=new struct edge[e];
    struct edge* ans=new struct edge[n-1];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].source=s;
        edges[i].dest=d;
        edges[i].weight=w;
    }
    sort(edges,edges+e,mycompare);
    cout<<endl;


    // for(int i=0;i<e;i++){
       
    //     cout<<edges[i].source<<" "
    //     <<edges[i].dest<<" "
    //     <<edges[i].weight<<endl;
    // }

    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int i=0,siz=0;
    while(i<e&&siz<n-1){
        int p=findparent(parent,edges[i].source);
        int p1=findparent(parent,edges[i].dest);

        if(p!=p1){
            ans[siz].source=edges[i].source;
            ans[siz].dest=edges[i].dest;
            ans[siz].weight=edges[i].weight;
            parent[p1]=p;
            siz++;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        cout<<ans[i].source<<" "<<ans[i].dest<<" "<<ans[i].weight<<endl;
    }
    return 0;
}