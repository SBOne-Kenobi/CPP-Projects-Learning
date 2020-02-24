#include "Employee.h"

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
  employee.print(os);
  checkOutputStream(os);
  return os;
}

std::istream &operator>>(std::istream &is, Employee &employee) {
  employee.scan(is);
  checkInputStream(is);
  return is;
}

std::ofstream &operator<<(std::ofstream &os, const Employee &employee) {
  employee.fprint(os);
  checkOutputStream(os);
  return os;
}

std::ifstream &operator>>(std::ifstream &is, Employee &employee) {
  employee.fscan(is);
  checkInputStream(is);
  return is;
}

Employee::Employee(std::string name, int32_t baseSalary) : _name(name), _base_salary(baseSalary) {}

std::ostream &Employee::print(std::ostream &os) const {
  return os << "Name: " << _name << "\nBase Salary: " << _base_salary << "\n";
}

std::istream &Employee::scan(std::istream &is) {
  return is >> _name >> _base_salary;
}

int Employee::salary() const {
  return 0;
}

std::ofstream &Employee::fprint(std::ofstream &os) const {
  for (char c : _name)
    os << binary<char>(c);
  os << binary<char>(0) << binary<int32_t>(_base_salary);
  return os;
}

std::ifstream &Employee::fscan(std::ifstream &is) {
  binary<char> c;
  is >> c;
  _name = "";
  while (c.data) {
    _name += c.data;
    is >> c;
  }
  binary<int32_t> sal;
  is >> sal;
  _base_salary = sal.data;
  return is;
}

bool checkInputStream(std::istream &is) {
  if (is.bad())
    std::cerr << "Fail input stream\n";
  else if (!is)
    std::cerr << "Fail input format\n";
  if (!is) {
    is.clear();
    return false;
  }
  return true;
}

bool checkOutputStream(std::ostream &os) {
  if (!os) {
    std::cerr << "Fail output stream\n";
    os.clear();
    return false;
  }
  return true;
}
