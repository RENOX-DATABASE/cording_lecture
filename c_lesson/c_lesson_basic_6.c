/*すぐわかるC/C++、塚越一雄著、1.10~1.11節*/
/*配列、構造体、クラス(C++)*/

//kyotest_3.cでは文字列用の配列を扱った
//配列は同じ型の変数を多数使う場合に便利
//構造体は様々な型を1つのものとして扱いたい場合に便利
#include <stdio.h>//入出力などが行える基本ライブラリ
#include <string.h>//strcpyという文字列をコピーする関数に必要

//配列＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
falgo()
{
    int i;
    long int price[3];//[3]=[0]~[2]:[]内は要素という。

    price[0]=7589;
    price[1]=658;
    price[2]=34;

    printf("商品番号　価格\n");
    for(i=0; i<3;i++)
        printf("   %d      %4ld\n",i,price[i]);//%4ld:データを右詰めで揃えるために桁数を4桁に指定している。
    
    return 0;
}

ralgo()
{
    int f;
    long int price[]={7589, 658, 34};//宣言と同時に配列の初期化。falgo関数内のように1つ1つデータを与えるよりも楽。

    printf("商品番号　価格\n");
    for(f=0; f<3;f++)
        printf("   %d      %ld\n",f,price[f]);//%ld:桁数を指定しないと左詰めになる。

    return 0;
}

//構造体＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
struct Person{//構造体の定義。構造体Personのメンバー変数nameとage。
    char name[20];
    int age;
};//;(セミコロン)必要
jaglo()
{
    struct Person who;//構造体宣言。変数宣言と同様にwhoというstruct Person型の構造体を宣言。

    //whoの各メンバーに代入。ピリオドを使用する。
    strcpy(who.name, "Camila");//char型の配列なのでstrcpyで代入
    who.age=19;//int型の変数なので=演算子で代入

    printf("name:%s\nage:%d\n",who.name,who.age);

    return 0;
}

main()
{
    falgo();
    ralgo();

    jaglo();
    
    return 0;
}

//クラス(C++)＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
/*
★1 CとC++における構造体の宣言の仕方の違い
Cの場合
struct Person who;
C++の場合
Person who;
つまり、C++ではstruct無しに構造体の名前を型名として使える。

★2 上記の構造体をクラスで定義。
class Person{
    public:         //:(コロン)
    char name[20];
    int age;
};                  //;(セミコロン)

★3 メンバーの参照の仕方は構造体と同様にピリオドを使う。
who.age=19;

★4 C++のクラスとCの構造体の大きな違い=>メンバー関数
class Person{
    int data;
public:
    void yalgo();  //メンバー関数(メンバーの中にある関数)
};

また、C++でのメンバー関数と通常の関数を区別するため、クラス名と関数名を::で区切るように書く。
void Person::yalgo()
{
    ..............
}

★5 メンバー関数の呼び出し方
通常のメンバー参照と同様にピリオドを使う。
Person who;
who.yalgo();
*/