/* Copyright 2019 
This app accepts a non-case sensitive month name and prints the number of days
in that month followed by a new line. Returns 0.

When month is not found, returns 1.
*/

#include <algorithm>
using std::transform;
#include <cassert>
// using assert
#include <cctype>
// using toupper
#include <cstddef>
// using size_t
#include <cstdint>
// using uint8_t
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <utility>
using std::make_pair;


/* Searches an array for a value and returns its index or -1 */
template<class T>
int LinearSearch(const T& key, const T vals[], const size_t size);


/* Fills a map object for use in place of LinearSearch */
template<class FROM, class TO>
void LoadMap(const FROM months[], const TO days[], const size_t size,
    map<FROM, TO>* target);


/* Provides a map object with fill constructor for use in place of LoapMap */
class DaysInMonth : private map<string, uint8_t> {
 public:
  DaysInMonth();

  unsigned int DaysIn(const string& month) const;

  bool IsMonth(const string& key) const;
 private:
  string ToUpper(const string& from) const;
};


int main(int argc, char* argv[]) {
  const int month_index = 1;
  assert(month_index < argc);

  DaysInMonth calendar;
  int days_in = calendar.DaysIn(argv[month_index]);
  if (days_in) {
    cout << calendar.DaysIn(argv[month_index]) << endl;
    return 0;
  }
  return 1;
}



template<class T>
int LinearSearch(const T& key, const T vals[], const size_t size) {
  for (size_t i = 0; i < size; ++i)
    if (key == vals[i])
      return i;

  return -1;
}


template<class FROM, class TO>
void LoadMap(const FROM months[], const TO days[], const size_t size,
    map<FROM, TO>* target) {
  for (size_t i = 0; i < size; ++i)
    target->insert(make_pair(months[i], days[i]));
}


DaysInMonth::DaysInMonth() {
  const size_t julian_size = 12;
  const string months[julian_size] = {
    "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST",
    "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
  const uint8_t days_in_month[julian_size] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  for (size_t i = 0; i < julian_size; ++i)
    insert(make_pair(months[i], days_in_month[i]));
}

unsigned int DaysInMonth::DaysIn(const string& month) const {
  if (IsMonth(month))
    return at(ToUpper(month));
  else
    return 0;
}

bool DaysInMonth::IsMonth(const string& key) const {
  if (key.size() > 9)
    return false;

  map<string, uint8_t>::const_iterator c_it = find(ToUpper(key));
  return c_it != end();
}

string DaysInMonth::ToUpper(const string& from) const {
  string to_str(from);
  transform(to_str.begin(), to_str.end(), to_str.begin(), toupper);
  return to_str;
}
