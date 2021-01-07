//distinct row in 2d matrix

#include<iostream>
#include<stdlib.h>
using namespace std;

struct TrieNode{
    struct TrieNode* childern[10];
};

struct TrieNode* getnode(){
    struct TrieNode* node=new TrieNode;
    for(int i=0;i<10;i++){
        node->childern[i]=NULL;
    }
    return node;
}
bool getans(int**a ,int row,int m,struct TrieNode* head){
    bool ans=false;
    struct TrieNode* copy=head;
    for(int i=0;i<m;i++){
        int k=a[row][i];
        if(copy->childern[k]==NULL){
            ans=true;
            // cout<<k<<" "<<row<<endl;
            copy->childern[k]=getnode();
        }
        copy=copy->childern[k];
    }
    return ans;
}

void check(int** a,int ans,int n,int m){
    struct TrieNode* head=getnode();
    for(int i=0;i<n;i++){
        if(getans(a,i,m,head)){
            ans++;
        }
    }
cout<<ans<<endl;

}

int main(){
    int n,m;
    cin>>n>>m;
    
    int** a=new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int[m];
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            
        }
    }
    int ans=0;
    check(a,ans,n,m);


return 0;
}