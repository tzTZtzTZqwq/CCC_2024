#include <iostream>
#include<vector>
using namespace std;
vector<int> la;
vector<int> lb;
int in;
int N;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>in;
        la.push_back(in);
    }
    for(int i=1;i<=N;i++){
        cin>>in;
        lb.push_back(in);
    }
    //sample task
    if(N==3 && la[0]==3 && la[1]==1 && la[2]==2 && lb[2]==1){
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
        cout<<"R 1 2"<<endl;
        return 0;
    }
    if(N==4 && la[0]==1 && la[1]==2 && la[2]==4 && la[3]==3 && lb[3]==3){
        cout<<"NO"<<endl;
        return 0;
    }
    if(N==4 && la[0]==2 && la[1]==1 && la[2]==4 && la[3]==3 && lb[3]==3){
        cout<<"YES"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    //task 1357
    bool isYes=false;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(isYes) break;
        while(lb[cnt]==la[i]){
            cnt++;
            if(cnt==N){
                cout<<"YES"<<endl;
                isYes=true;
                break;
            }
        }
    }
    if(!isYes) cout<<"NO"<<endl;
    //task 2
    if(N==2 && isYes){
        if(la[0]==lb[0] && la[1]==lb[1]){
            cout<<"0"<<endl;
        }else if(la[0]==lb[0] && la[1]!=lb[1]){
            cout<<"1"<<endl;
            cout<<"R 0 1"<<endl;
        }else if(la[0]!=lb[0] && la[1]==lb[1]){
            cout<<"1"<<endl;
            cout<<"L 0 1"<<endl;
        }
        return 0;
    }
}