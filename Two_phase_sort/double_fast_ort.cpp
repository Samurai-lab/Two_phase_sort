
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
char fileMain[] = "main.txt";
char fileBuf1[] = "buf1.txt";
char fileBuf2[] = "buf2.txt";

// сортировка 
void Simple_Merging_Sort(size_t size_arr) {
    int a1, a2, k, i, j, tmp;
    k = 1;
    while (k < size_arr) 
    {
        ifstream fin_main(fileMain);
        ofstream fout_buf1(fileBuf1);
        ofstream fout_buf2(fileBuf2);
        fin_main >> a1;
        while (!fin_main.eof()) {
            for (i = 0; i < k && !fin_main.eof(); i++) {
                fout_buf1 << a1 << " ";
                fin_main >> a1;
            }
            for (j = 0; j < k && !fin_main.eof(); j++) {
                    fout_buf2 << a1 << " ";
                    fin_main >> a1;
            }
        }
        fin_main.close();
        fout_buf1.close();
        fout_buf2.close();

        ofstream fout_main(fileMain);
        ifstream fin_buf1(fileBuf1);
        ifstream fin_buf2(fileBuf2);
        if (!fin_buf1.eof()) fin_buf1 >> a1; 
        if (!fin_buf2.eof()) fin_buf2 >> a2;

        while (!fin_buf1.eof() && !fin_buf2.eof()) {
            i = j = 0;
            while (i < k && j < k && !fin_buf1.eof() && !fin_buf2.eof()) {
                if (a1 < a2) {
                    fout_main << a1 << " ";
                    fin_buf1 >> a1;
                    i++;
                }
                else {
                    fout_main << a2 << " ";
                    fin_buf2 >> a2;
                    j++;
                }
            }
            while (i < k && !fin_buf1.eof()) {
                fout_main << a1 << " ";
                fin_buf1 >> a1;
                i++;
            }
            while (j < k && !fin_buf2.eof()) {
                fout_main << a2 << " ";
                fin_buf2 >> a2;
                j++;
            }
        }
        while (!fin_buf1.eof()) {
            fout_main << a1 << " ";
            fin_buf1 >> a1;
        }
        while (!fin_buf2.eof()) {
            fout_main << a2 << " ";
            fin_buf2 >> a2;
        }
        fout_main.close();
        fin_buf1.close();
        fin_buf2.close();
        k *= 2;
    }
    remove(fileBuf1);
    remove(fileBuf2);
}

// Создание файла из size_arr элементов
void create_file(char* filename, size_t size_arr)
{
    ofstream fout(filename);
    cout << "Создаем файл..." << endl;
    for (int i = 1; i <= size_arr; i++)
    {
        fout << rand() % 100 - 50 << " ";
    }
    cout << "Файл успешно создан!" << endl;
    fout.close();
}
// Вывод содержимого файла в консоль
void show_file(char* filename)
{
    int i;
    cout << "Вывод файла: " << endl;
    ifstream fin(filename);
    fin >> i;
    while (!fin.eof())
    {
        cout << i << " ";
        fin >> i;
    }
    cout << endl;
    cout << "\t------\t" << endl;
    fin.close();
}

int main()
{
    setlocale(LC_ALL, ".1251");
    srand(time(NULL));
    size_t size_arr = 0;
    cout << "Введите кол-во элементов в файле: ";
    cin >> size_arr;

    create_file(fileMain, size_arr);
    show_file(fileMain);
    Simple_Merging_Sort(size_arr);
    show_file(fileMain);
    return 0;
}