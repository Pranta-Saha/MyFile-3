/// visit all vertex
/// minimum cost
/// minimum path
/// bipertip or not
/// number of part

#include<bits/stdc++.h>
using namespace std;

vector<int > adj[100];
bool visit[100];
stack<int> stk;
int bipertit[100],parents,child;
int dstnc[100],prnt[100];
map<string,int>stoi;
map<int,string>itos;

void DFS(int src)
{
    int top;
    visit[src]=1;
    stk.push(src);
    cout<<src<<" ";

    while(!stk.empty())
    {
        top= stk.top();
        stk.pop();

        for(int i=0;i<adj[top].size();i++)
        {
            int tmp=adj[top][i];
            if(visit[tmp]==0)
            {
                visit[tmp]=1;
                stk.push(top);
                stk.push(tmp);
                cout<<tmp<<" ";
                break ;
            }
        }
    }

}

int main()
{
    freopen("in.txt","r" , stdin);

    int eg,vrtx,i,j,n=0;

    string u,v,src,dst;

    cin>>eg>>src;

    for(i=1;i<=eg;i++)
    {
        cin>>u>>v;

        if(stoi.find(u)==stoi.end())
        {
            stoi[u]=++n;
            itos[n]=u;
        }

        if(stoi.find(v)==stoi.end())
        {
            stoi[v]=++n;
            itos[n]=v;
        }

        adj[stoi[u]].push_back(stoi[v]);
        adj[stoi[v]].push_back(stoi[u]);

    }

cout<<"visited way: ";

    DFS( stoi[src] );
}
