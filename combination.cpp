#include<bits/stdc++.h>
using namespace std;

bool flag[100];
int num[100];

void combination(int at, int left, int n,int r)
{
        if(left==0)
        {
                for(int i=1;i<=r;i++)
                        cout<<num[i]<<' ';
                cout<<endl;
                return ;
        }
        if(at==n+1) return;
        if(left > n-at+1 ) return;

        num[r-left+1]=at;
        combination(at+1,left-1,n,r);
        combination(at+1,left,n,r);
}

int main()
{
        int n,r;
        cin>>n>>r;
        combination(1,r,n,r);
}
