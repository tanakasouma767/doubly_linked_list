#include <fstream>
#include <string> 
#include <assert.h>

struct Score { //���уf�[�^
    int score; //�X�R�A
    std::string userName; //���[�U�[��
};

class DoublyLinkedList { //�o�������X�g

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
        

        ConstIterator& operator --() { //�Q�Ɨv�f��擪�����ֈړ�
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

            current = current->prev;
            return *this;
        }

        ConstIterator operator --(int) { //�Q�Ɨv�f��擪�����ֈړ�
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

            ConstIterator temp = *this;
            --*this;
            return temp;
        }

        ConstIterator& operator ++() { //�Q�Ɨv�f�𖖔������ֈړ�
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

            current = current->next;
            return *this;
        }
        
        ConstIterator operator ++(int) { //�Q�Ɨv�f�𖖔������ֈړ�
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

            ConstIterator temp = *this;
            ++* this;
            return temp;
        }

        const Score& operator *() const { //const�ŎQ�Ɨv�f(���R�[�h�̐��э\����)���擾
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

            return current->score;
        }

        ConstIterator& operator =(const ConstIterator& itr) { //�C�e���[�^�̑��

            if (itr != *this) {
                current = itr.current;
                refList = itr.refList;
            }

            return *this;
        }

        bool operator ==(ConstIterator itr) const { //�C�e���[�^�̔�r
            return (current == itr.current) && (refList == itr.refList);
        }

        bool operator !=(ConstIterator itr) const {
            return current != (itr.current);
        }
    };

    class Iterator : public ConstIterator { //�C�e���[�^�N���X

    public:
        using ConstIterator::ConstIterator;

        Score& operator *() const { //�Q�Ɨv�f(���R�[�h�̐��э\����)�̎擾 (��const)
            assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));
            return current->score;
        }
    };

    const int getSize() const { //�f�[�^���̎擾
        return size;
    }

    //�C�e���[�^�Ŏw�肵���ʒu�Ƀ��R�[�h��}������
    int insert(const ConstIterator& i, const std::string& score, const std::string& userName) {
        
        //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
        if (i.current == NULL || i.refList != this) {
            return -1;
        }
        
        Record* record;
        record = new Record;
        record->score.score = atoi(score.c_str());
        record->score.userName = userName;

        //�����������R�[�h������ɂ��炵�đ}��
        record->prev = i.current->prev;
        record->next = i.current;

        i.current->prev->next = record;
        i.current->prev = record;

        size++;

        return 0;
    }

    // ���X�g�̖����ɐV���ȃ��R�[�h(�m�[�h)��}������
    int insert(const std::string& score, const std::string& userName) {

        Iterator it = getEnd();
        insert(it, score, userName);

        return 0;
    }

    //�e�X�g�pinsert�֐� (�C�e���[�^,��)
    int insert(const ConstIterator& itr, int n) {

        for (int i = 0; i < n; i++) {
            insert(itr, "-1", "test");
        }
        return 0;
    }

    //�e�X�g�pinsert�֐� (��)
    int insert(int n) {

        for (int i = 0; i < n; i++) {
            insert("-1", "test");
        }
        return 0;
    }

    int remove(ConstIterator i) { //�f�[�^�̍폜

        //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
        if (i.current == NULL || i.refList != this) {
            return -1;
        }

        //�폜���w�肳�ꂽ���R�[�h���ԕ��ł���ꍇ�A�폜���Ȃ�
        if (i.current == sentinel) {
            return 0;
        }

        i.current->prev->next = i.current->next;
        i.current->next->prev = i.current->prev;
        delete i.current;

        size--;

        return 0;
    }


    Iterator getHead() { //�擪�C�e���[�^�̎擾
        Iterator itr(this, sentinel->next);
        return itr;
    }

    const ConstIterator getHeadConst() const { //�擪�C�e���[�^�̎擾 const��
        ConstIterator itr(this, sentinel->next);
        return itr;
    }

    Iterator getTail() { //�Ō�̗v�f�̃C�e���[�^�̎擾
        Iterator itr = Iterator(this, sentinel->prev);
        return itr;
    }

    const ConstIterator getTailConst() const { //�Ō�̗v�f�̃C�e���[�^�̎擾 const��
        ConstIterator itr = ConstIterator(this, sentinel->prev);
        return itr;
    }

    Iterator getEnd() { //�����C�e���[�^�̎擾
        Iterator itr = Iterator(this, sentinel);
        return itr;
    }

    const ConstIterator getEndConst() const { //�����C�e���[�^�̎擾 const��
        ConstIterator itr(this, sentinel);
        return itr;
    }

    ~DoublyLinkedList() { //�f�X�g���N�^

        ConstIterator it = getHead();
        ConstIterator next = getHead();

        while (it != getEnd()) {
            next++;
            remove(it);
            it = next;
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
