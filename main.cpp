#include <functional>
#include <iostream>
#include <queue>
#include <string_view>
#include <string>
#include <sstream>
#include <vector>
#include "person.h"
#include "utils.h"

using namespace utils;
using namespace std;

void init_people_queue(priority_queue<Person> *people_queue, int n) {
  for (int i = 0; i < n; i++) {
    int age = generateRandomInt(1,100);
    ostringstream oss;
    oss << 2025-age << "-" << generateRandomInt(1,12) << "-" << generateRandomInt(1,30);
    string birthdate = oss.str();
    Person new_person(generateRandomName(10), age, birthdate);
    people_queue->push(new_person);
  }
}

int main() {
    std::priority_queue<Person> people_by_age;

    init_people_queue(&people_by_age, 10);
    
    while (!people_by_age.empty()) {
      Person p = people_by_age.top();
      p.displayInfo();
      people_by_age.pop();
    }

    std::priority_queue<Person> people_by_birthday; // or maybe here

    // you need something here

    init_people_queue(&people_by_birthday, 10);

    while (!people_by_birthday.empty()) {
      Person p = people_by_birthday.top();
      p.displayInfo();
      people_by_birthday.pop();
    }
}


