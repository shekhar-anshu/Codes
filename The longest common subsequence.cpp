#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    void lcs_length(int [],int [],int,int);
    int n,m,a[101],b[101];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    lcs_length(a,b,n,m);
    return 0;
}

void lcs_length(int a[],int b[],int n,int m)
{
    int c[101][101],d[101][101],i,j;
    void print_lcs(int [][101],int [],int,int);
    for(i=1;i<=n;i++)
        c[i][0]=0;
    for(j=0;j<=m;j++)
        c[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                d[i][j]=111;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                d[i][j]=222;
            }
            else
            {
                c[i][j]=c[i][j-1];
                d[i][j]=333;
            }
        }
    }
    print_lcs(d,a,n,m);
}
void print_lcs(int d[][101],int a[],int i,int j)
{
   if(i==0||j==0)
    return;
   if(d[i][j]==111)
   {
       print_lcs(d,a,i-1,j-1);
       cout<<a[i]<<" ";
   }
   else if(d[i][j]==222)
    print_lcs(d,a,i-1,j);
   else
    print_lcs(d,a,i,j-1);
}