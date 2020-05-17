#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
using namespace std;
int main(){
int n,q;
cin>>n>>q;
int tab[q];
FOR(i,q)scanf("%d",&tab[i]);
FOR1(i,n){
int ch=1;
FOR(j,q){if(tab[j]==i)ch=0;}


if(ch){
int x[n-1];
int cnt=0;
FOR1(j,n){if(j!=i){x[cnt]=j;cnt++;}}


do{
printf("%d ",i);
FOR(j,cnt)printf("%d ",x[j]);
printf("\n");
}while(next_permutation(x,x+cnt));


}

}

}
