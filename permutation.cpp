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

or
    string str;
    ll len;
    set<string>st;
    void go(string pre, ll flag)
    {
        if(pre.size()==len) { st.insert(pre); return; }
        for(ll i=len-1;i>=0;i--)
        {
            if((flag&(1<<i))==0)
            {
                pre+=str[len-i-1];
                go(pre,flag|(1<<i));
                pre.pop_back();
            }
        }
    }
    // call go("",0);
