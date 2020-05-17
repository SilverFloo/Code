#include<stdio.h>
int m,n;
int t[20][20];
int tab[20][20];
int check(int i,int j){
if(i>0){
        if(tab[i][j]==tab[i-1][j]&&t[i-1][j]==1){
            if(j>0){if(t[i][j-1]==1)if(tab[i][j]==tab[i][j-1]){return 1;}}
            if(j<n-1){if(t[i][j+1]==1)if(tab[i][j]==tab[i][j+1]){return 1;}}
        }
}

if(i<m-1){
        if(tab[i][j]==tab[i+1][j]&&t[i+1][j]==1){
         if(j>0){if(t[i][j-1]==1)if(tab[i][j]==tab[i][j-1]){return 1;}}
            if(j<n-1){if(t[i][j+1]==1)if(tab[i][j]==tab[i][j+1]){return 1;}}
        }
}
return 0;
}
int ch(int i,int j){
int c=0;
if(i>0){if(tab[i][j]==tab[i-1][j])c++;}
if(j>0){if(tab[i][j]==tab[i][j-1])c++;}
if(i<m-1){if(tab[i][j]==tab[i+1][j])c++;}
if(j<n-1){if(tab[i][j]==tab[i][j+1])c++;}
return c;
}
main(){
int count=0,i,j;
scanf("%d",&m);
n=m;
for(i=0;i<m;i++){
for(j=0;j<n;j++){
scanf(" %d",&tab[i][j]);
}
}

for(i=0;i<m;i++){
for(j=0;j<n;j++){
t[i][j]=ch(i,j);

}
}

for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(t[i][j]==2){
    if(check(i,j)){count++;}
}
}
}
printf("%d",count);
}
