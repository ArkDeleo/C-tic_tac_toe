#include <iostream>
//#include <conio.h>

using namespace std;

char arr_map[9];

bool game_over = false;
int flag = 0;
int turn = -1;

void print() {
    for (int i=0; i < 9; i++) {
        if ( i%3 == 0 && i!=0)  cout << endl;

        cout << " " << arr_map[i] << " ";
    }
    cout << endl;
}



int main() {


    for (int i=0; i < 9; i++) {
        arr_map[i] = '.';
    }

    while (!game_over){
        system("clear");
        print();

        cin >> turn;
        if (0 <= turn && turn <= 8  ) {
            if (flag == 0) {
                arr_map[turn] = 'X';
                flag = 1;
            }
            else {
                arr_map[turn] = 'O';
                flag = 0;
            }
        }
    }


//    getch(); //#Ждет ввода для завершения работы программы

    return 0;
}
