#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//navie opprach
int naive(string& s){
    if(s.size()==0){
        return 0;
    }
    int max_sofar=0;
    for(int i=0;i<s.size();i++){
        unordered_map<char,int> help;
        help[s[i]]++;
        int length=1;
        for(int j=i+1;j<s.size();j++){
            if(help[s[j]]==0){
                help[s[i]]++;
                length++;
            }else{
                break;
            }
        }
        max_sofar=max(max_sofar,length);
    }
    return max_sofar;
}

int slider(string& s){

    if(s.size()==0){
        return 0;
    }
    int left=0,right=0,max_sofar=0;
    unordered_map<char,int> help;
    while(right<s.size()){
        help[s[right]]++;

        while(help[s[right]]>1){
            help[s[left]]--;
            left++;
        }
        max_sofar=max(max_sofar,right-left+1);
        right++;

    }

return max_sofar;
}
int main(){
    string s;
    getline(cin,s);
    cout<<endl;
    cout<<"naive"<<" "<<naive(s)<<endl;
    cout<<"slider"<<" "<<slider(s)<<endl;
    
}