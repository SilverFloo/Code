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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        q.p(a);
        }
        int d=0;
        while(++d){
            q.p(q.top()+1);
            q.pop();
            if(d==q.top()){printf("%d\n",d);break;}
        }

    }
}
