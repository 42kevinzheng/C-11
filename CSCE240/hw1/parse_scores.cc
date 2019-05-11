/*	parse_scores Copyright 2019
*
*/


#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
int max_id;
double max_score;
int number_of_students;
cin >> number_of_students;

cout << "{" << endl;
cout << "  \"students\" : [" << endl;



for (int i = 1; i <= number_of_students; ++i) {
    if (i != number_of_students) {
    int student_id;
    cin >> student_id;
    int number_of_grades;
    cin >> number_of_grades;
    std::vector <double> arr;
    for (int i = 0; i < number_of_grades; ++i) {
     double the_grade;
     cin >> the_grade;
     if (the_grade > max_score) {  // Check for the max score
     max_score = the_grade;
     max_id = student_id;
     }
     arr.push_back(the_grade);
    }  // end of second for loop
    cout << "    { \"id\" : "<< student_id << " , \"grades\" : [ ";
    int size_of_vector = arr.size();
    for (int i = 0; i < size_of_vector; ++i) {
     if (i != size_of_vector-1) {
       cout << arr[i] << ", ";
      } else { cout << arr[i] << ""; }
    }  // end of third for loop, this is for command for the number of grades
cout << " ] }," << endl;
} else {
    int student_id;
    cin >> student_id;
    int number_of_grades;
    cin >> number_of_grades;
    std::vector <double> arr;
    for (int i = 0; i < number_of_grades; ++i) {
     double the_grade;
     cin >> the_grade;
if (the_grade > max_score) {  // Check for the max score
     max_score = the_grade;
     max_id = student_id;
     }
     arr.push_back(the_grade);
    }  // end of second for loop
    cout << "    { \"id\" : "<< student_id << " , \"grades\" : [ ";
    int size_of_vector = arr.size();
    for (int i = 0; i < size_of_vector; ++i) {
     if (i != size_of_vector-1) { cout << arr[i] << ", ";
     } else { cout << arr[i] << ""; }
    }  // end of third for loop, this is for the number of grades
cout << " ] }" << endl;
     }
  }  // end of the first for loop counting the number of students.

cout << "  ]," << endl;
cout << "  \"max_id\" : " << max_id << "," << endl;
cout << "  \"max_score\" : " << max_score << endl;
cout << "}";
}  // end of main
