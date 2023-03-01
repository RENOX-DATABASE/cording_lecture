/*新C++言語入門、林晴比古著、Chapter1.3~1.8*/
/*C++の文字入力と名前の付け方*/

#include <iostream>
using namespace std;

int moji_input(void)
{
    int num;    //整数用変数
    char txt[80];    //文字用変数

    cout << "数値を入力する\n=>";
    cin >> num;
    cout << "ローマ字を入力する\n=>";
    cin >> txt;

    num=2*num;

    cout << "入力した数値の2培値は" << num << "、入力したローマ字は" << txt << '\n';

    return 0;
}

int Kurikaesi(void)
{
    int i, sm;
    sm=0;

    for(i=0; i<=5; i++){
        sm=sm+i;
        cout << "i=" << i << " sum=" << sm << '\n';
    }

    return 0;
}

main()
{
    moji_input();
    Kurikaesi();

    return 0;
}

/*関数等の名前の付け方
abc         正
dt100       正
3pt         誤(数字は先頭文字として使えない)
str$        誤($は使えない)
CTR         正
InputFile   正
post_file   正
vsjk_       正

その他、C++の予約語は名前に使わないようにする。
*/