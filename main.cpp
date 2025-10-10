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

/*
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
*/

int main() {
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    println("data", data);

    std::queue<int> default_queue;
    std::priority_queue<int> max_priority_queue;

    //std::priority_queue<Person> people_queue;
    //init_people_queue(&people_queue, 10);
    //while (!people_queue.empty()) {
    //  Person p = people_queue.top();
    //  p.displayInfo();
    //  people_queue.pop();
    //}
    
    // Fill the priority queue.
    for (int n : data) {
        default_queue.push(n);
        max_priority_queue.push(n);
    }

    pop_front_println("default_queue", default_queue);
    pop_println("max_priority_queue", max_priority_queue);
 
    // std::greater<int> makes the max priority queue act as a min priority queue.
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        min_priority_queue1(data.begin(), data.end());
 
    pop_println("min_priority_queue1", min_priority_queue1);
 
    // Second way to define a min priority queue.
    std::priority_queue min_priority_queue2(data.begin(), data.end(), std::greater<int>());
 
    pop_println("min_priority_queue2", min_priority_queue2);
 
    // Using a custom function object to compare elements.
    struct
    {
        bool operator()(const int l, const int r) const { return l > r; }
    } customLess;
 
    std::priority_queue custom_priority_queue(data.begin(), data.end(), customLess);
 
    pop_println("custom_priority_queue", custom_priority_queue);
 
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> lambda_priority_queue(cmp);
 
    for (int n : data)
        lambda_priority_queue.push(n);
 
    pop_println("lambda_priority_queue", lambda_priority_queue);
}


