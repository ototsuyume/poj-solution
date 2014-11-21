#include<iostream>
#include<algorithm>
#include<numeric>
#include<string.h>
using namespace std;

int data[30],m,n;
bool used[30];

bool dfs(int pos,int cur,int target,int total,int ts){
    used[pos] = true;
    cur+=data[pos];
    ++ts;
    if(cur==target){
        total++;
        if(ts==n&&total==4)
            return true;
        else if(total==4||ts==n){
            used[pos]=false;
            return false;
        }
        int next = 0;
        while(used[next])++next;
        if(dfs(next,0,target,total,ts))
            return true;
        used[pos]=false;
        return false;
    }
    if(ts==n){
        used[pos]=false;
        return false;
    }
    for(int i=pos+1;i<n;++i){
        if(used[i])continue;
        if(cur+data[i]>target)
            break;
        if(dfs(i,cur,target,total,ts))
            return true;
    }

    used[pos]=false;
    return false;
}


int main(){
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>n;
        for(int j=0;j<n;++j)

            cin>>data[j];
        int sum = accumulate(data,data+n,0);
        if(sum%4!=0||sum<4||n<4){
            cout<<"no"<<endl;
            continue;
        }

        int len = sum/4;
        memset(used,0,sizeof(used));
        sort(data,data+n);
        if(dfs(0,0,len,0,0))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
