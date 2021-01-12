#include<iostream>
#include<queue>

using namespace std;
// void bfs(int** b,int v){
// bool visited[v];
// for(int i=0;i<v;i++){
//     visited[i]=false;
// }
// queue<int> help;
// help.insert



// }

int parent(int unions[],int child){
    if(unions[child]==child){
        return child;
    }
    while(unions[child]!=child){
        child=unions[child];
    }
    return child;

}

bool hashpath(int** b,int source,int destination,int edge,bool visited[]){
    // cout<<source<<" ";
    if(source==destination){
        return true;
    }
    for(int i=0;i<edge;i++){
        if(i==source){
            continue;
        }
        if(b[source][i]&&!visited[i]){
        visited[i]=true;
        bool anser=hashpath(b,i,destination,edge,visited);
        if(anser==true){
            // cout<<endl;
            return true;
        }}
    }

return false;

}


int main(){
int n;
cin>>n;
// int a[n][n];
// int b[n][n];

int** a=new int*[n];
int** b=new int*[n];
for(int i=0;i<n;i++){
    a[i]=new int[n];
    b[i]=new int[n];
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        a[i][j]=0;
        b[i][j]=0;
    }
}
int v;
cin>>v;
for(int i=0;i<v;i++){
    int p,q;
    cin>>p>>q;
    a[p][q]=1;
    a[q][p]=1;
}

bool visited[n];


//naive solution 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]){
            bool ans=false;
            for(int k=0;k<n;k++){
                if(j==k)continue;
                if(a[i][k]){
                    for(int q=0;q<n;q++){
                        visited[q]=false;
                    }
                    if(hashpath(b,k,j,n,visited)){
                        ans=true;
                        break;
                    }
                    
                    




                }
            }
            if(ans==false){
                b[i][j]=1;
                b[j][i]=1;
            }




        }



    }
}


for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<b[i][j]<<' ';
    }
    cout<<endl;
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        b[i][j]=0;
    }
}
cout<<endl;




//union  solution   




int unions[n];
for(int i=0;i<v;i++){
    unions[i]=i;
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]){
            int p=parent(unions,i);
            int p2=parent(unions,j);
            if(p!=p2){
                b[i][j]=1;
                b[j][i]=1;
                unions[p2]=p;
            }
        }
    }
}


for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<b[i][j]<<' ';
    }
    cout<<endl;
}

for(int i=0;i<n;i++){
    delete [] a[i];
    delete [] b[i];
 }

 delete [] a;
 delete [] b;

 return 0;

}

