
/// visit all vertex
/// minimum cost
/// minimum path
/// bipertip or not
/// number of part




#include<bits/stdc++.h>
using namespace std;

vector<int > adj[100];
bool visit[100];
queue<int> que;
int bipertit[100];
int dstnc[100],prnt[100];
map<string,int>string_To_integer;
map<int,string>integer_To_string;



///BFS function start.
        void BFS(int src, int dst)
        {
            int nd,parents,child,i,chkb=1,no_perant=0;

            que.push(src);
            visit[src]=true;
            prnt[src]=0;
            bipertit[src]=1;

        ///cout<<endl<<"visited way: "<<integer_To_string[src]<<" ";

            while(!que.empty())
            {
                parents=que.front();
                que.pop();

                for(i=0; i<adj[parents].size(); i++)
                {
                    child= adj[parents][i];

                    if(bipertit[child] == bipertit[parents] ) chkb=0;

                    if(visit[child]==0)
                    {
                        if(bipertit[parents]==1) bipertit[child]=2;
                        else bipertit[child]=1;

                        que.push(child);
                        visit[child]=true;
                        dstnc[child]=dstnc[parents]+1;
                        prnt[child]=parents;
       /// cout<<integer_To_string[child]<<" ";
                    }
                }
            }


       /// cout<<endl<<"cost: "<<dstnc[dst];


///        cout<<endl<<"path :";
//            stack<int>wayes;
//            nd=dst;
//            wayes.push(dst);
//            while(nd!=src)
//            {
//                if(prnt[nd]==0) { no_perant=1; break; }
//                wayes.push(prnt[nd]);
//                nd=prnt[nd];
//            }
//
//            if(no_perant==1)
//        cout<<"NOT conected";
//            else while(!wayes.empty())
//            {
//                cout<< integer_To_string[wayes.top()]<<" ";
//                wayes.pop();
//            }



//            if(chkb==0)
//        cout<<endl<<"NOT bipertite";
//            else
//        cout<<endl<<"bipertite";



        }
///end of BFS function.


int main()
{
    freopen("in.txt","r",stdin);

    int eg,vrtx,i,j,n=0;

    string u,v,src,dst;

    cin>>eg;  ///total edge number.

    cin>>src>>dst; ///source and destination


            for(i=1;i<=eg;i++) ///taking input and convert string & saving in map.
            {
                cin>>u>>v;

                if(string_To_integer.find(u)==string_To_integer.end())
                {
                    string_To_integer[u]=++n;
                    integer_To_string[n]=u;
                }

                if(string_To_integer.find(v)==string_To_integer.end())
                {
                    string_To_integer[v]=++n;
                    integer_To_string[n]=v;
                }

                if(u!=v)
                {
                    adj[string_To_integer[u]].push_back(string_To_integer[v]);
                    adj[string_To_integer[v]].push_back(string_To_integer[u]);
                }
            }

    BFS(string_To_integer[src],string_To_integer[dst]);
    int cntPart=1;

    for(i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            cntPart++;
            BFS(i,string_To_integer[dst]);

        }
    }

    cout<<endl<<endl<<"Number of part: "<<cntPart<<endl;

}