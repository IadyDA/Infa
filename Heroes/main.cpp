#include <iostream>
#include "build.h"
using namespace std;

int main()
{
    Tavern t;
    int coins = 600, stones = 30;
    if (coins >= t.get_gold() && stones >= t.get_stone()) {
        FortificationsUp fUp;
    }
    Well w;
    Castle c;
    cout << c.get_gold() << endl;

    return 0;
}

