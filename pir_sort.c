#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void func(int *n, int sh, int b)
{
  int max, temp, r = 0; 
  while ((sh * 2 <= b) && (!r))
  {
    if (sh * 2 == b) max = sh * 2; 
    else
    if (n[sh * 2] > n[sh * 2 + 1]) max = sh * 2;
    else
    max = sh * 2 + 1;
    if (n[sh] < n[max]){
      temp = n[sh];
      n[sh] = n[max];
      n[max] = temp;
      sh = max;
    }
    else r = 1; 
  }
}
void sort_pir(int *n, int arr)
{
    int temp;
  for (int i = (arr / 2) - 1; i >= 0; i--){
    func(n, i, arr - 1);
  }
  for (int i = arr- 1; i >= 1; i--){
    temp = n[0];
    n[0] = n[i];
    n[i] = temp;
    func(n, 0, i - 1);
  }
}
int main(int argc, char* argv[])
{
  int m;
  scanf("%d",&m);
  int a[m];
  for (int i=0; i<m; i++)
    scanf("%d",&a[i]);
  sort_pir(a,m);
  for (int i=0; i<m; i++)
    printf("%d ",a[i]);
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
