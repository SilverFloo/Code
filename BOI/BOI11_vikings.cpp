#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
char tab[705][705];
int t[705][705];
int st[705][705];
int visit[705][705];
int n,m;
void findtime(int i,int j){
    queue<pair<int,ii>> q;
    q.emplace(1,make_pair(i,j));
    while(!q.empty()){
        i = q.front().s.f;
        j = q.front().s.s;
        int l = q.front().f;
        q.pop();
        if(i<=0||j<=0||i>n||j>m||tab[i][j]=='I'||visit[i][j]==1)continue;
        int tmp = i+1;
        while(tmp<=n&&tab[tmp][j]!='I'&&st[tmp][j]!=3&&st[tmp][j]!=1){
            if(st[tmp][j]==0)st[tmp][j]=1,t[tmp][j]=l;
            else st[tmp][j]=3;
            tmp++;
        }
        tmp = i-1;
        while(tmp>0&&tab[tmp][j]!='I'&&st[tmp][j]!=3&&st[tmp][j]!=1){
            if(st[tmp][j]==0)st[tmp][j]=1,t[tmp][j]=l;
            else st[tmp][j]=3;
            tmp--;
        }
        tmp = j-1;
        while(tmp>0&&tab[i][tmp]!='I'&&st[i][tmp]!=3&&st[i][tmp]!=2){
            if(st[i][tmp]==0)st[i][tmp]=2,t[i][tmp]=l;
            else st[i][tmp]=3;
            tmp--;
        }
        tmp = j+1;
        while(tmp<=m&&tab[i][tmp]!='I'&&st[i][tmp]!=3&&st[i][tmp]!=2){
            if(st[i][tmp]==0)st[i][tmp]=2,t[i][tmp]=l;
            else st[i][tmp]=3;
            tmp++;
        }
        st[i][j]=3;
        if(t[i][j]==0)t[i][j]=l;
        visit[i][j]=1;
        q.emplace(l+1,make_pair(i+1,j));
        q.emplace(l+1,make_pair(i-1,j));
        q.emplace(l+1,make_pair(i,j+1));
        q.emplace(l+1,make_pair(i,j-1));
    }

}
int main(){
    cin>>n>>m;
    ii viking,treasure,you;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tab[i][j];
            if(tab[i][j]=='V')viking = {i,j};
            if(tab[i][j]=='Y')you = {i,j};
            if(tab[i][j]=='T')treasure = {i,j};
        }
    }
    findtime(viking.f,viking.s);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",t[i][j]);
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            visit[i][j]=0;
        }
    }
    queue<pair<int,ii>> q;
    q.emplace(1,make_pair(you.f,you.s));
    while(!q.empty()){
        int i=q.front().s.f;
        int j=q.front().s.s;
        int l = q.front().f;
        q.pop();
        if(i<=0||j<=0||i>n||j>m||tab[i][j]=='I'||visit[i][j]==1)continue;
        if(treasure==make_pair(i,j)){
            printf("YES");
            exit(0);
        }
        visit[i][j]=1;
        if(t[i+1][j]>l+1)q.emplace(l+1,make_pair(i+1,j));
        if(t[i-1][j]>l+1)q.emplace(l+1,make_pair(i-1,j));
        if(t[i][j+1]>l+1)q.emplace(l+1,make_pair(i,j+1));
        if(t[i][j-1]>l+1)q.emplace(l+1,make_pair(i,j-1));
    }
    printf("NO");
}