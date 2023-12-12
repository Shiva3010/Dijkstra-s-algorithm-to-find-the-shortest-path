// Write a C code for solving the following problem.
// 1. Your code will take a positive integer n as input which is the number of vertices of a connected graph G.
// 2. Your code will ask for adjacent vertices of every vertex one by one. Here vertex indices are from 0
// to n − 1.
// 3. Based on your adjacency list it will take the weight of every edge as input in a matrix of size n × n.
// If aij is the element of the matrix then it corresponds to the directed edge (i, j).
// 4. If there is no edge between any two vertices then weight will be character ‘N’.
// 5. Based on these inputs the code will ask for a source vertex S as input (it will be an integer from 0
// to n − 1).
// 6. Your code will display distances from source vertex S to every other vertices.
// 7. Your code will display shortest path from S to other vertices. If there is an edge between a to b it
// will print ‘a → b’.
// 8. For finding the shortest path, you need to use the Dijkstra’s algorithm.
// 9. Finally find the Maximum spanning tree of G using Prim’s algorithm. If there is an edge between
// a to b it will print ‘a → b’.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INT_MAX 1000000

int main() {
    int n;

    printf("Enter the number of vertices ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a positive integer of vertices.\n");
        return 1;
    }

    char weight[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the weights\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d to %d: ", i, j);
            scanf(" %c", &weight[i][j]);

            if (weight[i][j] == 'N') {
                weight[i][j] == INT_MAX;
            }
        }
    }

    printf("\nWeight matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (weight[i][j] == INT_MAX) {
                printf("N ");
            } else {
                printf("%c ", weight[i][j]);
            }
        }
        printf("\n");
    }

    maxSpanningTreePrim(n, weight);

    return 0;
}

void maxSpanningTreePrim(int n, char weight[MAX_VERTICES][MAX_VERTICES]) {
    int maxParent[MAX_VERTICES];
    int maxKey[MAX_VERTICES];
    int mstSet[MAX_VERTICES] = {0};

    for (int i = 0; i < n; i++) {
        maxKey[i] = -1;
    }

    maxKey[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int maxWeight = -1;

        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && maxKey[v] > maxWeight) {
                u = v;
                maxWeight = maxKey[v];
            }
        }

        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && weight[u][v] != 'N' && weight[u][v] > maxKey[v]) {
                maxParent[v] = u;
                maxKey[v] = weight[u][v] - '0';
            }
        }
    }

    printf("maxWeight \n");
    for (int i = 1; i < n; i++) {
        printf("%d -> %d\n", maxParent[i], i);
    }
}