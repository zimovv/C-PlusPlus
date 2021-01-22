#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
    static shared_ptr<Singleton> getInstance();
    ~Singleton(){cout << "Destructing..." <<endl;}

private:
    Singleton(){cout << "Contructing..." << endl;}
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

    static shared_ptr<Singleton> m_instance;
    static mutex m_mutex;
};
shared_ptr<Singleton> Singleton::m_instance = nullptr;
mutex Singleton::m_mutex; //how to initialize it ?

shared_ptr<Singleton> Singleton::getInstance()
{
    if(m_instance == nullptr)
    {
        lock_guard<mutex> lk(m_mutex); //avoid lock even if m_intance is not null
        if(m_instance == nullptr){  //avoid competition among threads
            m_instance = shared_ptr<Singleton>(new Singleton());
        }//unlock automatically
    }
    return m_instance;
}

class DerivedS : public Singleton
{
public:
    //Singleton * m_instance_d = new Singleton();//‘Singleton::Singleton()’ is private
};

void doSomething()
{
    shared_ptr<Singleton> s = Singleton::getInstance();
}

int main()
{
    //shared_ptr<Singleton> s1 = Singleton::getInstance();
    //shared_ptr<Singleton> s2 = Singleton::getInstance();

    //test if any way can create another instance
    //Singleton s3; //‘Singleton::Singleton()’ is private
    //Singleton s4(*s1); //‘Singleton::Singleton(const Singleton&)’ is private
    //Singleton *s5=nullptr;
    //*s5 = *s2;//‘Singleton& Singleton::operator=(const Singleton&)’ is private

    //DerivedS d; // not neccessary to create DerivedS object
    
    thread t1(doSomething);
    thread t2(doSomething);
    t1.join();
    t2.join();

    return 0;
}