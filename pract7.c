// social network connectivity using graph traversal(adjecancy matrix)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Adjacency matrix */
int adj[MAX][MAX];
int n;

/* Add connection between two users */
void addConnection(int u, int v) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        printf("Invalid user ID!\n");
        return;
    }

    if (u == v) {
        printf("Self-connection is not allowed.\n");
        return;
    }

    /* Add connection between u and v */
    adj[u][v] = 1;
    adj[v][u] = 1;

    printf("Connection added successfully.\n");
}

/* Breadth First Search */
void BFS(int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    if (start < 0 || start >= n) {
        printf("Invalid starting user ID!\n");
        return;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        for (int v = 0; v < n; v++) {
            if (adj[current][v] == 1 && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    printf("\n");
}

/* Depth First Search using recursion */
void DFSUtil(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int v = 0; v < n; v++) {
        if (adj[vertex][v] == 1 && !visited[v]) {
            DFSUtil(v, visited);
        }
    }
}

/* DFS traversal */
void DFS(int start) {
    int visited[MAX] = {0};

    if (start < 0 || start >= n) {
        printf("Invalid starting user ID!\n");
        return;
    }

    printf("DFS Traversal: ");
    DFSUtil(start, visited);
    printf("\n");
}

/* Display adjacency matrix */
void displayGraph(void) {
    printf("\nSocial Network (Adjacency Matrix):\n");

    printf("   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);

        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }
}

/* Main function */
int main(void) {
    int choice, u, v, start;

    printf("Enter number of users (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of users!\n");
        return 1;
    }

    /* Initialize adjacency matrix */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    do {
        printf("\n--- Social Network Menu ---\n");
        printf("1. Add Connection\n");
        printf("2. Display Graph\n");
        printf("3. Perform BFS\n");
        printf("4. Perform DFS\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two user IDs (0 to %d): ", n - 1);
                scanf("%d %d", &u, &v);
                addConnection(u, v);
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                printf("Enter starting user ID: ");
                scanf("%d", &start);
                BFS(start);
                break;

            case 4:
                printf("Enter starting user ID: ");
                scanf("%d", &start);
                DFS(start);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
