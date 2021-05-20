#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll arr[200005];
ll tree[800005];

void build(ll treePos, ll lft, ll rht)
{
    if(lft==rht)
    {
        tree[treePos] =arr[lft];
        return;
    }
    ll mid = (lft+rht)/2;
    build( treePos*2 ,lft,mid);
    build( treePos*2+1, mid+1,rht);
    tree[treePos]=min(tree[treePos*2],tree[treePos*2+1]);
}

void update(ll arrayPos, ll treePos, ll lft, ll rht, ll value)
{
    if(arrayPos<lft || rht<arrayPos)
        return;
    if(lft==rht)
    {
        tree[treePos]=value;
        return;
    }
    ll mid=(lft+rht)/2;
    update(arrayPos, treePos*2, lft, mid, value);
    update(arrayPos, treePos*2+1, mid+1, rht, value);
    tree[treePos]=min(tree[treePos*2], tree[treePos*2+1]);
}

ll rangeq(ll qlft, ll qrht, ll treePos, ll lft, ll rht)
{
    if( qrht < lft || rht < qlft) return 1e18;
    if( qlft<=lft && rht<=qrht )
    {
        return tree[treePos];
    }
    ll mid=(lft+rht)/2;
    ll x = rangeq(qlft, qrht, treePos*2, lft, mid);
    ll y = rangeq(qlft, qrht, treePos*2+1, mid+1, rht);
    return min(x,y);
}

int main()
{
    ll q,i,j,l,r;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>arr[i];

    build(1,1,n);
    //cout<<tree[1];

    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1) ///update
        {
            ll k,u;
            cin>>k>>u;
            arr[k]=u;
            update(k,1,1,n,u);
        }
        else ///query
        {
            cin>>l>>r;
            cout<<rangeq(l,r,1,1,n)<<endl;
        }
    }

    return 0;
}

