#include <iostream>
#include<cstring>
using std::cout;
using std::endl;

class String {
private:
    char* m_Data;
    int m_Size;
public:
    String(): m_Data(nullptr),m_Size(0) {}
    String(const char* string) {
        cout<<"Created\n";
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        strcpy(m_Data,string);
    }
    String(const String& other) {
        cout<<"Copied\n";
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        strcpy(m_Data,other.m_Data);
    }
    String(String&& other) noexcept {
        cout<<"Moved constructor\n";
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        //You're stealing the data
        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    String& operator=(String&& other) noexcept {
        cout << "Moved\n";
        if(this != &other) {
            delete m_Data;
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            //You're stealing the data
            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        return *this;
    }
    String& operator=(const String& other) {
        std::cout<<"operator=\n";
        if(this != &other) {
            delete m_Data;
            m_Size=other.m_Size;
            m_Data = new char[m_Size];
            strcpy(m_Data,other.m_Data);
        }
        return *this;
    }
    ~String() {
        cout<<"Destroyed\n";
        delete m_Data;
    }
    void print() {
        if(m_Size!=0)
            cout<<m_Data<<endl;
    }
};

class Entity {
    String m_Name;
public:
    //explicit Entity(const String& name) : m_Name(name) {/*std::cout<<"const String& constructor\n";*/}
    explicit Entity(String  name) : m_Name(std::move(name)) {/*std::cout<<"String name constructor with std::move\n";*/}
    //explicit Entity(String&& name) : m_Name(std::move(name)) {/*std::cout<<"rvalue constructor\n";*/}
    void printName() {
        m_Name.print();
    }
};

int main() {
    Entity entity(String("Petko"));
    entity.printName();
    String name("Ivana");
    Entity entity2(name);
    Entity entity1 = entity;
    Entity entity3(String("Ivana"));
    cout<<"---------------------------------\n";
    cout<<"String example\n";
    String string("Hello world!");//same af Sting string("...")
    String dest2(string);
    String dest(std::move(string));
    String dest3(std::move(String("dest2")));
    dest.print();

    //Move assigment operator
    cout<<"\nMove assigment operator\n";
    String orange("Orange");
    String dest1;
    cout<<"Orange:";
    orange.print();
    cout<<"Dest1:\n";
    dest1.print();
    dest1 = String("dad");
    dest1 = std::move(orange);
    cout<<"Orange:\n";
    orange.print();
    cout<<"Dest1:";
    dest1.print();
    String apple = "apple", name1="Petko";
    apple = "b";
    apple = name1;
    return 0;
}
