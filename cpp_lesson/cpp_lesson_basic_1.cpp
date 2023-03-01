/*新C++言語入門、林晴比古著、Chapter1.3*/
/*C++の基本の基本*/

#include <iostream>//coutなどの入出力機能を使うための標準ライブラリ。
using namespace std;//これがないとcoutが使えない。
                    //標準ライブラリで使われている、いろいろな名前を指定できる様にするための記述。外から呼び出すときにも使える。(https://qiita.com/_EnumHack/items/430da105a541f9ecd774)

int main()//関数。C++ではメインルーチン、関数、手続き(サブルーチン)をまとめて関数と呼ぶ。
{
    cout << "Hello" << endl;//endlは改行
    cout << "World" << '\n';//'\n'も改行

    return 0;
}

/*
//C++には行の概念がない
//先頭が#の行は分割できない。
#include <iostream>
//using namespace std;で宣言しない場合は下のようにstd::でそのつど指定する必要がある。しかし、名前空間に宣言してあるコードを自分の名前空間やグローバルにすべて持ち込むことになる。

//以下の通常の記述は語の切れ目で分割できる。
int
main
(    
)
{
    std::cout << "Hello\n";

    return 0;
}
*/

