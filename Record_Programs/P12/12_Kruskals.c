#include <stdio.h>

int parent[10];

int find(int x){
    while(parent[x]!=x)
        x=parent[x];
    return x;
}

void uni(int x,int y){
    parent[y]=x;
}

int main(){
    int n,edges=0;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int cost[10][10];
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(int i=0;i<n;i++)
        parent[i]=i;

    printf("Edges in MST using Kurksals Algorithm:\n");

    while(edges<n-1){
        int min=9999,a=-1,b=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j]!=0 && cost[i][j] < min){
                    int u=find(i);
                    int v=find(j);
                    if(u!=v){
                        min = cost[i][j];
                        a=i; b=j;
                    }
                }

        uni(find(a),find(b));
        printf("%d -- %d (weight = %d)\n",a,b,min);
        cost[a][b]=cost[b][a]=9999;
        edges++;
    }
    return 0;
}
