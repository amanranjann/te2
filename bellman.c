#include<stdio.h>

int bellman(int graph[10][10],int edge[10][2],int E,int V)
{
   int dist[V],parent[V],src;
   int flag=1,i,j;
  for(i=0;i<V;i++)
  {
     dist[i]=1000;
     parent[i]=-1;
  }
  printf("Enter the source\n");
  scanf("%d",&src);
  dist[src-1]=0;
   
  for(i=0;i<V-1;i++)
  {
     for(j=0;j<E;j++)
     {
        int u,v;
        u=edge[j][0];v=edge[j][1];
        if(dist[u]+graph[u][v]<dist[v])
        {
           dist[v]=dist[u]+graph[u][v];
           parent[v]=u;
         }  
     }
  }
  
    for(j=0;j<E;j++)
     {
        int u,v;
        u=edge[j][0];v=edge[j][1];
        if(dist[u]+graph[u][v]<dist[v])
          flag=0;
     } 
  
  if(flag)
  {
     for(i=0;i<V;i++)
       printf("Vertex %d->cost=%d parent=%d\n",i+1,dist[i],parent[i]+1);
  }
  return flag;
}


int main()
{
  int edge[10][2],graph[10][10],V,k=0,i,j;
  
  printf("Enter the no of vertices\n");
  scanf("%d",&V);
  
  int weight;
  for(i=0;i<V;i++)
   {
     for(j=0;j<V;j++)
     {
        scanf("%d",&weight);
        graph[i][j]=weight;
        if(weight!=0)
        {
           edge[k][0]=i;edge[k++][1]=j;
        }
     }
   }
   if(bellman(graph,edge,k,V))
  	printf("No negative edge cycle\n");
   else
       printf("Negative edge cycle exists\n");
   
   return 0;
}

