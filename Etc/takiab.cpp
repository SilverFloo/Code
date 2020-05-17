#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
scanf("%d %d",&n,&k);
int tab[n];
for(int i=0;i<n;i++){scanf("%d",&tab[i]);}
sort(tab,tab+n);
int c=0;
for(int i=0;i<n-1;i++){
if(tab[i+1]-tab[i]<=k){c++;i++;}
}
printf("%d",c);

}
