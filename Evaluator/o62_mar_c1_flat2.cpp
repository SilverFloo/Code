#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int t[100005<<4];
int lz[100005<<4];
int lzre[100005<<4];
int ans[100005];

void uplz(int l,int r,int p,int v){

    t[p]+=(r-l+1)*v;
    lz[p]+=v;
}
void dolz(int l,int r,int p){
    if(lzre[p]==1){
        t[p]=0;
        t[p<<1]=0;
        t[p<<1|1]=0;
        lzre[p<<1]=1;
        lzre[p<<1|1]=1;
        lzre[p]=0;
    }
    if(lz[p]==0)return;

   // printf("  <<%d %d>>  ",l,r);
    int m=(l+r)/2;
    uplz(l,m,p<<1,lz[p]);
    uplz(m+1,r,p<<1|1,lz[p]);
    lz[p]=0;
}
void update(int st,int ed,int v,int p=1,int l=0,int r=100005){
    if(st<=l&&r<=ed){
       // dolz(l,r,p);
        uplz(l,r,p,v);
        return;
    }
    if(r<st||l>ed)return;
    int m=(l+r)/2;
    dolz(l,r,p);
    update(st,ed,v,p<<1,l,m);
    update(st,ed,v,p<<1|1,m+1,r);
    t[p]=t[p<<1|1]+t[p];
}
void re(int st,int ed,int p=1,int l=0,int r=100005){
    if(st<=l&&r<=ed){
       dolz(l,r,p);
        t[p]=0;
        lzre[p]=1;
        return;
    }
    if(r<st||l>ed)return;
    int m=(l+r)/2;
    dolz(l,r,p);
    re(st,ed,p<<1,l,m);
    re(st,ed,p<<1|1,m+1,r);
    t[p]=t[p<<1|1]+t[p];
}
int query(int x,int p=1,int l=0,int r=100005){
    if(l==r){return t[p];}
    dolz(l,r,p);
    int m=(l+r)/2;
    if(x<=m)return query(x,p<<1,l,m);
    else return query(x,p<<1|1,m+1,r);
}
map<int,int> m;
priority_queue<int> q;
queue<int> tmp;
int x[100005];
int main(){
    int n,w;
    //cin>>n>>w;
    n=10,w=-10;
    srand(time(NULL));
    int a,b;
    FOR(i,n){
        ans[i]=-1;
        //scanf("%d",&a)
        a=rand()%20;
        if(i>0)x[i-1]=min(a,b);
        b=a;
        m[x[i-1]]=1;
        printf("%d ",x[i-1]);
    }
    cout<<endl;
    ans[n]=-1;
    int ptr=0;
    for(auto &i:m)i.second=ptr++;


    for(int i=0;i<n-1;i++){//printf("   <%d>   ",query(1));

         //printf("%d<->%d ",x[i],q.top());
        while(!q.empty()&&q.top()>x[i]){

            int aa=query(m[q.top()]);
       printf("%d -> %d\n",q.top(),aa);
            ans[aa]=max(ans[aa],q.top());
            tmp.push(q.top());
            q.pop();
        }
            re(m[x[i]]+1,n);
        //printf("/%d/",m[x[i]]);
        update(0,m[x[i]],1);
        q.push(x[i]);
    }

     while(!q.empty()){
            int aa=query(m[q.top()]);
        printf("%d -> %d\n ",q.top(),aa);
            ans[aa]=max(ans[aa],q.top());
            tmp.push(q.top());
            q.pop();
        }

    if(w==-10)for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    else printf("%d",ans[w]);
}
/*
10 -10
8 7 2 4 7 4 6 9 8 0
*/

