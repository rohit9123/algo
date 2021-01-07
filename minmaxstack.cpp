#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>

using namespace std;

int main(){
vector<pair<int,int> >help;
stack<int> minmax;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int k;
    cin>>k;
    if(i==0){
        help.push_back(make_pair(k,k));
        minmax.push(k);
    }else{
        int z=min(k,help[help.size()-1].first);
        int q=max(k,help[help.size()-1].second);
        help.push_back(make_pair(z,q));
        minmax.push(k);
    }
}

    while(minmax.size()){
        cout<<help[help.size()-1].first<<" "<<help[help.size()-1].second<<endl;
        cout<<minmax.top()<<endl;
        help.pop_back();
        minmax.pop();
        cout<<endl;

    }


return 0;






}