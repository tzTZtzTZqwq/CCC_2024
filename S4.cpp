#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> links;
int main(){
    int M,N,in1,in2;
    cin>>M>>N;
    for(int i=1;i<=N;i++){
        cin>>in1>>in2;
        links.push_back(make_pair(in1,in2));
    }
    for(int i=0;i<N;i++){
        if (abs(links[i].first-links[i].second)==1){
            if(min(links[i].first,links[i].second)%2==1){
                cout<<"R";
            }else{
                cout<<"B";
            }
        }else{
            cout<<"G";
        }
    }
}
