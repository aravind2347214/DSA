#include <stdio.h>

// Maximum number of workers
#define MAX_WORKERS 20

int adj[MAX_WORKERS][MAX_WORKERS], n, m, q[MAX_WORKERS], visited[MAX_WORKERS];

// Worker structure
struct worker {
    int id;
    char name[20];
};

// Edge representation
struct edge {
    int s, d;
};

struct edge e[MAX_WORKERS];

// Function to create Adjacency Matrix
void createAdjMatrix(struct edge e[]) {
    int i, j, x, y;

    // Initialize the adjacency matrix to zero
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Traverse the array of Edges
    for (i = 0; i < m; i++) {
        // Find X and Y of Edges as source and destination of the edges
        x = e[i].s;
        y = e[i].d;
        // Update value to 1
        adj[x][y] = 1;
        adj[y][x] = 1; // not required in the case of a directed graph
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void dfs(int v) {
    int i;
    for (i = 0; i < n; i++) {
        if (adj[v][i] != 0 && visited[i] == 0) {
            visited[i] = 1;
            printf("%d  ", i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, v;
    char ch = 'y';

    m = 0;
    i = 0;

    printf("Enter the number of workers: ");
    scanf("%d", &n);

    while (ch == 'y') {
        printf("Enter the ID of the worker: ");
        scanf("%d", &e[i].s);
        printf("Enter the ID of the worker to connect: ");
        scanf("%d", &e[i].d);
        printf("Do you want to add more connections? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);
        m = m + 1;
        i++;
    }

    // Function call to create Adjacency Matrix
    createAdjMatrix(e);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nEnter the starting worker ID: ");
    scanf("%d", &v);

    printf("\nDFS traversal is:\n");
    visited[v] = 1;
    printf("%d   ", v);
    dfs(v);

    return 0;
}
 