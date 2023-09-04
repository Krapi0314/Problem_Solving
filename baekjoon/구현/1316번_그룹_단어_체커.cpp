/*
baekjoon 1316��: �׷� �ܾ� üĿ

�ð� ����: 2��
�޸� ����: 128 MB

����
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.
�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�. 
*/

#include <stdio.h>

#define MAX_N 100
#define MAX_LENGTH 100

int main(void) {
  int n;
  int i,k;
  char str[MAX_N][MAX_LENGTH];

  char alphabet;
  int idx;
  int flag;
  int grouped = 0;
  int m;

  scanf("%d",&n);
  for(i=0; i<n; i++)
  {
    scanf("%s",str[i]);
  }

  for(i=0; i<n; i++)
  {
    k = 0;
    flag = 0; //1�� ��-�׷� �ܾ� 0�� �׷� �ܾ�
    idx = 0;

    while(str[i][k] != '\0')
    {
      alphabet = str[i][k];
      idx = k;
      m = 0;
      while(str[i][k+m] == alphabet)
      {
        idx++;
        m++;
      }

      while(str[i][idx] != '\0')
      {
        if(str[i][idx] == alphabet)
        {
          flag = 1;
        }
        idx++;
      }

      k++;
    }

    if(flag == 0)
    {
      grouped++;
    }
  }

  printf("%d\n",grouped);
  return 0;
}
