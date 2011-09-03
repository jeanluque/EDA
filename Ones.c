#include <iostream>
#include <stdlib.h>


using namespace std;

int countDigit (int n){
    int s = 0;
    while (n > 0){
        n = n / 10;
        s++;
    }
    return s;
}

int ones (int n){
    if (n%2 == 0 || n%5 ==0 || n < 0 ) return 0;
    int o = 1;
    int size = countDigit(n);
    for (int i = 0; i < size;++i)
        o = o*10 + 1;
    int cont = size + 1;
    while (o%n != 0){
        o = (o%n) * 10 + 1;
        cont++;
    }
    return cont;
}

int main()
{
    int p;
    while(cin>>p)
    cout << ones (p)<< endl;

    return 0;
}
