#include "pch.h"
#include "doubly_linked_list.inl"

namespace ListTest {

// リストは
// sentinel -> head_record -> record -> ... -> tail_record -> sentinel
// という構造で、レコードの連なりを持つ
// 
// begin()は head_record のイテレータを返す (リストが空であれば sentinel )
// getTail()は tail_record のイテレータを返す (リストが空であれば sentinel )
// end()は sentinel のイテレータを返す
// 
// insert()の引数にイテレータを指定した場合、
// イテレータの場所にあった要素を一つ後ろにずらしてレコードを挿入する
//
// イテレータを指定しなければ末尾に挿入される

//======================//
//       リスト         //
//======================//

//=================================== データ数の取得 ===================================

//  ID: 0
//  テスト項目: リストが空である場合の戻り値
//  想定する戻り値: 0
	TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
		DoublyLinkedList<Score> list;

		EXPECT_EQ(0, list.getSize());
	}


	//  ID: 1
	//  テスト項目: リスト末尾への挿入を行った際の戻り値
	//  想定する戻り値: 1
	TEST(GetDataNumTest, TestGetDataNumAfterPushEnd)
	{
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.end();

		ASSERT_EQ(0, list.insert(it, Score("0", "user")));
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
		DoublyLinkedList<Score> list;

		ASSERT_EQ(0, list.insert(Score("0", "user")));
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
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));
		ASSERT_EQ(1, list.getSize());

		DoublyLinkedList<Score>::Iterator it = list.begin();

		ASSERT_EQ(0, list.remove(it));
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
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.begin();
		list.remove(it);

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
		DoublyLinkedList<Score> list0;
		DoublyLinkedList<Score>::Iterator it0 = list0.begin();
		EXPECT_EQ(0, list0.insert(it0, Score("0", "user0")));

		//末尾への挿入
		DoublyLinkedList<Score> list1;
		DoublyLinkedList<Score>::Iterator it1 = list1.end();
		EXPECT_EQ(0, list1.insert(it1, Score("1", "user1")));
	}

	//  ID: 10
	//  テスト項目: リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
	//  想定する戻り値: 0 (正常終了)
	TEST(InsertDataTest, TestInsertDataHead) {

		DoublyLinkedList<Score> list;

		list.insert(Score("0","user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it = list.begin();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));

		EXPECT_EQ(0, list.insert(it, Score("2", "user2")));
		it = list.begin();
		EXPECT_TRUE(((*it).score == 2) && ((*it).userName == "user2"));
	}

	//  ID: 11
	//  テスト項目: リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
	//  想定する戻り値: 0 (正常終了)
	TEST(InsertDataTest, TestInsertDataEnd) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it = list.end();
		EXPECT_EQ(0, list.insert(it, Score("2", "user2")));
	}

	//  ID: 12
	//  テスト項目: リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
	//  想定する戻り値: 0 (正常終了)
	TEST(InsertDataTest, TestInsertDataNotHeadAndEnd) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		list.insert(Score("2", "user2"));

		DoublyLinkedList<Score>::ConstIterator citr = list.beginConst();
		++citr;

		EXPECT_EQ(0, list.insert(Score("3", "user3")));
	}

	//  ID: 13
	//  テスト項目: ConstIteratorを指定して挿入を行った際の挙動
	//  想定する戻り値: 0 (正常終了)
	TEST(InsertDataTest, TestInsertDataWithConstIterator) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		list.insert(Score("2", "user2"));

		//中央に挿入
		DoublyLinkedList<Score>::ConstIterator citr = list.beginConst();
		++citr;
		EXPECT_EQ(0, list.insert(citr, Score("3", "user3")));

		//先頭に挿入
		citr = list.beginConst();
		EXPECT_EQ(0, list.insert(citr, Score("4", "user4")));

		//末尾に挿入
		citr = list.endConst();
		EXPECT_EQ(0, list.insert(citr, Score("5", "user5")));
	}

	//  ID: 14
	//  テスト項目: 不正なイテレータを渡して、挿入した場合の挙動
	//  想定する戻り値: -1(異常終了)
	TEST(InsertDataTest, TestInsertDataNotWithWrongIterator) {
		//リストの参照がないイテレータを渡した場合
		DoublyLinkedList<Score> list0;
		DoublyLinkedList<Score>::Iterator it;
		EXPECT_EQ(-1, list0.insert(it, Score("0", "user")));

		//別のリストの参照を持つイテレータを渡した場合
		DoublyLinkedList<Score> list1;
		it = list0.begin();
		EXPECT_EQ(-1, list1.insert(it, Score("0", "user")));
	}

	//  ID: 15
	//  テスト項目: 非constのメソッドであるか
	//  想定する戻り値: 自動テスト化しなくてよい

	//=================================== データの削除 ===================================

	//  ID: 16
	//  テスト項目: リストが空である場合に、削除を行った際の挙動
	//  想定する戻り値: 0(正常終了)
	TEST(DeleteDataTest, TestDeleteDataWhenEmpty) {
		DoublyLinkedList<Score> list;

		//先頭イテレータを渡した場合
		DoublyLinkedList<Score>::Iterator it = list.begin();
		EXPECT_EQ(0, list.remove(it));

		//末尾イテレータを渡した場合
		it = list.end();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 17
	//  テスト項目: リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
	//  想定する戻り値: 0(正常終了)
	TEST(DeleteDataTest, TestDeleteDataHead) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it = list.begin();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 18
	//  テスト項目: リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
	//  想定する戻り値: 0(正常終了) (末尾は番兵なので何も起こらない)
	TEST(DeleteDataTest, TestDeleteDataEnd) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		ASSERT_EQ(2, list.getSize());

		DoublyLinkedList<Score>::Iterator it = list.end();
		EXPECT_EQ(0, list.remove(it));
		EXPECT_EQ(2, list.getSize());
	}

	//  ID: 19
	//  テスト項目: リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
	//  想定する戻り値: 0(正常終了)
	TEST(DeleteDataTest, TestDeleteDataNotHeadAndEnd) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		list.insert(Score("2", "user2"));

		DoublyLinkedList<Score>::ConstIterator cit = list.beginConst();
		++cit;

		EXPECT_EQ(0, list.remove(cit));
	}

	//  ID: 20
	//  テスト項目: ConstIteratorを指定して削除を行った際の挙動
	//  想定する戻り値: 0(正常終了)
	TEST(InsertDataTest, TestDeleteDataWithConstIterator) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		list.insert(Score("2", "user2"));

		//中央を削除
		DoublyLinkedList<Score>::ConstIterator citr = list.beginConst();
		++citr;
		EXPECT_EQ(0, list.remove(citr));

		//先頭を削除
		citr = list.beginConst();
		EXPECT_EQ(0, list.remove(citr));

		//末尾を削除
		citr = list.endConst();
		EXPECT_EQ(0, list.remove(citr));
	}

	//  ID: 21
	//  テスト項目: 不正なイテレータを渡して、削除した場合の挙動
	//  想定する戻り値: -1(異常終了)
	TEST(DeleteDataTest, TestDeleteDataNotWithWrongIterator) {

		//リストの参照がないイテレータを渡した場合
		DoublyLinkedList<Score> list0;
		list0.insert(Score("0", "user"));

		DoublyLinkedList<Score>::Iterator it;
		EXPECT_EQ(-1, list0.remove(it));

		//別のリストの参照を持つイテレータを渡した場合
		DoublyLinkedList<Score> list1;
		list1.insert(Score("0", "user"));

		it = list0.begin();
		EXPECT_EQ(-1, list1.remove(it));
	}

	//  ID: 22
	//  テスト項目: 非constのメソッドであるか
	//  想定する戻り値: 自動テスト化しなくてよい


	//=================================== 先頭イテレータの取得 ===================================

	//  ID: 23
	//  テスト項目: リストが空である場合に、呼び出した際の挙動
	//  想定する戻り値: Iterator ダミーノードを指すイテレータが返る
	TEST(GetHeadDataTest, TestGetHeadDataWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();
		EXPECT_TRUE(it == list.end());
	}

	//  ID: 24
	//  テスト項目: リストに要素が一つある場合に、呼び出した際の挙動
	//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataTest, TestGetHeadDataWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0","user"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 25
	//  テスト項目: リストに二つ以上の要素がある場合に、呼び出した際の挙動
	//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataTest, TestGetHeadDataWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));
	}

	//  ID: 26
	//  テスト項目: データの挿入を行った後に、呼び出した際の挙動
	//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataTest, TestGetHeadDataAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();

		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 27
	//  テスト項目: データの削除を行った後に、呼び出した際の挙動
	//  想定する戻り値: Iterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataTest, TestGetHeadDataAfterDelete) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		ASSERT_EQ(0, list.remove(it));

		it = list.begin();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));
	}

	//  ID: 28
	//  テスト項目: constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	//  想定する戻り値: 自動テスト化しなくてよい


	//=================================== 先頭コンストイテレータの取得 =============================

	//  ID: 29
	//  テスト項目: リストが空である場合に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator ダミーノードを指すイテレータが返る
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(cit == list.endConst());
	}

	//  ID: 30
	//  テスト項目: リストに要素が一つある場合に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 31
	//  テスト項目: リストに二つ以上の要素がある場合に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user0"));
	}

	//  ID: 32
	//  テスト項目: データの挿入を行った後に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataConstTest, TestGetHeadDataConstAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 33
	//  テスト項目: データの削除を行った後に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 先頭要素を指すイテレータが返る
	TEST(GetHeadDataConstTest, TestGetHeadDataConstAfterDelete) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		ASSERT_EQ(0, list.remove(cit));

		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user0"));
	}

	//  ID: 34
	//  テスト項目: constのメソッドであるか
	//  想定する戻り値: 自動テスト化しなくてよい


	//=================================== 末尾イテレータの取得 ===================================

	//  ID: 35
	//  テスト項目: リストが空である場合に、呼び出した際の挙動
	//  想定する戻り値: Iterator ダミーノードを指すイテレータが返る
	TEST(GetTailDataTest, TestGeTailDataWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(it == list.end());
	}

	//  ID: 36
	//  テスト項目: リストに要素が一つある場合に、呼び出した際の挙動
	//  想定する戻り値: Iterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataTest, TestGetTailDataWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 37
	//  テスト項目: リストに二つ以上の要素がある場合に、呼び出した際の挙動
	//  想定する戻り値: Iterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataTest, TestGetTailDataWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 1) && ((*it).userName == "user1"));
	}

	//  ID: 38
	//  テスト項目: データの挿入を行った後に、呼び出した際の挙動
	//  想定する戻り値: Iterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataTest, TestGetTailDataAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 39
	//  テスト項目: データの削除を行った後に、呼び出した際の挙動
	//  想定する戻り値: Iterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataTest, TestGetTailDataAfterDelete) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		ASSERT_EQ(0, list.remove(it));

		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));
	}

	//  ID: 40
	//  テスト項目: constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	//  想定する戻り値: 自動テスト化しなくてよい

	//=================================== 末尾コンストイテレータの取得 ==============================

	//  ID: 41
	//  テスト項目: リストが空である場合に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator ダミーノードを指すイテレータが返る
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(cit == list.endConst());
	}

	//  ID: 42
	//  テスト項目: リストに要素が一つある場合に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 43
	//  テスト項目: リストに二つ以上の要素がある場合に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 1) && ((*cit).userName == "user1"));
	}

	//  ID: 44
	//  テスト項目: データの挿入を行った後に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataConstTest, TestGetTailDataConstAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 45
	//  テスト項目: データの削除を行った後に、呼び出した際の挙動
	//  想定する戻り値: ConstIterator 末尾要素を指すイテレータが返る
	TEST(GetTailDataConstTest, TestGetTailDataConstAfterDelete) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		ASSERT_EQ(0, list.remove(cit));

		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user0"));
	}

	//  ID: 46
	//  テスト項目: constのメソッドであるか
	//  想定する戻り値: 自動テスト化しなくてよい

	//=================================================================================================
}