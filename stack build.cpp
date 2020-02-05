#include <bits/stdc++.h>
using namespace std;

template<class T>

class stck{
    int top=-1;
    T st[100000];

    public:

    void push(T a)
    {
        st[++top]=a;

    }

    void pop()
    {
        if(top>=0)
            top--;
        else
            cout<<"No element remain"<<endl;
    }

    T TOP()
    {
        if(top>=0)
            return st[top];
        else
            cout<<"No element remain"<<endl;
    }

};

int main()
{

    int tmp;

    //declare demo;
    stck<double>stk;

    return 0;
}
