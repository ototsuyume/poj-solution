#include<cmath>
#include<iostream>

using namespace std;



int main(){
    int n,e;
    while(cin>>n){
        cin>>e;
        int ans=0;
        for(int i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            tmp = pow(tmp,e);
            ans+=(tmp>0?tmp:0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
