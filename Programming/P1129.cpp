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
bool visit[5005];
int main(){
    int n, k;
    cin>>n>>k;
    int pos = 0;
    int cnt = k%n;
    int in = n;
    while(1){
        if(!visit[pos])cnt--;
        if(cnt == 0){
            printf("%d\n", pos+1);
            visit[pos] = 1;
            in--;
            cnt = k;
            if(in == 0) break;
            if(cnt > in) cnt %= in;
            if(cnt == 0) cnt = in;

        }
        pos++;
        if(pos == n) pos = 0;
    }
}
