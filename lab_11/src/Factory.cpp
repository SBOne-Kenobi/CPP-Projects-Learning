#include "Factory.h"

std::map<int, Creator> reg;

void registration(int id, Creator creator) {
  reg[id] = creator;
}

Employee *create_employee(int id) {
  return reg[id]();
}

template<typename T>
Employee *scan_without_id(T &is, int id) {
  if (!checkInputStream(is))
    return new Employee();
  Employee *employee = create_employee(id);
  is >> *employee;
  return employee;
}

Employee *scan_employee(std::istream &is) {
  int id;
  is >> id;
  return scan_without_id(is, id);
}

Employee *fscan_employee(std::ifstream &is) {
  binary<int32_t> id;
  is >> id;
  return scan_without_id(is, id.data);
}
