#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5

struct Queue
{
    int items[MAX_NODES], front, rear;
};

struct Queue *create_queue()
{
    struct Queue *que = (struct Queue *)malloc(sizeof(struct Queue));
    que->front = 0;
    que->rear = -1;
    return que;
}

void enque(int elem, struct Queue *que)
{
    que->items[++que->rear] = elem;
}

int deque(struct Queue *que)
{
    if (que->front <= que->rear)
    {
        return que->items[que->front++];
    }
}

int is_not_empty(struct Queue *que)
{
    return (que->front <= que->rear);
}

void display(struct Queue *que)
{
    printf("Elements are\n");
    for (int i = que->front; i <= que->rear; i++)
    {
        printf("%d ", que->items[i]);
    }
}

int is_present(int elem, struct Queue *que)
{
    int is_found = 0;
    for (int i = que->front; i <= que->rear; i++)
    {
        if (que->items[i] == elem)
        {
            is_found = 1;
            break;
        }
    }
    return is_found;
}

void read_graph(int adj_matrix[MAX_NODES][MAX_NODES], int n_vertices, int is_visited[MAX_NODES])
{
    for (int i = 0; i < n_vertices; i++)
    {
        is_visited[i] = 0;
        for (int j = 0; j < n_vertices; j++)
        {
            // scanf("%d", &adj_matrix[i][j]);
            adj_matrix[i][j] = 0;
        }
    }
    // sample input 1
    adj_matrix[0][1] = adj_matrix[0][2] = adj_matrix[0][3] = 1;
    adj_matrix[1][0] = adj_matrix[2][0] = adj_matrix[3][0] = 1;
    adj_matrix[4][2] = adj_matrix[2][4] = 1;

    // sample input 2
    // adj_matrix[4][1] = adj_matrix[1][4] = adj_matrix[1][2] = 1;
    // adj_matrix[1][3] = adj_matrix[3][1] = adj_matrix[2][1] = 1;
    // adj_matrix[0][3] = adj_matrix[3][0] = 1;
}

int main()
{
    int adj_matrix[MAX_NODES][MAX_NODES], n_vertices, is_visited[MAX_NODES];
    n_vertices = 5;
    read_graph(adj_matrix, n_vertices, is_visited);
    struct Queue *to_visit_que = create_queue();
    int start = 0;
    enque(start, to_visit_que);
    while (is_not_empty(to_visit_que))
    {
        int current_vertex = deque(to_visit_que);
        printf("%d, ", current_vertex);
        is_visited[current_vertex] = 1;
        for (int neigbor = 0; neigbor < n_vertices; neigbor++)
        {
            int is_adjacent = adj_matrix[current_vertex][neigbor];
            if (is_adjacent && !is_visited[neigbor] && !is_present(neigbor, to_visit_que))
            {
                enque(neigbor, to_visit_que);
            }
        }
    }

    return 0;
}