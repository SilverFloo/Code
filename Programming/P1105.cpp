#include<bits/stdc++.h>
bool a[2000001];
main(){
int n,f;
scanf("%d %d",&n,&f);
for(int i=0;i<n;i++){
int x;
scanf("%d",&x);
a[x]=1;
}int c=0;
for(int i=2000000;i>0;i--){
if(a[i])c++;
if(c==f){printf("%d",i);break;}
}

}
