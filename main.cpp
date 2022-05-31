#include <iostream>
using namespace std;

#include "DoubleList.tpp"
#include "DoubleListImpl.tpp"

template <typename T>
void print(const DoubleList<T> &dl) {
  for (auto p = dl.head(Red); p != nullptr; p = p->next(Red))
    cout << p->value() << " ";
  cout << "-- ";
  for (auto p = dl.head(Blue); p != nullptr; p = p->next(Blue))
    cout << p->value() << " ";
  cout << endl;
}

int main() {
  // DoubleList<int> dl;
  // dl.insert('a', 0, 0);
  // dl.insert('b', 1, 0);
  int array[5] = {31,2,41,12,4};
  int brray[3] = {22,44,66};
  DoubleList<int> dl(array, 5);
  DoubleList<int> d2(brray, 3);
  dl.insert(11,0,3);
  print(dl);
  dl.remove(1, Blue);
  print(dl);
  cout << dl.get(2, Red)->value() << " " << dl.get(4, Blue)->value() << endl;
  dl.append(d2);
  print(dl);
  print(d2);
  // char t[] = {'x', 'y'};
  // DoubleList<char> other_dl(t, 2);
  // dl.append(other_dl);
  // print(dl);
  // print(other_dl);

  // dl.remove(1, Blue);
  // print(dl);

  // try {
  //   dl.remove(5, Red);
  //   cout << "Remove success!" << endl;
  // } catch (const InvalidIndexException &e) {
  //   cout << "Invalid Index Exception" << endl;
  // }

  // DoubleList<char> clone_dl(dl);
  // dl.insert('z', 0, 2);
  // clone_dl.insert('p', 1, 0);
  // print(dl);
  // print(clone_dl);
  return 0;
}
