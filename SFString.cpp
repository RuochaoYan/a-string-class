//
//  SFString.cpp
//  class_test
//
//  STUDENT: Your job here is to implement the string class functionality in this file...
//
//

#include "SFString.hpp"
#include <iostream>
#include <cstring>

int memory = 0;
int SFString::maxMemory = 0;
/* ------- overload new and delete -------- */
void * operator new(size_t size)
{
    memory++;
    SFString::maxMemory = SFString::maxMemory > memory ? SFString::maxMemory : memory;
    void * p = malloc(size);
    return p;
}

void operator delete(void * p)
{
    memory--;
    free(p);
}

/* ------ constructor and destructor --------------- */
SFString::SFString(){
    size = 0;
    str = new char[1];
    str[0] = 0;
}
SFString::~SFString(){
    if(str != nullptr)
    delete[] str;
}

/* -------------- copy constructor ----------------- */
SFString::SFString(const SFString& aString){
    size = aString.size;
    str = new char[size+1];
    strcpy(str, aString.str);
}

/* -------------- convert constructor ----------------- */
SFString::SFString(const char* aString){
    if(!aString){
        str = new char[1];
        size = 0;
        str[0] = 0;
    }
    else{
        size = strlen(aString);
        str = new char[size+1];
        strcpy(str, aString);
    }
}


/* -------------- assignment operations ----------------- */
SFString&    SFString::operator=(const SFString& aString){
    if(this != &aString){
        if(str != nullptr)
            delete[] str; // avoid memory leak
        size = aString.size;
        str = new char[size+1];
        strcpy(str, aString.str);
    }
    return *this;
}
SFString&    SFString::operator=(const char* aString){
    if(this->str != aString){
        if(str != nullptr)
            delete[] str;
        size = strlen(aString);
        str = new char[size+1];
        strcpy(str, aString);
    }
    return *this;
}

/* -------------- cast operation ----------------- */
SFString::operator const char*() const{
    return str;
}

/* -------------- get operation ----------------- */
char         SFString::operator[](int pos) const{
    if(pos < 0 || pos >= strlen(str))
        throw 1;
    return str[pos];
}

/* -------------- concatenation operations ----------------- */
SFString&    SFString::operator+=(const SFString &aString){
    char* newStr;
    size_t newSize = size + aString.size;
    newStr = new char[newSize+1];
    strcpy(newStr, str);
    strcpy(newStr+size, aString.str);
    delete[] str;
    str = newStr;
    size = newSize;
    return *this;
}
SFString&    SFString::operator+=(const char* &aString){
    char* newStr;
    size_t newSize = size + strlen(aString);
    newStr = new char[newSize+1];
    strcpy(newStr, str);
    strcpy(newStr+size, aString);
    delete[] str;
    str = newStr;
    size = newSize;
    return *this;
}

/* -------------- relational operations ----------------- */
bool         SFString::operator<(const SFString &aString){
    return strcmp(str, aString.str) < 0;
}
bool         SFString::operator<(const char* &aString){
    return strcmp(str, aString) < 0;
}

bool         SFString::operator<=(const SFString &aString){
    return strcmp(str, aString.str) <= 0;
}
bool         SFString::operator<=(const char* &aString){
    return strcmp(str, aString) <= 0;
}

bool         SFString::operator>(const SFString &aString){
    return strcmp(str, aString.str) > 0;
}
bool         SFString::operator>(const char* &aString){
    return strcmp(str, aString) > 0;
}

bool         SFString::operator>=(const SFString &aString){
    return strcmp(str, aString.str) >= 0;
}
bool         SFString::operator>=(const char* &aString){
    return strcmp(str, aString) >= 0;
}

bool         SFString::operator==(const SFString &aString){
    if(size != aString.size)
        return false;
    if(strcmp(str, aString.str) == 0)
        return true;
    else
        return false;
}
bool         SFString::operator==(const char* &aString){
    if(size != strlen(aString))
        return false;
    if(strcmp(str, aString) == 0)
        return true;
    else
        return false;
}

bool         SFString::operator!=(const SFString &aString){
    return !(*this == aString);
}
bool         SFString::operator!=(const char* &aString){
    return !(*this == aString);
}

/* -------------- insert operations ----------------- */
SFString&    SFString::insert(size_t aPos, const SFString &aString){
    char* newStr;
    size += aString.size;
    newStr = new char[size + 1];
    strncpy(newStr, str, aPos);
    strncpy(newStr+aPos, aString.str, aString.size);
    strcpy(newStr+aPos+aString.size, str+aPos);
    delete[] str;
    str = newStr;
    return *this;
}
SFString&    SFString::insert(size_t aPos, const char* &aString){
    char* newStr;
    size_t anotherSize = strlen(aString);
    size += anotherSize;
    newStr = new char[size + 1];
    strncpy(newStr, str, aPos);
    strncpy(newStr+aPos, aString, anotherSize);
    strcpy(newStr+aPos+anotherSize, str+aPos);
    delete[] str;
    str = newStr;
    return *this;
}

SFString&    SFString::insert(size_t aPos, const char aChar){
    char* newStr;
    size++;
    newStr = new char[size + 1];
    strncpy(newStr, str, aPos);
    newStr[aPos] = aChar;
    strcpy(newStr+1, str+aPos);
    delete[] str;
    str = newStr;
    return *this;
}

/* -------------- erase operation ----------------- */
SFString&    SFString::erase(size_t aPos, size_t aLength){
    char* newStr;
    if(aPos + aLength > size){
        size = aPos;
        newStr = new char[aPos];
        strncpy(newStr, str, aPos);
        newStr[aPos] = 0;
    }
    else{
        size = size - aLength;
        newStr = new char[size + 1];
        strncpy(newStr, str, aPos);
        strcpy(newStr+aPos, str+aPos+aLength);
    }
    delete[] str;
    str = newStr;
    return *this;
}

/* -------------- replace operations ----------------- */
SFString&    SFString::replace(size_t pos, size_t len, const SFString &aString){
    char* newStr;
    size = size - len + aString.size;
    newStr = new char[size + 1];
    strncpy(newStr, str, pos);
    strncpy(newStr+pos, aString.str, aString.size);
    strcpy(newStr+pos+aString.size, str + pos + len);
    delete[] str;
    str = newStr;
    return *this;
}
SFString&    SFString::replace(size_t pos, size_t len, const char* &aString){
    char* newStr;
    size_t anotherSize = strlen(aString);
    size = size - len + anotherSize;
    newStr = new char[size + 1];
    strncpy(newStr, str, pos);
    strncpy(newStr+pos, aString, anotherSize);
    strcpy(newStr+pos+anotherSize, str + pos + len);
    delete[] str;
    str = newStr;
    return *this;
}

/* -------------- find operations ----------------- */
int          SFString::find(const SFString &aString, size_t offset){
    char* result = strstr(str+offset, aString.str);
    if(result){
        return (int)(result - str);
    }
    else{
        return -1;
    }
}
int          SFString::find(const char* &aString, size_t offset){
    char* result = strstr(str+offset, aString);
    if(result){
        return (int)(result - str);
    }
    else{
        return -1;
    }
}

/* -------------- Extra Credit ----------------- */
SFString operator+(const SFString& lhs, const SFString& rhs){
    SFString newSFStr(lhs);
    newSFStr += rhs;
    return newSFStr;
}
SFString operator+(const SFString& lhs, const char* rhs){
    SFString newSFStr(lhs);
    newSFStr += rhs;
    return newSFStr;
}
SFString operator+(const char* lhs, const SFString& rhs){
    SFString newSFStr(lhs);
    newSFStr += rhs;
    return newSFStr;
}
