#include "pch.h"
#include "doubly_linked_list.inl"
#include "ManualTest.h"

//======================//
//       リスト         //
//======================//

namespace ListTest {

//=================================== データ数の取得 ===================================
	//  ID: 8
	//  テスト項目: constのメソッドであるか
	//  意図する結果: コンパイル成功
	TEST(GetDataNumTest, TestGetDataNumIsConst)
	{
#if defined TEST_GET_DATA_NUM_IS_CONST
		const DoublyLinkedList<Score> list;
		EXPECT_EQ(0, list.getSize());
#endif
		SUCCEED();
	}

//=================================== データの挿入 ===================================
	//  ID: 15
	//  テスト項目: 非constのメソッドであるか
	//  意図する結果: コンパイルエラー
	TEST(InsertDataTest, TestInsertDataIsNotConst) {
#if defined TEST_IMSERT_DATA_IS_NOT_CONST
		const DoublyLinkedList<Score> list;
		list.insert(Score("0", "user")); //コンパイルエラー
#endif
		SUCCEED();
	}

//=================================== データの削除 ===================================
	//  ID: 22
	//  テスト項目: 非constのメソッドであるか
	//  意図する結果: コンパイルエラー
	TEST(DeleteDataTest, TestDeleteDataIsNotConst) {
#if defined TEST_DELETE_DATA_IS_NOT_CONST
		const DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit = list.beginConst();
		list.remove(it); //コンパイルエラー
#endif
		SUCCEED();
	}

//=================================== 先頭イテレータの取得 ===================================
	//  ID: 28
	//  テスト項目: constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	//  意図する結果: コンパイルエラー
	TEST(GetHeadDataTest, TestGetHeadDataFromConstList) {
#if defined TEST_GET_HEAD_DATA_FROM_CONST_LIST
		const DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it;
		it = list.begin(); //コンパイルエラー
#endif
		SUCCEED();
	}

//=================================== 先頭コンストイテレータの取得 =============================
	//  ID: 34
	//  テスト項目: constのメソッドであるか
	//  意図する結果: コンパイル成功
	TEST(GetHeadDataConstTest, TestGetHeadDataConstIsConst) {
#if defined TEST_GET_HEAD_DATA_CONST_IS_CONST
		const DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst(); //コンパイル成功
#endif
		SUCCEED();
	}

//=================================== 末尾イテレータの取得 ===================================
	//  ID: 40
	//  テスト項目: constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
	//  意図する結果: コンパイルエラー
	TEST(GetTailDataTest, TestGetTailDataFromConstList) {
#if defined TEST_GET_TAIL_DATA_FROM_CONST_LIST
		const DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail(); //コンパイルエラー
#endif
		SUCCEED();
	}

//=================================== 末尾コンストイテレータの取得 ==============================
	//  ID: 46
	//  テスト項目: constのメソッドであるか
	//  意図する結果: コンパイル成功
	TEST(GetTailDataConstTest, TestGetTailDataConstIsConst) {
#if defined TEST_GET_TAIL_DATA_CONST_IS_CONST
		const DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst(); //コンパイル成功
#endif
		SUCCEED();
	}
}


//======================//
//    　 Iterator       //
//======================//
namespace IteratorTest {

//================================ イテレータの指す要素を取得する ============================
	//  ID: 2
	//  テスト項目: ConstIteratorから取得した要素に対して、値の代入が行えないかをチェック
	//  意図する結果: コンパイルエラー
	TEST(GetIteratorTest, TestGetConstIteratorAndPushValue) {
#if defined TEST_GET_CONST_ITERATOR_AND_PUSH_VALUE
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		(*cit).score = 100; //コンパイルエラー
#endif
		SUCCEED();
	}

//=================================== イテレータのコピーを行う ===================================
	//  ID: 17
	//  テスト項目: ConstIteratorから、Iteratorのコピーが作成されないかをチェック
	//  意図する結果: コンパイルエラー
	TEST(CopyIteratorTest, TestConstIteratorConstructorFromIterator) {
#if defined Test_Const_Iterator_Constructor_From_Iterator
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator it0 = list.getTailConst();
		DoublyLinkedList<Score>::Iterator it1 = DoublyLinkedList<Score>::Iterator(it0); //コンパイルエラー
#endif
		SUCCEED();
	}

//=================================== イテレータの代入を行う ===================================
	//  ID: 19
	//  テスト項目: IteratorにConstIteratorを代入できない事をチェック
	//  意図する結果: コンパイルエラー
	TEST(AssignIteratorTest, TestAssignConstIteratorToIterator) {
#if defined TEST_ASSIGN_CONST_ITERATOR_TO_ITERATOR
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator it0 = list.getTailConst();
		DoublyLinkedList<Score>::Iterator it1;

		it1 = it0; //コンパイルエラー
#endif
		SUCCEED();
	}
	
}