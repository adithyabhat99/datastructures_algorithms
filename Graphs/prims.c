//Finding MST for a graph

#include <stdio.h>
void main()
{
     int i, j, n, s, w;
     printf("Enter number of elements: ");
     scanf("%d", &n);
     int a[n][n], dist[n], used[n], parent[n];
     printf("Enter graph in matrix form:\n");
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               scanf("%d", &a[i][j]);
          }
     }
     for (i = 0; i < n; i++)
     {
          dist[i] = 999;
          used[i] = 0;
     }
     dist[0] = 0;
     parent[0] = -1;
     for (i = 0; i < n - 1; i++)
     {
          int u = 0, min = 999;
          for (j = 0; j < n; j++)
               if (dist[j] < min && used[j] == 0)
               {
                    u = j;
                    min = dist[j];
               }
          used[u] = 1;
          for (w = 0; w < n; w++)
          {
               if (!used[w] && a[u][w] != 999 && a[u][w] < dist[w])
               {
                    parent[w] = u;
                    dist[w] = a[u][w];
               }
          }
     }
     printf("Results:\n");
     for (i = 1; i < n; i++)
          printf("%d -> %d = %d\n", parent[i], i, dist[i]);
}