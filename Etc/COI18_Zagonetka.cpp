#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int tab[105];
int x[105];
int visit[105];
int edge[105][105];
vector<int> e[105];
int deg[105];
int n;
int q=0;
int query(){
    FOR1(i,n){
        x[tab[i]]=i;
    }
    printf("query ");
    for(int i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    cout<<endl;
    int x;
    cin>>x;
    q++;
    return !x;
}
void find(int i){
    visit[tab[i]]=1;
    while(i>1&&edge[tab[i-1]][tab[i]]!=1){
        swap(tab[i],tab[i-1]);
         if(edge[tab[i-1]][tab[i]]==-1){
             i--;
             continue;
         }
        if(query()){
            swap(tab[i],tab[i-1]);
            edge[tab[i-1]][tab[i]]=1;
            find(i-1);
            continue;
        }
        else{
            edge[tab[i-1]][tab[i]]=-1;
            i--;
        }
    }
}
int t=1;
int cnt = 1;
int getmnn(int u){
    int mn = u;
    for(auto v:e[u]){
        if(!visit[v])mn = min(mn,getmnn(v));
    }
    return mn;
}
int getmn(int u){
    int mn = INF;
    for(auto v:e[u]){
        if(!visit[v])mn = min(mn,getmnn(v));
    }
    return mn;
}
void go(int i){
    int x = getmn(i);
    while(x!=INF){
        go(x);
        x= getmn(i);
    }
    visit[i]=1;
    if(t==1)tab[i]=cnt++;
    else tab[i]=cnt--;
}
int main(){
    cin>>n;  
    FOR1(i,n){
        cin>>x[i];
        tab[x[i]]=i;
    }   
    FOR1(i,n){
        for(int j=i-1;j>0;j--)edge[tab[j]][tab[i]]=-1;
        edge[i][i]=-1;
    }
    
    // FOR1(i,n){
    //     FOR1(j,n){printf("%2d ",edge[i][j]);}
    //     cout<<endl;
    // }
 
    while(visit[tab[n]]!=1){
        find(n);
    }
    printf("end");
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edge[j][i]==1){
                e[i].pb(j);
            }
        }
    }
    FOR1(i,n)visit[i]=0;
    FOR1(i,n)if(!visit[i])go(i);
    FOR1(i,n)printf("%d ",tab[i]);
    FOR1(i,n)e[i].clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edge[j][i]==1){
                e[j].pb(i);
            }
        }
    }
    cout<<endl;
    t=0;
    cnt = n;
    FOR1(i,n)visit[i]=0;
    FOR1(i,n)if(!visit[i])go(i);
    FOR1(i,n)printf("%d ",tab[i]);
    cout<<endl;
    // cout<<q<<endl;
    // FOR1(i,n){
    //     FOR1(j,n){printf("%2d ",edge[i][j]);}
    //     cout<<endl;
 
    // }
}