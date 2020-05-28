#include "vector.h"
#include <iostream>

int main() {
  //тип - int, конструктор по умолчанию, методы size(), capacity(), push_back()
  std::cout << "Тип - int, конструктор по умолчанию, методы size(), "
               "capacity(), push_back()"
            << std::endl;
  vector<int> vec1;
  vec1.push_back(10);
  vec1.push_back(20);
  vec1.print();
  std::cout << "If size<=4: size = " << vec1.size()
            << ", capacity = " << vec1.capacity() << std::endl;
  for (size_t i = 3; i < 8; i++)
    vec1.push_back(i * 10);
  vec1.print();
  std::cout << "If size>4: size = " << vec1.size()
            << ", capacity = " << vec1.capacity() << std::endl;
  std::cout << std::endl;

  // тип - double, конструктор по умолчанию
  std::cout << "Тип - double, конструктор по умолчанию" << std::endl;
  vector<double> d1;
  for (size_t i = 0; i < 6; i++)
    d1.push_back(i * 0.1);
  d1.print();
  // тип - double, конструктор копирования
  std::cout << "Тип - double, конструктор копирования от предыдущего вектора"
            << std::endl;
  vector<double> d2(d1);
  d2.print();
  std::cout << std::endl;

  // оператор присваивания
  std::cout << "Оператор присваивания (перед этим push_back(3.1416))" <<
  std::endl;
  d2.push_back(3.1416);
  d1 = d2;
  d1.print();
  std::cout << std::endl;

  // получение эелемента по позиции, первый и последний элементы
  std::cout << "Получение эелемента по позиции" << std::endl;
  try {
    for (size_t i = 0; i <= d1.size(); i++)
      std::cout << "Элемент №" << i << " - " << d1.at(i) << std::endl;
  } catch (std::exception &d) {
    std::cout << "Поймали выход за границы" << std::endl;
    std::cout << d.what() << std::endl;
  }
  std::cout << "Первый элемент - " << d1.front() << std::endl;
  std::cout << "Последний элемент - " << d1.back() << std::endl;
  std::cout << std::endl;

  // проверка метода empty() и clear() (после очищения вектор становится пустым)
  std::cout << "Проверка метода empty() и clear() (после очищения вектор "
               "становится пустым)"
            << std::endl;
  if (!d1.empty())
    std::cout << "Данный массив не пустой" << std::endl;
  d1.clear();
  if (d1.empty())
    std::cout << "Данный массив пустой после clear()" << std::endl;
  std::cout << std::endl;

  // вставка элементов
  std::cout << "Вставка элементов в вектор:" << std::endl;
  vec1.print();
  vec1.insert(4, 2222);
  std::cout << "Вектор должен быть после вставки на 4 позицию 2222:\n/10 20 "
               "30 "
               "40 2222 50 60 70/"
            << std::endl;
  vec1.print();
  std::cout << std::endl;

  // удавление элементов
  std::cout << "Удаление элелемента в конце" << std::endl;
  vec1.pop_back();
  vec1.print();
  std::cout << "Удаление с позиции 3" << std::endl;
  vec1.erase(3);
  std::cout << "Вектор должен быть после удаления:\n/10 "
               "20 30 2222 50 60/"
            << std::endl;
  vec1.print();
  std::cout << "size = " << vec1.size() << ", capacity = " << vec1.capacity()
            << std::endl;
  std::cout << "Удаление с позиций 1-2-3" << std::endl;
  vec1.erase(1, 3);
  std::cout << "Вектор должен быть после удаления:\n/10"
               " 50 60/"
            << std::endl;
  vec1.print();
  std::cout << "size = " << vec1.size() << ", capacity = " << vec1.capacity()
            << ", то есть capacity "
               "уменьшился"
            << std::endl;
  std::cout << std::endl;

  // resize()
  std::cout << "resize()" << std::endl;
  std::cout << "До resize: size = " << d1.size()
            << ", capacity = " << d1.capacity() << std::endl;
  d1.resize(26);
  std::cout << "После resize: size = " << d1.size()
            << ", capacity = " << d1.capacity() << std::endl;
  d1.clear();
  d1.push_back(144.90);
  std::cout << std::endl;

  // swap()
  std::cout << "swap()" << std::endl;
  std::cout << "До swap" << std::endl;
  d1.print();
  d2.print();
  std::cout << "После swap" << std::endl;
  d1.swap(d2);
  d1.print();
  d2.print();
}