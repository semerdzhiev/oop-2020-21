#include <iostream>
#include <memory>

struct Entity {
    explicit Entity(int a=0) : a(a) { std::cout << "Entity constructed!\n"; }

    Entity(const Entity& other) : a(other.a), ptr(other.ptr){
        std::cout<<"Copy constructor a="<<a<<'\n';
    }

    ~Entity() { std::cout << "Entity destructed="<<a<<std::endl; }

    void print() const { std::cout << "I'm entity with a="<<a<<'\n'; }
    std::shared_ptr<Entity> ptr;
    void test() {
        ptr = std::make_shared<Entity>(*this);
    }
private:
    int a = 0;
};

template<class T>
class MySmartPointer {
private:
    T *ptr = nullptr;
public:
    MySmartPointer() = default;

    explicit MySmartPointer(T *ptr) : ptr(ptr) {}

    MySmartPointer(const MySmartPointer& other) = delete;
    MySmartPointer& operator=(const MySmartPointer& other) = delete;
    ~MySmartPointer() {
        clean();
    }
    MySmartPointer(MySmartPointer<T>&& other)  noexcept {
        this->ptr = other.ptr;
        other.ptr = nullptr;
    }

    MySmartPointer<T>& operator=(MySmartPointer<T>&& other) noexcept {
        clean();
        this->ptr = other.ptr;
        other.ptr = nullptr;
    }

    T* operator->() {
        return ptr;
    }

    T& operator*() {
        return *(ptr);
    }

private:
    void clean() {
        delete ptr;
    }
};

int main() {
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(6);
        //std::unique_ptr<Entity> entity1 = entity;// Cannot copy
        entity->print();
    }

    {
        std::shared_ptr<Entity> entity1;
        //std::weak_ptr<Entity> entity1;
        {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>(45);
            entity1 = entity;
        }
        entity1->print();
    }
    MySmartPointer<Entity> ptr(new Entity(2));
    ptr->print();
    Entity e(9);
//    e.ptr = std::make_shared<Entity>(88);
//    e.ptr->print();
    e.test();
    return 0;
}
