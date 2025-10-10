#include <iostream>
#include <string>
#include <ctime> // For handling dates
#include <random>
#include <algorithm>
#include "person.h"

// Constructor
Person::Person(const std::string& name, int age, const std::string& birthdate)
  : name(name), age(age), birthdate(birthdate) {}

std::string Person::getName() const {
  return name;
}

int Person::getAge() const {
  return age;
}

std::string Person::getBirthdate() const {
  return birthdate;
}

void Person::displayInfo() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Birthdate: " << birthdate << std::endl;
}

//bool Person::operator<(const Person& other) const {
//        return age < other.age;
//}

std::string generateRandomName(size_t length) {
    // A string of all possible letters for the name
    const std::string lower_chars = "abcdefghijklmnopqrstuvwxyz";
    const std::string upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Create a high-quality, non-deterministic random number generator
    std::random_device rd;
    std::mt19937 generator(rd());

    // Create a uniform integer distribution for character indices
    // The distribution's range is from 0 to the size of the alphabet minus 1
    std::uniform_int_distribution<size_t> upper_dist(0, upper_chars.size() - 1);
    std::uniform_int_distribution<size_t> lower_dist(0, lower_chars.size() - 1);

    std::string random_name;
    
    if (length > 0) {
        // First character is always an uppercase letter
        random_name += upper_chars[upper_dist(generator)];

        // Remaining characters are lowercase letters
        for (size_t i = 1; i < length; ++i) {
            random_name += lower_chars[lower_dist(generator)];
        }
    }
    
    return random_name;
}
