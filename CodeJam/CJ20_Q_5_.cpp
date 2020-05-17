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
int main(){
    int t;
    cin>>t;
    FOR1(k,t){
        int n,m;
        cin>>n>>m;
        if(m%n!=0){
            printf("Case #%d: IMPOSSIBLE\n",k);
            continue;
        }
        printf("Case #%d: POSSIBLE\n",k);
        int x=(n*n-m)/n;
        //db(x);
        for(int i=n-x;i>0;i--){
            for(int j=0;j<n;j++){
                printf("%d ",(i+j-1)%n+1);
            }
            cout<<endl;
        }
        for(int i=n;i>n-x;i--){
            for(int j=0;j<n;j++){
                printf("%d ",(i+j-1)%n+1);
            }
            cout<<endl;
        }
    }
}
