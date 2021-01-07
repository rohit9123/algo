#include<iostream>
#include<algorithm>

#define lli long long int
using namespace std;
int main(){
    int n;
    cin>>n;
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
lli max_so_far=0;
lli max_tillnow=arr[0];
lli min_tillnow=arr[0] ;


for(int i=1;i<n;i++){
    max_tillnow=max_tillnow*arr[i];
    min_tillnow=min_tillnow*arr[i];

    max_tillnow=max(arr[i],max(max_tillnow,min_tillnow));
    min_tillnow=min(arr[i],min(max_tillnow,min_tillnow));
    max_so_far=max(max_so_far,max_tillnow);
}
cout<<max_so_far<<endl;
return 0;



}