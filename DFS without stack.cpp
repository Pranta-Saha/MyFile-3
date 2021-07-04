/// visit all vertex
/// bipertip or not
/// number of part

#include<bits/stdc++.h>
using namespace std;

vector<int > adj[100];
bool visit[100];
stack<int> stk;
int color[100],chkbipertite;
int dstnc[100],prnt[100];
map<string,int>stoi;
map<int,string>itos;


void DSF(int src)
{

    if(visit[src]==1) return;

    visit[src]=1;
    //color[src]=1;

cout<<src<<' ';

    for(int i=0;i<adj[src].size();i++)
    {
        if(color[src]==color[adj[src][i]]) chkbipertite=1;

        if(visit[adj[src][i]]==0)
        {
            if(color[src]==1) color[adj[src][i]]=2;
            else color[adj[src][i]]=1;

            DSF(adj[src][i]);
        }
    }
}

int main()
{
    freopen("in.txt","r" , stdin);

    int eg,vrtx,i,j,n=0,countpart=0;

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

        if(v==u)
        {
            ;
        }
        else
        {
            adj[stoi[u]].push_back(stoi[v]);
            adj[stoi[v]].push_back(stoi[u]);
        }

    }

cout<<"visited way: ";



    for(int i=1;i<=n;i++)
    {

        if(visit[i]!=1)
        {
            color[i]=1;
            countpart++;
            DSF( i );

        }
        //cout<<color[i]<<" ";

    }


    cout<<endl<<"number of part: "<<countpart<<endl;

    if(chkbipertite==1) cout<<"not bipertite"<<endl;
    else cout<<"Bipertite"<<endl;

}
