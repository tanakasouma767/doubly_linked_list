#pragma once
#include "doubly_linked_list.h"

//DoublyLinkedListクラス

//コンストラクタ
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    sentinel = new Record;
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    size = 0;
}

//渡されたレコードがリストの番兵であるかを判定する
template<typename T>
const bool DoublyLinkedList<T>::isSentinel(const Record* record) const {
    return sentinel == record;
}


//ConstIteratorクラス

//コンストラクタ
template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator() {
    refList = nullptr;
    current = nullptr;
}

template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator(const DoublyLinkedList* list, Record* record) {
    refList = list;
    current = record;
}

//コピーコンストラクタ
template<typename T>
DoublyLinkedList<T>::ConstIterator::ConstIterator(const ConstIterator& itr) {
    current = itr.current;
    refList = itr.refList;
}

//参照要素を先頭方向へ移動
template<typename T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator --() {
    //assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current->prev)));
    assert(current != nullptr);
    assert(refList != nullptr);
    assert(!(refList->isSentinel(current->prev)));

    current = current->prev;
    return *this;
}

//参照要素を先頭方向へ移動 後置デクリメント
template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator --(int) {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current->prev)));

    ConstIterator temp = *this;
    --* this;
    return temp;
}

//参照要素を末尾方向へ移動 前置インクリメント
template<typename T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator ++() {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current)));

    current = current->next;
    return *this;
}

//参照要素を末尾方向へ移動 後置インクリメント
template<typename T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator ++(int) {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current)));

    ConstIterator temp = *this;
    ++* this;
    return temp;
}

//constで参照要素(data)を取得
template<typename T>
const T& DoublyLinkedList<T>::ConstIterator::operator *() const {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current)));

    return current->data;
}

//イテレータの代入
template<typename T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator =(const ConstIterator& itr) {

    if (itr != *this) {
        current = itr.current;
        refList = itr.refList;
    }

    return *this;
}

//イテレータの比較
template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator ==(ConstIterator itr) const {
    return (current == itr.current) && (refList == itr.refList);
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator !=(ConstIterator itr) const {
    return current != (itr.current);
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator <=(ConstIterator itr) const {

    ConstIterator i = *this;
    ConstIterator tail = refList->getTailConst();

    while (i != tail) {
        if (i == itr) {
            return true;
        }
        ++i;
    }
    if (i == itr) {
        return true;
    }

    return false;
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator >=(ConstIterator itr) const {

    ConstIterator i = *this;
    ConstIterator begin = refList->beginConst();

    while (i != begin) {
        if (i == itr) {
            return true;
        }
        --i;
    }
    if (i == itr) {
        return true;
    }

    return false;
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator <(ConstIterator itr) const {

    ConstIterator i = *this;

    return (++i) <= itr;
}

template<typename T>
bool DoublyLinkedList<T>::ConstIterator::operator >(ConstIterator itr) const {

    ConstIterator i = *this;

    return (--i) >= itr;
}

//イテレータクラス

//参照要素の取得 (非const)
template<typename T>
T& DoublyLinkedList<T>::Iterator::operator *() const {

    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current)));

    return current->data;
}

//参照要素を先頭方向へ移動 前置デクリメント
template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator --() {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current->prev)));

    ConstIterator::operator --();
    return *this;
}

//参照要素を先頭方向へ移動 後置デクリメント
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator --(int) {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current->prev)));

    Iterator temp = *this;
    --* this;
    return temp;
}

//参照要素を末尾方向へ移動 前置インクリメント
template<typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator ++() {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current)));

    ConstIterator::operator ++();
    return *this;
}

//参照要素を末尾方向へ移動 後置インクリメント
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator ++(int) {
    assert(current != nullptr && refList != nullptr && !(refList->isSentinel(current)));

    Iterator temp = *this;
    ++* this;
    return temp;
}


//DoublyLinkedListクラス

//データ数の取得
template<typename T>
const int DoublyLinkedList<T>::getSize() const {
    return size;
}

//イテレータで指定した位置にレコードを挿入する
template<typename T>
int DoublyLinkedList<T>::insert(const ConstIterator& i, const T& data) {

    //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
    if (i.current == nullptr || i.refList != this) {
        return -1;
    }

    Record* record;
    record = new Record;
    record->data = data;

    //元あったレコードを一つ後ろにずらして挿入
    record->prev = i.current->prev;
    record->next = i.current;

    i.current->prev->next = record;
    i.current->prev = record;

    size++;

    return 0;
}

// リストの末尾に新たなレコード(ノード)を挿入する
template<typename T>
int DoublyLinkedList<T>::insert(const T& data) {

    Iterator it = end();
    int r = insert(it, data);

    return r;
}

//データの削除
template<typename T>
int DoublyLinkedList<T>::remove(ConstIterator i) {

        //イテレータのポインタが空 or 参照先のリストが自身ではない際の処理
    if (i.current == nullptr || i.refList != this) {
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

//先頭イテレータの取得
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	Iterator itr(this, sentinel->next);
	return itr;
}

//先頭イテレータの取得 const版
template<typename T>
const typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::beginConst() const {
    ConstIterator itr(this, sentinel->next);
    return itr;
}

//最後の要素のイテレータの取得
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getTail() {
    Iterator itr = Iterator(this, sentinel->prev);
    return itr;
}

//最後の要素のイテレータの取得 const版
template<typename T>
const typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::getTailConst() const {
    ConstIterator itr = ConstIterator(this, sentinel->prev);
    return itr;
}

//末尾イテレータの取得
template<typename T>
typename DoublyLinkedList<T>::Iterator  DoublyLinkedList<T>::end() {
    Iterator itr = Iterator(this, sentinel);
    return itr;
}

//末尾イテレータの取得 const版
template<typename T>
const typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::endConst() const {
    ConstIterator itr(this, sentinel);
    return itr;
}


template<typename T>
bool compare0(const T& a, const T& b) {
    return a < b;
}

template<typename T>
bool compare1(const T& a, const T& b) {
    return a >= b;
}

template<typename T>
int DoublyLinkedList<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;

    return 0;
}

#include <iostream>
template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::partition(Iterator left, Iterator right) {
    Iterator i = left;
    Iterator j = right;
    --j;

    std::cout << "i = " << *i << ", j = " << *j << std::endl;;

    while (i <= j) {
        while (compare0(*i, *right)) {
            ++i;
            std::cout << "i = " << *i << std::endl;
        }
        while (compare1(*j, *right) && j >= i) {
            --j;
            std::cout << "j = " << *j << std::endl;
        }
        if (i < j) {
            swap(*i, *j);
        }
    }
    swap(*i, *right);

    return i;
}

template<typename T>
int DoublyLinkedList<T>::quicksort(Iterator left, Iterator right) {

    Iterator pivot = partition(left, right);

    Iterator pivot_left = pivot;
    --pivot_left;
    Iterator pivot_right = pivot;
    ++pivot_right;

    quicksort(left, pivot_left);
    quicksort(pivot_right, right);

    return 0;
}

template<typename T>
int DoublyLinkedList<T>::sort(int order, int key) {

    quicksort(begin(), getTail());

    return 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { //デストラクタ

    Iterator it = begin();
    Iterator next = begin();

    while (it != end()) {
        next++;
        remove(it);
        it = next;
    }

    delete sentinel; //残った番兵を削除
}