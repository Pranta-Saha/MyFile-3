#include<bits/stdc++.h>
using namespace std;
//http://103.3.226.208/

int colom[100]={0},diagonal1[100]={0},diagonal2[100]={0},flag[100]={0};

void nqueen(int x,int n)
{
        if(x==n+1)
        {
                for(int i=1;i<=n;i++)
                        cout<<flag[i]<<' ';
                cout<<endl;
                return ;
        }
        for(int i=1;i<=n;i++)
        {
                if(colom[i] || diagonal1[x+i] || diagonal2[x-i+n]) continue;
                flag[x]=i;
                colom[i]=diagonal1[x+i]=diagonal2[x-i+n]=1;
                nqueen(x+1,n);
                colom[i]=diagonal1[x+i]=diagonal2[x-i+n]=0;
        }
}

int main()
{
        int n;
        cin>>n;
        nqueen(1,n);
}
