#include "EmployeesArray.h"

void EmployeesArray::add(const Employee *e) {
  _employees.push_back(e);
}

int EmployeesArray::total_salary() const {
  int total = 0;
  for (auto it : _employees)
    total += it->salary();
  return total;
}

EmployeesArray::~EmployeesArray() {
  for (auto it : _employees)
    delete it;
}

std::ostream &operator<<(std::ostream &os, const EmployeesArray &array) {
  for (size_t i = 0; i < array._employees.size(); i++) {
    os << i + 1 << ". " << *array._employees[i];
    if (!checkOutputStream(os))
      return os;
  }
  os << "== " << "Total salary: " << array.total_salary() << "\n\n";
  checkOutputStream(os);
  return os;
}

std::istream &operator>>(std::istream &is, EmployeesArray &array) {
  int n;
  is >> n;
  if (!checkInputStream(is))
    return is;
  for (int i = 0; i < n; i++)
    array.add(scan_employee(is));
  return is;
}

std::ofstream &operator<<(std::ofstream &os, const EmployeesArray &array) {
  os << binary<int32_t>(array._employees.size());
  if (!checkOutputStream(os))
    return os;
  for (auto it : array._employees)
    os << *it;
  checkOutputStream(os);
  return os;
}

std::ifstream &operator>>(std::ifstream &is, EmployeesArray &array) {
  binary<int32_t> sz;
  is >> sz;
  if (!checkInputStream(is))
    return is;
  for (int i = 0; i < sz.data; i++)
    array.add(fscan_employee(is));
  return is;
}
