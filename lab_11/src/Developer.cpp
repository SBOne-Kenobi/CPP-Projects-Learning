#include "Developer.h"
#include "Factory.h"

int Developer::salary() const {
  int salary = _base_salary;
  if (_has_bonus) { salary += 1000; }
  return salary;
}

Developer::Developer(char *name, int32_t baseSalary, bool hasBonus) : Employee(name, baseSalary),
                                                                      _has_bonus(hasBonus) {}

std::ostream &Developer::print(std::ostream &os) const {
  os << "Developer\n";
  return Employee::print(os) << "Has bonus: " << (_has_bonus ? "+" : "-") << "\n";
}

std::istream &Developer::scan(std::istream &is) {
  return Employee::scan(is) >> _has_bonus;
}

std::ofstream &Developer::fprint(std::ofstream &os) const {
  os << binary<int>(employeeId::DEVELOPER);
  Employee::fprint(os);
  os << binary<char>(_has_bonus ? 1 : 0);
  return os;
}

std::ifstream &Developer::fscan(std::ifstream &is) {
  Employee::fscan(is);
  binary<bool> bonus;
  is >> bonus;
  _has_bonus = bonus.data;
  return is;
}
