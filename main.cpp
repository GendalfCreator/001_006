#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//02. Функция для склеивания двух файлов в один с использованием выделенной памяти
void Combine(string path0, string path1) {
  string pathcombine = "filecombine.txt";
  fstream file0, file1, filecombine;
  string stringboofer;
  string* combineboofer;

  filecombine.open(pathcombine, fstream::out);
  file0.open(path0, fstream::in);
  file1.open(path1, fstream::in);

  if (!file0.is_open() || !file1.is_open() || !filecombine.is_open()) {
      cout << "Закрыто" << endl;
    }
  else {
      int i = 0;

      while (!file0.eof() && !file1.eof()) {
          getline(file0, stringboofer);
          i++;
          getline(file1, stringboofer);
          i++;
        }

      file0.close();
      file1.close();

      combineboofer = new string[i];

      file0.open(path0, fstream::in);
      file1.open(path1, fstream::in);

      i = 0;
      while (!file0.eof()) {
          stringboofer = "";
          getline(file0, combineboofer[i]);
          i++;
        }
      while (!file1.eof()) {
          stringboofer = "";
          getline(file1, combineboofer[i]);
          i++;
        }

      for(int j = 0; j < i; j++) {
          filecombine << combineboofer[j] << "\n";
        }

      delete[] combineboofer;
    }

  filecombine.close();
  file0.close();
  file1.close();
}

int main()
{

//01. Создание двух файлов с данными
  string path0 = "file0.txt", path1 = "file1.txt";
  fstream file0, file1;

  file0.open(path0, fstream::out);
  file1.open(path1, fstream::out);

  if (!file0.is_open() || !file1.is_open()) {
      cout << "Закрыто" << endl;
    }
  else {
      for (int i = 1; i < 6; i++) {
          file0 << "Файл 0. Строка с символами " << i << endl;
        }
      for (int i = 1; i < 6; i++) {
          file1 << "Файл 1. Строка с символами " << i << endl;
        }
    }

  file0.close();
  file1.close();

  Combine(path0, path1);

  return 0;
}
