#include "pch.h"
#include "doubly_linked_list.h"
#include "List_ManualTest.h"

//======================//
//       ���X�g         //
//======================//

namespace ListTest {

//=================================== �f�[�^���̎擾 ===================================
	//  ID: 8
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �Ӑ}���錋��: �R���p�C������
	TEST(GetDataNumTest, TestGetDataNumIsConst)
	{
#if defined TEST_GET_DATA_NUM_IS_CONST
		const DoublyLinkedList list;
		EXPECT_EQ(0, list.getSize());
#endif
		SUCCEED();
	}

//=================================== �f�[�^�̑}�� ===================================
	//  ID: 15
	//  �e�X�g����: ��const�̃��\�b�h�ł��邩
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(InsertDataTest, TestInsertDataIsNotConst) {
#if defined TEST_IMSERT_DATA_IS_NOT_CONST
		const DoublyLinkedList list;
		list.insert("0", "user"); //�R���p�C���G���[
#endif
		SUCCEED();
	}

//=================================== �f�[�^�̍폜 ===================================
	//  ID: 22
	//  �e�X�g����: ��const�̃��\�b�h�ł��邩
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(DeleteDataTest, TestDeleteDataIsNotConst) {
#if defined TEST_DELETE_DATA_IS_NOT_CONST
		const DoublyLinkedList list;
		list.remove(); //�R���p�C���G���[
#endif
		SUCCEED();
	}

//=================================== �擪�C�e���[�^�̎擾 ===================================
	//  ID: 28
	//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(GetHeadDataTest, TestGetHeadDataFromConstList) {
#if defined TEST_GET_HEAD_DATA_FROM_CONST_LIST
		const DoublyLinkedList list;
		DoublyLinkedList::Iterator it;
		it = list.getHead(); //�R���p�C���G���[
#endif
		SUCCEED();
	}

//=================================== �擪�R���X�g�C�e���[�^�̎擾 =============================
	//  ID: 34
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �Ӑ}���錋��: �R���p�C������
	TEST(GetHeadDataConstTest, TestGetHeadDataConstIsConst) {
#if defined TEST_GET_HEAD_DATA_CONST_IS_CONST
		const DoublyLinkedList list;
		DoublyLinkedList::ConstIterator cit;
		cit = list.getHeadConst(); //�R���p�C������
#endif
		SUCCEED();
	}

//=================================== �����C�e���[�^�̎擾 ===================================
	//  ID: 40
	//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(GetTailDataTest, TestGetTailDataFromConstList) {
#if defined TEST_GET_TAIL_DATA_FROM_CONST_LIST
		const DoublyLinkedList list;
		DoublyLinkedList::Iterator it;
		it = list.getTail(); //�R���p�C���G���[
#endif
		SUCCEED();
	}

//=================================== �����R���X�g�C�e���[�^�̎擾 ==============================
	//  ID: 46
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �Ӑ}���錋��: �R���p�C������
	TEST(GetTailDataConstTest, TestGetTailDataConstIsConst) {
#if defined TEST_GET_TAIL_DATA_CONST_IS_CONST
		const DoublyLinkedList list;
		DoublyLinkedList::ConstIterator cit;
		cit = list.getTailConst(); //�R���p�C������
#endif
		SUCCEED();
	}
}


//======================//
//    �@ Iterator       //
//======================//
namespace IteratorTest {

//================================ �C�e���[�^�̎w���v�f���擾���� ============================
	//  ID: 2
	//  �e�X�g����: ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(GetIteratorTest, TestGetConstIteratorAndPushValue) {
#if defined TEST_GET_CONST_ITERATOR_AND_PUSH_VALUE
		DoublyLinkedList list;
		list.insert("0", "user");

		DoublyLinkedList::ConstIterator cit;
		cit = list.getHeadConst();
		(*cit).score = 100; //�R���p�C���G���[
#endif
		SUCCEED();
	}

//=================================== �C�e���[�^�̃R�s�[���s�� ===================================
	//  ID: 17
	//  �e�X�g����: ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(CopyIteratorTest, TestConstIteratorConstructorFromIterator) {
#if defined Test_Const_Iterator_Constructor_From_Iterator
		DoublyLinkedList list;
		list.insert("0", "user");

		DoublyLinkedList::ConstIterator it0 = list.getTailConst();
		DoublyLinkedList::Iterator it1 = DoublyLinkedList::Iterator(it0); //�R���p�C���G���[
#endif
		SUCCEED();
	}

//=================================== �C�e���[�^�̑�����s�� ===================================
	//  ID: 19
	//  �e�X�g����: Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
	//  �Ӑ}���錋��: �R���p�C���G���[
	TEST(AssignIteratorTest, TestAssignConstIteratorToIterator) {
#if defined TEST_ASSIGN_CONST_ITERATOR_TO_ITERATOR
		DoublyLinkedList list;
		list.insert("0", "user");

		DoublyLinkedList::ConstIterator it0 = list.getTailConst();
		DoublyLinkedList::Iterator it1;

		it1 = it0; //�R���p�C���G���[
#endif
		SUCCEED();
	}

}