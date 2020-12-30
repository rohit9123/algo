#include<iostream>
#include<vector>
using namespace std;


void findans(vector<int>&sets,vector<vector<int> >&rec,int index){
    if(index<0){
        vector<int> k;
        rec.push_back(k);
        return;
    }
    findans(sets,rec,index-1);
    int siz=rec.size();
    int s=sets[index];
    for(int i=0;i<siz;i++){
        vector<int> k;
        for(int j:rec[i]){
            k.push_back(j);
        }
        k.push_back(s);
        rec.push_back(k);
    }

}



int main(){
vector<int> sets;
for(int i=1;i<=4;i++){
    sets.push_back(i);
}
vector<vector<int> >rec;
findans(sets,rec,sets.size()-1);
vector<vector<int> >powerset;
vector<int> k;
powerset.push_back(k);
// cout<<powerset.size()<<endl;
for(int i=0;i<sets.size();i++){
    int len=powerset.size();
 
    k.clear();
    for(int j=0;j<len;j++){
        for(int z:powerset[j]){
            k.push_back(z);
        }
        k.push_back(sets[i]);
        powerset.push_back(k);
        k.clear();
    }
    //    k.push_back(sets[i]);
    // powerset.push_back(k);
    // k.clear();
    

}
 for(int j=0;j<rec.size();j++){
        for(int z:rec[j]){
            cout<<z<<" ";
        }
        cout<<endl;
        }


}