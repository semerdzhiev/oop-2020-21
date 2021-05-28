#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
    bool state;

    void copy(bool state);

public:
    Engine();
    Engine(Engine const &other);
    Engine &operator=(Engine const &other);
    ~Engine();

    void start();
    void stop();

    bool getState() const { return this->state; }
};

#endif /* ifndef ENGINE_H */