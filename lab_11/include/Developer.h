#ifndef LAB_11_DEVELOPER_H
#define LAB_11_DEVELOPER_H

#include <ostream>
#include "Employee.h"

class Developer : public Employee {
private:
  bool _has_bonus = false;

  std::ostream &print(std::ostream &os) const override;

  std::istream &scan(std::istream &is) override;

  std::ofstream &fprint(std::ofstream &os) const override;

  std::ifstream &fscan(std::ifstream &is) override;

public:

  Developer() = default;

  Developer(char *name, int32_t baseSalary, bool hasBonus);

  int salary() const override;
};


#endif
