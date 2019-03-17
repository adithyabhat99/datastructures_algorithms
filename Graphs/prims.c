#include <stdio.h>
void main() {
   int i, j, n, s;
   printf("Enter number of elements: ");
   scanf("%d", &n);
   int a[n][n], dist[n], used[n], parent[n];
   printf("Enter graph in matrix form:\n");
   for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            }
        }
   for (i = 0; i < n; i++) {
        dist[i] = 999;
        used[i] = 0;
        }
   dist[0] = 0;
   parent[0] = -1;
   for (i = 0; i < n-1; i++) {
        int k = 0, k_s = 999;
        for (j = 0; j < n; j++) if (dist[j] < k_s && used[j] == 0) {
             k = j;
             k_s = dist[j];
        }
        used[k] = 1;
        for (j = 0; j < n; j++) {
            if (!used[j] && a[k][j] != 999 && a[k][j] < dist[j]) parent[j] = k, dist[j] = a[k][j];
        }
   }
   printf("Results:\n");
   for (i = 1; i < n; i++) printf("%d -> %d = %d\n", i, parent[i], dist[i]);
}
