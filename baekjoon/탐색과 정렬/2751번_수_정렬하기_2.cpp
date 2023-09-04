/*
baekjoon 2751��: �� �����ϱ� 2

�ð� ����: 2��
�޸� ����: 256 MB 

����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
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

  //�� ����
  qsort(arr,n,sizeof(int),compare);

  //��� ���
  for(i=0; i<n; i++)
  {
    printf("%d\n",arr[i]);
  }

  return 0;
}
