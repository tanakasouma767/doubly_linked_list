#include <fstream>
#include <string> 
#include <assert.h>

struct Score { //���уf�[�^
    int score; //�X�R�A
    std::string userName; //���[�U�[��

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
class DoublyLinkedList { //�o�������X�g

    struct Record { //���X�g�̃��R�[�h(�m�[�h)

        T data; //�f�[�^
        Record* prev; //�O�̃m�[�h
        Record* next; //���̃m�[�h
    };

    Record* sentinel; //�ԕ�

    int size;

public:
    //�R���X�g���N�^
    DoublyLinkedList();

    //�n���ꂽ���R�[�h�����X�g�̔ԕ��ł��邩�𔻒肷��
    const bool isSentinel(const Record* record) const;


    class ConstIterator { //const�C�e���[�^�N���X
    protected:
        const DoublyLinkedList<T>* refList;
        Record* current;

    public:
        friend DoublyLinkedList;
        
        //�R���X�g���N�^
        ConstIterator();

        ConstIterator(const DoublyLinkedList* list, Record* record);
        
        //�R�s�[�R���X�g���N�^
        ConstIterator(const ConstIterator& itr);
        
        //�Q�Ɨv�f��擪�����ֈړ� �O�u�f�N�������g
        ConstIterator& operator --();

        //�Q�Ɨv�f��擪�����ֈړ� ��u�f�N�������g
        ConstIterator operator --(int);

        //�Q�Ɨv�f�𖖔������ֈړ� �O�u�C���N�������g
        ConstIterator& operator ++();
        
        //�Q�Ɨv�f�𖖔������ֈړ� ��u�C���N�������g
        ConstIterator operator ++(int);

        //const�ŎQ�Ɨv�f(data)���擾
        const T& operator *() const;

        //�C�e���[�^�̑��
        ConstIterator& operator =(const ConstIterator& itr);

        //�C�e���[�^�̔�r
        bool operator ==(ConstIterator itr) const;

        bool operator !=(ConstIterator itr) const;
    };


    class Iterator : public ConstIterator { //�C�e���[�^�N���X

    public:
        using ConstIterator::ConstIterator;
        using ConstIterator::refList;
        using ConstIterator::current;

        //�Q�Ɨv�f�̎擾 (��const)
        T& operator *() const;
        
        //�Q�Ɨv�f��擪�����ֈړ� �O�u�f�N�������g
        Iterator& operator --();

        //�Q�Ɨv�f��擪�����ֈړ� ��u�f�N�������g
        Iterator operator --(int);

        //�Q�Ɨv�f�𖖔������ֈړ� �O�u�C���N�������g
        Iterator& operator ++();

        //�Q�Ɨv�f�𖖔������ֈړ� ��u�C���N�������g
        Iterator operator ++(int);
        
    };


    //�f�[�^���̎擾
    const int getSize() const;

    //�C�e���[�^�Ŏw�肵���ʒu�Ƀ��R�[�h��}������
    int insert(const ConstIterator& i, const T& data);

    //���X�g�̖����ɐV���ȃ��R�[�h(�m�[�h)��}������
    int insert(const T& data);

    //�f�[�^�̍폜
    int remove(ConstIterator i);

    //�擪�C�e���[�^�̎擾
    Iterator begin();

    //�擪�C�e���[�^�̎擾 const��
    const ConstIterator beginConst() const;

    //�Ō�̗v�f�̃C�e���[�^�̎擾
    Iterator getTail();

    //�Ō�̗v�f�̃C�e���[�^�̎擾 const��
    const ConstIterator getTailConst() const;

    //�����C�e���[�^�̎擾
    Iterator end();

    //�����C�e���[�^�̎擾 const��
    const ConstIterator endConst() const;

    //�f�X�g���N�^
    virtual ~DoublyLinkedList();
};