#ifndef LAB_11_BINARY_INL
#define LAB_11_BINARY_INL

#include <istream>
#include <ostream>
#include <fstream>

template<typename T>
struct binary {
  T data;
  inline explicit binary(const T &data = 0) : data(data) {}
};

template<typename T>
inline std::istream &operator>>(std::istream &is, binary<T> &x) {
  is.read(reinterpret_cast<char *>(&x.data), sizeof(T));
  return is;
}

template<typename T>
inline std::ostream &operator<<(std::ostream &os, const binary<T> &x) {
  os.write(reinterpret_cast<const char *>(&x.data), sizeof(T));
  return os;
}

#endif
