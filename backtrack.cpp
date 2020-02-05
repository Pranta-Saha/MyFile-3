#include<bits/stdc++.h>
using namespace std;


class sum_of_subset{
public:
        int arr[200];
        bool flag[200];
        int sum,n;

        void print()
        {
                for(int i=0;i<n;i++)
                        if(flag[i]==1)
                                cout<<arr[i]<<' ';
                cout<<endl;
        }
        void go(int pos,int total)
        {
                if(total>sum) return;
                if(total==sum) {print(); return; }
                if(pos>=n) return;

                flag[pos]=1;
                go(pos+1,total+arr[pos]);

                flag[pos]=0;
                go(pos+1,total);
        }
        void solve()
        {
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            cin>>sum;
            go(0,0);

        }
};

int main()
{
    freopen("in.txt","r",stdin);
    sum_of_subset ob;
    ob.solve();
    return 0;
}
