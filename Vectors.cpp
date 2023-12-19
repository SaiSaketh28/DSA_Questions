 // Vectors (same as array but has dynamic memory allocation)

// Vector has a dynamic memeory allocation: It means we can add elements (and also) remove elements from
// a defined vector. which is not possible in an array

//  Vector:Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
//  with their storage being handled automatically by the container.

// Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. 
// In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. 
// Removing the last element takes only constant time because no resizing happens. 
// Inserting and erasing at the beginning or in the middle is linear in time.

// Vectors can be accessed from standard template library.
// Intialization of Vector: Vector <Data Type> Name
// let v be name of a vector => 
//                                v.pushback(element) -- pushes the element to the vector from last
//                                v.popback() --- ------ this command removes the last element of vector 
//                                v.size[] ------------- gives the size of the vector

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    v={1,9,5,7,6,4};
    v.push_back(5);
     cout<<v;
}             
*/