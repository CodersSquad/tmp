#include <functional>
#include <iostream>
#include <queue>
#include <string_view>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "person.h"
#include "utils.h"
#include "stacks/expressions_calculator.h"

using namespace utils;
using namespace std;
void fill_people_queue(priority_queue<Person>* pq_ptr, int total) {
  for (int idx = 0; idx < total; idx++) {
    int years = generateRandomInt(1,100);
    ostringstream date_stream;
    date_stream << 2025-years << "-" << generateRandomInt(1,12) << "-" << generateRandomInt(1,30);
    string bdate = date_stream.str();
    Person person(generateRandomName(6), years, bdate);
    pq_ptr->push(person);
  }
}
template<typename PQ>
void fill_people_queue_custom(PQ& pq, int total) {
  for (int idx = 0; idx < total; idx++) {
    int years = generateRandomInt(1,100);
    ostringstream date_stream;
    date_stream << 2025-years << "-" << generateRandomInt(1,12) << "-" << generateRandomInt(1,30);
    string bdate = date_stream.str();
    Person person(generateRandomName(6), years, bdate);
    pq.push(person);
  }
}
struct CompareBirthday {
  bool operator()(const Person& pa, const Person& pb) const {
    auto extract_month_day = [](const string& bdate) {
      int year=0,month=0,day=0;
      char sep;
      istringstream iss(bdate);
      iss >> year >> sep >> month >> sep >> day;
      return month*100+day;
    };
    int key_a = extract_month_day(pa.getBirthdate());
    int key_b = extract_month_day(pb.getBirthdate());
    return key_a > key_b;
  }
};
int main(int argc, char** argv) {
  if (argc > 1) {
    string expression = argv[1];
    try {
      auto postfix_expr = expr_calc::infix_to_postfix(expression);
      double final_result = expr_calc::evaluate_postfix(postfix_expr);
      string compact_str = expr_calc::postfix_to_compact_string(postfix_expr);
      cout << "Infix expression   : " << expression << "\n";
      cout << "Postfix expression : " << compact_str << "\n";
      cout << "Final Result       : " << setprecision(15) << final_result << "\n";
    } catch (const exception& exc) {
      cerr << "Error processing expression: " << exc.what() << "\n";
      return 1;
    }
    return 0;
  }
  priority_queue<Person> age_queue;
  fill_people_queue(&age_queue, 10);
  cout << "People prioritized by AGE (top = largest age):\n";
  while (!age_queue.empty()) {
    Person person = age_queue.top();
    person.displayInfo();
    cout << "--------------------------\n";
    age_queue.pop();
  }
  priority_queue<Person, vector<Person>, CompareBirthday> birthday_queue;
  fill_people_queue_custom(birthday_queue, 10);
  cout << "\nPeople prioritized by BIRTHDAY (top = earliest month-day):\n";
  while (!birthday_queue.empty()) {
    Person person = birthday_queue.top();
    person.displayInfo();
    cout << "--------------------------\n";
    birthday_queue.pop();
  }
  return 0;
}
