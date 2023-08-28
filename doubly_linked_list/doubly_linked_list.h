#include <fstream>
#include <string> 
#include <assert.h>

struct Score { //���уf�[�^
    int score; //�X�R�A
    std::string userName; //���[�U�[��
};

class DoublyLinkedList { //�o�������X�g �}���Əo�͂̂ݎ���

    struct Record { //���X�g�̃��R�[�h(�m�[�h)

        Score score; //���уf�[�^
        Record* prev; //�O�̃m�[�h
        Record* next; //���̃m�[�h
    };

    Record* sentinel; //�ԕ�

    int size;

public:
    DoublyLinkedList() { //�R���X�g���N�^
        sentinel = new Record;
        sentinel->prev = sentinel;
        sentinel->next = sentinel;
        size = 0;
    }

    bool isSentinel(const Record* record) const {
        return sentinel == record;
    }

    class ConstIterator { //const�C�e���[�^�N���X
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
        

        void operator --() { //�Q�Ɨv�f��擪�����ֈړ�
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current->prev)));

            current = current->prev;
        }
        void operator --(int) { //�Q�Ɨv�f��擪�����ֈړ�
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current->prev)));

            current = current->prev;
        }

        void operator ++() { //�Q�Ɨv�f�𖖔������ֈړ�
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));

            current = current->next;
        }
        
        void operator ++(int) { //�Q�Ɨv�f�𖖔������ֈړ�
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));

            current = current->next;
        }

        const Score& operator *() const { //const�ŎQ�Ɨv�f(���R�[�h�̐��э\����)���擾
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));

            return current->score;
        }

        Record* getRecord() const { //const�ŎQ�Ɨv�f(���R�[�h)���擾
            return current;
        }

        const DoublyLinkedList* getList() const { //�Q�ƃ��X�g�̎擾
            return refList;
        }

        int operator =(ConstIterator itr) { //�C�e���[�^�̑��
            current = itr.getRecord();
            refList = itr.getList();
            return 0;
        }

        bool operator ==(ConstIterator itr) const { //�C�e���[�^�̔�r
            return (current == itr.getRecord()) && (refList == itr.getList());
        }

        bool operator !=(ConstIterator itr) const {
            return current != (itr.getRecord());
        }
    };

    class Iterator : public ConstIterator { //�C�e���[�^�N���X

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

        Score& operator *() const { //�Q�Ɨv�f(���R�[�h�̐��э\����)�̎擾 (��const)
            assert(getRecord() != NULL && getList() != NULL && !(getList()->isSentinel(current)));
            return current->score;
        }
    };

    int getSize() const { //�f�[�^���̎擾
        return size;
    }
    
    // ���X�g�̖����ɐV���ȃ��R�[�h(�m�[�h)��}������
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

    //�C�e���[�^�Ŏw�肵���ʒu�Ƀ��R�[�h��}������
    int insert(ConstIterator i, const std::string& score, const std::string& userName) {
        
        //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
        if (i.getRecord() == NULL || i.getList() != this) {
            return -1;
        }
        
        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        //�����������R�[�h������ɂ��炵�đ}��
        record->prev = i.getRecord()->prev;
        record->next = i.getRecord();

        i.getRecord()->prev->next = record;
        i.getRecord()->prev = record;

        size++;

        return 0;
    }

    //�e�X�g�pinsert�֐� (�C�e���[�^,��)
    int insert(Iterator itr, int n) {

        for (int i = 0; i < n; i++) {
            insert(itr, "-1", "test");
        }
        return 0;
    }

    //�e�X�g�pinsert�֐� (��)
    int insert(int n) {
        std::string score = "-1";
        std::string userName = "test";

        for (int i = 0; i < n; i++) {
            insert(score, userName);
        }
        return 0;
    }

    int remove(ConstIterator i) { //�f�[�^�̍폜

        //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
        if (i.getRecord() == NULL || i.getList() != this) {
            return -1;
        }

        //�폜���w�肳�ꂽ���R�[�h���ԕ��ł���ꍇ�A�폜���Ȃ�
        if (i.getRecord() == sentinel) {
            return 0;
        }

        i.getRecord()->prev->next = i.getRecord()->next;
        i.getRecord()->next->prev = i.getRecord()->prev;
        delete i.getRecord();

        size--;

        return 0;
    }

    int remove(Record* record) { //�f�[�^�̍폜

        //�C�e���[�^�̃|�C���^����̍ۂ̏���
        if (record == NULL) {
            return -1;
        }

        //�폜���w�肳�ꂽ���R�[�h���ԕ��ł���ꍇ�A�폜���Ȃ�
        if (record == sentinel) {
            return 0;
        }

        record->prev->next = record->next;
        record->next->prev = record->prev;
        delete record;

        size--;

        return 0;
    }

    int remove() { //�f�[�^�̍폜 �����Ȃ� �������폜

        delete(sentinel->prev);

        return 0;
    }

    Iterator getHead() { //�擪�C�e���[�^�̎擾
        Iterator itr(this, sentinel->next);
        return itr;
    }

    ConstIterator getHeadConst() const { //�擪�C�e���[�^�̎擾 const��
        ConstIterator itr(this, sentinel->next);
        return itr;
    }

    Iterator getTail() { //�Ō�̗v�f�̃C�e���[�^�̎擾
        Iterator itr = Iterator(this, sentinel->prev);
        return itr;
    }

    ConstIterator getTailConst() const { //�Ō�̗v�f�̃C�e���[�^�̎擾 const��
        ConstIterator itr = ConstIterator(this, sentinel->prev);
        return itr;
    }

    Iterator getEnd() { //�����C�e���[�^�̎擾
        Iterator itr = Iterator(this, sentinel);
        return itr;
    }

    ConstIterator getEndConst() const { //�����C�e���[�^�̎擾 const��
        ConstIterator itr(this, sentinel);
        return itr;
    }

    ~DoublyLinkedList() { //�f�X�g���N�^

        Record* record;
        Record* next;

        record = sentinel->next;
        next = record->next;

        while (record != sentinel) {
            remove(record);
            record = next;
            next = next->next;
        }

        delete sentinel; //�c�����ԕ����폜
    }

};

int print_list(DoublyLinkedList & list) { //���X�g�̗v�f��擪���珇�ɑS�ĕW���o�͂���

    DoublyLinkedList::Iterator it;

    for (it = list.getHead();  it != list.getEnd(); ++it) {
        printf("%d %s\n", (*it).score, (*it).userName.c_str());
    }
    return 0;
}
