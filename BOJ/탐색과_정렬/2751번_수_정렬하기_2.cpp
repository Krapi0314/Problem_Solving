/*
BOJ 2751번: 수 정렬하기 2

시간 제한: 2초
메모리 제한: 256 MB 

문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

int compare( const void * a, const void * b)
{
  int num1 = *(int *)a;
  int num2 = *(int *)b;

  if(num1 < num2)
  {
    return -1;
  }
  else if(num1 > num2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main(void) {
  int n;
  int arr[1000000];
  int i;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&arr[i]);
  }

  //퀵 정렬
  qsort(arr,n,sizeof(int),compare);

  //결과 출력
  for(i=0; i<n; i++)
  {
    printf("%d\n",arr[i]);
  }

  return 0;
}
