

#include<iostream>
#include"CHRONO.h"
#include"STRING.h"
using namespace std;

int main()
{
    STRING a = "HitagiHitagiHitagiHitagiHitagi";
    STRING b = "TsubasaTsubasaTsubasaTsubasaTsubasa";

    //num回交換した時間を計る準備
    int num = 10000000;
    CHRONO timer;

    //コピーで入れ替え
    cout << "Copy:";
    timer.start();
    for (int i = 0; i < num; i++) {
        STRING w = a;
        a = b;
        b = w;
    }
    timer.end();

    //ムーブで入れ替え
    cout << "Move:";
    timer.start();
    for (int i = 0; i < num; i++) {
        STRING w = move(a);
        a = move(b);
        b = move(w);
    }
    timer.end();

    system("pause>0");
}

