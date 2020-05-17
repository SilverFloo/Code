#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
char x[1005];
void rev(int now,int ed){
    if(now==ed)return;
    rev(now-1,ed);
    printf("%c",x[now]);
}

void find(int st,int now){
    if(x[now]=='_'){
        rev(st,now);
        printf("_");
        find(now-1,now-1);
    }
    else if(x[now]=='\0'){
        rev(st,now);
    }
    else find(st,now-1);
}

int main(){
    scanf("%s",x);
    find(strlen(x)-1,strlen(x)-1);
}
