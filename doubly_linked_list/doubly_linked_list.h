#include <fstream>
#include <string> 
#include <assert.h>

struct Score { //成績データ
    int score; //スコア
    std::string userName; //ユーザー名
};

class DoublyLinkedList { //双方向リスト

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
        friend DoublyLinkedList;
        
        ConstIterator() {
            refList = NULL;
            current = NULL;
        }

        ConstIterator(const DoublyLinkedList* list, Record* record) {
            refList = list;
            current = record;
        }

        
        ConstIterator(const ConstIterator& itr) {
            current = itr.current;
            refList = itr.refList;
        }
        

        ConstIterator& operator --() { //参照要素を先頭方向へ移動
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

            current = current->prev;
            return *this;
        }

        ConstIterator operator --(int) { //参照要素を先頭方向へ移動
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

            ConstIterator temp = *this;
            --*this;
            return temp;
        }

        ConstIterator& operator ++() { //参照要素を末尾方向へ移動
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

            current = current->next;
            return *this;
        }
        
        ConstIterator operator ++(int) { //参照要素を末尾方向へ移動
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

            ConstIterator temp = *this;
            ++* this;
            return temp;
        }

        const Score& operator *() const { //constで参照要素(レコードの成績構造体)を取得
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

            return current->score;
        }

        ConstIterator& operator =(const ConstIterator& itr) { //イテレータの代入

            if (itr != *this) {
                current = itr.current;
                refList = itr.refList;
            }

            return *this;
        }

        bool operator ==(ConstIterator itr) const { //イテレータの比較
            return (current == itr.current) && (refList == itr.refList);
        }

        bool operator !=(ConstIterator itr) const {
            return current != (itr.current);
        }
    };

    class Iterator : public ConstIterator { //イテレータクラス

    public:
        using ConstIterator::ConstIterator;

        Score& operator *() const { //参照要素(レコードの成績構造体)の取得 (非const)
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));
            return current->score;
        }
    };

    const int getSize() const { //データ数の取得
        return size;
    }

    //イテレータで指定した位置にレコードを挿入する
    int insert(const ConstIterator& i, const std::string& score, const std::string& userName) {
        
        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
        if (i.current == NULL || i.refList != this) {
            return -1;
        }
        
        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        //元あったレコードを一つ後ろにずらして挿入
        record->prev = i.current->prev;
        record->next = i.current;

        i.current->prev->next = record;
        i.current->prev = record;

        size++;

        return 0;
    }

    // リストの末尾に新たなレコード(ノード)を挿入する
    int insert(const std::string& score, const std::string& userName) {

        Iterator it = getEnd();
        insert(it, score, userName);

        return 0;
    }

    //テスト用insert関数 (イテレータ,個数)
    int insert(const ConstIterator& itr, int n) {

        for (int i = 0; i < n; i++) {
            insert(itr, "-1", "test");
        }
        return 0;
    }

    //テスト用insert関数 (個数)
    int insert(int n) {

        for (int i = 0; i < n; i++) {
            insert("-1", "test");
        }
        return 0;
    }

    int remove(ConstIterator i) { //データの削除

        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
        if (i.current == NULL || i.refList != this) {
            return -1;
        }

        //削除を指定されたレコードが番兵である場合、削除しない
        if (i.current == sentinel) {
            return 0;
        }

        i.current->prev->next = i.current->next;
        i.current->next->prev = i.current->prev;
        delete i.current;

        size--;

        return 0;
    }


    Iterator getHead() { //先頭イテレータの取得
        Iterator itr(this, sentinel->next);
        return itr;
    }

    const ConstIterator getHeadConst() const { //先頭イテレータの取得 const版
        ConstIterator itr(this, sentinel->next);
        return itr;
    }

    Iterator getTail() { //最後の要素のイテレータの取得
        Iterator itr = Iterator(this, sentinel->prev);
        return itr;
    }

    const ConstIterator getTailConst() const { //最後の要素のイテレータの取得 const版
        ConstIterator itr = ConstIterator(this, sentinel->prev);
        return itr;
    }

    Iterator getEnd() { //末尾イテレータの取得
        Iterator itr = Iterator(this, sentinel);
        return itr;
    }

    const ConstIterator getEndConst() const { //末尾イテレータの取得 const版
        ConstIterator itr(this, sentinel);
        return itr;
    }

    ~DoublyLinkedList() { //デストラクタ

        ConstIterator it = getHead();
        ConstIterator next = getHead();

        while (it != getEnd()) {
            next++;
            remove(it);
            it = next;
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
