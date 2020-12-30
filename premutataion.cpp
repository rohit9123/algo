#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > ans;

    void helper(vector<int>nums,int index){
        if(index==nums.size()){
            return;
        }
        if(index==nums.size()-1){
            ans.push_back(nums);
            return;
        }else{
            for(int j=index;j<nums.size();j++){
                int k=nums[j];
                nums[j]=nums[index];
                nums[index]=k;
                helper(nums,index+1);
                nums[index]=nums[j];
                nums[j]=k;
            }
            
            
            
        }
    }
    
    
    vector<vector<int> > permute(vector<int>& nums) {
        
        helper(nums,0);
        for(int i=0;i<ans.size();i++){
            for(int j:ans[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
    


int main(){
    vector<int> k;
    k.push_back(0);
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);
    k.push_back(1);
    k.push_back(5);

    permute(k);
    return 0;
}