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
        int st=v>>i&1;
        if(tree[p][st]==0){
            tree[p][st]=ptr++;
        }
        p=tree[p][st];
    }
    if(tree[p][0]==0)tree[p][0]=x;
}
ii query(int v){
    int p=0,a=0;
    for(int i=20;i>=0;i--){
        int st=v>>i&1;
        if(tree[p][st^1]!=0){
            a+=1<<i;
            p=tree[p][st^1];
        }
        else p=tree[p][st];
    }
    return ii(a,tree[p][0]);
}
int main(){
    int n;
    cin>>n;
    int tab[n];
    FOR(i,n){
        scanf("%d",&tab[i]);
        if(i!=0)tab[i]^=tab[i-1];
    }
    pair<int,ii> ans;
    ans.f=-1;
    update(0,1);
    FOR1(i,n-1){
           // printf("<%d>",tab[i]);
    ii a=query(tab[i]);
   // printf("%d ",a.f);
   // if(a.f<tab[i]){a.f=tab[i];a.s=i;}
    if(a.f>ans.f||(ans.f==a.f&&a.s<ans.s.f)){
        ans.f=a.f;
        ans.s.f=a.s;
        ans.s.s=i;
    }
    // printf("%d %d %d\n",ans.f,ans.s.f,ans.s.s);
   // printf("/%d",tab[i-1]);
    update(tab[i-1],i+1);
    }
    printf("%d %d %d",ans.f,ans.s.f,ans.s.s+1);
}
