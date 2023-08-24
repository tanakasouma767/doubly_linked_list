#include <fstream>
#include <string> 

class DoublyLinkedList { //双方向リスト 挿入と出力のみ実装

    struct Score { //成績データ
        int score; //スコア
        std::string userName; //ユーザー名
    };

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


    class Iterator { //イテレータクラス
    protected:
        DoublyLinkedList* refList;
        Record* current;

    public:
        //Record* current;

        Iterator() {
            refList = NULL;
            current = NULL;
        }

        Iterator(DoublyLinkedList* list, Record* record) {
            refList = list;
            current = record;
        }

        Record* operator *() { //参照要素(レコード)の取得
            return current;
        }

        DoublyLinkedList* getList() { //参照リストの取得
            return refList;
        }
    };

    class ConstIterator : public Iterator { //constイテレータクラス

    public:
        
        ConstIterator() {
            refList = NULL;
            current = NULL;
        }

        ConstIterator(DoublyLinkedList* list, Record* record) {
            refList = list;
            current = record;
        }

        ConstIterator(Iterator itr) {
            current = (*itr);
        }

        void operator --() { //参照要素を先頭方向へ移動
            current = current->prev;
        }

        void operator ++() { //参照要素を末尾方向へ移動
            current = current->next;
        }

        const Record* operator *() { //constで参照要素(レコード)を取得
            return current;
        }

        void operator =(ConstIterator itr) { //イテレータの代入
            current = itr.current;
        }

        bool operator ==(ConstIterator itr) { //イテレータの比較
            return current == (*itr);
        }

        bool operator !=(ConstIterator itr) {
            return current != (*itr);
        }
    };

    int getSize() { //データ数の取得
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
    int insert(Iterator i, const std::string& score, const std::string& userName) {
        
        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
        if (*i == NULL || i.getList() != this) {
            return -1;
        }
        
        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        //元あったレコードを一つ後ろにずらして挿入
        record->prev = (*i)->prev;
        record->next = (*i);

        (*i)->prev->next = record;
        (*i)->prev = record;

        size++;

        return 0;
    }

    //テスト用insert関数 (イテレータ,個数)
    int insert(Iterator itr, int n) {
        std::string score = "0";
        std::string userName = "test";

        for (int i = 0; i < n; i++) {
            insert(itr, score, userName);
        }
        return 0;
    }

    //テスト用insert関数 (個数)
    int insert(int n) {
        std::string score = "0";
        std::string userName = "test";

        for (int i = 0; i < n; i++) {
            insert(score, userName);
        }
        return 0;
    }

    int deleteRecord(Iterator i) { //データの削除

        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
        if (*i == NULL || i.getList() != this) {
            return -1;
        }

        //削除を指定されたレコードが番兵である場合、削除しない
        if (*i == sentinel) {
            return 0;
        }

        (*i)->prev->next = (*i)->next;
        (*i)->next->prev = (*i)->prev;
        delete *i;

        size--;

        return 0;
    }

    int deleteRecord(Record* record) { //データの削除

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

    Iterator getHead() { //先頭イテレータの取得
        Record* record;
        record = sentinel->next;
        Iterator itr(this, record);
        return itr;
    }

    ConstIterator getHeadConst() { //先頭イテレータの取得 const版
        ConstIterator itr(this, sentinel);
        ++itr;
        return itr;
    }

    Iterator getEnd() { //末尾イテレータの取得
        Record* record;
        record = sentinel->prev;
        Iterator itr = Iterator(this, record);
        return itr;
    }

    ConstIterator getEndConst() { //末尾イテレータの取得 const版
        ConstIterator itr(this, sentinel);
        --itr;
        return itr;
    }

    int print_list() { //リストの要素を先頭から順に全て標準出力する

        ConstIterator itr = getHeadConst();

        while (*itr != sentinel) {
            printf("%d %s\n", (*itr)->score.score, (*itr)->score.userName.c_str());
            ++itr;
        }
        return 0;
    }

    ~DoublyLinkedList() { //デストラクタ

        Record* record;
        Record* next;

        record = sentinel->next;
        next = record->next;

        while (record != sentinel) {
            deleteRecord(record);
            record = next;
            next = next->next;
        }
        delete sentinel; //残った番兵を削除
    }

};