#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <stdexcept>

class HashTable
{
private:
    std::vector<std::list<std::pair<int, int>>> table;
    int sizeTable;

    int hashFunction(int key) const;

public:
    HashTable(int size);

    void insert(int key, int value);
    int find(int key) const;
    void remove(int key);
    bool contains(int key) const;
};

HashTable::HashTable(int size) : table(size), sizeTable(size) {}

void HashTable::insert(int key, int value)
{
    int index = hashFunction(key);
    for (auto &entry : table[index])
    {
        if (entry.first == key)
        {
            entry.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}

int HashTable::find(int key) const
{
    int index = hashFunction(key);
    for (const auto &entry : table[index])
    {
        if (entry.first == key)
        {
            return entry.second;
        }
    }
    throw std::runtime_error("Key not found");
}

void HashTable::remove(int key)
{
    int index = hashFunction(key);
    table[index].remove_if([key](const std::pair<int, int> &entry)
                             { return entry.first == key; });
}

int HashTable::hashFunction(int key) const
{
    return key % sizeTable;
}

bool HashTable::contains(int key) const
{
    int index = hashFunction(key);
    for (const auto &entry : table[index])
    {
        if (entry.first == key)
        {
            return true;
        }
    }
    return false;
}

#endif