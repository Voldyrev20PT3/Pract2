#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;
bool TrialDivision(uint64_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}
uint64_t genPrime(unsigned int n, bool isPrime(uint64_t), unsigned int c)
{
    uint64_t min = 1ULL<<(n-3);
    uint64_t max = (min << 2) + 2;
    uint64_t r;
    mt19937_64 gen(clock());
    uniform_int_distribution<uint64_t> rnd(min,max);
    for (int i=0; i<c; i++) {
        auto start = high_resolution_clock::now();
        do {
            r = rnd(gen);
            cout<<i+1<<") число:"<<r<<"\t";
        } while (isPrime(r));
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end-start);
        cout<<"Время генерации: "<<duration.count()<<"миллисекунд"<<endl;
    }
    return r;
}
int main(int argc, char **argv)
{
    genPrime(1,TrialDivision,3);
    return 0;
}