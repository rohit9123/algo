#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


//structure of trie
struct TrieNode{
    struct TrieNode* children[26];
    bool isend;
};

//to create a node 
struct TrieNode* getNode(){
    struct TrieNode *node=new TrieNode;
    node->isend=false;
    for(int i=0;i<26;i++){
        node->children[i]=NULL;
    }
    return node;
}


// inserting a string
void insert(string key,struct TrieNode* head){
    struct TrieNode* tri=head;
    int le=key.size();
    for(int i=0;i<le;i++){
        int index=key[i]-'a';
        if(tri->children[index]==NULL){
            tri->children[index]=getNode();
        }
        tri=tri->children[index];

    }
    tri->isend=true;
}



//searching for  a key
bool search(string key,TrieNode* head){
    struct TrieNode* tri=head;
    for(int i=0;i<key.size();i++){
        int index=key[i]-'a';
        if(tri->children[index]==NULL){
            return false;
        }
        tri=tri->children[index];
    }
    if(tri->isend==true){
        return true;
    }
    return false;
}


//helper for delete
bool check(struct TrieNode* head){
    for(int i=0;i<26;i++){
        if(head->children[i]!=NULL){
            return false;
        }
    }
    return true;
}

//deleting a string
struct TrieNode* del(string key,struct TrieNode* head,int index){
    if(head==NULL){
        return NULL;
    }
   
    if(index==key.size()){
        head->isend=false;
        if(check(head)){
            delete (head);
            return NULL;
        }
        return head;
    }
   
    int i=key[index]-'a';
    head->children[i]=del(key,head->children[i],index+1);
    if(check(head)&&head->isend==false){
        delete head;
        return NULL;
    }

    return head;

}



int main(){
    struct TrieNode* head=getNode();
    string a="rohit",b="ras",c="rez",d="rezh";
    insert(a,head);
    insert(b,head);
    insert(c,head);
    insert(d,head);
    del(c,head,0);
    bool k=search("rez",head);
    bool z=search("rezh",head);
    cout<<k<<" "<<z<<endl;


}