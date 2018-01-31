# ECE-180 Assignment2
Due: Jan 30, 11:15p (PST)

## Preface

We've spent the last few weeks covering the intricacies of C++ classes in considerable detail. Now it's your turn to create your first moderately complex class.

## Welcome to JobCo!

You've just started a new internship at JobCo, a chic software company in the heart of Silicon Valley that sells party balloons with integrated block-chain tracking. You've met your new manager, Chloe, who introduces you to the rest of the team. As you are wisked through the office, you race past a herd of zombies that are wandering aimlessly in the basement. "Oh my goodness", you say, in disbelief.  "Don't let them bother you", Chloe says smiling, "that's just the marketing department taking a lunch break". JobCo is going to be very interesting.

### Your FIRST Sprint Meeting

The next morning you get to sit in on your very first "Sprint Meeting" where the team discusses the work they're going to accomplish for the week. Each of the engineers talks briefly about their challenges and expected output. At last, all eyes drop onto you. Before panic seizes you, Chloes says, "Hey everyone, this is our new summer intern!". The team smiles knowingly, suggesting you may be in for more than you bargained for.  What happens next is mostly a blur. For one, you don't remember actually saying anything. But suddenly you realize that Chloe has tasked you with delivering some mission critical code, and FAST!  

### Your Team Makes a Decision

Just before the end of the standup meeting, Morris (a performance engineer) raises the topic of how slowly the application is performing. "Seriously", he says, "the app is running 5x slower today than it was a month ago". "What we need", he continues, "is someone to rewrite our string class to stop all the unnecessary memory allocations and performance problems."

"Great -- our new intern can build us a new string class this Sprint!", Chloes exclaims, never missing an opportunity. Sade, a UX designer on the team, says, "Hold on, why can't we just use the std::string class provided by the STL? Won't that be cheaper than building our own?"  Morris can barely contain himeself. "No!", he chides, "the STL is great in general, but it's way too big, and I just know we can build something smaller and faster!"

Sadly, no amount of arguing about re-inventing the wheel would stop Morris and Chloe from building their own string class. Welcome to Silicon Valley. :)

## Assignment Details

In this assignment, you are going to build a string class. String classes provide an object-oriented solution to managing character buffers in an application. Most modern applications have to manage strings to some degre, but some applications, like word-processors and browsers, string management can have a tremendous impact on performance and memory management.

### Class interface (incomplete)

We have provided a starting point for your string class, in the SFString.hpp file.  It looks like this:

```

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
  
  SFString&    insert(int aPos, const SFString &aString);
  SFString&    insert(int aPos, const char aChar);
  
  SFString&    replace(size_t pos, size_t len, const SFString &aString);
  
  int          find(const SFString &aString, size_t offset=0);
  
};

```

That's not too bad. One problem, though, is that the class also needs to support standard `char*` strings as well. 

### Part 1. -- Update the SFString class declaration in your .hpp file

In addition to the methods we have already provided for you, you need to add versions for most of these methods so users can use standard c-strings. For example, you will add a conversion constructor that accepts a const char*, like this:

```
  SFString(const char* aString);
```
Below, is an updated sample that indicates which methods you need to add to fully support const char*. Everywhere you see a comment that starts with "ADD...", you need to declare an additional member (method or operator) as indicated:

```

class SFString {
public:
  
  SFString();
  SFString(const SFString& aString);
  //ADD a conversion constructor that supports const char*...
  
  SFString&    operator=(const SFString& aString);
		//ADD "operator=" that supports const char*...
  
  operator const char*() const;
  char         operator[](int pos) const;

  SFString&    operator+=(const SFString &aString);
		//ADD "operator+=" that supports const char*...
  
  bool         operator<(const SFString &aString);
		//ADD "operator<" that supports const char*...
  
  bool         operator<=(const SFString &aString);
		//ADD "operator<=" that supports const char*...
  
  bool         operator>(const SFString &aString);
		//ADD "operator>" that supports const char*...
  
  bool         operator>=(const SFString &aString);
		//ADD "operator>=" that supports const char*...
  
  bool         operator==(const SFString &aString);
		//ADD "operator==" that supports const char*...
  
  bool         operator!=(const SFString &aString);
		//ADD "operator!=" that supports const char*...
  
  SFString&    insert(int aPos, const SFString &aString);
		//ADD "insert()" method that supports const char*...
  
  SFString&    replace(size_t pos, size_t len, const SFString &aString);
		//ADD "replace()" method that supports const char*...
  
  int          find(const SFString &aString, size_t offset=0);
		//ADD "find()" method that supports const char*...
};

```

### Part 2. -- Update the given class interface 

Now that you have updated your header file (.hpp), take a look at the SFString.cpp file. You'll notice that is almost completely empty, as shown below.  You need to implement all of the SFString class functionality in your .cpp file. 

```
//
//  SFString.cpp
//  class_test
//
//  STUDENT: Your job here is to implement the string class functionality in this file...
//
//  Created by rick gessner on 1/29/18.
//  Copyright © 2018 rick gessner. All rights reserved.
//

#include "SFString.hpp"

```
### Part 3. -- Testing your SFString class implementation 

No self-respecting engineer would consider the job done unless s/he provided a complete set of tests to ensure that the solution worked as designed. Well, we've already provided a class testing harness for you, contained in the SFStringTester files:

```
class SFStringTester {
public:
  static int runTests();
};
```
asdf
