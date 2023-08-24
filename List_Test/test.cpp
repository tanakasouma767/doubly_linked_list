#include "pch.h"
#include "doubly_linked_list.h"

// リストは
// sentinel -> head_record -> record -> ... -> end_record -> sentinel
// というレコードの連なりを持つ
// 
// getHead()は head_record のポインタを返す
// getEnd()は end_record のポインタを返す
// 
// insert()の引数にイテレータを指定した場合、
// 元の場所にあった要素を一つ後ろにずらしてレコードを挿入する
//
// 挿入する要素を末尾にしたい場合、イテレータを指定しなければ末尾に挿入される

//======================//
//       リスト         //
//======================//

//=================================== データ数の取得 ===================================

//  ID: 0
//  テスト項目: リストが空である場合の戻り値
//  想定する戻り値: 0
TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
	DoublyLinkedList list;

	EXPECT_EQ(0, list.getSize());
}


//  ID: 1
//  テスト項目: リスト末尾への挿入を行った際の戻り値
//  想定する戻り値: 1
TEST(GetDataNumTest, TestGetDataNumAfterPushEnd)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getEnd();

	EXPECT_EQ(0, list.insert(it, 1));
	EXPECT_EQ(1, list.getSize());
}


//  ID: 2
//  テスト項目: リスト末尾への挿入が失敗した際の戻り値
//  想定する戻り値: 0
TEST(GetDataNumTest, TestGetDataNumAfterPushEndFailed)
{
	//省略
}


//  ID: 3
//  テスト項目: データの挿入を行った際の戻り値
//  想定する戻り値: 1
TEST(GetDataNumTest, TestGetDataNumAfterPush)
{
	DoublyLinkedList list;
	
	EXPECT_EQ(0, list.insert(1));
	EXPECT_EQ(1, list.getSize());
}


//  ID: 4
//  テスト項目: データの挿入に失敗した際の戻り値
//  想定する戻り値: 0
TEST(GetDataNumTest, TestGetDataNumAfterPushHeadFailed)
{
	//省略
}


//  ID: 5
//  テスト項目: データの削除を行った際の戻り値
//  想定する戻り値: 0
TEST(GetDataNumTest, TestGetDataNumAfterDelete)
{
	DoublyLinkedList list;
	list.insert(1);

	DoublyLinkedList::Iterator it = list.getEnd();

	EXPECT_EQ(0, list.deleteRecord(it));
	EXPECT_EQ(0, list.getSize());
}


//  ID: 6
//  テスト項目: データの削除が失敗した際の戻り値
//  想定する戻り値: 1
TEST(GetDataNumTest, TestGetDataNumAfterDeleteFailed)
{
	//省略
}


//  ID: 7
//  テスト項目: リストが空である場合に、データの削除を行った際の戻り値
//  想定する戻り値: 0
TEST(GetDataNumTest, TestGetDataNumAfterDeleteWhenEmpty)
{
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getEnd();
	list.deleteRecord(it);

	EXPECT_EQ(0, list.getSize());
}


//  ID: 8
//  テスト項目: constのメソッドであるか　自動テスト化しなくてよい
//  想定する戻り値: 



//=================================== データの挿入 ===================================

//  ID: 9
//  テスト項目: リストが空である場合に、挿入した際の挙動
//  想定する戻り値: 0 (正常終了)
TEST(InsertDataTest, TestInsertDataWhenEmpty) {
	//先頭への挿入
	DoublyLinkedList list0;
	DoublyLinkedList::Iterator it0 = list0.getHead();
	std::string score0 = "0";
	std::string userName0 = "user0";
	EXPECT_EQ(0, list0.insert(it0, score0, userName0));

	//末尾への挿入
	DoublyLinkedList list1;
	DoublyLinkedList::Iterator it1 = list1.getEnd();
	std::string score1 = "1";
	std::string userName1 = "user1";
	EXPECT_EQ(0, list1.insert(it1, score1, userName1));
}

//  ID: 10
//  テスト項目: リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
//  想定する戻り値: 0 (正常終了)
TEST(InsertDataTest, TestInsertDataHead) {

	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getHead();
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(0, list.insert(it, score, userName));
}

//  ID: 11
//  テスト項目: リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
//  想定する戻り値: 0 (正常終了)
TEST(InsertDataTest, TestInsertDataEnd) {
	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getEnd();
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(0, list.insert(it, score, userName));
}

//  ID: 12
//  テスト項目: リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
//  想定する戻り値: 0 (正常終了)
TEST(InsertDataTest, TestInsertDataNotHeadAndEnd) {
	DoublyLinkedList list;

	list.insert(3);

	DoublyLinkedList::ConstIterator citr = list.getHeadConst();
	++citr;
	std::string score = "0";
	std::string userName = "user";

	EXPECT_EQ(0, list.insert(score, userName));
}

//  ID: 13
//  テスト項目: ConstIteratorを指定して挿入を行った際の挙動
//  想定する戻り値: 0 (正常終了)
TEST(InsertDataTest, TestInsertDataWithConstIterator) {
	DoublyLinkedList list;

	list.insert(3);

	//中央に挿入
	DoublyLinkedList::ConstIterator citr = list.getHeadConst();
	++citr;
	std::string score0 = "0";
	std::string userName0 = "user0";
	EXPECT_EQ(0, list.insert(citr, score0, userName0));

	//先頭に挿入
	citr = list.getHeadConst();
	std::string score1 = "1";
	std::string userName1 = "user1";
	EXPECT_EQ(0, list.insert(citr, score1, userName1));

	//末尾に挿入
	citr = list.getEndConst();
	std::string score2 = "2";
	std::string userName2 = "user2";
	EXPECT_EQ(0, list.insert(citr, score2, userName2));
}

//  ID: 14
//  テスト項目: 不正なイテレータを渡して、挿入した場合の挙動
//  想定する戻り値: -1(異常終了)
TEST(InsertDataTest, TestInsertDataNotWithWrongIterator) {
	//リストの参照がないイテレータを渡した場合
	DoublyLinkedList list0;
	DoublyLinkedList::Iterator it;
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(-1, list0.insert(it, score, userName));

	//別のリストの参照を持つイテレータを渡した場合
	DoublyLinkedList list1;
	it = list0.getHead();
	EXPECT_EQ(-1, list1.insert(it, score, userName));
}

//  ID: 15
//  テスト項目: 非constのメソッドであるか
//  想定する戻り値: 自動テスト化しなくてよい

//=================================== データの削除 ===================================

//  ID: 16
//  テスト項目: リストが空である場合に、削除を行った際の挙動
//  想定する戻り値: 0(正常終了)
TEST(DeleteDataTest, TestDeleteDataWhenEmpty) {
	DoublyLinkedList list;

	//先頭イテレータを渡した場合
	DoublyLinkedList::Iterator it = list.getHead();
	EXPECT_EQ(0, list.deleteRecord(it));

	//末尾イテレータを渡した場合
	it = list.getEnd();
	EXPECT_EQ(0, list.deleteRecord(it));
}

//  ID: 17
//  テスト項目: リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
//  想定する戻り値: 0(正常終了)
TEST(DeleteDataTest, TestDeleteDataHead) {
	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getHead();
	EXPECT_EQ(0, list.deleteRecord(it));
}

//  ID: 18
//  テスト項目: リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
//  想定する戻り値: 0(正常終了)
TEST(DeleteDataTest, TestDeleteDataEnd) {
	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getEnd();
	EXPECT_EQ(0, list.deleteRecord(it));
}

//  ID: 19
//  テスト項目: リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
//  想定する戻り値: 0(正常終了)
TEST(DeleteDataTest, TestDeleteDataNotHeadAndEnd) {
	DoublyLinkedList list;

	list.insert(3);

	DoublyLinkedList::ConstIterator cit = list.getHeadConst();
	++cit;

	EXPECT_EQ(0, list.deleteRecord(cit));
}

//  ID: 20
//  テスト項目: ConstIteratorを指定して削除を行った際の挙動
//  想定する戻り値: 0(正常終了)
TEST(InsertDataTest, TestDeleteDataWithConstIterator) {
	DoublyLinkedList list;

	list.insert(3);

	//中央を削除
	DoublyLinkedList::ConstIterator citr = list.getHeadConst();
	++citr;
	EXPECT_EQ(0, list.deleteRecord(citr));

	//先頭を削除
	citr = list.getHeadConst();
	EXPECT_EQ(0, list.deleteRecord(citr));

	//末尾を削除
	citr = list.getEndConst();
	EXPECT_EQ(0, list.deleteRecord(citr));
}

//  ID: 21
//  テスト項目: 不正なイテレータを渡して、削除した場合の挙動
//  想定する戻り値: -1(異常終了)
TEST(DeleteDataTest, TestDeleteDataNotWithWrongIterator) {
	
	//リストの参照がないイテレータを渡した場合
	DoublyLinkedList list0;
	list0.insert(1);

	DoublyLinkedList::Iterator it;
	EXPECT_EQ(-1, list0.deleteRecord(it));

	//別のリストの参照を持つイテレータを渡した場合
	DoublyLinkedList list1;
	list1.insert(1);

	it = list0.getHead();
	EXPECT_EQ(-1, list1.deleteRecord(it));
}

//  ID: 22
//  テスト項目: 非constのメソッドであるか
//  想定する戻り値: 自動テスト化しなくてよい


//=================================== 先頭イテレータの取得 ===================================

//  ID: 23
//  テスト項目: リストが空である場合に、呼び出した際の挙動
//  想定する戻り値: Iterator ダミーノードを指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataWhenEmpty) {
	DoublyLinkedList list;
	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 24
//  テスト項目: リストに要素が一つある場合に、呼び出した際の挙動
//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataWhenOneRecord) {
	DoublyLinkedList list;
	list.insert(1);

	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 25
//  テスト項目: リストに二つ以上の要素がある場合に、呼び出した際の挙動
//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataWhenMoreThanTwo) {
	DoublyLinkedList list;
	list.insert(2);

	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 26
//  テスト項目: データの挿入を行った後に、呼び出した際の挙動
//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataAfterPush) {
	DoublyLinkedList list;
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(0, list.insert(score, userName));

	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 27
//  テスト項目: データの削除を行った後に、呼び出した際の挙動
//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataAfterDelete) {
	DoublyLinkedList list;
	list.insert(2);

	DoublyLinkedList::Iterator it;
	it = list.getHead();
	EXPECT_EQ(0, list.deleteRecord(it));

	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 28
//  テスト項目: constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
//  想定する戻り値: 自動テスト化しなくてよい


//=================================== 先頭コンストイテレータの取得 =============================

//  ID: 29
//  テスト項目: リストが空である場合に、呼び出した際の挙動
//  想定する戻り値: ConstIterator ダミーノードを指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataConstWhenEmpty) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 30
//  テスト項目: リストに要素が一つある場合に、呼び出した際の挙動
//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataConstWhenOneRecord) {
	DoublyLinkedList list;
	list.insert(1);

	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 31
//  テスト項目: リストに二つ以上の要素がある場合に、呼び出した際の挙動
//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataConstWhenMoreThanTwo) {
	DoublyLinkedList list;
	list.insert(2);

	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 32
//  テスト項目: データの挿入を行った後に、呼び出した際の挙動
//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataConstAfterPush) {
	DoublyLinkedList list;
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(0, list.insert(score, userName));

	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 33
//  テスト項目: データの削除を行った後に、呼び出した際の挙動
//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
TEST(GetHeadDataTest, TestGetHeadDataConstAfterDelete) {
	DoublyLinkedList list;
	list.insert(2);

	DoublyLinkedList::ConstIterator it;
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
	EXPECT_EQ(0, list.deleteRecord(it));

	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 34
//  テスト項目: constのメソッドであるか
//  想定する戻り値: 自動テスト化しなくてよい


//=================================== 末尾イテレータの取得 ===================================

//  ID: 35
//  テスト項目: 
//  想定する戻り値: 

//  ID: 36
//  テスト項目: 
//  想定する戻り値: 

//  ID: 37
//  テスト項目: 
//  想定する戻り値: 

//  ID: 38
//  テスト項目: 
//  想定する戻り値: 

//  ID: 39
//  テスト項目: 
//  想定する戻り値: 

//  ID: 40
//  テスト項目: 
//  想定する戻り値: 

//=================================== 末尾コンストイテレータの取得 ==============================

//  ID: 41
//  テスト項目: 
//  想定する戻り値: 

//  ID: 42
//  テスト項目: 
//  想定する戻り値: 

//  ID: 43
//  テスト項目: 
//  想定する戻り値: 

//  ID: 44
//  テスト項目: 
//  想定する戻り値: 

//  ID: 45
//  テスト項目: 
//  想定する戻り値: 

//  ID: 46
//  テスト項目: 
//  想定する戻り値: 

//=================================================================================================


//======================//
//    　 Iterator       //
//======================//


//================================ イテレータの指す要素を取得する ============================

//  ID: 0
//  テスト項目: 
//  想定する戻り値: 

//  ID: 1
//  テスト項目: 
//  想定する戻り値: 

//  ID: 2
//  テスト項目: 
//  想定する戻り値: 

//  ID: 3
//  テスト項目: 
//  想定する戻り値: 

//  ID: 4
//  テスト項目: 
//  想定する戻り値: 

//================================ イテレータをリストの末尾に向かって一つ進める ================

//  ID: 5
//  テスト項目: 
//  想定する戻り値: 

//  ID: 6
//  テスト項目: 
//  想定する戻り値: 

//  ID: 7
//  テスト項目: 
//  想定する戻り値: 

//  ID: 8
//  テスト項目: 
//  想定する戻り値: 

//  ID: 9
//  テスト項目: 

//  ID: 10
//  テスト項目: 
//  想定する戻り値:


//============================== イテレータをリストの先頭に向かって一つ進める ====================

//  ID: 11
//  テスト項目: 
//  想定する戻り値: 

//  ID: 12
//  テスト項目: 
//  想定する戻り値: 

//  ID: 13
//  テスト項目: 
//  想定する戻り値: 

//  ID: 14
//  テスト項目: 

//  ID: 15
//  テスト項目: 
//  想定する戻り値: 

//  ID: 16
//  テスト項目: 
//  想定する戻り値: 


//=================================== イテレータのコピーを行う ===================================

//  ID: 17
//  テスト項目: 
//  想定する戻り値: 

//  ID: 18
//  テスト項目: 
//  想定する戻り値: 


//=================================== イテレータの代入を行う ===================================

//  ID: 19
//  テスト項目: 

//  ID: 20
//  テスト項目: 
//  想定する戻り値: 


//=========================== 二つのイテレータが同一のものであるか、比較を行う=========================

//  ID: 21
//  テスト項目: 
//  想定する戻り値: 

//  ID: 22
//  テスト項目: 
//  想定する戻り値: 

//  ID: 23
//  テスト項目: 
//  想定する戻り値: 


//============================== 二つのイテレータが異なるものであるか、比較を行う=============

//  ID: 24
//  テスト項目: 

//  ID: 25
//  テスト項目: 
//  想定する戻り値: 

//  ID: 26
//  テスト項目: 
//  想定する戻り値: 

