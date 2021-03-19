/**
 * \brief Helper functions
 * \author D. Zhekov
 */
#ifndef helpers
#define helpers

//! Gets string length
int strlen(const char *text)
{
    int len = 0;
    while (text[len])
    {
        ++len;
    }
    return len;
}

//! Copies string
void strcpy(char *dest, const char *src)
{
    int pos = 0;
    while (src[pos])
    {
        dest[pos] = src[pos];
        ++pos;
    }
    dest[pos] = '\0';
}

//! Compare strings
int strcmp(const char *text1, const char *text2)
{
    while (*text1 && *text1 == *text2)
    {
        ++text1;
        ++text2;
    }
    return *text1 - *text2;
}

#endif