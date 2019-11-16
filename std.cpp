#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int in[10010];
int money[10010];
struct Edge
{
	int to;
	int next;
}edge[20000+10];
int top,head[10000+10];
int n;
int topo()
{
//	priority_queue<int, vector<int>, greater<int> > q; 	//优先队列错误 
	queue<int> q;//适用一般队列 
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
			q.push(i);
	}
	int ans=0,cnt=0,v;
	while(!q.empty())
	{
		//v=q.top();
		v=q.front();
		q.pop();
		in[v]--;
		ans+=money[v];
		cnt++;
		for(int i=head[v];i!=-1;i=edge[i].next)		
		{
			Edge E=edge[i];				
			in[E.to]--;			
			if(in[E.to]==0)
			{
				q.push(E.to);
				money[E.to]=money[v]+1;
			}
		}
	}
	if(cnt!=n)
		ans=-1;
	return ans;
}
int main()
{
	int m;
	int a,b;
	while(~scanf("%d%d",&n,&m))
	{
		memset(in,0,sizeof(in));
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++)
			money[i]=888;
		int sum;	
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			edge[i].to=a;
			edge[i].next=head[b];
			head[b]=i;
			in[a]++;
		}
		sum=topo();
		printf("%d\n",sum);
	}
	return 0;
}
