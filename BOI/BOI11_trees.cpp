#include<bits/stdc++.h>
using namespace std;
int t[200005];
    int n,m;
inline void update(int p,int v){
    //if(p<=0)return;
    for(int i=p;i<=n;i+=(i&-i)){
        //printf("%d ",i);
        t[i]+=v;
    }
}
inline int query(int p){
    int ans = 0;
    for(int i=p;i>0;i-=i&-i){
        ans+=t[i];
    }
    return ans;
}
int find(int a){
    int l=1,r=n;
    int ans = n+1;
    while(l<=r){
        int m=(l+r)/2;
        if(query(m)>=a){
            ans = m;
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}
int tab[200005];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
    }
    sort(tab,tab+n);
    for(int i=0;i<n;i++){
        if(i==0)update(1,tab[0]);
        else update(i+1,tab[i]-tab[i-1]);
    }
    while(m--){
        char c;
        int a,b;
        scanf(" %c %d %d",&c,&a,&b);
        if(c=='F'){
            int st = find(b);
            int mx = query(min(n,st+a));
            int ed = find(mx);
            ed = max(st,ed);
            // printf("<%d %d>",st,ed);
            update(st,+1);
            update(ed,-1);
            int more = a-ed+st;
            // printf("/%d/",find(mx+1));
            int x = find(mx+1);
            update(max(ed,x-more),+1);
            update(max(ed,x),-1);
            // for(int i=1;i<=n;i++)printf("%d ",query(i));
            // cout<<endl;
        }
        else{
            printf("%d\n",find(b+1)-find(a));
        }
    }
}
