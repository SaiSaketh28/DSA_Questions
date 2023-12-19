#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v = {1,2,3,4,5,6,7,8,9};
    cout<<v.size()<<endl;
    cout<<v.max_size()<<endl;
    cout<<v.capacity()<<endl;
    v.resize(5);
    v.reserve(6);
    cout<<v.size()<<endl;
    cout<<v.max_size()<<endl;
    cout<<v.capacity()<<endl;
    v.shrink_to_fit();
    return 0;

}