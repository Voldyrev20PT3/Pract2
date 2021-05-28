#include <iostream>
#include <ctime>
#include <locale>

using namespace std;
int main(int argc, char **argv)
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    char buff[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format = "%c";
    strftime(buff,80,format,timeinfo);
    cout<<buff<<endl;
    return 0;
}
