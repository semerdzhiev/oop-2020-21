#include "Jedi.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

char* dyncopy_str(const char* skill)
{
    size_t length = strlen(skill);
    char* new_str = new (nothrow) char[length + 1];
    assert(new_str);
    strcpy_s(new_str, length + 1, skill);
    return new_str;
}

int Jedi::s_version = 1;

void Jedi::resizeSkills()
{
    m_skills_capacity *= 2;

    char** new_skills = new (nothrow) char* [m_skills_capacity];
    assert(new_skills);

    for (size_t i = 0; i < m_skills_count; ++i)
    {
        new_skills[i] = m_skills[i];
    }

    delete[] m_skills;
    m_skills = new_skills;
}

void Jedi::copy(const Jedi& other)
{
    m_skills_count = other.m_skills_count;
    m_skills_capacity = other.m_skills_capacity;
    assert(m_skills_count < m_skills_capacity); // we can skip this because we now the class handles the dyn array correctly

    m_skills = new (nothrow) char* [m_skills_capacity];
    assert(m_skills);

    for (size_t i = 0; i < m_skills_count; ++i)
    {
        m_skills[i] = dyncopy_str(other.m_skills[i]);
    }

    m_age = other.m_age;
}

void Jedi::erase()
{
    for (size_t i = 0; i < m_skills_count; ++i)
    {
        delete[] m_skills[i];
    }
    delete[] m_skills;
}

Jedi::Jedi() :
    m_skills_capacity(1),
    m_skills_count(0),
    m_skills(new char* [m_skills_capacity]),
    m_age(0)
{}

Jedi::Jedi(const Jedi& other)
{
    copy(other);
}

Jedi& Jedi::operator=(const Jedi& other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }

    return *this;
}

Jedi::~Jedi()
{
    erase();
}

void Jedi::addSkill(const char* skill)
{
    if (m_skills_count >= m_skills_capacity)
    {
        resizeSkills();
    }

    m_skills[m_skills_count++] = dyncopy_str(skill);
}

void Jedi::write(const char* filename) const
{
    ofstream file(filename);
    if (file.is_open())
    {
        file << s_version << " " << m_skills_count << " " << m_skills_capacity << " " << m_age << "\n";

        for (size_t i = 0; i < m_skills_count; ++i)
        {
            file << strlen(m_skills[i]) << " " << m_skills[i] << endl;
        }

        file.close();
    }
}

void Jedi::read(const char* filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        erase();
        file >> s_version >> m_skills_count >> m_skills_capacity;

        if (s_version >= 1)
        {
            file >> m_age;
        }
        else
        {
            m_age = 0;
        }

        m_skills = new (nothrow) char* [m_skills_capacity];
        assert(m_skills);

        for (size_t i = 0; i < m_skills_count; ++i)
        {
            size_t skill_length = 0;
            file >> skill_length;

            char* skill = new (nothrow) char[skill_length + 1];
            assert(skill);

            // Read the empty space between the length of this skill and the skill itself
            // You can do this either like this:
            //char c;
            //file >> noskipws >> c >> skipws;
            // Or:
            file.get(); // homework: research put() and get() methods of streams

            file.getline(skill, skill_length + 1);
            m_skills[i] = skill;
        }
        file.close();
    }
}