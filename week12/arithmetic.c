#include <stdio.h>
#include <string.h>

int f(int a[], int n, int i, int j) {
  int k, s = 0;
  for (k = j + 1; k < n; k++)
    if (a[k] + a[i] > a[j] * 2)
      break;
    else if (a[k] + a[i] == a[j] * 2) {
      s = 1;
      break;
    }
  if (s)
    return (f(a, n, j, k) + 1);
  else
    return (2);
}
int main() {
  int a[5001] = {0}, d, l = 0, b, i, j, t, s = 0, n, p, m = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (i = n - 1; i >= 0; i--)
    for (j = 0; j < i; j++)
      if (a[j] > a[j + 1]) {
        p = a[j];
        a[j] = a[j + 1];
        a[j + 1] = p;
      }
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++) {
      if (j > n + 1 - l)
        break;
      if (a[i] + (l - 1) * (a[j] - a[i]) > a[n - 1])
        continue;
      t = f(a, n, i, j);
      if (t > l) {
        l = t;
        d = a[j] - a[i];
        b = a[i];
      } else if (t == l && a[j] - a[i] > d) {
        d = a[j] - a[i];
        b = a[i];
      } else if (t == l && a[j] - a[i] == d && a[i] > b)
        b = a[i];
    }
  if (l > 2)
    for (i = 0; i < l; i++) {
      if (s)
        printf(",");
      printf("%d", b);
      b += d;
      s = 1;
    }
  else
    printf("NO");
}
