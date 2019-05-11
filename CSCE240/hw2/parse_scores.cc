/*  Copyright 2019 
*
*   Kevin Zheng
*
*   CSCE 240
*
*   Homework 2
*/

#include "./parse_scores.h"  // NOLINT

int get_num_grades(int id, const std::string values[], int size) {
int total = react(values, size);
if(total != size)
return -10;

    int num_grades;
    int kSize = size;
    int copy[kSize];
    for (int i = 0; i < size; ++i) {
        copy[i] = stoi(values[i]);
        if (copy[i] == id) {
            num_grades = stoi(values[i+1]);
            return num_grades;
        }
    }
    return -1;
}

int get_grades(int id, const std::string values[], int size, double grades[]) {
int total = react(values, size);
if(total != size)
return -10;

    int num_grades;
    int kSize = size;
    int copy[kSize];
    for (int i = 0; i < size; ++i) {
        copy[i] = stoi(values[i]);
        if (copy[i] == id) {
            num_grades = stoi(values[i+1]);
            int index = i + 2;
            for (int j = 0; j < num_grades; ++j) {
                grades[j] = stod(values[index]);
                ++index;
            }
            return num_grades;
        }
    }
    return -1;
}

double get_grade(int id, int grade_index
                                  , const std::string values[], int size) {
int num_gradess = 0, sstart = 1;
int nexts = 0;
for(int i = 0; i < size; ++i) {
if(i > sstart) {
num_gradess = stoi(values[sstart+1]);
nexts = sstart + num_gradess + 2;
sstart = nexts;
}
}

if(sstart != size)
return -10;

    double num_grades;
    int kSize = size;
    double copy[kSize];
    double grades[kSize];
    for (int i = 0; i < size; ++i) {
        copy[i] = stod(values[i]);

        if (copy[i] == id) {
            num_grades = stod(values[i+1]);
            int index = i + 2;
            for (int j = 0; j < num_grades; ++j) {
                grades[j] = stod(values[index]);
                ++index;
            }
                if (grade_index > num_grades-1) {
                   return -2;
                }
           num_grades = grades[grade_index];
            return num_grades;
        }
    }
    return -1;
}

int get_max_grade_id(const std::string values[], int size) {
int total = react(values, size);
if(total != size)
return -10;

int bee = stoi(values[0]);
if(bee == 0)
return -1;

int index = 0, num_grades = 0, user = 1, sid = 0;
double max_score = 0;
int kSize = size;
double grades[kSize];
for (int i = 0 ; i < size; ++i) {
    if ((i == user) && (user <= size)) {
        num_grades = stoi(values[user+1]);
        index = user + 2;
        for (int j = 0; j < num_grades; ++j) {
            grades[j] = stod(values[index]);
            ++index;
        }
        for (int x = 0; x < size; ++x) {
            if (grades[x] >= 0 && grades[x] <= 100) {
                if (grades[x] > max_score) {
                    max_score = grades[x];
                    sid = stoi(values[user]);
                }
            }
        }
            user = index;
    }
}
if(max_score == 0)
return -2;

return sid;
}

double get_max_grade(const std::string values[], int size) {
int totaal = react(values, size);
if(totaal != size)
return -10;

int be = stoi(values[0]);
if(be == 0)
return -1;

int index = 0, start = 2, total = 0, num_grades = 0;
int kSize = size;
double grades[kSize];
for (int i = 0 ; i < size; ++i) {
  if ((i == start) && (start <= size)) {
        num_grades = stoi(values[i]);
        index = i+1;
        for (int j = 0 ; j < num_grades; ++j) {
            grades[total] = stod(values[index]);
            ++index;
            total = total + 1;
        }
        start = index+1;
    }
}

double max_score = 0;
for (int i = 0; i < size; ++i) {
    if (grades[i] <= 100 && grades[i] >= 0) {
        if (grades[i] >= max_score)
            max_score = grades[i];
    }
}

if (max_score == 0) {
return -2;
}

return max_score;
}

int get_student_ids(const std::string values[], int size, int ids[]) {
int totaal = react(values, size);
if(totaal != size)
return -10;

int num_user = stoi(values[0]);
int index = 0, num_grades = 0, user = 1, total = 0;
for (int i = 0; i < size; ++i) {
    if ((i == user) && (user <= size)) {
        ids[total] = stoi(values[user]);
        num_grades = stoi(values[user+1]);
        index = user + num_grades;
        if (user <= size) {
        user = index + 2;
        ++total;
        }
    }
}
    return num_user;
}

int react(const std::string values[], int size) {
int num_gradess = 0, sstart = 1, nexts = 0;

for (int i = 0; i < size; ++i) {
if (i > sstart) {
num_gradess = stoi(values[sstart+1]);
nexts = sstart + num_gradess + 2;
sstart = nexts;
}
}
return sstart;
}








