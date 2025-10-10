#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
  std::string name;
  int age;
  std::string birthdate; 

public:
  Person(const std::string& name, int age, const std::string& birthdate);
  Person() = default;
  std::string getName() const;
  int getAge() const;
  std::string getBirthdate() const;
  void displayInfo() const;
  //bool operator<(const Person& other) const;
};

std::string generateRandomName(size_t length);

#endif // PERSON_H
