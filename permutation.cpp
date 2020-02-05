#include<bits/stdc++.h>
using namespace std;

bool flag[100];
int num[100];

void permutation(int at, int n)
{

        if(at==n+1)
        {
                for(int i=1;i<=n;i++)
                        cout<<num[i]<<' ';
                cout<<endl;
                return;
        }
        for(int i=1;i<=n;i++)
        {
                if(flag[i]==1) continue;
                num[at]=i;
                flag[i]=1;
                permutation(at+1,n);
                flag[i]=0;
        }
}

int main()
{
        int n;
        cin>>n;
        permutation(1,n);
}
