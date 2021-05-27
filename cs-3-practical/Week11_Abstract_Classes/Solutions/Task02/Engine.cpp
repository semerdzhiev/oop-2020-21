#include <iostream>

#include "Engine.h"

void Engine::copy(bool state)
{
    this->state = state;
}

Engine::Engine()
{
    state = false;
}

Engine::Engine(Engine const &other)
{
    this->copy(other.state);
}

Engine &Engine::operator=(Engine const &other)
{
    if (this != &other)
    {
        this->copy(other.state);
    }

    return *this;
}

Engine::~Engine()
{
}

void Engine::start()
{
    state= true;

    std::cout << "Starting engine" << std::endl;
}

void Engine::stop()
{
    state = false;

    std::cout << "Stopping engine" << std::endl;
}