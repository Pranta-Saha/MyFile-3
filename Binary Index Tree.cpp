#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll arr[200005];
ll BITarray[200005];

void add(ll pos, ll value)
{
    while(pos<=n)
    {
        BITarray[pos]+=value;
        pos += pos&(-pos);
    }
}

ll sumq(ll pos)
{
    ll s=0;
    while(pos>=1)
    {
        s+=BITarray[pos];
        pos -= pos&(-pos);
    }
    return s;
}

int main()
{
    ll q,i,j,l,r;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>arr[i];

    for(i=1;i<=n;i++)
        add(i,arr[i]);


    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1) ///update
        {
            ll k,u;
            cin>>k>>u;
            add(k,u-arr[k]);
            arr[k]=u;
        }
        else ///query
        {
            cin>>l>>r;
            cout<<sumq(r)-sumq(l-1)<<endl;
        }
    }

    return 0;
}

