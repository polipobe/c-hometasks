/*
в этом файле решается такая задача
дано n сотрудников и для каждого из них
у нас есть его имя и то сколько часов он уже отработал
дальше у нас есть q запросов которые сообщаю нам что
сотрудник с именем name работал в день day в час hours
когда мы насчитываем мы создаем трехмерную табличку где
в каждой ячейке мы храним работал ли сотрудник в этот день
и час, для этого нам нужен трехмерный массив его мы создаем с помощью
int***. Еще было бы удобно если бы для каждого сотрудника
у нас была бы ячейка памяти где хранилось его имя и количество дней что
он отработал, для этого мы используем void* и для каждого сотрудника
выделяем 20 байт, 4 под число часов и 16 под имя. После выполнения программы
в ответ выводится для каждого сотрудника его имя новое число часов и час в
который он работал больше всего
*/

#include <cstring>
#include <iomanip>
#include <iostream>

int main() {
  int*** cur;
  int n, mxd, hour = 24;
  std::cin >> n >> mxd;
  cur = new int** [n];
  for (int i = 0; i < n; ++i) {
    cur[i] = new int* [mxd];
    for (int j = 0; j < mxd; ++j) {
      cur[i][j] = new int [hour];
      for (int f = 0; f < hour; ++f) {
        cur[i][j][f] = 0;
      }
    }
  }
  int len_block = 20;
  void * workers = ::operator new(len_block * n);
  char* start = static_cast<char*>(workers);
  for (int i = 0; i < n; ++i) {
    int* counter = static_cast<int*>(static_cast<void*>(start + len_block * i));
    char* name = start + len_block * i + 4;
    std::cin >> std::setw(16) >> name;
    std::cin >> *counter;
  }
  int q;
  std::cin >> q;
  char* name;
  name = new char[16];
  for (int i = 0; i < q; ++i) {
    std::cin >> std::setw(16) >> name;
    int day, hours;
    std::cin >> day >> hours;
    --day;
    for (int j = 0; j < n; ++j) {
      char* wrkr = start + len_block * j + 4;
      if (std::strcmp(name, wrkr) == 0) {
        int* counter = static_cast<int*>(static_cast<void*>(start + len_block * j));
        if (cur[j][day][hours] == 0) {
          (*counter)++;
        }
        cur[j][day][hours] = 1;
      }
    }
  }
  delete[] name;
  int* best_hour;
  best_hour = new int[hour];
  for (int i = 0; i < n; ++i) {
    int* counter = static_cast<int*>(static_cast<void*>(start + len_block * i));
    char* name = start + len_block * i + 4;
    std::cout << name << " " << *counter << '\n';
    for (int j = 0; j < hour; ++j) {
      best_hour[j] = 0;
    }
    for (int j = 0; j < mxd; ++j) {
      for (int k = 0; k < hour; ++k) {
        best_hour[k] += cur[i][j][k];
      }
    }
    int mx = 0;
    for (int j = 0; j < hour; ++j) {
      if (best_hour[j] > best_hour[mx]) {
        mx = j;
      }
    }
    std::cout << mx << '\n';
  }
  delete[] best_hour;
  ::operator delete(workers);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < mxd; ++j) {
      delete [] cur[i][j];
    }
    delete []cur[i];
  }
  delete[] cur;
}

