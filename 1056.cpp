#include<cstdio>

using namespace std;


struct node{
    int child[2];
};

node trie[1<<10];

int used;

bool add(const char *str){
    int cur=0;
    while(*str){
        char c=*str-'0';
        if(trie[cur].child[c]>0){
            cur = trie[cur].child[c];
            if(trie[cur].child[0]==0&&trie[cur].child[1]==0)
                return false;
        }
        else{
            trie[cur].child[c]=++used;
            cur = used;
            trie[cur].child[0]=trie[cur].child[1]=0;
        }
        ++str;
    }
    return true;
}


int main(){
    char buf[128];
    used=0;
    trie[0].child[0]=trie[0].child[1]=0;
    bool ans = true;
    int num=1;
    while(scanf("%s",buf)!=EOF){
        if(buf[0]=='9'){
            used=0;
            trie[0].child[0]=trie[0].child[1]=0;
            if(ans)
                printf("Set %d is immediately decodable\n",num++);
            else
                printf("Set %d is not immediately decodable\n",num++);
            ans = true;
            continue;
        }
        if(ans)
            ans = add(buf);
    }
    return 0;
}
