#ifndef LAB_11_FACTORY_H
#define LAB_11_FACTORY_H

#include "Employee.h"
#include <map>
#include <typeindex>

using Creator = Employee *(*)();

template<typename T>
void registrate(int id) {
  void registration(int id, Creator creator);
  registration(id, []() -> Employee * { return new T(); });
}

Employee *create_employee(int id);

Employee *scan_employee(std::istream &is);

Employee *fscan_employee(std::ifstream &is);

#endif
