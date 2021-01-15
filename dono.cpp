#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<climits>
 
 
#define ll long long
#define lli long long int
 
#define pb push_back
#define in insert
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;


void solve();

int main(){
    fast;
    int testcase=1;
   
    cin>>testcase;
    while (testcase--)
    {
        solve();
    }
    
}

void solves(int** z,int weight[],bool visited[],int n){
    for(int i=0;i<n+1;i++){
        weight[i]=INT_MAX;
        visited[i]=false;
    }
    for(int i=0;i<n+1;i++){
        cout<<weight[i]<<" ";
    }
    visited[0]=true;
    weight[1]=0;
    for(int j=0;j<n;j++){
            int small=INT_MAX;
            int index=0;
            for(int i=0;i<n+1;i++){
                if(small>weight[i]&&!visited[i]){
                    small=weight[i];
                    index=i;
                }
            }

            visited[index]=true;
            for(int i=0;i<n+1;i++){
                if(z[index][i]!=-1){
                    if(weight[i]>z[index][i]-weight[index]&&!visited[i])
                    weight[i]=z[index][i]-weight[index];
                }
            }
    }
    for(int i=2;i<n+1;i++){
        cout<<weight[i]<<endl;
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    int weight[n+1];
    // weight[1]=0;
   int **z=new int*[6];
   for(int i=0;i<6;i++){
       z[i]=new int [6];
   }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            z[i][j]=-1;
        }
    }
    
        while(k--){
        cout<<k<<endl;
       int a,b,c;
       cin>>a>>b>>c;
       z[a][b]=c;
       z[b][a]=c;}
   
//    cout<<endl<<"here";
   bool visited[n+1];
    // visited[0]=true;
    // cout<<"here";
   solves (z,weight,visited,n);
   for(int i=0;i<n+1;i++){
       delete [] z[i];
   }
   delete [] z;

}