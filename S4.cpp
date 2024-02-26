#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M,N,in1,in2;
vector<pair<int,int>> links;
vector<bool> vis;
bool cmp(pair<int,int> ia,pair<int,int> ib){
    return (ia.first<ib.first);
}
int getNext(int n){
    for(int i=0;i<links.size();i++){
        if(n==links[i].first && vis[i]==false){
            return i;
        }
        if(n==links[i].second && vis[i]==false){
            swap(links[i].first,links[i].second);
            return i;
        }
    }
    return 0;
}
bool checkChain(){
    vector<pair<int,int>> links2;
    links2=links;
    sort(links2.begin(),links2.end(),cmp);
    int cnt=1;
    for(int i=0;i<=N-1;i++){
        if(links2[i].first==cnt && links2[i].second==cnt+1){
            cnt++;
        }
    }
    return (cnt==M);
}
int main(){
    cin>>M>>N;
    for(int i=1;i<=N;i++){
        cin>>in1>>in2;
        links.push_back(make_pair(in1,in2));
        vis.push_back(0);
    }
    //cout<<checkChain()<<endl;
    if(checkChain() || M!=N){//chain 1-n
        
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
    }else{//m=n,tree
        for(int i=1;i<=N;i++){
            cout<<"R";
        }
        /*
            int cnt=1;
            int S=links[0].first;
            int now=links[0].first;
            cout<<"G";
            while(links[now].first!=S){
                vis[now]=1;
                cout<<(cnt%2==0?"R":"B");
                cnt++;
                now=getNext(links[now].second);
            }
        }
        */
    }
}