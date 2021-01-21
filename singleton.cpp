#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton * getInstance();
    ~Singleton(){cout << "Destructing..." <<endl;}

private:
    Singleton(){cout << "Contructing..." << endl;}
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

    static Singleton * m_instance;
};
Singleton * Singleton::m_instance = nullptr;

Singleton * Singleton::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Singleton();
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
    Singleton * s1 = Singleton::getInstance();
    Singleton * s2 = Singleton::getInstance();

    //test if any way can create another instance
    //Singleton s3; //‘Singleton::Singleton()’ is private
    //Singleton s4(*s1); //‘Singleton::Singleton(const Singleton&)’ is private
    //Singleton *s5=nullptr;
    //*s5 = *s2;//‘Singleton& Singleton::operator=(const Singleton&)’ is private

    //DerivedS d; // not neccessary to create DerivedS object

    delete s1;
    //delete s2; //double free
    return 0;
}