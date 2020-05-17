#include<bits/stdc++.h>
using namespace std;
int m;long long unsigned n;
const int maxm=1e6+5;
int data[maxm];
int a[maxm];
void search(int l,int r){
if(l==r){
printf("%d",l);return;}
int mid=(l+r)/2;
long long unsigned w=0;
for(int i=0;i<m;i++){w+=mid/data[i];}
long long unsigned wb=0;
for(int i=0;i<m;i++){wb+=(mid-1)/data[i];}

    if(w==n&&wb==n){
    while(wb==n){mid--;
    wb=0;
    for(int i=0;i<m;i++){wb+=(mid-1)/data[i];}
    }
    printf("%d",mid);return;
    }
    if(w>=n&&wb<n){printf("%d",mid);return;}
    else if(w>n&&wb>n){search(l,mid);}
    else{search(mid,r);}
}

int main(){
scanf("%d %llu",&m,&n);

for(int i=0;i<m;i++){scanf("%d",&data[i]);}
search(0,1000000);
}
