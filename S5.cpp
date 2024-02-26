#include<iostream>
using namespace std;
int N,in;
float nums[4];//1 4 6 1
//1 5 11 12
  int res[12][4]={{1,2,3,4},{1,2,3,3},{1,3,2,3},{3,3,1,2},{3,1,3,2},{1,1,2,2},{1,2,1,2},{1,1,1,2},{1,1,2,1},{1,2,1,1},{2,1,1,1},{1,1,1,1}};
float sub[12][4]={{1,1,1,1},{1,1,2,0},{1,1,2,0},{1,1,2,0},{1,1,2,0},{2,2,0,0},{2,2,0,0},{3,1,0,0},{3,1,0,0},{3,1,0,0},{3,1,0,0},{4,0,0,0}};
int tot[5];
int conv(int n){
    if(n<1){
        return 4;
    }else if(n<5){
        return 3;
    }else if(n<11){
        return 2;
    }else{
        return 1;
    }
}
bool check(int k){
    float g=tot[1]/sub[k][0];
    for(int i=1;i<=conv(k);i++){
        if(tot[i]/sub[k][i-1]!=g){
            return false;
        }
    }
    return true;
}
void reset(){
    for(int i=0;i<=4;i++) tot[i]=0;
}
int main(){
    cin>>N;
    for(int i=0;i<=3;i++){
        cin>>nums[i];
    }
    for(int i=0;i<=11;i++){
        reset();
        for(int j=0;j<=3;j++){
            tot[res[i][j]]+=nums[j];
        }
        if(check(i)){
            /*
            cout<<i<<endl;
            cout<<tot[1]<<endl;
            cout<<tot[2]<<endl;
            cout<<tot[3]<<endl;
            cout<<tot[4]<<endl;
            */
            cout<<conv(i);
            return 0;
        }
    }
}