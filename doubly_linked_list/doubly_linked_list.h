#include <fstream>
#include <string> 

class DoublyLinkedList { //�o�������X�g �}���Əo�͂̂ݎ���

    struct Score { //���уf�[�^
        int score; //�X�R�A
        std::string userName; //���[�U�[��
    };

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


    class Iterator { //�C�e���[�^�N���X
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

        Record* operator *() { //�Q�Ɨv�f(���R�[�h)�̎擾
            return current;
        }

        DoublyLinkedList* getList() { //�Q�ƃ��X�g�̎擾
            return refList;
        }
    };

    class ConstIterator : public Iterator { //const�C�e���[�^�N���X

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

        void operator --() { //�Q�Ɨv�f��擪�����ֈړ�
            current = current->prev;
        }

        void operator ++() { //�Q�Ɨv�f�𖖔������ֈړ�
            current = current->next;
        }

        const Record* operator *() { //const�ŎQ�Ɨv�f(���R�[�h)���擾
            return current;
        }

        void operator =(ConstIterator itr) { //�C�e���[�^�̑��
            current = itr.current;
        }

        bool operator ==(ConstIterator itr) { //�C�e���[�^�̔�r
            return current == (*itr);
        }

        bool operator !=(ConstIterator itr) {
            return current != (*itr);
        }
    };

    int getSize() { //�f�[�^���̎擾
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
    int insert(Iterator i, const std::string& score, const std::string& userName) {
        
        //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
        if (*i == NULL || i.getList() != this) {
            return -1;
        }
        
        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        //�����������R�[�h������ɂ��炵�đ}��
        record->prev = (*i)->prev;
        record->next = (*i);

        (*i)->prev->next = record;
        (*i)->prev = record;

        size++;

        return 0;
    }

    //�e�X�g�pinsert�֐� (�C�e���[�^,��)
    int insert(Iterator itr, int n) {
        std::string score = "0";
        std::string userName = "test";

        for (int i = 0; i < n; i++) {
            insert(itr, score, userName);
        }
        return 0;
    }

    //�e�X�g�pinsert�֐� (��)
    int insert(int n) {
        std::string score = "0";
        std::string userName = "test";

        for (int i = 0; i < n; i++) {
            insert(score, userName);
        }
        return 0;
    }

    int deleteRecord(Iterator i) { //�f�[�^�̍폜

        //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
        if (*i == NULL || i.getList() != this) {
            return -1;
        }

        //�폜���w�肳�ꂽ���R�[�h���ԕ��ł���ꍇ�A�폜���Ȃ�
        if (*i == sentinel) {
            return 0;
        }

        (*i)->prev->next = (*i)->next;
        (*i)->next->prev = (*i)->prev;
        delete *i;

        size--;

        return 0;
    }

    int deleteRecord(Record* record) { //�f�[�^�̍폜

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

    Iterator getHead() { //�擪�C�e���[�^�̎擾
        Record* record;
        record = sentinel->next;
        Iterator itr(this, record);
        return itr;
    }

    ConstIterator getHeadConst() { //�擪�C�e���[�^�̎擾 const��
        ConstIterator itr(this, sentinel);
        ++itr;
        return itr;
    }

    Iterator getEnd() { //�����C�e���[�^�̎擾
        Record* record;
        record = sentinel->prev;
        Iterator itr = Iterator(this, record);
        return itr;
    }

    ConstIterator getEndConst() { //�����C�e���[�^�̎擾 const��
        ConstIterator itr(this, sentinel);
        --itr;
        return itr;
    }

    int print_list() { //���X�g�̗v�f��擪���珇�ɑS�ĕW���o�͂���

        ConstIterator itr = getHeadConst();

        while (*itr != sentinel) {
            printf("%d %s\n", (*itr)->score.score, (*itr)->score.userName.c_str());
            ++itr;
        }
        return 0;
    }

    ~DoublyLinkedList() { //�f�X�g���N�^

        Record* record;
        Record* next;

        record = sentinel->next;
        next = record->next;

        while (record != sentinel) {
            deleteRecord(record);
            record = next;
            next = next->next;
        }
        delete sentinel; //�c�����ԕ����폜
    }

};