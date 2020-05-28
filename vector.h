#ifndef LR_5_TEMPLATE_VECTOR_H
#define LR_5_TEMPLATE_VECTOR_H

#include <iostream>

template <class T> class vector {
private:
  T *data_;
  size_t size_ = 0;
  size_t capacity_ = 0;

  explicit vector(size_t length) : size_(length) {
    capacity_ = cap(size_);
    data_ = new T[capacity_];
  }

  //увеличение capacity
  void IncreaseCapacity(const size_t &new_cap) {
    capacity_ = cap(new_cap);
    T *data1 = new T[capacity_];
    std::copy(data_, data_ + size_, data1);
    delete[] data_;
    data_ = data1;
  }

  // вычисление capacity для значения size
  size_t cap(const size_t &size) {
    if (size <= 4)
      return size;
    else {
      size_t cap = 4;
      while (cap < size)
        cap *= 1.5;
      return cap;
    }
  }

  void invalid_index(const size_t &pos) {
    if (pos < 0 || pos >= size_)
      throw std::out_of_range("Invalid index");
  }

public:
  vector() : vector(0) {}

  vector(const vector<T> &other) : vector(other.size_) {
    std::copy(other.data_, other.data_ + size_, data_);
  }

  ~vector() { delete[] data_; }

  [[nodiscard]] size_t size() const noexcept { return size_; }

  vector<T> &operator=(const vector<T> &other) {
    if (capacity_ != other.capacity_) {
      T *data1 = new T[other.capacity_];
      delete[] data_;
      data_ = data1;
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
    std::copy(other.data_, other.data_ + other.size_, data_);
    return *this;
  }

  T &operator[](const size_t &pos) { return data_[pos]; }

  T &at(const size_t &pos) {
    invalid_index(pos);
    return data_[pos];
  }

  T &front() noexcept { return data_[0]; }

  T &back() noexcept { return data_[size_ - 1]; }

  T *data() noexcept { return *this; }

  bool empty() const noexcept { return size_ == 0; }

  void reserve(size_t new_cap) {
    // что-то резервируем толкьо если нужно увеличить capacity, исключение
    // бросает выделение новой памяти (new)
    if (capacity_ < new_cap)
      IncreaseCapacity(new_cap);
  }

  size_t capacity() const noexcept { return capacity_; }

  void clear() noexcept {
    T *data1 = new T[0];
    delete[] data_;
    data_ = data1;
    size_ = 0;
    capacity_ = 0;
  }

  void insert(const size_t &pos, const T &value) {
    invalid_index(pos);
    if (size_ == capacity_)
      IncreaseCapacity(capacity_ + 1);
    for (size_t i = size_; i > pos; i--)
      data_[i] = data_[i - 1]; // size_ != 0, т.к. мы предварительно увеличили
    // массив
    data_[pos] = value;
    size_++;
  }

  void push_back(const T &value) {
    if (size_ == capacity_)
      IncreaseCapacity(capacity_ + 1);
    data_[size_] = value;
    size_++;
  }

  void erase(const size_t &pos) {
    invalid_index(pos);
    for (size_t i = pos; i < size_ - 1; ++i)
      data_[i] = data_[i + 1];
    size_--;
    if (capacity_ != cap(size_)) {
      capacity_ = cap(size_ - 1);
      T *data1 = new T[capacity_];
      std::copy(data_, data_ + size_, data1);
      delete[] data_;
      data_ = data1;
    }
  }

  void erase(const size_t &pos1, const size_t &pos2) {
    invalid_index(pos1);
    invalid_index(pos2);
    if (pos1 > pos2)
      throw std::out_of_range(
          "Invalid index: first should be less than the second");
    else {
      for (size_t i = pos1; i < size_ - (pos2 - pos1) - 1; ++i)
        data_[i] = data_[i + pos2 - pos1 + 1];
      size_ -= pos2 - pos1 + 1;
      if (capacity_ != cap(size_)) {
        capacity_ = cap(size_);
        T *data1 = new T[capacity_];
        std::copy(data_, data_ + size_, data1);
        delete[] data_;
        data_ = data1;
      }
    }
  }

  void pop_back() {
    capacity_ = cap(size_ - 1);
    T *data1 = new T[capacity_];
    std::copy(data_, data_ + size_ - 1, data1);
    delete[] data_;
    data_ = data1;
    size_--;
  }

  void resize(const size_t &new_size) {
    size_ = new_size;
    if (capacity_ != cap(size_)) {
      capacity_ = cap(size_);
      T *data1 = new T[capacity_];
      std::copy(data_, data_ + size_, data1);
      delete[] data_;
      data_ = data1;
    }
  }

  void swap(vector<T> &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }

  void print() const {
    for (size_t i = 0; i < size_; i++)
      std::cout << data_[i] << ' ';
    std::cout << std::endl;
  }
};

#endif // LR_5_TEMPLATE_VECTOR_H
