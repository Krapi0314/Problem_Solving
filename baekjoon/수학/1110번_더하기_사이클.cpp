/*
baekjoon 1110��: ���ϱ� ����Ŭ

�ð� ����: 2��
�޸� ����: 128 MB

����
0���� ũ�ų� ����, 99���� �۰ų� ���� ������ �־��� �� ������ ���� ������ �� �� �ִ�. ���� �־��� ���� 10���� �۴ٸ� �տ� 0�� �ٿ� �� �ڸ� ���� �����, �� �ڸ��� ���ڸ� ���Ѵ�. �� ����, �־��� ���� ���� ������ �ڸ� ���� �տ��� ���� ���� ���� ������ �ڸ� ���� �̾� ���̸� ���ο� ���� ���� �� �ִ�. ���� ���� ����.
26���� �����Ѵ�. 2+6 = 8�̴�. ���ο� ���� 68�̴�. 6+8 = 14�̴�. ���ο� ���� 84�̴�. 8+4 = 12�̴�. ���ο� ���� 42�̴�. 4+2 = 6�̴�. ���ο� ���� 26�̴�.
���� ���� 4������ ���� ���� ���ƿ� �� �ִ�. ���� 26�� ����Ŭ�� ���̴� 4�̴�.
N�� �־����� ��, N�� ����Ŭ�� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. N�� 0���� ũ�ų� ����, 99���� �۰ų� ���� �����̴�.

���
ù° �ٿ� N�� ����Ŭ ���̸� ����Ѵ�. 
*/

#include <stdio.h>

int trans_n(int n) // 1 <= n <= 99
{
  int first_digit, second_digit;
  int temp_num;

  int right_n;

  first_digit = n / 10;
  second_digit = n % 10;

  temp_num = first_digit + second_digit;

  right_n = temp_num % 10;
  //left_n = second_digit;

  return (second_digit * 10 + right_n);
}

int main(void)
{
  int n;
  int changed_n;

  int count = 0;

  scanf("%d",&n);
  
  changed_n = n;
  while(1)
  {
    changed_n = trans_n(changed_n);
    count++;

    if(changed_n == n)
    {
      break;
    }
  }
  
  printf("%d\n",count);
  return 0;
}
