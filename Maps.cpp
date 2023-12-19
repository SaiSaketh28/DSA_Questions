#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>name_of_map;
    name_of_map.insert({1,"abc"});
    name_of_map.insert({0,"def"});
    for(auto it= name_of_map.begin(); it != name_of_map.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    auto it = name_of_map.find(0);
    cout<<(*it).first<<" "<<(*it).second;
    return 0;
}
// Map store the values in a pair key and value map<key,value>name_of_the_map, map sorts the key in their increasing order 
// if the key is a string it orders the key in lexographical manner (Dictioonary order)
// Maps has three types 1. map  2.unordered map  3.multimap.
// In unordered map the key value are stored in unordered manner. 
// Map only take unique value of key if same key with another value is inserted it overwrities the past value.