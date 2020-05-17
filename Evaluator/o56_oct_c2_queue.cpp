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
const int INF = 1e9;
const int MAX = 200005;
int t[MAX];
map<int,int> m1,m2;
void update(int x,int v){
    for(int i=x;i<MAX;i+=i&-i){t[i]+=v;}
}
int query(int x){
    int ans=0;
    for(int i=x;i>0;i-=i&-i){ans+=t[i];}
    return ans;
}
int main(){
    int n;
    cin>>n;
    int cnt=1;
    FOR(i,n){
        int c;
        scanf("%d",&c);
        if(c==1){
            int a;
            scanf("%d",&a);
            m1[a]=cnt;
            m2[cnt]=a;
            cnt++;
            update(a,1);
        }
        else if(c==2){
            int l=1,r=MAX-1;
            int ans=-1;
            while(l<=r){
                int m=(l+r)/2;
                int xx=query(m);
                if(xx>1)r=m-1;
                else if(xx==1)r=m-1,ans=m;
                else l=m+1;
            }
            if(ans==-1){printf("0\n");
            continue;}
            //printf("/%d/",ans);
            printf("%d\n",m1[ans]);
            update(ans,-1);
        }
        else{
            int a;
            scanf("%d",&a);
            printf("%d\n",query(m2[a])-1);
        }
    }
}
