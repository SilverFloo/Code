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
int tree[(int)1<<20][2];
int ptr=1;
void update(int v,int x){
    int p=0;
    for(int i=20;i>=0;i--){

        int st=(v>>i)&1; //printf("%d->",st);
        if(tree[p][st]==0){
        tree[p][st]=ptr++;
        }
        p=tree[p][st];
    }
    tree[p][0]=x;
}
ii query(int v){
    int a=0,p=0;
    for(int i=20;i>=0;i--){
        int st=v>>i&1;
       // printf("->");
        st^=1;
        if(tree[p][st]!=0){//printf("%din",st);
        a+=1<<i;
        p=tree[p][st];
        }
        else {p=tree[p][st^1];//printf("%d",st^1);
        }
    }
    return ii(a,tree[p][0]);
}
int main(){
    int n;
    cin>>n;
    pair<int,ii> ans;
    ans.f=-1;
    FOR(i,n){
        int x;
        scanf("%d",&x);
        if(i!=0){
        ii a=query(x);
       // printf("%d/",a.f);
        if(a.f==ans.f&&a.s<ans.s.f){
            ans.f=a.f;
            ans.s.f=a.s;
            ans.s.s=i+1;
        }
        if(a.f>ans.f){
            ans.f=a.f;
            ans.s.f=a.s;
            ans.s.s=i+1;
        }}
        update(x,i+1);
    }
    printf("%d %d %d",ans.f,ans.s.f,ans.s.s);
}
