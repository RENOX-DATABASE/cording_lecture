/*新C++言語入門、林晴比古著、Chapter4,5*/
/*演算子と制御文*/

#include <iostream>
# include <stdlib.h>
using namespace std;

int main()
{
    int  n, i, b;
    char a[80];

    n=5;
    for(i=0;i<n;i++){
        cout << "＊\n";
    }
    cout << "--------\n";

    while(n--){//上のfor文と同じように表示する。ただし、5,4,3,2,1の順。
        cout << "＊\n";
    }
    cout << "--------\n";

    // キーボード入力
    cout << "Input 1 or 2 => ";
    cin >> a;
    b = atoi(a);

    n=5;
    switch(b){
        case 1:
            cout << "case1,now\n";
            break;//上を表示したらswitch文を脱出する。
        case 2:
            cout << "case2,now\n";
            for (i=0;i<n;i++){
                cout << "value = " << i << endl;
                if (i==3){
                    continue;//3のときだけcontinue文でスキップする(3の時だけtrue)
                }
            cout << "Error: value is not true...\n";
            
            }
        cout << "解説\nvalue = 3の時だけtrueなのでエラーが表示されていない\n";
    }
    
    return 0;
}