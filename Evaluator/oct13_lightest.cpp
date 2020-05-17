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
int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    FOR(i,n+m){
        char a;
        scanf(" %c",&a);
        if(a=='P'){
            if(q.empty())printf("0\n");
            else {
                printf("%d\n", q.top().s);
                q.pop();
            }
        }
        else{
            int c,d;
            scanf("%d %d",&c,&d);
            q.p(c,d);
        }

    }
}
