#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> pii;
const ll inf = 1e16;
const ll sz = 200005;

ll parent[sz][21];
ll depth[sz];
vector<ll>adj[sz];

class solution{
public:
    int kthAncestor(ll node, ll k)
    {
        if(k == 0) return node;
        while(k>0 && node != -1)
        {
            ll jumpto = log2(k);
            node = parent[node][jumpto];
            k = k - pow(2,jumpto);
        }
        return node;
    }


    //work when input in parent array;
    int findDepth(ll node)
    {
        if(depth[node] != -1) return depth[node];
        return depth[node] = findDepth(parent[node][0]) + 1;
    }



    void dfs(ll node, ll prnt=-1, ll dpth=0)
    {
        depth[node] = dpth;
        parent[node][0] = prnt;
        for(int i=0;i<adj[node].size();i++)
        {
            if(adj[node][i] == prnt) continue;
            dfs(adj[node][i],node,dpth+1);
        }
    }

    ///lowest common ancestor
    ll lca(int a, int b)
    {
        if(depth[a] > depth[b]) swap(a,b);
        ll diff = depth[b]-depth[a];
        for(ll i=0;i<=20;i++)
        {
            if(diff & (1<<i))
                b=parent[b][i];
        }
        if(a==b) return a;
        for(ll i=20;i>=0;i--)
        {
            if(parent[b][i] != parent[a][i])
            {
                a=parent[a][i];
                b=parent[b][i];
            }
        }
        return parent[a][0];
    }



    ll i,j,q,sum=0,c=0,k,w,h,ii,u,v,n,m,node;
    void solve()
    {
        cin>>n>>q;
        memset(depth,-1,sizeof(depth));
        depth[1] = 0;

        ///when input in parent array.
//        for(node=2;node<=n;node++)
//        {
//            cin>>u;
//            adj[u].push_back(node);
//            adj[node].push_back(u);
//            parent[node][0] = u;
//        }

        ///when input in edge list.
        for(node=2;node<=n;node++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);
        //depth[0] = 0;
        parent[1][0] = -1;
      
        //making sparse table of ancestors.
        for(i=1;i<=20;i++)
        {
            for(ll node=2;node<=n;node++)
            {
                parent[node][i] = parent[ parent[node][i-1] ][i-1];
            }
        }

        ll node;
        ll a,b, tmp,tmpDepth,x,y;
        while(q--)
        {
            cin>>a>>b;
            ll c=lca(a,b);
            cout<< depth[a]-depth[c] + depth[b]-depth[c] <<endl;
        }

    }
};


int main()
{
    int tc=1,tccnt=1;
    //cin>>tc;
    while(tc--)
    {
        solution ob;
        //cout<<"Case "<<tccnt++<<": ";
        ob.solve();
    }
    return 0;
}
