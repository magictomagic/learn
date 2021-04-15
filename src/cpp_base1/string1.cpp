#include<iostream>
#include<string.h>
// using namespace std;
class MyStr{
    public:
    MyStr(const char * m_ptr);
    MyStr(const MyStr& m_ptr);
    MyStr& operator=(const MyStr& m_ptr);
    // MyStr& operator<<(const MyStr& m_ptr);
    friend std::ostream & operator<<(std::ostream & output, const MyStr& m_ptr);

    ~MyStr();
    private:
    int m_len;
    char *m_data;

};

MyStr::MyStr(const char * m_ptr){
    if(m_ptr == nullptr){
        m_data = new char[1];
        m_data[0] = '\0';
        m_len = 0;
    }else{
        m_len = strlen(m_ptr);
        m_data = new char[m_len + 1];
        strcpy(m_data, m_ptr);
    }
}

MyStr::MyStr(const MyStr& m_ptr){
    m_len = m_ptr.m_len;
    m_data = new char[m_len + 1];
    strcpy(m_data, m_ptr.m_data);
}

MyStr& MyStr::operator=(const MyStr& m_ptr){
    if(this == &m_ptr){
        return *this;
    }
    m_len = strlen(m_ptr.m_data);
    delete[] m_data;
    m_data = new char[m_len];
    strcpy(m_data, m_ptr.m_data);
}

std::ostream & operator<<(std::ostream & output, const MyStr& m_ptr){
    output << m_ptr.m_data;
    return output;
}


MyStr::~MyStr(){
    delete[] m_data;
}


int main(){
    MyStr demo1 = "dasfads";
    auto demo2 = MyStr("fdasf");
    MyStr demo3(demo1);
    MyStr demo4 = demo1;
    std::cout<<demo1<<std::endl<<demo2<<std::endl<<demo3<<std::endl<<demo4;
}