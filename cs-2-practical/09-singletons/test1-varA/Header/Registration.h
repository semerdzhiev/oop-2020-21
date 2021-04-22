#pragma once

class Registration {
    char reg[9];

private:
    bool isValid(const char *str);

public:
    explicit Registration(const char *str);

    Registration &operator=(const char *str);

    bool operator==(const char *str) const;

    const char* toString() const;
};
