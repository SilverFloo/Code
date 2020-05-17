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
int t[100005];
ii q[100005];
int ans[100005];
int tab[100005];
void update(int p){
    if(p==0)return;
    for(int i=p;i>0;i-=i&-i){
        t[i]++;
    }
}
int query(int p){
    int ans=0;
    for(int i=p;i<100005;i+=i&-i){
        ans+=t[i];
    }
    return ans;
}
int main(){
    int n,m;
    int pos = 1;
    cin>>n>>m;
    FOR(i,n){
        scanf("%d",&tab[i]);
    }
    FOR1(i,m){
        scanf("%d",&q[i].f);
        q[i].s=i;
    }
    sort(q+1,q+m+1);
    stack<int> s;
    FOR(i,n){
    //    printf("%d(%d) ",i,tab[i]);
        while(!s.empty()&&s.top()>=tab[i]){
            pos--;
            s.pop();
  //          printf("%d-> ",pos);
        }

//        printf("up %d ",pos-1);
        update(pos-1);
        //cout<<endl;
            while(tab[i+1]-tab[i]>q[pos].f&&pos<=m){
            s.p(tab[i]+q[pos].f);
            pos++;
            //printf("<-%d ",pos);
        }
    }
    FOR1(i,m){
        ans[q[i].s]=query(i);
    }
    FOR1(i,m)printf("%d\n",ans[i]);
}
