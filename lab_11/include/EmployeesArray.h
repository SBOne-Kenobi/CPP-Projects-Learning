#ifndef LAB_11_EMPLOYEESARRAY_H
#define LAB_11_EMPLOYEESARRAY_H

#include "Factory.h"
#include <vector>

class EmployeesArray {
private:
  std::vector<const Employee *> _employees;

public:
  EmployeesArray() = default;

  virtual ~EmployeesArray();

  EmployeesArray(const EmployeesArray &other) = delete;

  void add(const Employee *e);

  friend std::ostream &operator<<(std::ostream &os, const EmployeesArray &array);

  friend std::istream &operator>>(std::istream &is, EmployeesArray &array);

  friend std::ofstream &operator<<(std::ofstream &os, const EmployeesArray &array);

  friend std::ifstream &operator>>(std::ifstream &is, EmployeesArray &array);

  int total_salary() const;
};


#endif
