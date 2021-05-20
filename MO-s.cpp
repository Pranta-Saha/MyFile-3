#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll block;
class query
{
public:
    ll l,r,indx;
    query(){}
    query(ll lft, ll rht, ll i){l=lft; r=rht; indx=i;}
    bool operator<(const query& b)const
    {
        if(l/block == b.l/block)
            return r < b.r;
        return l/block < b.l/block;
    }
};


int main()
{
    ll n,q,i,j,l,r;
    cin>>n>>q;
    block = sqrt(n);
    ll arr[n+1];
    vector<query>queries;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    for(i=1;i<=q;i++)
    {
        cin>>l>>r;
        queries.push_back(query(l,r,i));
    }
    sort(queries.begin(),queries.end());

    ll sum=arr[1];
    ll lft=1,rht=1;
    ll res[q+1];
    for(i=0;i<q;i++)
    {
        while(rht<queries[i].r)
        {
            sum+=arr[++rht];
        }
        while(queries[i].l<lft)
        {
            sum+=arr[--lft];
        }
        while(queries[i].r<rht)
        {
            sum-=arr[rht--];
        }
        while(lft<queries[i].l)
        {
            sum-=arr[lft++];
        }
        res[queries[i].indx]=sum;
    }
    for(i=1;i<=q;i++)
        cout<<res[i]<<endl;

    return 0;
}








