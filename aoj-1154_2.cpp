#include <iostream>
using namespace std;

const int MAX = 3 * 1e+5;
int n;
int num[MAX];  // 月曜土曜数を格納する配列
bool prime[MAX];

int main() {
  // エラトステネスの篩を月曜土曜数に適用して月曜土曜素数を抽出する
  int cnt = 0;
  for (int i=2; i<MAX; i++) {
    if (i % 7 == 1 || i % 7 == 6) {
      num[cnt++] = i;
    }
  }
  for (int i=0; i<cnt; i++) {
    for (int j=0; num[i]*num[j]<MAX; j++) {
      prime[num[i]*num[j]] = true;
    }
  }
  // 月曜土曜数を受け取って、月曜土曜素因数を出力する
  while (cin >> n, n != 1) {
    cout << n << ":";
    for (int i=0; i<cnt; i++) {
      if (!prime[num[i]]) {
        if (n % num[i] == 0) {
          cout << " " << num[i];
        }
      }
    }
    cout << endl;
  }
  return 0;
}
