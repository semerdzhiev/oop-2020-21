#include <iostream>
#include <memory>

struct Entity {
    explicit Entity(int a=0) : a(a) { std::cout << "Entity constructed!\n"; }

    ~Entity() { std::cout << "Entity destructed\n"; }

    void print() const { std::cout << "I'm entity with a="<<a<<'\n'; }

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
        if(ptr!= nullptr) delete ptr;
    }
};

int main() {
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(6);
        //std::unique_ptr<Entity> entity1 = entity; Cannot copy
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

    return 0;
}
