#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int i=0;i<k;++i){
        int r,e,c;
        cin>>r>>e>>c;
        int re = e-c;
        if(r>re)
            cout<<"do not advertise"<<endl;
        else if(r==re)
            cout<<"does not matter"<<endl;
        else
            cout<<"advertise"<<endl;
    }
    return 0;
}
