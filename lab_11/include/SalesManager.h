#ifndef LAB_11_SALESMANAGER_H
#define LAB_11_SALESMANAGER_H

#include "Employee.h"

class SalesManager : public Employee {
private:
  int32_t _sold_nm = 0, _price = 0;

  std::ostream &print(std::ostream &os) const override;

  std::ofstream &fprint(std::ofstream &os) const override;

  std::ifstream &fscan(std::ifstream &is) override;

  std::istream &scan(std::istream &is) override;

public:

  SalesManager() = default;

  int salary() const override;

  SalesManager(char *name, int32_t baseSalary, int32_t soldNm, int32_t price);
};


#endif
