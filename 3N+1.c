#include <iostream>
#include <vector>


using namespace std;

int problem (int n){
    int cont=1;
    while (n!=1){
        if(n%2==0)
        {
            n=n/2;
            cont++;
        }
        else
        {
          n=n*3+1;
          cont++;
        }
    }
    return cont;
}


int contTotal(int a, int b)
{
    if(a>b)
    {
        int c;
        c=a;
        a=b;
        b=c;
    }
    int cont=0;
    int p;
    for (int i=a;i<=b; i++)
    {
        p=problem(i);
        if(p>cont)
            cont=p;
    }
    return cont;
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<a<<' '<<b<<' '<<contTotal(a,b)<<endl;
    }
        return 0;
}
