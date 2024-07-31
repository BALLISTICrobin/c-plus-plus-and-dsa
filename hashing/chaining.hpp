#ifndef CHAINING_HPP
#define CHAINING_HPP
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "node.hpp"
using namespace std;

typedef long long ll;

bool isPrime(ll num);
ll nextPrime(ll num);

class chaining
{
    ll Hash1(string key) // djb2 hash function
    {
        char *str = (char *)key.c_str();
        unsigned long hash = 5381;
        int c;

        while ((c = *str++))
        {
            hash = ((hash << 5) + hash) + c;
        }

        return hash % N;
    }
    ll hash2(string key) // polynomial rolling hash function
    {
        ll hashVal = 0;

        for (ll i = 0; i < key.length(); i++)
            hashVal = 37 * hashVal + key[i];

        hashVal %= N;

        if (hashVal < 0)
            hashVal += N;

        return hashVal;
    }

public:
    ll N, size, collisions, probes, initialSize;
    vector<list<Node>> hashTable;
    ll hashFunction;
    ll numOfInsertion;
    ll chainLength;
    ll maxChainLength;
    ll numOfDeletetion;
    chaining(ll N, ll hashFunction, ll chainLength = 5)
    {
        this->N = nextPrime(N);
        initialSize = this->N;
        hashTable.resize(this->N);
        size = collisions = probes = numOfInsertion = numOfDeletetion= 0;
        this->hashFunction = hashFunction;
        this->chainLength = chainLength;
        this->maxChainLength = 0;
    }
    void insert(string key, ll value)
    {
        // findMaxChainlength();
        if (numOfInsertion > 100)
            reHash(1);
        ll i = hashFunction == 1 ? Hash1(key) : hash2(key);
        for (auto it : hashTable[i])
        {
            if (it.key == key)
            {
                it.value = value;
                return;
            }
        }
        if (hashTable[i].size() > 0)
        {
            collisions += hashTable[i].size();
            probes += hashTable[i].size();
        }
        else
        {
            probes++;
        }

        hashTable[i].push_back(Node(key, value));
        size++;
        numOfInsertion++;
    }

    void remove(string key)
    {
        if (numOfDeletetion > 100)
            reHash(2);
        ll i = hashFunction == 1 ? Hash1(key) : hash2(key);
        for (auto it : hashTable[i])
        {
            if (it.key == key)
            {
                hashTable[i].remove(it);
                size--;
                numOfDeletetion++;
                return;
            }
        }
    }

    ll find(string key)
    {
        ll i = hashFunction == 1 ? Hash1(key) : hash2(key);
        for (auto it : hashTable[i])
        {
            probes++;
            if (it.key == key)
                return it.value;
        }
        return -1;
    }

    void reHash(ll n)
    {
        // cout<<"rehashing"<<endl;
        ll oldN = N, oldCollisions = collisions;

        findMaxChainlength();
        if (n == 1)
        {
        //    cout<<numOfInsertion<<endl;
            numOfInsertion = 0;
            if (maxChainLength > chainLength)
            {
                N = nextPrime(N * 2);
                std::cout << "before rehashing from size: " << oldN << " to size: " << N << endl;
                std::cout << "avg probe count: " << (double)probes / size << " load factor: " << (double)size / N << " max chain length: " << maxChainLength<<endl;
            }
            else
            {
                return;
            }
        }
        else if (n == 2)
        {
            numOfDeletetion = 0;
            if (maxChainLength < 0.8 * chainLength)
            {
                N = nextPrime(N / 2);
                if (N < initialSize)
                {
                    return;
                }
                std::cout << "before rehashing from size: " << oldN << " to size: " << N << endl;
                std::cout << "avg probe count: " << (double)probes / size << "load factor: " << (double)size / N << " max chain length: " << maxChainLength <<endl;
                
            }
            else
            {
                return;
            }
        }

        vector<list<Node>> temp = hashTable;
        hashTable.clear();
        hashTable.resize(N);
        size = 0;
        collisions = 0;
        probes = 0;
        for (ll i = 0; i < oldN; i++)
        {
            for (auto it : temp[i])
            {
                insert(it.key, it.value);
                   numOfInsertion =0;
                
                
            }
        }
        findMaxChainlength();
        std::cout << "after rehashing from size: " << oldN << " to size: " << N << endl;
        std::cout<<"avg probe count: "<<(double)probes/size << " load factor: " << (double)size / N << " max chain length: " << maxChainLength <<endl;
    }

    void findMaxChainlength()
    {
        maxChainLength = 0;
        for (ll i = 0; i < N; i++)
        {
            // std::cout<<hashTable[i].size()<<" ";
            if (!hashTable[i].empty() && hashTable[i].size() > maxChainLength)
            {
                maxChainLength = hashTable[i].size();
            }
        }
    }

    // void print(){
    //     std::cout<<"table size: "<<N<<" total probing: "<<probes<<" size: "<<size<<" collisions: "<<collisions<<"maximum chain length: "<<maxChainLength<<endl;
    //     for(ll i=0; i<N; i++)
    //     {
    //         for(auto it:hashTable[i]){
    //             std::cout<<it.key<<":"<<it.value<<endl;
    //         }
    //     }
    // }
};

#endif