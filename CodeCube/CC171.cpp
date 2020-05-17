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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
char s[200005];
int ans[200005];
int t[400005<<2];
void update(int x,int v,int p=1,int l=0,int r=400005){
    if(l==r){
        t[p]=v;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,v,p<<1,l,m);
    else update(x,v,p<<1|1,m+1,r);
    t[p]=min(t[p<<1],t[p<<1|1]);
}
int query(int st,int ed,int p=1,int l=0,int r=400005){
    if(st<=l&&r<=ed){return t[p];}
    if(r<st||l>ed)return 1e9;
    int m=(l+r)/2;
    return min(query(st,ed,p<<1,l,m),query(st,ed,p<<1|1,m+1,r));
}
int main(){
    //rf();
    scanf("%s",s);
    int n=strlen(s);
    int q;
    cin>>q;
    int cnt=0;
    stack<char> x;
    FOR1(i,2*n){
        if(!x.empty()&&x.top()=='('&&s[(i-1)%n]==')')x.pop();
        else x.push(s[(i-1)%n]);
        //printf("%d ",x.size());
        update(i,x.size());
    }
    FOR(i,q){
        int a,b;
        scanf("%d %d",&a,&b);
        if(b<a)b+=n;
        int x=query(a-1,a-1);
        if(query(b,b)!=x){
            printf("no");
        }
        else if(x>query(a,b)){
            printf("no");
        }
        else printf("yes");
        printf("\n");
    }

}
