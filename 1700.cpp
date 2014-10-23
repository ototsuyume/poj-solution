#include<iostream>
#include<algorithm>

using namespace std;

int s[10000],n;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n;
        for(int j=0;j<n;++j)
            cin>>s[j];
        if(n<=2){
            int ans = (n==1)?s[0]:(max(s[0],s[1]));
            cout<<ans<<endl;
        }else{
            sort(s,s+n);
            int ans=s[1],mx=n-1,smx=n-2;
            while(smx>1){
                ans+=s[0];
                if(s[mx]+s[smx]+s[0]>s[mx]+s[1]*2)
                    ans+=s[mx]+s[1]*2;
                else
                    ans+=s[mx]+s[smx]+s[0];
                mx-=2,smx-=2;
            }
            if(mx>1)
                ans+=s[mx]+s[0];
            cout<<ans<<endl;
        }
    }
    return 0;
}
