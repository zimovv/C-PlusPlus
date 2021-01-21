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

int main()
{
    Singleton * s1 = Singleton::getInstance();
    Singleton * s2 = Singleton::getInstance();
    return 0;
}