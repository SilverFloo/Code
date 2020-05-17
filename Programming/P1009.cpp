#include<bits/stdc++.h>
using namespace std;
char a[10][3][3]={
 {
' ','_',' ',
'|',' ','|',
'|','_','|',},

{
' ',' ',' ',
' ',' ','|',
' ',' ','|',},
{
' ','_',' ',
' ','_','|',
'|','_',' ',},
{
' ','_',' ',
' ','_','|',
' ','_','|',},
{
' ',' ',' ',
'|','_','|',
' ',' ','|',},
{
' ','_',' ',
'|','_',' ',
' ','_','|',},
{
' ','_',' ',
'|','_',' ',
'|','_','|',},
{
' ','_',' ',
' ',' ','|',
' ',' ','|',},
{
' ','_',' ',
'|','_','|',
'|','_','|',},
{
' ','_',' ',
'|','_','|',
' ','_','|',},
};


int main(){
  int i,j,k,l;
  int nx,ny;long long unsigned nox=0,noy=0;
cin>>nx>>ny;
string x[3];
string y[3];
getline(cin,x[0]);
getline(cin,x[0]);
getline(cin,x[1]);
getline(cin,x[2]);
getline(cin,y[0]);
getline(cin,y[1]);
getline(cin,y[2]);
for(int i=0;i<3;i++){x[i].resize(4*nx,' ');y[i].resize(4*ny,' ');}

for(i=0;i<nx;i++){
for(j=0;j<10;j++){
  int ch=0;
 for(k=0;k<3;k++){
   for(l=0;l<3;l++){
   if(x[k][4*i+l]!=a[j][k][l]){ch=1;break;
   }
   }
  if(ch)break;

 }
  if(ch==0){nox*=10;nox+=j;break;}
}

}

for(i=0;i<ny;i++){
for(j=0;j<10;j++){
  int ch=0;
 for(k=0;k<3;k++){
   for(l=0;l<3;l++)if(y[k][4*i+l]!=a[j][k][l]){ch=1;break;}if(ch)break;
 }
  if(ch==0){noy*=10;noy+=j;break;}
}
}
printf("%llu",nox+noy);
}
/*

3
1
 _       _
 _|   | |_
 _|   | |_|
 _
  |
  |
*/

