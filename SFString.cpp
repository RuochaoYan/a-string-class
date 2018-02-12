//
//  SFString.cpp
//  class_test
//
//  STUDENT: Your job here is to implement the string class functionality in this file...
//
//

#include "SFString.hpp"
#include <iostream>
SFString::SFString(){
    str = new char[1];
    *str = '\0';
}
SFString::~SFString(){
    if(str != nullptr)
        delete[] str;
}
/* -------------- copy constructor ----------------- */
SFString::SFString(const SFString& aString){
    str = new char[strlen(aString.str)+1];
    strcpy(str, aString.str);
}

/* -------------- convert constructor ----------------- */
SFString::SFString(const char* aString){
    if(!aString){
        str = new char[1];
        *str = '\0';
    }
    else{
        str = new char[strlen(aString)+1];
        strcpy(str, aString);
    }
}

/* -------------- assignment operations ----------------- */
SFString&    SFString::operator=(const SFString& aString){
    if(this != &aString){
        if(str != nullptr)
            delete[] str; // avoid memory leak
        str = new char[strlen(aString.str)+1];
        strcpy(str, aString.str);
    }
    return *this;
}
SFString&    SFString::operator=(const char* aString){
    if(this->str != aString){
        if(str != nullptr)
            delete[] str;
        str = new char[strlen(aString)+1];
        strcpy(str, aString);
    }
    return *this;
}

/* -------------- cast operation ----------------- */
SFString::operator const char*() const{
    return this->str;
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
    newStr = new char[strlen(str)+strlen(aString.str)+1];
    strcpy(newStr, str);
    delete[] str;
    strcat(newStr, aString.str);
    str = newStr;
    return *this;
}
SFString&    SFString::operator+=(const char* &aString){
    char* newStr;
    newStr = new char[strlen(str)+strlen(aString)+1];
    strcpy(newStr, str);
    delete[] str;
    strcat(newStr, aString);
    str = newStr;
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
    if(strlen(str) != strlen(aString.str))
        return false;
    if(strcmp(str, aString.str) == 0)
        return true;
    else
        return false;
}
bool         SFString::operator==(const char* &aString){
    if(strlen(str) != strlen(aString))
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
    newStr = new char[strlen(str) + strlen(aString.str) + 1];
    strncpy(newStr, str, aPos);
    strcat(newStr, aString.str);
    strcat(newStr, str+aPos);
    delete[] str;
    str = newStr;
    return *this;
}
SFString&    SFString::insert(size_t aPos, const char* &aString){
    char* newStr;
    newStr = new char[strlen(str) + strlen(aString) + 1];
    strncpy(newStr, str, aPos);
    strcat(newStr, aString);
    strcat(newStr, str+aPos);
    delete[] str;
    str = newStr;
    return *this;
}

SFString&    SFString::insert(size_t aPos, const char aChar){
    char* newStr;
    newStr = new char[strlen(str) + 2];
    strncpy(newStr, str, aPos);
    newStr[aPos] = aChar;
    strcat(newStr, str+aPos);
    delete[] str;
    str = newStr;
    return *this;
}

/* -------------- erase operation ----------------- */
SFString&    SFString::erase(size_t aPos, size_t aLength){
    char* newStr;
    if(aPos + aLength > strlen(str)){
        newStr = new char[strlen(str) + 1];
        strncpy(newStr, str, aPos);
        newStr[aPos] = '\0';
    }
    else{
        newStr = new char[strlen(str) - aLength + 1];
        strncpy(newStr, str, aPos);
        strcat(newStr, str+aPos+aLength);
    }
    delete[] str;
    str = newStr;
    return *this;
}

/* -------------- replace operations ----------------- */
SFString&    SFString::replace(size_t pos, size_t len, const SFString &aString){
    char* newStr;
    newStr = new char[strlen(str) - len + strlen(aString.str) + 1];
    strncpy(newStr, str, pos);
    strcat(newStr, aString.str);
    strcat(newStr, str + pos + len);
    delete[] str;
    str = newStr;
    return *this;
}
SFString&    SFString::replace(size_t pos, size_t len, const char* &aString){
    char* newStr;
    newStr = new char[strlen(str) - len + strlen(aString) + 1];
    strncpy(newStr, str, pos);
    strcat(newStr, aString);
    strcat(newStr, str + pos + len);
    delete[] str;
    str = newStr;
    return *this;
}

/* -------------- find operations ----------------- */
int          SFString::find(const SFString &aString, size_t offset){
    char* temp;
    temp = new char[strlen(str) - offset + 1];
    strcpy(temp, str + offset);
    char* result = strstr(temp, aString.str);
    size_t position = -1;
    if(result){
        position = result - temp;
    }
    delete[] temp;
    return (int)(position + offset);
}
int          SFString::find(const char* &aString, size_t offset){
    char* temp;
    temp = new char[strlen(str) - offset + 1];
    strcpy(temp, str + offset);
    char* result = strstr(temp, aString);
    size_t position = -1;
    if(result){
        position = result - temp;
    }
    delete[] temp;
    return (int)(position + offset);
}

/* -------------- Extra Credit ----------------- */
SFString operator+(const SFString& lhs, const SFString& rhs){
    SFString newSFStr;
    newSFStr.str = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(newSFStr.str, lhs.str);
    strcat(newSFStr.str, rhs.str);
    return newSFStr;
}
SFString operator+(const SFString& lhs, const char* rhs){
    SFString newSFStr;
    newSFStr.str = new char[strlen(lhs.str) + strlen(rhs) + 1];
    strcpy(newSFStr.str, lhs.str);
    strcat(newSFStr.str, rhs);
    return newSFStr;
}
SFString operator+(const char* lhs, const SFString& rhs){
    SFString newSFStr;
    newSFStr.str = new char[strlen(lhs) + strlen(rhs.str) + 1];
    strcpy(newSFStr.str, lhs);
    strcat(newSFStr.str, rhs.str);
    return newSFStr;
}
