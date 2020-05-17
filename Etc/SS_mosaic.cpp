#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
using namespace std;
int n,m;
const int MAX=3000;
vector<int> p1[MAX],p2[MAX];
int color[MAX];
int main(){
    cin>>n>>m;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        p1[a].pb(b);
        p1[b].pb(a);
    }
    FOR(i,MAX){
        sort(all(p1[i]));
    }
    queue<int> q;
    q.push(0);
    color[0]=1;
    while(!q.empty()){
        int u=q.front();
        //printf("%d %d\n",u+1,color[u]);
        q.pop();
        for(auto i:p1[u]){
            if(color[i]==0){
                for(int j=1;;j++){
                if(j==color[u])continue;
                int ch=1;
                for(auto k:p1[i]){if(color[k]==j){ch=0;break;}}
                    if(ch){
                        color[i]=j;
                        q.push(i);
                        break;
                    }
                }

            }
        }


    }
    FOR(i,MAX)if(color[i]!=0)printf("%d\n",color[i]);
}
/*
8
17
14 16
14 1
14 18
14 15
14 13
14 12
14 17
16 1
16 18
16 12
16 17
1 18
18 13
15 13
15 12
15 17
12 17
*/
