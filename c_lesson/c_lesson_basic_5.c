/*すぐわかるC/C++、塚越一雄著、1.9節*/
/*関数定義と呼び出し ~return 0;の意味~*/
#include <stdio.h>//入出力などが行える基本ライブラリ
#include <stdlib.h>//文字列からint型への変換に必要

//関数定義＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
void algo(void)//引数を持たない関数を定義する場合は()内にvoidと書く。
               //引数のvoidはcでは省略もできるが引数のチェックが行われないため明示的にvoidを指定した方が良い。
               //void algo(void):関数型 関数名(引数)
{
    printf("あいうえお\n");
}

void salgo(int n, float m)//引数を渡すことができる
{
    printf("n=%d, m=%f\n",n,m);
//[mynote:void型ならint型のようにreturnが必要ない。]
}

void elgo(int n)
{
    for(int i=0; i<n; i++)
    putchar('*');
    printf("\n");
}


int old(void)//kyotest_4.cの一部のコードを関数化
{
    char s[80];
    printf("あなたの現在の年齢は?\n=>");
    gets(s);
    return atoi(s);/*戻り値を戻す
                    f=atoi(s);
                    return f;と同じ意味*/
}


valgo(int r)//関数型にvoidも他の型も指定されていないときはint型を必ず返す。
{
    printf("%d\n",r);
    return 1024;//intを返す[mynote:返すのはint型であればなんでもよさそう。]

}

float calmany()
{
    printf("H\n");
    return 3.14;//float型なので。
}


//関数呼び出し＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
main()
{
    algo();
    salgo(10,3.14);

    elgo(1);
    elgo(2);
    elgo(3);
    elgo(4);

    int x;
    x=old();//数の入力を関数化。関数oldの本体が実行され、関数oldの戻り値が変数xに代入される。
    printf("%d\n",x);

    valgo(2);

    calmany();

    return 0;//関数mainは関数型が指定されていないので必ずint(今回は0)を返す。また、returnで返せるのは1つの値のみである。
}

