//
//  SFString.hpp
//  class_test
//
//  STUDENTS: This interface is incomplete; refer to the assignment readme for detailed instructions!
//

#ifndef SFString_hpp
#define SFString_hpp

#include <string>

class SFString {
public:
  
  SFString();
  SFString(const SFString& aString);
  
  SFString&    operator=(const SFString& aString);
  
  operator const char*() const;
  
  char         operator[](int pos) const;

  SFString&    operator+=(const SFString &aString);
  
  bool         operator<(const SFString &aString);
  bool         operator<=(const SFString &aString);
  bool         operator>(const SFString &aString);
  bool         operator>=(const SFString &aString);
  bool         operator==(const SFString &aString);
  bool         operator!=(const SFString &aString);
  
  SFString&    insert(size_t aPos, const SFString &aString);
  SFString&    insert(size_t aPos, const char aChar);
  
  SFString&    erase(size_t aPos, size_t aLength);

  SFString&    replace(size_t pos, size_t len, const SFString &aString);
  
  int          find(const SFString &aString, size_t offset=0);
  
};

#endif /* SFString_hpp */

