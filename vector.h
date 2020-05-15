#ifndef LR_5_TEMPLATE_VECTOR_H
#define LR_5_TEMPLATE_VECTOR_H

#include <iostream>

//реализация без учёта capacity
template <class T> class vector {
private:
  T *data_;
  size_t size_ = 0;
  size_t capacity_ = 0;

public:
  explicit vector(size_t length) : size_(length) { data_ = new T[size_]; }

  vector() : vector(0) {}

  vector(const vector<T> &other) : size_(other.Size()) {
    std::copy(other, other + other.Size(), data_);
  }

  ~vector() { delete[] data_; }

  [[nodiscard]] size_t Size() const noexcept { return size_; }

  T &at(const size_t &pos) {
    if (pos < 0 || pos >= size_)
      throw std::out_of_range("Invalid index");
    return data_[pos];
  }

  T &front() noexcept { return data_[0]; }

  T &back() noexcept { return data_[size_ - 1]; }

  T *data() noexcept { return *this; }

  bool empty() const noexcept { return size_ == 0; }

  size_t capacity() const noexcept { return capacity_; }

  void clear() noexcept {
    T *data1 = new T[0];
    delete[] data_;
    data_ = data1;
    size_ = 0;
  }

  void insert(const size_t &pos, const T &value) {
    T *data1 = new T[size_ + 1];
    std::copy(data_, data_ + pos, data1);
    data1[pos] = value;
    std::copy(data_ + pos, data_ + size_, data1 + pos);
    delete[] data_;
    data_ = data1;
  }
};

#endif // LR_5_TEMPLATE_VECTOR_H
