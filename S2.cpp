#include <iostream>
using namespace std;
int M,N;
string in;
void att(){
    int isHeavy[30];
	for(int i=0;i<=29;i++) isHeavy[i]=0;
    cin>>in;
    for(char c:in){
        isHeavy[c-'a']++;
    }
    bool nowHeavy=(isHeavy[in[0]-'a']>1);
    for(char c:in){
		//cout<<c<<" "<<isHeavy[c-'a']<<endl;
        if((isHeavy[c-'a']>1)!=nowHeavy){
            cout<<"F"<<endl;
            return;
        }
		nowHeavy = !nowHeavy;
    }
    cout<<"T"<<endl;    
}
int main(){
    cin>>M>>N;
    for(int i=1;i<=M;i++){
        att();
    }
}