#ifndef LAB_11_EMPLOYEE_H
#define LAB_11_EMPLOYEE_H

#include <cstdint>
#include <iostream>
#include <string>
#include "binary.inl"

class Employee {
protected:
  std::string _name = "Undef";

  int32_t _base_salary = 0;

  virtual std::ostream &print(std::ostream &os) const;

  virtual std::istream &scan(std::istream &is);

  virtual std::ofstream &fprint(std::ofstream &os) const;

  virtual std::ifstream &fscan(std::ifstream &is);

public:

  virtual int salary() const;

  Employee() = default;

  Employee(std::string name, int32_t baseSalary);

  Employee(const Employee &other) = delete;

  virtual ~Employee() = default;

  friend std::ostream &operator<<(std::ostream &os, const Employee &employee);

  friend std::istream &operator>>(std::istream &is, Employee &employee);

  friend std::ofstream &operator<<(std::ofstream &os, const Employee &employee);

  friend std::ifstream &operator>>(std::ifstream &is, Employee &employee);
};

namespace employeeId {
  enum {
    DEVELOPER = 1,
    SALES_MANAGER = 2
  };
};

bool checkInputStream(std::istream &is);

bool checkOutputStream(std::ostream &os);

#endif
