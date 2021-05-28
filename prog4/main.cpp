#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;
bool TrialDivision(uint32_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint32_t i = 3; i <= (uint32_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}
void genPrime(unsigned int n, bool isPrime(uint32_t), unsigned int c)
{
    uint32_t min = 1ULL<<(n-3);
    uint32_t max = (min << 2) + 2;
    uint32_t r;
    vector<uint32_t> vect;
    vect.reserve(c);
    mt19937 gen(clock());
    uniform_int_distribution<uint32_t> rnd(min,max);
    for (int i=0; i<c; i++) {
        auto start = high_resolution_clock::now();
        do {
            r = rnd(gen);
            vect.push_back(r);

        } while (isPrime(r));
        cout<<i+1<<") число:"<<r<<"\t";
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end-start);
        cout<<"Время генерации: "<<duration.count()<<"миллисекунд"<<endl;
    }
    sort (vect.begin(), vect.end(), greater<uint32_t>());
    cout<<"Минимальное число:"<<vect[vect.size()-1]<<endl;
    cout<<"Максимальное число:"<<vect[0]<<endl;
}
int main(int argc, char **argv)
{
    genPrime(10,TrialDivision,3);
    return 0;
}