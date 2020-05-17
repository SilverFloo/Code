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
int main(){
    int n;
    cin>>n;
    FOR(j,n){
        FOR(i,n){
            if(i%2==0){
                printf("%d ",n*i+j+1);
            }
            else printf("%d ",n*(i+1)-j);
        }
        printf("\n");
    }
}
