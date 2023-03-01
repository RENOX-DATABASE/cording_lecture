/*新C++言語入門、林晴比古著、Chapter8*/
/*関数、グローバル変数とローカル変数*/

#include <iostream>
using namespace std;

void func();//プロトタイプ宣言

int z = 123;//グローバル変数

int main ()
{
    cout << "main_z   = " << z << endl;
    func();

    return 0;
}

void func()
{
    int z = 4;//ローカル変数、グローバル変数と同じ変数が使える。
    cout << "func_z   = " << z << endl;
    cout << "grobal_z = " << ::z << endl;//::zでグローバル変数の表示を指示。
}