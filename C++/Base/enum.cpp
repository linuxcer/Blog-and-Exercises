/*************************************************************************
 *  --------->    FILE: enum.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/03/2015    TIME:07:30:32
 ************************************************************************/

#include <iostream>
using namespace std;
enum GameResult {WIN, LOSE, TIMEE, CANCEL};

int main() {
    GameResult result;
    enum GameResult omit = CANCEL;

    for (int count = WIN; count <= CANCEL; count++ ) {
        result = GameResult(count);
        if (result == omit) {
            cout << "The game was cancelled" << endl;
        } else {
            cout << "The game was played" << endl;
            if (result == WIN) {
                cout << " and we won!";
            }
            if (result == LOSE) {
                cout << "and we lost.";
            }
            cout << endl;
        }
    }
}
