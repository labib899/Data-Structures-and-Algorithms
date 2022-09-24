#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//queue
#define size 100
typedef struct queue queue;
struct queue {
    int items[size];
    int front,rear;
};
queue *create_queue();
void enqueue(queue *q,int node);
int dequeue(queue *q);
bool empty(queue *q);

//graph
const int N=1000;
int graph[1001][1001];
int visited[1000+1];
int level[1000+1];
void bfs(int node);


int main() {
    int n,m; scanf("%d %d", &n,&m);
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        graph[a][b]=1;
        //graph[b][a]=1;
    }
    bfs(1);
    for(int i=1;i<=n;i++) printf("%d ", level[i]);
}


void bfs(int node) {
    queue *q=create_queue();
    enqueue(q,node);
    visited[node]=1;
    while(!empty(q)) {
        int p=dequeue(q);
        printf("%d ", p);
        for(int j=1;j<=N;j++) {
            if(graph[p][j]==1 && !visited[j]) {
                printf("   %d ", j);
                enqueue(q,j);
                visited[j]=1;
                level[j]=level[p]+1;
            }
        }
        printf("\n");
    }
}

queue *create_queue() {
    queue *q=malloc(sizeof(queue));
    q->front=q->rear=-1;
    return q;
}

void enqueue(queue *q,int node) {
    if(q->rear==size) return; //queue is full
    if(q->front==-1) q->front=0;
    q->items[++q->rear]=node;
}

int dequeue(queue *q) {
    int item;
    if(!empty(q)) {
        item=q->items[q->front++];
        if(q->front > q->rear) q->front=q->rear=-1; //resetting queue
        return item;
    }
}

bool empty(queue *q) {
    if(q->rear==-1) return true;
    else return false;
}
