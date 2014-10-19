#include<string.h>
#include<iostream>

using namespace std;

char str[10][100];

bool mystrstr(const char *input,const char *t,int len){
    for(int i=0;i<60;++i){
        bool succ=true;
        for(int j=0;j<len;++j){
            if(input[i+j]!=t[j]){
                succ=false;
                break;
            }
        }
        if(succ){
            return true;
        }
    }
    return false;
}

int mystrcmp(const char *s1, const char *s2, int len){
    for(int i=0;i<len;++i){
        if(s1[i]>s2[i])
            return 1;
        else if(s1[i]<s2[i])
            return -1;
    }
    return 0;
}

int main(){
    int m;
    cin>>m;
    for(int i=0;i<m;++i){
        int n;
        cin>>n;
        for(int j=0;j<n;++j)
            cin>>str[j];
        int pos=0,len=60,bp=0,bl=0;
        for(int j=1;j<n;++j){
            bool find=false;
            for(int l=len;l>=3;--l){
                for(int k=0;k<len-l+1;++k){
                    if(mystrstr(str[j],str[0]+k+pos,l)){
                        if(!find){
                            find = true;
                            bp = k+pos;
                            bl = l;
                        }
                        else if(mystrcmp(str[0]+bp,str[0]+k+pos,l)>0){
                            bp = k+pos;
                            bl = l;
                        }
                    }
                }
                if(find){
                    pos = bp, len = l;
                    break;
                }
            }
            if(!find){
                len=0;
                break;
            }
        }
        if(len==0)
            cout<<"no significant commonalities"<<endl;
        else{
            str[0][pos+len]=0;
            cout<<str[0]+pos<<endl;
        }
    }
    return 0;
}
