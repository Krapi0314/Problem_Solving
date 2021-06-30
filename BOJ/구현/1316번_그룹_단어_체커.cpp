/*
BOJ 1316번: 그룹 단어 체커

시간 제하: 2초
메모리 제한: 128 MB

문제
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

출력
첫째 줄에 그룹 단어의 개수를 출력한다. 
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
    flag = 0; //1은 비-그룹 단어 0은 그룹 단어
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
