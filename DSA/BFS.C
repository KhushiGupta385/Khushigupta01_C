// BREADTH FIRST SEARCH(BFS)
/*ITS USING QUEUE(FIFO) DATA STRUCTURE*/
#include<stdio.h>
#define size 10
int q[size];
int r=-1, f=-1;

void Insert(int v) {
    if(r==size-1) {
        printf("Queue is full\n");
        return;
    }
    if(f==-1) {
        f=r=0;
    }else{
        r++;
    }
    q[r]=v;
}

int Del() {
    if(f==-1 || f>r) {
        printf("Queue is empty\n");
        return -1;
    } 
    int data= q[f++];

    if(f>r) {
        f=r=-1;
    }
    return data;
}

int isEmpty() {
    return(f==-1 || f>r);
}

void bfs(int adj[size][size],int n_v,int start_ver) {
    int visited[size]={0};
    visited[start_ver]=1;
    Insert(start_ver);

    while(!isEmpty() ) {
        int curv = Del();
        printf("cv=%d",curv);
        for(int i=0;i<n_v;i++) {
            if(adj[curv][i]==1 && !visited[i]) {
                visited[i]=1;
                Insert(i);
            }
        }
    }
}

int main() {
    int adj[size][size],n_v,start_ver;

    printf("Enter the total number of vertices: ");
    scanf("%d", &n_v);

    printf("Enter the element of the adjacency matrix: \n");
    for(int i=0;i<n_v;i++) {
        for(int j=0;j<n_v;j++) {
            scanf("%d", & adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start_ver);
     
    printf("BFS started from vertex= %d\n",start_ver);
    scanf("%d",&start_ver);

    printf("BFS started from vertex= %d\n",start_ver);
    bfs(adj, n_v, start_ver);

    return 0;
}

