#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void sort_fast(int *a, int l, int r){
    int i=l, j=r,d,m=a[(l + r)/2];
    while(i <= j)
    {
        for(i=l; a[i] < m; i++);
        for(j=r; a[j] > m; j--);
        if(i <= j)
        {
            d = a[i];
            a[i++] = a[j];
            a[j--] = d;
        }
    }
    if(l < j) sort_fast(a,l,j);
    if(i < r) sort_fast(a,i,r);
}
 
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    sort_fast(arr,0,n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
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
