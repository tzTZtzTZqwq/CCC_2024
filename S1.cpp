#include <iostream>
using namespace std;
int nums[1000010];
int N,ans=0;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin>>nums[i];
    }
    for(int i=1;i<=N/2;i++){
        if (nums[i]==nums[i+N/2]){
            ans += 2;
        }
    }
    cout<<ans<<endl;
}