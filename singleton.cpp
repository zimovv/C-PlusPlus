#include <iostream>
#include <memory>
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
};
shared_ptr<Singleton> Singleton::m_instance = nullptr;

shared_ptr<Singleton> Singleton::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = shared_ptr<Singleton>(new Singleton());
    }
    return m_instance;
}

class DerivedS : public Singleton
{
public:
    //Singleton * m_instance_d = new Singleton();//‘Singleton::Singleton()’ is private
};

int main()
{
    shared_ptr<Singleton> s1 = Singleton::getInstance();
    shared_ptr<Singleton> s2 = Singleton::getInstance();

    //test if any way can create another instance
    //Singleton s3; //‘Singleton::Singleton()’ is private
    //Singleton s4(*s1); //‘Singleton::Singleton(const Singleton&)’ is private
    //Singleton *s5=nullptr;
    //*s5 = *s2;//‘Singleton& Singleton::operator=(const Singleton&)’ is private

    //DerivedS d; // not neccessary to create DerivedS object

    return 0;
}