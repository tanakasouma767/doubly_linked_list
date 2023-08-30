#include <fstream>
#include <string> 
#include <assert.h>

struct Score { //成績データ
    int score; //スコア
    std::string userName; //ユーザー名

    Score() {
        score = -1;
        userName = "";
    }

    Score(const std::string& score_arg, const std::string& userName_arg) {
        score = atoi(score_arg.c_str());
        userName = userName_arg;
    }
}; 

template<typename T>
class DoublyLinkedList { //双方向リスト

    struct Record { //リストのレコード(ノード)

        T data; //データ
        Record* prev; //前のノード
        Record* next; //次のノード
    };

    Record* sentinel; //番兵

    int size;

public:
    //コンストラクタ
    DoublyLinkedList();

    //渡されたレコードがリストの番兵であるかを判定する
    const bool isSentinel(const Record* record) const;


    class ConstIterator { //constイテレータクラス
    protected:
        const DoublyLinkedList<T>* refList;
        Record* current;

    public:
        friend DoublyLinkedList;
        
        //コンストラクタ
        ConstIterator();

        ConstIterator(const DoublyLinkedList* list, Record* record);
        
        //コピーコンストラクタ
        ConstIterator(const ConstIterator& itr);
        
        //参照要素を先頭方向へ移動 前置デクリメント
        ConstIterator& operator --();

        //参照要素を先頭方向へ移動 後置デクリメント
        ConstIterator operator --(int);

        //参照要素を末尾方向へ移動 前置インクリメント
        ConstIterator& operator ++();
        
        //参照要素を末尾方向へ移動 後置インクリメント
        ConstIterator operator ++(int);

        //constで参照要素(data)を取得
        const T& operator *() const;

        //イテレータの代入
        ConstIterator& operator =(const ConstIterator& itr);

        //イテレータの比較
        bool operator ==(ConstIterator itr) const;

        bool operator !=(ConstIterator itr) const;
    };


    class Iterator : public ConstIterator { //イテレータクラス

    public:
        using ConstIterator::ConstIterator;
        using ConstIterator::refList;
        using ConstIterator::current;

        //参照要素の取得 (非const)
        T& operator *() const;
        
        //参照要素を先頭方向へ移動 前置デクリメント
        Iterator& operator --();

        //参照要素を先頭方向へ移動 後置デクリメント
        Iterator operator --(int);

        //参照要素を末尾方向へ移動 前置インクリメント
        Iterator& operator ++();

        //参照要素を末尾方向へ移動 後置インクリメント
        Iterator operator ++(int);
        
    };


    //データ数の取得
    const int getSize() const;

    //イテレータで指定した位置にレコードを挿入する
    int insert(const ConstIterator& i, const T& data);

    //リストの末尾に新たなレコード(ノード)を挿入する
    int insert(const T& data);

    //データの削除
    int remove(ConstIterator i);

    //先頭イテレータの取得
    Iterator begin();

    //先頭イテレータの取得 const版
    const ConstIterator beginConst() const;

    //最後の要素のイテレータの取得
    Iterator getTail();

    //最後の要素のイテレータの取得 const版
    const ConstIterator getTailConst() const;

    //末尾イテレータの取得
    Iterator end();

    //末尾イテレータの取得 const版
    const ConstIterator endConst() const;

    //デストラクタ
    virtual ~DoublyLinkedList();
};