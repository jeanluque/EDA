#include <iostream>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <tbb/tick_count.h>
#include <tbb/spin_mutex.h>
#include <tbb/tbb_thread.h>
#include <stdlib.h>
#include <time.h>
using namespace tbb;

class Pila
{
    spin_mutex B;
    spin_mutex BB;
    spin_mutex Ocupado;
    spin_mutex Liberador;
    int tamanio;
    int* pil;
    int indexx;
    public:
    Pila(int a)
    {
        tamanio=a;
        pil=new int[tamanio];
        indexx=-1;
        spin_mutex::scoped_lock lockC(Ocupado);
           
    }
    void push(int k)
    {
        spin_mutex::scoped_lock lock(B);
       
        if(indexx== tamanio)
        {
            spin_mutex::scoped_lock lockT(Liberador);
            std::cout<<"esperando a disponibilidad de espacio..."<<std::endl;
            sleep(1);
            spin_mutex::scoped_lock lockC(Ocupado);
            lockC.release();
        }
        std::cout<<"metiendo el dato: "<<k<<std::endl;
        sleep(1);
        indexx++;
        pil[indexx]=k;
    }
    void pop()
    {
        spin_mutex::scoped_lock lock(BB);
        if(indexx== -1)
        {
            spin_mutex::scoped_lock lockB(Ocupado);
            std::cout<<"esperando a tener algun dato que sacar..."<<std::endl;
            sleep(1);
            spin_mutex::scoped_lock lockC(Liberador);
            lockC.release();
        }
        std::cout<<"sacando el dato: "<<pil[indexx]<<std::endl;
        sleep(1);
        pil[indexx]=-99999;
        indexx--;
    }
  
};


class MeterPila
{
    int ap;
    Pila * A;
    public:
    void f(int k,Pila * X)
    {
        ap=k;
        A=X;
    }
    void operator()()
    {
        A->push(ap);
    }
};

class SacarPila
{  
    Pila * A;
    public:
    void f(Pila * X)
    {
        A=X;
    }
    void operator()()
    {
        A->pop();
    }
};

int main(int argc, char** argv)
{
    Pila Z(5);
    MeterPila A;
    MeterPila B;
    MeterPila C;
    MeterPila D;
    MeterPila E;
    MeterPila F;
    MeterPila G;
    A.f(5,&Z);
    B.f(6,&Z);
    C.f(10,&Z);
    D.f(15,&Z);
    E.f(7,&Z);
    F.f(9,&Z);
    G.f(3,&Z);
  
    SacarPila AA;
    SacarPila AB;
    SacarPila AC;
    SacarPila AD;
    SacarPila AE;
    SacarPila AF;
    AA.f(&Z);
    AB.f(&Z);
    AC.f(&Z);
    AD.f(&Z);
    AE.f(&Z);
    AF.f(&Z);
  
    tbb_thread m1(A);
    tbb_thread m2(B);
    tbb_thread m3(C);
    tbb_thread m4(D);
    tbb_thread m5(E);
    tbb_thread m6(F);
    tbb_thread m7(G);
    tbb_thread m8(AA);
    tbb_thread m9(AB);
    tbb_thread m10(AC);
    tbb_thread m11(AD);
    tbb_thread m12(AE);
    tbb_thread m13(AF);
  
    m1.join();
    m2.join();
    m3.join();
    m4.join();
    m5.join();
    m6.join();
    m7.join();
    m8.join();
    m9.join();
    m10.join();
    m11.join();
    m12.join();
    m13.join();
    return 0;
  
}
