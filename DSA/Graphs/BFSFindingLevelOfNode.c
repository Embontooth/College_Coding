#include <stdio.h>
#include <stdlib.h>
void bfs(int** arr, int source, int vertices, int tar){
    int * visited = (int *)calloc(vertices,sizeof(int));
    visited[source]=1;
    int q[vertices];
    int front=0;
    int rear=0;
    q[rear++]=source;
    int level = -1;
    while(front<rear){
        int node = q[front++];
        level++;
        if(node == tar){
            printf("%d ", level);
            return;
        }
        for(int i=0;i<vertices;i++){
            if(arr[node][i] && !visited[i]){
                visited[i]=1;
                q[rear++]=i;
            }
        }
    }
    printf("-1");
}
int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    int ** arr = (int **)calloc(v,sizeof(int *));
    for(int i=0;i<v;i++){
        arr[i]=(int *)calloc(v,sizeof(int));
    }
    for(int i=0;i<e;i++){
        int val1,val2;
        scanf("%d %d",&val1,&val2);
        arr[val1][val2]=1;
        arr[val2][val1]=1;
    }
    int source;
    scanf("%d",&source);
    int tar;
    scanf("%d",&tar);
    bfs(arr,source,v,tar);
}