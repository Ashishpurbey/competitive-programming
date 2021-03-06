#include <bits/stdc++.h>
#define tp pair<long long, int>
using namespace std;

const int maxn=100000;
const int nosol=-100;
const long long inf=(long long)1<<60;

int n,m;
long long d[maxn];
int pre[maxn];

priority_queue<tp, vector<tp>, greater<tp> > pq;
vector<int> g[maxn];
vector<long long> w[maxn];
vector<int> ans;

void dijkstra(int s, int t){
    for(int i=0;i<n;++i){
        d[i]=inf;
        pre[i]=nosol;
    }

    d[s]=0;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        for(int i=0;i<g[v].size();++i){
            if(d[g[v][i]] > d[v]+w[v][i]) {
                d[g[v][i]] = d[v]+w[v][i];
                pre[g[v][i]] = v;
                pq.push(make_pair(d[g[v][i]],g[v][i]));
            }
        }
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<m;++i){
        int a,b; 
        long long c;
        scanf("%d %d %lli",&a,&b,&c);
        a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }

    int s=0;
    int t=n-1;
    dijkstra(s,t);
    if(pre[t]==nosol){
        cout<<-1<<endl;
        return 0;
    }

    ans.push_back(t+1);
    while(pre[t]!=s){
        ans.push_back(pre[t]+1);
        t=pre[t];
    }
    ans.push_back(s+1);

    for(int i=ans.size()-1;i>=0;--i) cout<<ans[i]<<" ";
    return 0;
}
