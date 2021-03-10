#include <stdio.h>

int n;

long long int d[110];

long long int f(){
    long long int min = 9223372036854775807;
    for(int i=1;i<=n;i++) min = min > d[i] ? d[i] : min;
    return min;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%lld", &d[i]);

  printf("%lld", f());
  return 0;
}