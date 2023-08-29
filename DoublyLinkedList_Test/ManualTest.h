#pragma once

// List_ManualTest.h
// GoogleTest手動テストコード

#if !defined ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___
#define      ___TECHTRAINING_CHAPTER2_LIST_MANUAL_TEST___


// マクロ定義
// コンパイル関連手動テスト

//======================//
//       リスト         //
//======================//

//  ID: 8	意図する結果: コンパイル成功
#define TEST_GET_DATA_NUM_IS_CONST

//  ID: 15	意図する結果: コンパイルエラー
//#define TEST_IMSERT_DATA_IS_NOT_CONST

//  ID: 22	意図する結果: コンパイルエラー
//#define TEST_DELETE_DATA_IS_NOT_CONST

//  ID: 28	意図する結果: コンパイルエラー
//#define TEST_GET_HEAD_DATA_FROM_CONST_LIST

//  ID: 34	意図する結果: コンパイル成功
//#define TEST_GET_HEAD_DATA_CONST_IS_CONST

//  ID: 40	意図する結果: コンパイルエラー
//#define TEST_GET_TAIL_DATA_FROM_CONST_LIST

//  ID: 46	意図する結果: コンパイル成功
//#define TEST_GET_TAIL_DATA_CONST_IS_CONST



//======================//
//    　 Iterator       //
//======================//

//  ID: 2	意図する結果: コンパイルエラー
//#define TEST_GET_CONST_ITERATOR_AND_PUSH_VALUE

//  ID: 17	意図する結果: コンパイルエラー
//#define Test_Const_Iterator_Constructor_From_Iterator

//  ID: 19	意図する結果: コンパイルエラー
//#define TEST_ASSIGN_CONST_ITERATOR_TO_ITERATOR

#endif