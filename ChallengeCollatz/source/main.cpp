#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const int MAX = 1000000;
vector<int> memo(MAX, 0);

long long normalFunc(long long num)
{
    if (num == 1)
    {
        return 1;
    }

    if (num % 2 == 0)
    {
        return 1 + normalFunc(num / 2);
    }
    else
    {
        return 1 + normalFunc((num * 3) + 1);
    }
}

long long efficientFunc(long long num)
{
    if (num == 1)
        return 1;

    if (num < MAX && memo[num] != 0)
        return memo[num];

    int steps = 1;
    if (num % 2 == 0)
        steps += efficientFunc(num / 2);
    else
        steps += efficientFunc((num * 3) + 1);

    if (num < MAX)
        memo[num] = steps;

    return steps;
}

int main()
{
    auto inicio = chrono::high_resolution_clock::now();
    long long currentSize = 0;
    long long maxSize = 0;
    long long maxNum = 0;
    for (long long i = 1; i < 1000000; i++)
    {
        currentSize = normalFunc(i);
        if (maxNum == 0)
        {
            maxNum = i;
        }
        else
        {
            if (currentSize > maxSize)
            {
                maxSize = currentSize;
                maxNum = i;
            }
        }
    }
    auto fim = chrono::high_resolution_clock::now();

    cout << "Solucao 1:" << endl;

    cout << "Inteiro com maxNum sequencia: " << maxNum << endl;
    cout << "maxNum sequencia: " << maxSize << endl;

    long long miliseconds = chrono::duration_cast<chrono::milliseconds>(fim - inicio).count();
    cout << "Tempo de execucao: " << miliseconds << " ms" << endl;

    cout << endl;

    inicio = chrono::high_resolution_clock::now();
    currentSize = 0;
    maxSize = 0;
    maxNum = 0;
    for (long long i = 1; i < 1000000; i++)
    {
        currentSize = efficientFunc(i);
        if (maxNum == 0)
        {
            maxNum = i;
        }
        else
        {
            if (currentSize > maxSize)
            {
                maxSize = currentSize;
                maxNum = i;
            }
        }
    }
    fim = chrono::high_resolution_clock::now();

    cout << "Solucao 2 (eficiente):" << endl;

    cout << "Inteiro com maxNum sequencia: " << maxNum << endl;
    cout << "maxNum sequencia: " << maxSize << endl;

    miliseconds = chrono::duration_cast<chrono::milliseconds>(fim - inicio).count();
    cout << "Tempo de execucao: " << miliseconds << " ms" << endl;

    cout << endl;

    return 0;
}