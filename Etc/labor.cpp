#include<bits/stdc++.h>
using namespace std;
int m;long long unsigned n;
const int maxm=1e6+5;
int data[maxm];
int a[maxm];
unsigned long long ans;
bool check(int a){
unsigned long long w=0;
for(int i=0;i<m;i++){w+=a/data[i];if(w>=n)return 1;}
//printf(">%llu<",w);
if(w>=n)return 1;
return 0;
}
void search(unsigned long long l,unsigned long long r){
if(l>r){printf("%llu",ans);return;}
unsigned long long mid=(l+r)/2;
if(check(mid)){ans=min(ans,mid);search(l,mid-1);}
else {search(mid+1,r);}
}
int main(){
scanf("%d %llu",&m,&n);


    long long last=2000000;

    for(int i=0;i<m;i++){
        scanf("%d",&data[i]);
        last=min(last,(long long)data[i]);
    }
    last*=n;
    ans=last;

        while(first<=last)
    {
        long long mid=(first+last)/2;
        long long many=0;
        for(int i=0;i<n;i++){
            many+=mid/party[i];
            if(many>=m) break;
        }
        if(many>=m){
            ans=min(ans,mid);
            last=mid-1;
        }
        else first=mid+1;
    }
    printf("%lld",ans);
}
