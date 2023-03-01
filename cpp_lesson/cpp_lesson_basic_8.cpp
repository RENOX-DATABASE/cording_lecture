/*新C++言語入門、林晴比古著、Chapter11*/
/*クラス*/

/*クラスは、構造体で使えたメンバ変数の他にメンバ関数が使えるようにしたものである。
クラスのデータは初期化することができ、コンストラクタという初期化用のメンバ関数を自作する必要がある。
コンストラクタの名前はクラスと同じ名前になる。また、コンストラクタは設定値の処理をするだけで戻り値を持たない。
""と0のように無難な値に初期化したい場合があるなら引数のないコンストラクタを合わせて記述すると良い。コンストラクタも多重定義できる。
現実には引数のないコンストラクタはデータの安定にも記述した方が良い。
private, publicの他にprotectedがある。これはprivate機能を持ち、派生クラス(既存のクラスを流用して機能追加したクラスのこと)からアクセスできる。
*/

#include <iostream>
#include <cstring>//strcpy用標準ライブラリ。https://runebook.dev/ja/docs/cpp/header/cstring
using namespace std;
//関数プロトタイプ宣言
void setname();
void setage();
void disp();

class x_man{//classを定義
private://;と間違いやすい。アクセス不可。ageとnameのデータの保護が可能。
    char name[40];
    int age;
public://;と間違いやすい。アクセス可能。
    x_man();//初期化を行うコンストラクタの宣言(引数なし)
    x_man(char *ss, int toshi);//初期化を行うコンストラクタの宣言(引数あり)
    void setname(char *ss);//名前用のメンバ関数の宣言
    void setage(int toshi);//年齢用のメンバ関数の宣言
    void disp();//cout用メンバ関数の宣言
};//;を忘れやすい。

/*クラスは以下のように簡潔に記述することができる。
class x_man{
private:
    char name[40];
    int age;
public:
    x_man::x_man() {strcpy(name, ""); age = 0;}//こういう書き方も可。

    x_man::x_man(char *ss, int toshi){
        strcpy(name, ss);
        if(toshi<0) age = 0; else age=toshi;
    }
    void setname(char *ss) {strcpy(name, ss)}
    void setage(int toshi) {if(toshi<0) age = 0; else age=toshi;}
    void disp(){
        cout << "名前:" << name << endl;
        cout << "年齢:" << age << endl;
    }
};

以下のような書き方も正しい
class sample{
    ・・・//先頭記述がない場合はprivate扱い。
    ・・・
public://公開部
    ・・・
    ・・・
private://非公開部
    ・・・
    ・・・
public://公開部
    ・・・
    ・・・
};
*/

int main()
{
    //x_man gti;//コンストラクタ未使用時

    x_man gti1("鈴木太郎",50);//初期化要素のある宣言。初期化内容
    x_man gti2;//初期化要素のない宣言
    gti1.disp();//初期化した内容をcout
    gti2.disp();

    // gti.setname("林一郎"); //非初期化設定をする。//引数なしコンストラクタ未使用時
    // gti.setage(20);
    // gti.disp();

    return 0;
}

x_man::x_man()//引数のないコンストラクタの定義
{
    strcpy(name, "");
    age = 0;
}

x_man::x_man(char *ss, int toshi)//引数のあるコンストラクタの定義
{
    strcpy(name, ss);
    if(toshi<0){
        age = 0;
    }
    else{
        age=toshi;
    }
}

void x_man::setname(char *ss)//メンバ関数の定義
{
    strcpy(name, ss);
}

void x_man::setage(int toshi)//メンバ関数の定義
{
    if(toshi<0){//負の年齢を防止。危険なデータは0と出力される。
        age = 0;
    }
    else{
        age=toshi;
    }
}

void x_man::disp()//メンバ関数の定義
{
    cout << "名前:" << name << endl;
    cout << "年齢:" << age << endl;
}

//このコードは警告が出る。文字列リテラルからchar*型への変換が非推奨な模様。自力では修正できなかった(2022/8/4)
//https://teratail.com/questions/9652
//https://bi.biopapyrus.jp/cpp/syntax/string.html