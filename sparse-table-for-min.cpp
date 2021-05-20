#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,q,i,j,l,r;
    cin>>n>>q;

    ll arr[n+1];
    for(i=1;i<=n;i++)
        cin>>arr[i];

    ll sparse[n+1][25];
    for(i=1;i<=n;i++)
    {
        sparse[i][0]=arr[i];
    }
    for(j=1;j<=20;j++)
    {
        ll len=pow(2,j);
        if(len>n) break;
        for(i=1;i<=n;i++)
        {
            if(i+len-1 > n) break;
            sparse[i][j]=min(sparse[i][j-1],sparse[i+(len/2)][j-1]);
        }
    }


    for(i=1;i<=q;i++)
    {
        cin>>l>>r;
        ll rang=r-l+1;
        ll k=log2(rang);
        ll ksqr=pow(2,k);
        cout<<min( sparse[l][k],sparse[r-ksqr+1][k])<<endl;
    }


    return 0;
}








