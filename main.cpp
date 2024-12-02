#include <iostream>
//#include <conio.h>

using namespace std;

char arr_map[9];

bool game_over = false;
int flag = 0;
int turn = -1;
int stage = 0;

void end();
void draw();
void win();

void print() {
    system("clear");
    for (int i=0; i < 9; i++) {
        if ( i%3 == 0 && i!=0)  cout << endl;

        cout << " " << arr_map[i] << " ";
    }
    cout << endl;
}


void draw() {
    if(stage == 9) {
        cout << "НИЧЬЯ!" << endl;
    }
}

void win() {
    bool over = false;

    for(int x = 0; x<3; x++) {
        if(arr_map[x*3]==arr_map[x*3+1] && arr_map[x*3]==arr_map[x*3+2] && arr_map[x*3]!='.' ||
        arr_map[x] == arr_map[x+3] && arr_map[x]==arr_map[x+6] && arr_map[x]!='.') {
            over = true;
            break;
        }
    }

    if (arr_map[0] == arr_map[4] && arr_map[0] == arr_map[8] && arr_map[0] != '.' ||
    arr_map[2] == arr_map[4] && arr_map[2] == arr_map[6] && arr_map[2] != '.') {
        over = true;
    }

    if(over){
        if(flag == 1){
            print();
            cout << "Победили крестики!" << endl;
            game_over = true;
        }
        else if(flag == 0) {
            print();
            cout << "Победили нолики!" << endl;
            game_over = true;
        }
    }
}



int main() {


    for (int i=0; i < 9; i++) {
        arr_map[i] = '.';
    }

    while (game_over == false){

        print();
        cin >> turn;

        if(turn == 0) game_over = true;

        if (1 <= turn && turn <= 9) {
            if(arr_map[turn-1] != '.') {
                cout << "Эта ячейка уже занята!" << endl;
            }
            else {
                if (flag == 0) {
                    arr_map[turn-1] = 'X';
                    flag = 1;
                    stage += 1;
                }
                else {
                    arr_map[turn-1] = 'O';
                    flag = 0;
                    stage += 1;
                }
            }

        }
        win();
        draw();

        if(game_over == true) {
            cout << "Если хотите продолжить нажмите цифру от 1 до 9. Выйти 0: ";
            cin >> turn;
            if (turn == 0) break;

            else {
                for (int i = 0; i < 9; i++) {
                    arr_map[i] = '.';
                }
            flag = 0;
            stage = 0;
            game_over = false;
            }

        }
    }


//    getch(); //#Ждет ввода для завершения работы программы

    return 0;
}
