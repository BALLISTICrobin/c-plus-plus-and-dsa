#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    string key;
    long long value;

    Node(string key = "", long long value = -1)
    {
        this->key = key;
        this->value = value;
    }
    // operator overloading

    bool operator==(const Node &other) const
    {
        return key == other.key;
    }
    bool operator!=(const Node &other) const
    {
        return key != other.key;
    }
};

#endif