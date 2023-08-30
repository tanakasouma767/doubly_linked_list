#pragma once
#include "doubly_linked_list.h"

//DoublyLinkedList�N���X

//�R���X�g���N�^
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    sentinel = new Record;
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;
}

//�n���ꂽ���R�[�h�����X�g�̔ԕ��ł��邩�𔻒肷��
template<typename T>
const bool DoublyLinkedList<T>::isSentinel(const Record* record) const {
    return sentinel == record;
}


//ConstIterator�N���X

//�R���X�g���N�^
template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator() {
    refList = NULL;
    current = NULL;
}

template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator(const DoublyLinkedList* list, Record* record) {
    refList = list;
    current = record;
}

//�R�s�[�R���X�g���N�^
template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator(const ConstIterator& itr) {
    current = itr.current;
    refList = itr.refList;
}

//�Q�Ɨv�f��擪�����ֈړ�
template<typename T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator --() {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

    current = current->prev;
    return *this;
}

//�Q�Ɨv�f��擪�����ֈړ� ��u�f�N�������g
template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator --(int) {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

    ConstIterator temp = *this;
    --* this;
    return temp;
}

//�Q�Ɨv�f�𖖔������ֈړ� �O�u�C���N�������g
template<typename T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator ++() {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

    current = current->next;
    return *this;
}

//�Q�Ɨv�f�𖖔������ֈړ� ��u�C���N�������g
template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator ++(int) {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

    ConstIterator temp = *this;
    ++* this;
    return temp;
}

//const�ŎQ�Ɨv�f(data)���擾
template<typename T>
const T& DoublyLinkedList<T>::ConstIterator::operator *() const {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

    return current->data;
}

//�C�e���[�^�̑��
template<typename T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator =(const ConstIterator& itr) {

    if (itr != *this) {
        current = itr.current;
        refList = itr.refList;
    }

    return *this;
}

//�C�e���[�^�̔�r
template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator ==(ConstIterator itr) const {
    return (current == itr.current) && (refList == itr.refList);
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator !=(ConstIterator itr) const {
    return current != (itr.current);
}


//�C�e���[�^�N���X

//�Q�Ɨv�f�̎擾 (��const)
template<typename T>
T& DoublyLinkedList<T>::Iterator::operator *() const {

    assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

    return current->data;
}

//�Q�Ɨv�f��擪�����ֈړ� �O�u�f�N�������g
template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator --() {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

    ConstIterator::operator --();
    return *this;
}

//�Q�Ɨv�f��擪�����ֈړ� ��u�f�N�������g
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator --(int) {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current->prev)));

    Iterator temp = *this;
    --* this;
    return temp;
}

//�Q�Ɨv�f�𖖔������ֈړ� �O�u�C���N�������g
template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator ++() {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

    ConstIterator::operator ++();
    return *this;
}

//�Q�Ɨv�f�𖖔������ֈړ� ��u�C���N�������g
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator ++(int) {
    assert(current != NULL && refList != NULL && !(refList->isSentinel(current)));

    Iterator temp = *this;
    ++* this;
    return temp;
}


//DoublyLinkedList�N���X

//�f�[�^���̎擾
template<typename T>
const int DoublyLinkedList<T>::getSize() const {
    return size;
}

//�C�e���[�^�Ŏw�肵���ʒu�Ƀ��R�[�h��}������
template<typename T>
int DoublyLinkedList<T>::insert(const ConstIterator& i, const T& data) {

    //�C�e���[�^�̃|�C���^���� or �Q�Ɛ�̃��X�g�����g�ł͂Ȃ��ۂ̏���
    if (i.current == NULL || i.refList != this) {
        return -1;
    }

    Record* record;
    record = new Record;
    record->data = data;

    //�����������R�[�h������ɂ��炵�đ}��
    record->prev = i.current->prev;
    record->next = i.current;

    i.current->prev->next = record;
    i.current->prev = record;

    size++;

    return 0;
}

//�C�e���[�^�Ŏw�肵���ʒu�Ƀ��R�[�h��}������
template<typename T>
int DoublyLinkedList<T>::insert(const ConstIterator& i, const std::string& score, const std::string& userName) {

    Score data;
    data.score = atoi(score.c_str());
    data.userName = userName;
    int r = insert(i, data);

    return r;
}

// ���X�g�̖����ɐV���ȃ��R�[�h(�m�[�h)��}������
template<typename T>
int DoublyLinkedList<T>::insert(const T& data) {

    Iterator it = end();
    int r = insert(it, data);

    return r;
}

// ���X�g�̖����ɐV���ȃ��R�[�h(�m�[�h)��}������
template<typename T>
int DoublyLinkedList<T>::insert(const std::string& score, const std::string& userName) {

    Iterator it = end();
    int r = insert(it, score, userName);

    return r;
}

//�f�[�^�̍폜
template<typename T>
int DoublyLinkedList<T>::remove(ConstIterator i) {

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

//�擪�C�e���[�^�̎擾
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	Iterator itr(this, sentinel->next);
	return itr;
}

//�擪�C�e���[�^�̎擾 const��
template<typename T>
const typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::beginConst() const {
    ConstIterator itr(this, sentinel->next);
    return itr;
}

//�Ō�̗v�f�̃C�e���[�^�̎擾
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getTail() {
    Iterator itr = Iterator(this, sentinel->prev);
    return itr;
}

//�Ō�̗v�f�̃C�e���[�^�̎擾 const��
template<typename T>
const typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::getTailConst() const {
    ConstIterator itr = ConstIterator(this, sentinel->prev);
    return itr;
}

//�����C�e���[�^�̎擾
template<typename T>
typename DoublyLinkedList<T>::Iterator  DoublyLinkedList<T>::end() {
    Iterator itr = Iterator(this, sentinel);
    return itr;
}

//�����C�e���[�^�̎擾 const��
template<typename T>
const typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::endConst() const {
    ConstIterator itr(this, sentinel);
    return itr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { //�f�X�g���N�^

    Iterator it = begin();
    Iterator next = begin();

    while (it != end()) {
        next++;
        remove(it);
        it = next;
    }

    delete sentinel; //�c�����ԕ����폜
}