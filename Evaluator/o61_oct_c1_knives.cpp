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
int h[1000005];
bool st[1000005];
int main(){
    int n,q,l;
    cin>>n>>l>>q;
    set<int> m;
    while(q--){
        char c;
        scanf(" %c",&c);
        if(c=='s'){
            int a,b;
            scanf("%d %d",&a,&b);
            h[a]+=l-b,h[a]%=l;
            m.insert(a);
        }
        if(c=='f'){
            int a;
            scanf("%d",&a);
            st[a]^=1;
            m.insert(a);
        }
        if(c=='q'){
            int a;
            scanf("%d",&a);
            ll cnt=0;
            cnt+=(n-m.size())*a;
            for(auto i:m){
                if(a==0){
                    if(!st[i])cnt+=(ll)h[i];
                    else cnt+=(ll)l+1-(h[i]+1);
                }
                else if(a==l){
                    if(!st[i])cnt+=(ll)(h[i]+a-1)%l+1;
                    else cnt+=(ll)l-((h[i]+a-1)%l+1);
                }
                else{
                    if(!st[i])cnt+=(ll)(h[i]+a-1)%l+1;
                    else cnt+=(ll)l-((h[i]+a-1)%l+1)==0?l:l-((h[i]+a-1)%l+1);
                }
            }
            printf("%lld\n",cnt);
        }
    }
}
/*
    75 min 0%
        add case a==l
    90 min 30%
        use set to optimal
    100 min 50%
*/
