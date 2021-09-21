#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<string.h>
#include<math.h>
#include<unordered_map>
#include<iomanip>
#include<unordered_set>
 
#define rep(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define mod 1000000007
#define pb push_back
#define in insert
#define pres(c,x) ((c).find(x)!=c.end());
#define lli long long int
 
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;
void input_output() {
#ifndef ONLINE_JUDGE
  freopen("f.txt", "r", stdin);
  freopen("output11.txt", "w+", stdout);
#endif
}
void solve();
int cas=1;
int main(){
  fast;
//    input_output();
 int t=1;
//  cin>>t;
 while (t--)
 {  solve();
     cas++;
 }
 return 0;
}
// unordered_map<string,int> dp;
// long findans(vector<long> prefix,int start,int end,long partition,long maxi,long mini){
// if(partition==0){
//   maxi=max(maxi,prefix[end]-prefix[start-1]);
//   mini=min(mini,prefix[end]-prefix[start-1]);
//   return maxi-mini;
  
// }
// string t=to_string(start)+'*'+to_string(maxi)+'*'+to_string(mini);
// if(dp.find(t)!=dp.end()){
//   return dp[t];
// }
// long ans=INT_MAX;
// for(int i=start;i<=end-partition;i++){
//   long maxi2=maxi,mini2=mini;
//   maxi2=max(maxi2,prefix[i]-prefix[start-1]);
//   mini2=min(mini2,prefix[i]-prefix[start-1]);
//   ans=min(ans,findans(prefix,i+1,end,partition-1,maxi2,mini2));
// }
// return dp[t]=ans;

// }


void solve(){
 int n;
 cin>>n;
 int log[n+1];
 log[1]=0;
 for(int i=2;i<=n;i++){
   log[i]=log[i/2]+1;
 }

 int sparetable[n][25];
 for(int i=0;i<n;i++){
   cin>>sparetable[i][0];
 }
 for(int j=1;j<25;j++){
   for(int i=0;i+(1<<j)<=n;i++){
     sparetable[i][j]=min(sparetable[i][j-1],sparetable[i+(1<<(j-1))][j-1]);
   }
 }
 int q;
 cin>>q;
 while(q--){
   int l,r;
   cin>>l>>r;
   int power=log[r-l+1];
   cout<<min(sparetable[l][power],sparetable[r-(1<<power)+1][power])<<endl;
 }

}

// //$ <