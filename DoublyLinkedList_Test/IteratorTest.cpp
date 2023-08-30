#include "pch.h"
#include "doubly_linked_list.inl"


namespace IteratorTest {

//======================//
//    　 Iterator       //
//======================//


//================================ イテレータの指す要素を取得する ============================

//  ID: 0
//  テスト項目: リストの参照がない状態で呼び出した際の挙動
//  想定する戻り値: なし (Assert発生)
	TEST(GetIteratorTest, TestGetIteratorWhenNoListRef) {
		DoublyLinkedList<Score>::Iterator it;
		
		EXPECT_DEATH(*it, "Assertion failed.*");
	}

	//  ID: 1
	//  テスト項目: Iteratorから取得した要素に対して、値の代入が行えるかをチェック
	//  想定する戻り値: true
	TEST(GetIteratorTest, TestGetIteratorAndPushValue) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user");

		DoublyLinkedList<Score>::Iterator it = list.begin();

		ASSERT_FALSE(((*it).score == 100) && ((*it).userName == "user"));

		(*it).score = 100;
		(*it).userName = "user";

		EXPECT_TRUE(((*it).score == 100) && ((*it).userName == "user"));
	}

	//  ID: 2
	//  テスト項目: ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
	//  想定する戻り値: コンパイルエラー 自動テスト化しなくてよい


	//  ID: 3
	//  テスト項目: リストが空の際の、先頭イテレータに対して呼び出した際の挙動
	//  想定する戻り値: 元の要件：なし (Assert発生)
	TEST(GetIteratorTest, TestGetHeadIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.begin();

		EXPECT_DEATH(*it, "Assertion failed.*");
	}

	//  ID: 4
	//  テスト項目: 末尾イテレータに対して呼び出した際の挙動
	//  想定する戻り値: 元の要件：なし (Assert発生)
	TEST(GetIteratorTest, TestGetEndIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.end();

		EXPECT_DEATH(*it, "Assertion failed.*");
	}

	//================================ イテレータをリストの末尾に向かって一つ進める ================

	//  ID: 5
	//  テスト項目: リストの参照がない状態で呼び出した際の挙動
	//  想定する戻り値: なし (Assert発生)
	TEST(IncrementIteratorTest, TestIncrementIteratorWhenNoListRef) {
		DoublyLinkedList<Score>::Iterator it;

		EXPECT_DEATH(++it, "Assertion failed.*");
	}

	//  ID: 6
	//  テスト項目: リストが空の際の、先頭イテレータに対して呼び出した際の挙動
	//  想定する戻り値: なし (Assert発生)
	TEST(IncrementIteratorTest, TestIncrementHeadIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.begin();

		EXPECT_DEATH(++it, "Assertion failed.*");
	}

	//  ID: 7
	//  テスト項目: 末尾イテレータに対して呼び出した際の挙動
	//  想定する戻り値: なし (Assert発生)
	TEST(IncrementIteratorTest, TestIncrementEndIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user");
		DoublyLinkedList<Score>::Iterator it = list.end();

		EXPECT_DEATH(++it, "Assertion failed.*");
	}

	//  ID: 8
	//  テスト項目: リストに二つ以上の要素がある場合に呼び出した際の挙動
	//  想定する戻り値: (次の要素を指す)
	TEST(IncrementIteratorTest, TestIncrementIteratorWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it = list.begin();
		ASSERT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));

		++it;
		EXPECT_TRUE(((*it).score == 1) && ((*it).userName == "user1"));
	}

	//  ID: 9
	//  テスト項目: 前置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
	//　想定する戻り値: (次の要素を指す)
	TEST(IncrementIteratorTest, TestPreIncrementIterator) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1;
		ASSERT_TRUE(((*it0).score == 0) && ((*it0).userName == "user0"));

		it1 = ++it0;
		EXPECT_TRUE(((*it1).score == 1) && ((*it1).userName == "user1"));
		EXPECT_TRUE(((*it0).score == 1) && ((*it0).userName == "user1"));
	}

	//  ID: 10
	//  テスト項目: 後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
	//  想定する戻り値: (次の要素を指す)
	TEST(IncrementIteratorTest, TestPostIncrementIterator) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1;
		ASSERT_TRUE(((*it0).score == 0) && ((*it0).userName == "user0"));

		it1 = it0++;
		EXPECT_TRUE(((*it1).score == 0) && ((*it1).userName == "user0"));
		EXPECT_TRUE(((*it0).score == 1) && ((*it0).userName == "user1"));
	}


	//============================== イテレータをリストの先頭に向かって一つ進める ====================

	//  ID: 11
	//  テスト項目: リストの参照がない状態で呼び出した際の挙動
	//  想定する戻り値: なし (Assert発生)
	TEST(DecrementIteratorTest, TestDecrementIteratorWhenNoListRef) {
		DoublyLinkedList<Score>::Iterator it;

		EXPECT_DEATH(--it, "Assertion failed.*");
	}

	//  ID: 12
	//  テスト項目: リストが空の際の、末尾イテレータに対して呼び出した際の挙動
	//  想定する戻り値: なし (Assert発生)
	TEST(DecrementIteratorTest, TestDecrementEndIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.end();

		EXPECT_DEATH(--it, "Assertion failed.*");
	}


	//  ID: 13
	//  テスト項目: 先頭イテレータに対して呼び出した際の挙動
	//  想定する戻り値: なし (Assert発生)
	TEST(DecrementIteratorTest, TestDecrementHeadIterator) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user");
		DoublyLinkedList<Score>::Iterator it = list.begin();

		EXPECT_DEATH(--it, "Assertion failed.*");
	}

	//  ID: 14
	//  テスト項目: リストに二つ以上の要素がある場合に呼び出した際の挙動
	//  想定する戻り値: (前の要素を指す)
	TEST(DecrementIteratorTest, TestDecrementIteratorWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it = list.getTail();
		ASSERT_TRUE(((*it).score == 1) && ((*it).userName == "user1"));

		--it;
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));
	}

	//  ID: 15
	//  テスト項目: 前置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
	//  想定する戻り値:  (前の要素を指す)
	TEST(DecrementIteratorTest, TestPreDecrementIterator) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it0 = list.getTail();
		DoublyLinkedList<Score>::Iterator it1;
		ASSERT_TRUE(((*it0).score == 1) && ((*it0).userName == "user1"));

		it1 = --it0;
		EXPECT_TRUE(((*it1).score == 0) && ((*it1).userName == "user0"));
		EXPECT_TRUE(((*it0).score == 0) && ((*it0).userName == "user0"));
	}

	//  ID: 16
	//  テスト項目: 後置デクリメントを行った際の挙動( --演算子オーバーロードで実装した場合 )
	//  想定する戻り値:  (前の要素を指す)
	TEST(DecrementIteratorTest, TestPostDecrementIterator) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it0 = list.getTail();
		DoublyLinkedList<Score>::Iterator it1;
		ASSERT_TRUE(((*it0).score == 1) && ((*it0).userName == "user1"));

		it1 = it0--;
		EXPECT_TRUE(((*it1).score == 1) && ((*it1).userName == "user1"));
		EXPECT_TRUE(((*it0).score == 0) && ((*it0).userName == "user0"));
	}


	//=================================== イテレータのコピーを行う ===================================

	//  ID: 17
	//  テスト項目: ConstIteratorから、Iteratorのコピーが作成されないかをチェック
	//  想定する戻り値:  コンパイルエラー 自動テスト化しなくてよい

	//  ID: 18
	//  テスト項目: コピーコンストラクト後の値がコピー元と等しいことをチェック
	//  想定する戻り値: 
	TEST(CopyIteratorTest, TestIteratorCopyConstructor) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user");

		DoublyLinkedList<Score>::ConstIterator it0 = list.getTailConst();
		DoublyLinkedList<Score>::ConstIterator it1 = DoublyLinkedList<Score>::ConstIterator(it0);

		EXPECT_TRUE(it0 == it1);

		DoublyLinkedList<Score>::Iterator it2 = list.getTail();
		DoublyLinkedList<Score>::Iterator it3 = DoublyLinkedList<Score>::Iterator(it2);

		EXPECT_TRUE(it2 == it3);
	}

	//=================================== イテレータの代入を行う ===================================

	//  ID: 19
	//  テスト項目: IteratorにConstIteratorを代入できない事をチェック
	//  想定する戻り値: コンパイルエラー 自動テスト化しなくてよい


	//  ID: 20
	//  テスト項目: 代入後の値がコピー元と等しいことをチェック
	//  想定する戻り値: 
	TEST(AssignIteratorTest, TestAssignIteratorEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.getTail();
		ASSERT_NE(it0, it1);

		it1 = it0;
		EXPECT_EQ(it0, it1);


		DoublyLinkedList<Score> list2;
		list2.insert("0", "user0");
		list2.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it2 = list2.begin();

		it2 = it1;
	}


	//=========================== 二つのイテレータが同一のものであるか、比較を行う=========================

	//  ID: 21
	//  テスト項目: リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
	//  想定する戻り値: true
	TEST(IteratorEqualityOperatorTest, TestIteratorEqualityOperatorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.end();
		EXPECT_TRUE(it0 == it1);
	}

	//  ID: 22
	//  テスト項目: 同一のイテレータを比較した際の挙動
	//  想定する戻り値: true
	TEST(IteratorEqualityOperatorTest, TestIteratorEqualityOperatorWhenEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.begin();
		EXPECT_TRUE(it0 == it1);
	}

	//  ID: 23
	//  テスト項目: 異なるイテレータを比較した際の挙動
	//  想定する戻り値: false
	TEST(IteratorEqualityOperatorTest, TestIteratorEqualityOperatorWhenNotEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.getTail();
		EXPECT_FALSE(it0 == it1);
	}


	//============================== 二つのイテレータが異なるものであるか、比較を行う=============

	//  ID: 24
	//  テスト項目: リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
	//  想定する戻り値: false
	TEST(IteratorNotEqualityOperatorTest, TestIteratorNotEqualityOperatorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.end();
		EXPECT_FALSE(it0 != it1);
	}


	//  ID: 25
	//  テスト項目: 同一のイテレータを比較した際の挙動
	//  想定する戻り値: false
	TEST(IteratorNotEqualityOperatorTest, TestIteratorNotEqualityOperatorWhenEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.begin();
		EXPECT_FALSE(it0 != it1);
	}

	//  ID: 26
	//  テスト項目: 異なるイテレータを比較した際の挙動
	//  想定する戻り値: true
	TEST(IteratorNotEqualityOperatorTest, TestIteratorNotEqualityOperatorWhenNotEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.getTail();
		EXPECT_TRUE(it0 != it1);
	}

	//=================================================================================================
}