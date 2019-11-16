#include<bits/stdc++.h>
using namespace std;

vector<int>d[10005];
int de[10005];
queue<int>p;

int n,m;
int sum;

int topo(){
	int k=0;
	while(!p.empty()) p.pop();
	int num=888;
	while(1){
		int tmp=-1;
		for(int i=1;i<=n;i++){
			if(de[i]==0) {
				p.push(i);
				tmp=1;
				k++;
			}
		}
		if(tmp==-1) break;
		while(!p.empty()){
			int cur=p.front();
			for(int i=0;i<d[cur].size();i++){
				de[d[cur][i]]--;
			}
			de[cur]=-1;
			p.pop();
			sum+=num;
		}
		num++;
	}
	if(k<n) return 0;
	else return 1;
}


int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=10000;i++){
			d[i].clear();
			de[i]=0;
		}
		sum=0;
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			d[y].push_back(x);
			de[x]++;
		}
		int flag=topo();
		if(!flag) printf("-1\n");
		else printf("%d\n",sum);
	}
	return 0;
}
