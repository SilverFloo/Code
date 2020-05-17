#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
using namespace std;
int main(){
    deque<int> q;
    int n,k;
    cin>>n>>k;
    int tab[n];
    FOR(i,n){scanf("%d",&tab[i]);}
    FOR(i,n){
        while(!q.empty()&&q.front()<i-k)q.pop_front();
        if(!q.empty()){
       // printf("%d",tab[q.front()]);
        tab[i]+=tab[q.front()];
        }
        while(!q.empty()&&tab[i]<tab[q.back()])q.pop_back();
        q.push_back(i);
        //printf("%d  ",tab[i]);
    }
    printf("%d",tab[n-1]);
}
