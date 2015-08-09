#pragma once
#include <iostream>

class DynamicString
{
    char* pData;

    void copy(const DynamicString&);
    void copy(const char*);
    void copy(const char);
    void destroy();

public:
    DynamicString();
    DynamicString(const DynamicString&);
    DynamicString(const char*);
    DynamicString(const char);
    DynamicString& operator=(const DynamicString&);
    DynamicString& operator=(const char*);
    DynamicString& operator=(const char);
    ~DynamicString();
    char* GetString()const;

    size_t size() const;
    char& operator[](size_t);

    friend bool operator==(const DynamicString&, const DynamicString&);
    friend bool operator==(const DynamicString&, const char*);
	friend bool operator==(const DynamicString&, const char);
    friend bool operator!=(const DynamicString&, const DynamicString&);
    friend bool operator!=(const DynamicString&, const char*);
	friend bool operator!=(const DynamicString&, const char);

    friend std::ostream& operator<<(std::ostream&, const DynamicString&);
    friend std::istream& operator>>(std::istream&, DynamicString&);
    friend std::istream& getline(std::istream&, DynamicString&);
};
