/*
1.线程安全
2.代码简洁
*/

#include <iostream>
//#include <memory>
using namespace std;

class Singleton
{
public:
    static Singleton& getInstance();
    ~Singleton(){cout << "Destructing..." <<endl;}
private:
    Singleton(){cout << "Constructing..." <<endl;}
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
};

Singleton& Singleton::getInstance()
{
    static Singleton m_instance;//在多线程中，静态变量的初始化过程结束前，其它运行到该代码行的线程会被阻塞
    return m_instance;
}

int main()
{
    //Singleton s1;//‘Singleton::Singleton()’ is private
    Singleton & s2 = Singleton::getInstance();
    Singleton * s3 = &(Singleton::getInstance());
    //delete s3; //core dump:free(): invalid pointer: 0x00000000006021c8 ***
    Singleton & s4 = Singleton::getInstance();
    
    //unique_ptr<Singleton> s5 = (unique_ptr<Singleton>)(&(Singleton::getInstance()));//core_dump:free(): invalid pointer: 0x00000000006021c8 ***
    
    return 0;
}