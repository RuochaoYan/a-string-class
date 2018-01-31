//
//  SFStringTester.cpp
//  class_test
//
//  Created by rick gessner on 1/29/18.
//  Copyright © 2018 rick gessner. All rights reserved.
//

#include "SFStringTester.hpp"
#include "SFString.hpp"
#include <string>
#include <iostream>

//compare results and return error status (side-effect output to terminal)...
int compare(const SFString& str1, const std::string &str2, const char* aMessage) {
  const char* s1=str1;
  const char* s2=str2.c_str();
  if(strcmp(s1,s2)) {
    std::cout << aMessage << std::endl;
    return 1;
  }
  return 0;
}

//compare int results and return error status (side-effect output to terminal)...
int compare(int anArg1, int anArg2,const char* aMessage) {
  if(anArg1!=anArg2) {
    std::cout << aMessage << std::endl;
    return 1;
  }
  return 0;
}

//compare construction operations against std::string...
int runConstructionTests() {
  int theResult=0;
  SFString sf1;
  std::string s1;
  theResult+=compare(sf1,s1,"dflt ctor() error");
  
  const char* theStr="constructor string";
  SFString sf2(theStr);
  std::string s2(theStr);
  theResult+=compare(sf2,s2,"ctor(const char*) error");
  
  SFString sf3(sf2);
  std::string s3(s2);
  theResult+=compare(sf3,s3,"ctor(const SFString&) error");
  
  return theResult;
}

//compare assignment operations against std::string...
int runAssignmentTests() {
  int theResult=0;
  
  const char* theStr="assignment string";
  SFString sf1(theStr);
  SFString sf2; sf2=sf1;
  
  std::string s1(theStr);
  std::string s2; s2=s1;
  theResult+=compare(sf2,s2,"operator=(const SFString&)");
  
  SFString sf3; sf3=theStr;
  
  std::string s3; s3=theStr;
  theResult+=compare(sf2,s2,"operator=(const char*)");
  
  return theResult;
}

//compare concatenation operations against std::string...
int runConcatenationTests() {
  int theResult=0;
  
  const char* theStr1="concat1";
  const char* theStr2=" concat2";
  
  SFString sf1(theStr1);
  SFString sf2(theStr2);
  SFString sf_temp = sf1+=sf2;
  
  std::string s1(theStr1);
  std::string s2(theStr2);
  std::string s_temp = s1+=s2;
  
  theResult+=compare(sf_temp,s_temp,"+=(const SFString&) error");
  
  sf_temp = sf1+=theStr2;
  s_temp = s1+=theStr2;
  
  theResult+=compare(sf_temp,s_temp,"+=(const const char*) error");
  
  return theResult;
}

//compare relational operations against std::string...
int runRelationalTests() {
  int theResult=0;

  const char* theStr1="concat1";
  const char* theStr2=" concat2";
  
  SFString sf1(theStr1);
  SFString sf2(theStr2);
  std::string s1(theStr1);
  std::string s2(theStr2);

  theResult+=compare(sf1==sf2, s1==s2, "operator==() error");
  theResult+=compare(sf1!=sf2, s1!=s2, "operator!=() error");
  theResult+=compare(sf1<sf2, s1<s2, "operator<() error");
  theResult+=compare(sf1<=sf2, s1<=s2, "operator<=() error");
  theResult+=compare(sf1>sf2, s1>s2, "operator>() error");
  theResult+=compare(sf1>=sf2, s1>=s2, "operator>=() error");

  return theResult;
}

//compare insertion operations against std::string...
int runInsertionTests() {
  int theResult=0;

  const char* theStr1="insert1";
  const char* theStr2="substr";
  
  SFString sf1(theStr1);
  SFString sf2(theStr2);
  sf1.insert(3,sf2);
  
  std::string s1(theStr1);
  std::string s2(theStr2);
  s1.insert(3,s2);

  theResult+=compare(sf1,s1,"insert(int, const string&) error");
  
  sf2.insert(3, "something");
  s2.insert(3, "something");
  theResult+=compare(sf2,s2,"insert(int, const char*) error");

  return theResult;
}

//compare replacement operations against std::string...
int runReplacementTests() {
  int theResult=0;

  const char* theStr1="original string";
  const char* theStr2="replacement";
  
  SFString sf1(theStr1);
  SFString sf2(theStr2);
  sf1.replace(9, 6, sf2);
  
  std::string s1(theStr1);
  std::string s2(theStr2);
  s1.replace(9, 6, s2);
  
  theResult+=compare(sf1,s1,"replace(int, int const string&) error");

  sf2.replace(3, 3, "new");
  s2.replace(3, 3, "new");

  theResult+=compare(sf2,s2,"replace(int, int const char*) error");

  return theResult;
}

//compare searching operations against std::string...
int runFindTests() {
  int theResult=0;

  const char* theStr1="original string";
  const char* theStr2="string";
  
  SFString sf1(theStr1);
  SFString sf2(theStr2);

  std::string s1(theStr1);
  std::string s2(theStr2);
  
  theResult+=compare((int)sf1.find(sf2,5), (int)s1.find(s2,5),"find(const string&, size_t) error");

  theResult+=compare((int)sf2.find("ring",2), (int)s1.find("ring",2),"find(const char*, size_t) error");

  return theResult;
}

int SFStringTester::runTests() {
  
  int theErrors=0;
  theErrors+=runConstructionTests();
  theErrors+=runAssignmentTests();
  theErrors+=runConcatenationTests();
  theErrors+=runRelationalTests();
  theErrors+=runInsertionTests();
  theErrors+=runReplacementTests();
  theErrors+=runFindTests();
  
  std::cout << theErrors << " errors found -- " << (theErrors ? "too bad!" : "woot!") << std::endl;
  return theErrors;
}

