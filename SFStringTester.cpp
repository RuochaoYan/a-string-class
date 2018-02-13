//
//  SFStringTester.cpp
//  class_test
//

#include "SFStringTester.hpp"
#include "SFString.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <chrono>

//compare results and return error status (side-effect output to terminal)...
int compare(const SFString& str1, const std::string &str2, const char* aMessage) {
    const char* s1=str1;
    const char* s2=str2.c_str();
    
    std::cout << "Test: " << aMessage;
    if(strcmp(s1,s2)) {
        std::cout << " Error! s1(" << s1 << ") s2(" << s2 << ")" << std::endl;
        return 1;
    }
    
    std::cout << " ok " << std::endl;
    return 0;
}

//compare int results and return error status (side-effect output to terminal)...
int compare(int anArg1, int anArg2,const char* aMessage) {
    std::cout << "Test: " << aMessage;
    if(anArg1!=anArg2) {
        std::cout << " Error! " << std::endl;
        return 1;
    }
    std::cout << " ok " << std::endl;
    return 0;
}

/* ----- generate a random string -------- */
void gen_random(char *s, const int len) {
    static const char alphanum[] =
    " 0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    s[len] = 0;
}

//run your own performance stress-tests here...
void performanceOfInsert(std::vector<SFString> sf1s, std::vector<SFString> sf2s, std::vector<std::string> s1s, std::vector<std::string>s2s){
    // SFString
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 1000000; i++){
        SFString sf1 = sf1s[i];
        SFString sf2 = sf2s[i];
        sf1.insert(20,sf2);
//                std::string s1 = s1s[i];
//                std::string s2 = s2s[i];
//                s1.insert(20,s2);
//                compare(sf1,s1,"insert(int, const string&)");
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Performance of SFString's insert function: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
    << " milliseconds\n";
    
    // string
    t1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 1000000; i++){
        std::string s1 = s1s[i];
        std::string s2 = s2s[i];
        s1.insert(20,s2);
        //compare(sf1,s1,"insert(int, const string&)");
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Performance of std::string's insert function: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
    << " milliseconds\n";
}
void performanceOfReplace(std::vector<SFString> sf1s, std::vector<SFString> sf2s, std::vector<std::string> s1s, std::vector<std::string>s2s){
    // SFString
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 1000000; i++){
        SFString sf1 = sf1s[i];
        SFString sf2 = sf2s[i];
        sf1.replace(20,20,sf2);
        //                std::string s1 = s1s[i];
        //                std::string s2 = s2s[i];
        //                s1.insert(20,s2);
        //                compare(sf1,s1,"insert(int, const string&)");
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Performance of SFString's replace function: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
    << " milliseconds\n";
    
    // string
    t1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 1000000; i++){
        std::string s1 = s1s[i];
        std::string s2 = s2s[i];
        s1.replace(20,20,s2);
        //compare(sf1,s1,"insert(int, const string&)");
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Performance of std::string's replace function: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
    << " milliseconds\n";
}
void performanceOfFind(std::vector<SFString> sf1s, std::vector<SFString> sf2s, std::vector<std::string> s1s, std::vector<std::string>s2s){
    // SFString
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 1000000; i++){
        SFString sf1 = sf1s[i];
        SFString sf2 = sf2s[i];
        sf1.find(sf2);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Performance of SFString's find function: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
    << " milliseconds\n";
    // string
    t1 = std::chrono::high_resolution_clock::now();
    for(int i = 1; i < 1000000; i++){
        std::string s1 = s1s[i];
        std::string s2 = s2s[i];
        s1.find(s2);
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Performance of std::string's find function: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
    << " milliseconds\n";
}

void runPerformanceTests() {
    // generate 2000000 strings respectively for SFString and String
    // half of them with size 100, and the other half with size 10
    std::vector<SFString> sf1s, sf2s;
    std::vector<std::string> s1s, s2s;
    for(int i = 0; i < 1000000; i++){
        char* temp = new char[100];
        gen_random(temp, 100);
        sf1s.push_back(SFString(temp));
        s1s.push_back(std::string(temp));
        delete[] temp;
    }
    for(int i = 0; i < 1000000; i++){
        char* temp = new char[10];
        gen_random(temp, 10);
        sf2s.push_back(SFString(temp));
        s2s.push_back(std::string(temp));
        delete[] temp;
    }

    performanceOfInsert(sf1s, sf2s, s1s, s2s);
    performanceOfFind(sf1s, sf2s, s1s, s2s);
    performanceOfFind(sf1s, sf2s, s1s, s2s);

}

//run your own performance stress-tests here...
void runMemoryTests() {
    
    /*
     I used the developer tool Instruments in Xcode and used the "allocations" profiling template to track the memory usage in the program and found some memory leak with the "leak" template and fixed them. I also overloaded global new and delete operators, added a static variable to track memory usage during the program.
    */
    std::cout << "maximum memory units used: " << SFString::maxMemory << std::endl;
    
}

//compare construction operations against std::string...
int runConstructionTests() {
    int theResult=0;
    SFString sf1;
    std::string s1;
    theResult+=compare(sf1,s1,"ctor()");
    
    const char* theStr="teststring";
    SFString sf2(theStr);
    std::string s2(theStr);
    theResult+=compare(sf2,s2,"ctor(const char*)");
    
    SFString sf3(sf2);
    std::string s3(s2);
    theResult+=compare(sf3,s3,"ctor(const SFString&)");
    
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
    
    theResult+=compare(sf_temp,s_temp,"operator+=(const SFString&)");
    
    sf_temp = sf1+=theStr2;
    s_temp = s1+=theStr2;
    
    theResult+=compare(sf_temp,s_temp,"operator+=(const const char*)");
    
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
    
    theResult+=compare(sf1==sf2, s1==s2, "operator==()");
    theResult+=compare(sf1!=sf2, s1!=s2, "operator!=()");
    theResult+=compare(sf1<sf2, s1<s2, "operator<()");
    theResult+=compare(sf1<=sf2, s1<=s2, "operator<=()");
    theResult+=compare(sf1>sf2, s1>s2, "operator>()");
    theResult+=compare(sf1>=sf2, s1>=s2, "operator>=()");
    
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
    
    theResult+=compare(sf1,s1,"insert(int, const string&)");
    
    sf2.insert(3, "something");
    s2.insert(3, "something");
    theResult+=compare(sf2,s2,"insert(int, const char*)");
    
    return theResult;
}

//compare erase operations against std::string...
int runEraseTests() {
    int theResult=0;
    
    const char* theStr1="this is a long string that is testing erase";
    
    SFString sf1(theStr1);
    sf1.erase(15,50);
    std::string s1(theStr1);
    s1.erase(15,50);
    
    theResult+=compare(sf1,s1,"erase(int, const string&)");
    
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
    
    theResult+=compare(sf1,s1,"replace(int, int const string&)");
    
    sf2.replace(3, 3, "new");
    s2.replace(3, 3, "new");
    
    theResult+=compare(sf2,s2,"replace(int, int, const char*)");
    
    return theResult;
}

//compare searching operations against std::string...
int runFindTests() {
    int theResult=0;
    
    const char* theStr1="original string contains string twice";
    const char* theStr2="string";
    
    SFString sf1(theStr1);
    SFString sf2(theStr2);
    
    std::string s1(theStr1);
    std::string s2(theStr2);
    
    theResult+=compare((int)sf1.find(sf2,5), (int)s1.find(s2,5),"find(const string&, size_t)");
    theResult+=compare((int)sf1.find("ring",20), (int)s1.find("ring",20),"find(const char*, size_t)");
    
    return theResult;
}

//only called if the STUDENT explicitly asks us to do it in main...
int runExtraCreditTests() {
    int theResult=0;
    
    const char* thePrefix="hello";
    const char* theSuffix=" there ";
    
    SFString sf1(theSuffix);
    SFString sf2 = thePrefix + sf1;
    
    std::string s1(theSuffix);
    std::string s2 = thePrefix + s1;
    
    theResult+=compare(sf2,s2,"operator+(const char*, const SFString&)");
    
    SFString sf3(thePrefix);
    SFString sf4 = sf3 + theSuffix ;
    
    std::string s3(thePrefix);
    std::string s4 = s3 + theSuffix;
    
    theResult+=compare(sf4,s4,"operator+(const SFString&, const char*)");
    
    return theResult;
}

int SFStringTester::runTests() {
    
    int theErrors=0;
    theErrors+=runConstructionTests();
    theErrors+=runAssignmentTests();
    theErrors+=runConcatenationTests();
    theErrors+=runRelationalTests();
    theErrors+=runInsertionTests();
    theErrors+=runEraseTests();
    theErrors+=runReplacementTests();
    theErrors+=runFindTests();
    
    theErrors+=runExtraCreditTests();
    runPerformanceTests();
    runMemoryTests();
    std::cout << theErrors << " errors found -- " << (theErrors ? "too bad!" : "woot!") << std::endl;
    return theErrors;
}
