#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int ans=1,cur=1;
        while(cur){
            cur=cur*10+1;
            ans++;
            cur%=n;
        }
        cout<<ans<<endl;
    }
    return 0;
}
