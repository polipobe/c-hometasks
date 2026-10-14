#include <iostream>
#include <iomanip>
#include <cstring>

void clear(char** cur) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      cur[i][j] = ' ';
    }
  }
}
bool bad(int x, int y) {
  return x < 0 || x >= 5 || y < 0 || y >= 10;
}
bool put(char** cur) {
  int x, y;
  char c;
  std::cin >> x >> y >> c;
  std::swap(x, y);
  if (bad(x, y)) {
    return false;
  }
  cur[x][y] = c;
  return true;
}
bool text(char** cur) {
  char *word;
  word = new char[20];
  int x, y;
  std::cin >> x >> y;
  std::swap(x, y);
  std::cin >> std::setw(20) >> word;
  int n = std::strlen(word);
  if (bad(x, y)) {
    delete []word;
    return false;
  }
  if (y + n > 10) {
    delete []word;
    return false;
  }
  for (int j = 0; j < n; ++j) {
    cur[x][j + y] = word[j];
  }
  delete []word;
  return true;
}
void print(char** cur) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << cur[i][j];
    }
    std::cout << '\n';
  }
}
void err() {
  std::cout << "error\n";
  return;
}
signed main() {
  char cur[20];
  char** table;
  table = new char* [5];
  for (int i = 0; i < 5; ++i) {
    table[i] = new char [10];
    for (int j = 0; j < 10; ++j) {
      table[i][j] = ' ';
    }
  }
  std::cin >> std::setw(20) >> cur;
  while (std::strcmp(cur, "quit") != 0) {
    if (std::strcmp(cur, "clear") == 0) {
      clear(table);
    }
    if (std::strcmp(cur, "put") == 0) {
      if (!put(table)) {
        err();
      }
    }
    if (std::strcmp(cur, "text") == 0) {
      if (!text(table)) {
        err();
      }
    }
    if (std::strcmp(cur, "print") == 0) {
      print(table);
    }
    std::cin >> std::setw(20) >> cur;
  }
  for (int i = 0; i < 5; ++i) {
    delete[] table[i];
  }
  delete[]table;
}

