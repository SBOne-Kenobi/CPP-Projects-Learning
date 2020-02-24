#include "EmployeesArray.h"
#include "SalesManager.h"
#include "Developer.h"
#include "Factory.h"
#include <iostream>

int add(EmployeesArray &array) {
  array.add(scan_employee(std::cin));
  return 0;
}

int list(EmployeesArray &array) {
  std::cout << array;
  return 0;
}

int load(EmployeesArray &array) {
  std::string file;
  std::cin >> file;
  std::ifstream is;
  is.open(file, std::ifstream::in | std::ifstream::binary);
  if (!is.is_open())
    return 1;
  is >> array;
  is.close();
  return 0;
}

int save(EmployeesArray &array) {
  std::string file;
  std::cin >> file;
  std::ofstream os;
  os.open(file, std::ofstream::out | std::ofstream::binary);
  if (!os.is_open())
    return 1;
  os << array;
  os.close();
  return 0;
}

using Cmd = int (*)(EmployeesArray &);
std::map<std::string, Cmd> executable;

void init() {
  executable["add"] = add;
  executable["save"] = save;
  executable["list"] = list;
  executable["load"] = load;

  registrate<SalesManager>(employeeId::SALES_MANAGER);
  registrate<Developer>(employeeId::DEVELOPER);
}

int execute(EmployeesArray &array, const std::string &cmd) {
  if (executable.find(cmd) == executable.end())
    return 1;
  return executable[cmd](array);
}

int main() {

  init();

  EmployeesArray array;

  std::string cmd;
  std::cin >> cmd;
  while (cmd != "exit") {
    if (execute(array, cmd))
      std::cerr << "Fail " << cmd << "\n";
    std::cin >> cmd;
  }

  return 0;
}
