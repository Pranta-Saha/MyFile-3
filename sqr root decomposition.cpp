#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ll n,q,i,j,l,r;
    cin>>n>>q;
    ll arr[n+1];
    for(i=0;i<n;i++)
        cin>>arr[i];

    ll block=sqrt(n);
    ll block_sum[n/block+5]={0};

    for(i=0;i<n;i++)
    {
        block_sum[i/block]+=arr[i];
    }

    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1) ///update
        {
            ll k,u;
            cin>>k>>u;
            k--;
            block_sum[k/block]-=arr[k];
            arr[k]=u;
            block_sum[k/block]+=arr[k];
        }
        else ///query
        {
            cin>>l>>r;
            l--;
            r--;
            ll sum=0;
            if(l/block == r/block)
            {
                for(i=l;i<=r;i++)
                    sum+=arr[i];
                cout<<sum<<endl;
                continue;
            }
            ll block_no_of_l=l/block;
            ll block_no_of_r=r/block;
            for(i=l ; i <= (block_no_of_l+1)*block-1 ; i++) sum+=arr[i];
            for(i=block_no_of_r*block; i<=r; i++) sum+=arr[i];
            for(i=block_no_of_l+1; i <= block_no_of_r-1; i++ ) sum+=block_sum[i];
            cout<<sum<<endl;
        }
    }

    return 0;
}

