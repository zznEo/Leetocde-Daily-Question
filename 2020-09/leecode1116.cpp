#include <bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;
class ZeroEvenOdd {
private:
    int n;
    int j, o;
    mutex mutex1, mutex2, mutex0;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->j = 1;
        this->o = 2;
        mutex1.lock();
        mutex1.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1;i <= n;i++){
            mutex0.lock();
            printNumber(0);
            if(i & 1)
                mutex1.unlock();
            else 
                mutex2.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2;i <= n;i += 2){
            mutex2.lock();
            printNumber(i);
            mutex0.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
         for(int i = 1;i <= n;i += 2){
            mutex1.lock();
            printNumber(i);
            mutex0.unlock();
        }
    }
};

void test() {
    thread t1(&ZeroEvenOdd::zero);
    thread t2(&ZeroEvenOdd::even);
    thread t3(&ZeroEvenOdd::odd);

    t1.join();
    t2.join();
    t3.join();
}

int main(){
    test();
    system("pause");
    return 0;
}