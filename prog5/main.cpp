#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(long long unsigned int n)
{
    long long unsigned int i;
    if (n== 0) return false;
    for (i=2; i<=sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int countBitOne(long long unsigned int n)
{
    long long unsigned int i;
    int countOne = 0;
    for (i=0; i<64; i++) {
        if((n>>i)%2==1) countOne++;
    }
    return countOne;
}
int main(int argc, char **argv)
{
    long long unsigned int i;
    long long unsigned int maxNum = 0xFFFFFFFFFFFFFFFF;
    for(i=2; i<maxNum; i++) {
        if ((countBitOne(i) == 2) && (isPrime(i))) {
            cout<<"Десятичное число: "<<i<<"\tШестнадцатиричное число: "<<maxNum<<i<<endl;
        }
    }
    return 0;
}