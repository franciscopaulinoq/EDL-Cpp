#include <iostream>
#include <list>
#include <set>
#include "HashTable.h"

using namespace std;

set<pair<int, int>> findPairsWithSum(int target, const list<int> &intList)
{
    set<pair<int, int>> result;
    HashTable hashTable(intList.size());

    for (int num : intList)
    {
        int complement = target - num;
        if (hashTable.contains(complement))
        {
            result.insert({min(num, complement), max(num, complement)});
        }
        hashTable.insert(num, num);
    }

    return result;
}

int main()
{
    int target = 8;
    list<int> intList = {1, 2, 3, 4, 5, 6, 7, 4, 5, 9, -1};

    set<pair<int, int>> pairs = findPairsWithSum(target, intList);

    cout << "Pares que somam " << target << ":\n";
    for (const auto &p : pairs)
    {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}