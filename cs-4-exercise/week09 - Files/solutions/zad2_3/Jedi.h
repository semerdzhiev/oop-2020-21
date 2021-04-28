#pragma once
class Jedi
{
    static int s_version;

    size_t m_skills_capacity;
    size_t m_skills_count;
    char** m_skills;
    int m_age;

    void resizeSkills();

    void copy(const Jedi& other);
    void erase();
public:
    Jedi();
    Jedi(const Jedi& other);
    Jedi& operator=(const Jedi& other);
    ~Jedi();

    void addSkill(const char* skill);

    void write(const char* filename) const;
    void read(const char* filename);
};

