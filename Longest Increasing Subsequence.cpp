#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> >LISseq;
vector<int>parent(200005);

int LISseqFunction(int arr[], int arrsz)
{
    if(arrsz > 0) {LISseq.push_back({arr[0],0}); parent[0]=-1;}

    for(int i=1; i<arrsz; i++)
    {
        pair<int,int> a = {arr[i],-2}, b = {arr[i],1e9};
        if(LISseq.back().first < arr[i])
        {
            parent[i] = LISseq.back().second;
            LISseq.push_back({arr[i],i});
        }
        else if( lower_bound(LISseq.begin(),LISseq.end(),a) != upper_bound(LISseq.begin(),LISseq.end(),b) ) {}
        else
        {
            pair<int,int> tmp = {arr[i],1e9};
            auto it = upper_bound(LISseq.begin(),LISseq.end(),tmp);
            if(it==LISseq.begin()) parent[i]=-1;
            else
            {
                it--;
                parent[i]=(*it).second;
                it++;
            }
            tmp.second=i;
            *it = tmp;
        }
    }
    return LISseq.size();
}

///LISseq -1.3.0   0.4.1

int main()
{
    int arr[] = { 1,1,1,1,1,5,5,5,1,1 };
    cout<<LISseqFunction(arr,10)<<endl;
    int indx = LISseq.back().second;
    while(indx!=-1)
    {
        cout<<arr[indx]<<" ";
        indx = parent[ indx ];
    }
    return 0;
}
