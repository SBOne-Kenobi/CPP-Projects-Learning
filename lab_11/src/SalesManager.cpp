#include "SalesManager.h"

#include "Factory.h"

SalesManager::SalesManager(char *name, int32_t baseSalary, int32_t soldNm, int32_t price) : Employee(name, baseSalary),
                                                                                            _sold_nm(soldNm),
                                                                                            _price(price) {}

int SalesManager::salary() const {
  return _base_salary + _sold_nm * _price / 100;
}

std::ostream &SalesManager::print(std::ostream &os) const {
  os << "Sales Manager\n";
  return Employee::print(os) << "Sold items: " << _sold_nm << "\nItem price: " << _price << "\n";;
}

std::istream &SalesManager::scan(std::istream &is) {
  return Employee::scan(is) >> _sold_nm >> _price;
}

std::ofstream &SalesManager::fprint(std::ofstream &os) const {
  os << binary<int>(employeeId::SALES_MANAGER);
  Employee::fprint(os);
  os << binary<int32_t>(_sold_nm) << binary<int32_t>(_price);
  return os;
}

std::ifstream &SalesManager::fscan(std::ifstream &is) {
  Employee::fscan(is);
  binary<int32_t> tmp;
  is >> tmp;
  _sold_nm = tmp.data;
  is >> tmp;
  _price = tmp.data;
  return is;
}
