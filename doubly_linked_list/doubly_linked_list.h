#include <fstream>
#include <string> 
#include <assert.h>

struct Score { //成績データ
    int score; //スコア
    std::string userName; //ユーザー名
};

class DoublyLinkedList { //双方向リスト 挿入と出力のみ実装

    struct Record { //リストのレコード(ノード)

        Score score; //成績データ
        Record* prev; //前のノード
        Record* next; //次のノード
    };

    Record* sentinel; //番兵

    int size;

public:
    DoublyLinkedList() { //コンストラクタ
        sentinel = new Record;
        sentinel->prev = sentinel;
        sentinel->next = sentinel;
        size = 0;
    }

    bool isSentinel(const Record* record) const {
        return sentinel == record;
    }

    class ConstIterator { //constイテレータクラス
    protected:
        const DoublyLinkedList* refList;
        Record* current;

    public:
        
        ConstIterator() {
            refList = NULL;
            current = NULL;
        }

        ConstIterator(const DoublyLinkedList* list, Record* record) {
            refList = list;
            current = record;
        }

        
        ConstIterator(const ConstIterator& itr) {
            current = itr.getRecord();
            refList = itr.getList();
        }
        

        void operator --() { //参照要素を先頭方向へ移動
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current->prev)));

            current = current->prev;
        }
        void operator --(int) { //参照要素を先頭方向へ移動
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current->prev)));

            current = current->prev;
        }

        void operator ++() { //参照要素を末尾方向へ移動
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));

            current = current->next;
        }
        
        void operator ++(int) { //参照要素を末尾方向へ移動
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));

            current = current->next;
        }

        const Score& operator *() const { //constで参照要素(レコードの成績構造体)を取得
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));

            return current->score;
        }

        Record* getRecord() const { //constで参照要素(レコード)を取得
            return current;
        }

        const DoublyLinkedList* getList() const { //参照リストの取得
            return refList;
        }

        int operator =(ConstIterator itr) { //イテレータの代入
            current = itr.getRecord();
            refList = itr.getList();
            return 0;
        }

        bool operator ==(ConstIterator itr) const { //イテレータの比較
            return (current == itr.getRecord()) && (refList == itr.getList());
        }

        bool operator !=(ConstIterator itr) const {
            return current != (itr.getRecord());
        }
    };

    class Iterator : public ConstIterator { //イテレータクラス

    public:
        Iterator() {
            refList = NULL;
            current = NULL;
        }

        Iterator(DoublyLinkedList* list, Record* record) {
            refList = list;
            current = record;
        }

        Iterator(const Iterator& itr) {
            current = itr.getRecord();
            refList = itr.getList();
        }

        Score& operator *() const { //参照要素(レコードの成績構造体)の取得 (非const)
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));
            return current->score;
        }
    };

    int getSize() const { //データ数の取得
        return size;
    }
    
    // リストの末尾に新たなレコード(ノード)を挿入する
    int insert(const std::string& score, const std::string& userName) {

        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        record->next = sentinel;
        record->prev = sentinel->prev;

        sentinel->prev->next = record;
        sentinel->prev = record;

        size++;

        return 0;
    }

    //イテレータで指定した位置にレコードを挿入する
    int insert(ConstIterator i, const std::string& score, const std::string& userName) {
        
        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
        if (i.getRecord() == NULL || i.getList() != this) {
            return -1;
        }
        
        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        //元あったレコードを一つ後ろにずらして挿入
        record->prev = i.getRecord()->prev;
        record->next = i.getRecord();

        i.getRecord()->prev->next = record;
        i.getRecord()->prev = record;

        size++;

        return 0;
    }

    //テスト用insert関数 (イテレータ,個数)
    int insert(Iterator itr, int n) {

        for (int i = 0; i < n; i++) {
            insert(itr, "-1", "test");
        }
        return 0;
    }

    //テスト用insert関数 (個数)
    int insert(int n) {
        std::string score = "-1";
        std::string userName = "test";

        for (int i = 0; i < n; i++) {
            insert(score, userName);
        }
        return 0;
    }

    int remove(ConstIterator i) { //データの削除

        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
        if (i.getRecord() == NULL || i.getList() != this) {
            return -1;
        }

        //削除を指定されたレコードが番兵である場合、削除しない
        if (i.getRecord() == sentinel) {
            return 0;
        }

        i.getRecord()->prev->next = i.getRecord()->next;
        i.getRecord()->next->prev = i.getRecord()->prev;
        delete i.getRecord();

        size--;

        return 0;
    }

    int remove(Record* record) { //データの削除

        //イテレータのポインタが空の際の処理
        if (record == NULL) {
            return -1;
        }

        //削除を指定されたレコードが番兵である場合、削除しない
        if (record == sentinel) {
            return 0;
        }

        record->prev->next = record->next;
        record->next->prev = record->prev;
        delete record;

        size--;

        return 0;
    }

    int remove() { //データの削除 引数なし 末尾を削除

        delete(sentinel->prev);

        return 0;
    }

    Iterator getHead() { //先頭イテレータの取得
        Iterator itr(this, sentinel->next);
        return itr;
    }

    ConstIterator getHeadConst() const { //先頭イテレータの取得 const版
        ConstIterator itr(this, sentinel->next);
        return itr;
    }

    Iterator getTail() { //最後の要素のイテレータの取得
        Iterator itr = Iterator(this, sentinel->prev);
        return itr;
    }

    ConstIterator getTailConst() const { //最後の要素のイテレータの取得 const版
        ConstIterator itr = ConstIterator(this, sentinel->prev);
        return itr;
    }

    Iterator getEnd() { //末尾イテレータの取得
        Iterator itr = Iterator(this, sentinel);
        return itr;
    }

    ConstIterator getEndConst() const { //末尾イテレータの取得 const版
        ConstIterator itr(this, sentinel);
        return itr;
    }

    ~DoublyLinkedList() { //デストラクタ

        Record* record;
        Record* next;

        record = sentinel->next;
        next = record->next;

        while (record != sentinel) {
            remove(record);
            record = next;
            next = next->next;
        }

        delete sentinel; //残った番兵を削除
    }

};

int print_list(DoublyLinkedList & list) { //リストの要素を先頭から順に全て標準出力する

    DoublyLinkedList::Iterator it;

    for (it = list.getHead();  it != list.getEnd(); ++it) {
        printf("%d %s\n", (*it).score, (*it).userName.c_str());
    }
    return 0;
}
