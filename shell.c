#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void shell_sort(int a[], int n)
{
  int d=n/2;
  while (d>0)
{
  for (int i=0; i<n-d; i++)
{
  int j=i;
  while (j>=0 && a[j]>a[j+d])
{
  int k=a[j];
  a[j]=a[j+d];
  a[j+d]=k;
  j--;
}
}
  d/=2;
}
  for (int i=0; i<n-d; i++)
       printf("%d ",a[i]);
}
int main(int argc, char* argv[])
{
  int m;
  scanf("%d",&m);
  int b[m];
  for (int i=0; i<m; i++)
    scanf("%d",&b[i]);
  shell_sort(b,m);
  srand(time(0));
  long double a1;
  int b1;
  time_t time1=time(0);
  for (int i=0; i<=100000; i++)
    for (int j=0; j<=10000; j++)
     a1*=(i+1.0)/(j+1.0);
  time_t time2=time(0);
  for (int i=0; i<=100000; i++)
    for (int j=0; j<=10000; j++)
     b1+=i-j;
  time_t time3=time(0);   
  printf("1: %ld;\t\t2: %ld\n", time2-time1, time3-time2);
  return a1+b1;
  return 0;
}
