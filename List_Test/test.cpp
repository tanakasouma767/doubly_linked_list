#include "pch.h"
#include "doubly_linked_list.h"

namespace ListTest {

// ���X�g��
// sentinel -> head_record -> record -> ... -> tail_record -> sentinel
// �Ƃ����\���ŁA���R�[�h�̘A�Ȃ������
// 
// getHead()�� head_record �̃C�e���[�^��Ԃ� (���X�g����ł���� sentinel )
// getTail()�� tail_record �̃C�e���[�^��Ԃ� (���X�g����ł���� sentinel )
// getEnd()�� sentinel �̃C�e���[�^��Ԃ�
// 
// insert()�̈����ɃC�e���[�^���w�肵���ꍇ�A
// �C�e���[�^�̏ꏊ�ɂ������v�f������ɂ��炵�ă��R�[�h��}������
//
// �C�e���[�^���w�肵�Ȃ���Ζ����ɑ}�������

//======================//
//       ���X�g         //
//======================//

//=================================== �f�[�^���̎擾 ===================================

//  ID: 0
//  �e�X�g����: ���X�g����ł���ꍇ�̖߂�l
//  �z�肷��߂�l: 0
	TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
		DoublyLinkedList list;

		EXPECT_EQ(0, list.getSize());
	}


	//  ID: 1
	//  �e�X�g����: ���X�g�����ւ̑}�����s�����ۂ̖߂�l
	//  �z�肷��߂�l: 1
	TEST(GetDataNumTest, TestGetDataNumAfterPushEnd)
	{
		DoublyLinkedList list;
		DoublyLinkedList::Iterator it = list.getEnd();

		ASSERT_EQ(0, list.insert(it, 1));
		EXPECT_EQ(1, list.getSize());
	}


	//  ID: 2
	//  �e�X�g����: ���X�g�����ւ̑}�������s�����ۂ̖߂�l
	//  �z�肷��߂�l: 0
	TEST(GetDataNumTest, TestGetDataNumAfterPushEndFailed)
	{
		//�ȗ�
	}


	//  ID: 3
	//  �e�X�g����: �f�[�^�̑}�����s�����ۂ̖߂�l
	//  �z�肷��߂�l: 1
	TEST(GetDataNumTest, TestGetDataNumAfterPush)
	{
		DoublyLinkedList list;

		ASSERT_EQ(0, list.insert(1));
		EXPECT_EQ(1, list.getSize());
	}


	//  ID: 4
	//  �e�X�g����: �f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
	//  �z�肷��߂�l: 0
	TEST(GetDataNumTest, TestGetDataNumAfterPushHeadFailed)
	{
		//�ȗ�
	}


	//  ID: 5
	//  �e�X�g����: �f�[�^�̍폜���s�����ۂ̖߂�l
	//  �z�肷��߂�l: 0
	TEST(GetDataNumTest, TestGetDataNumAfterDelete)
	{
		DoublyLinkedList list;
		list.insert(1);

		DoublyLinkedList::Iterator it = list.getHead();

		ASSERT_EQ(0, list.remove(it));
		EXPECT_EQ(0, list.getSize());
	}


	//  ID: 6
	//  �e�X�g����: �f�[�^�̍폜�����s�����ۂ̖߂�l
	//  �z�肷��߂�l: 1
	TEST(GetDataNumTest, TestGetDataNumAfterDeleteFailed)
	{
		//�ȗ�
	}


	//  ID: 7
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
	//  �z�肷��߂�l: 0
	TEST(GetDataNumTest, TestGetDataNumAfterDeleteWhenEmpty)
	{
		DoublyLinkedList list;
		DoublyLinkedList::Iterator it = list.getEnd();
		list.remove(it);

		EXPECT_EQ(0, list.getSize());
	}


	//  ID: 8
	//  �e�X�g����: const�̃��\�b�h�ł��邩�@�����e�X�g�����Ȃ��Ă悢
	//  �z�肷��߂�l: 



	//=================================== �f�[�^�̑}�� ===================================

	//  ID: 9
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataWhenEmpty) {
		//�擪�ւ̑}��
		DoublyLinkedList list0;
		DoublyLinkedList::Iterator it0 = list0.getHead();
		EXPECT_EQ(0, list0.insert(it0, "0", "user0"));

		//�����ւ̑}��
		DoublyLinkedList list1;
		DoublyLinkedList::Iterator it1 = list1.getEnd();
		EXPECT_EQ(0, list1.insert(it1, "1", "user1"));
	}

	//  ID: 10
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataHead) {

		DoublyLinkedList list;

		list.insert(2);

		DoublyLinkedList::Iterator it = list.getHead();
		EXPECT_EQ(0, list.insert(it, "0", "user"));
	}

	//  ID: 11
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataEnd) {
		DoublyLinkedList list;

		list.insert(2);

		DoublyLinkedList::Iterator it = list.getEnd();
		EXPECT_EQ(0, list.insert(it, "0", "user"));
	}

	//  ID: 12
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataNotHeadAndEnd) {
		DoublyLinkedList list;

		list.insert(3);

		DoublyLinkedList::ConstIterator citr = list.getHeadConst();
		++citr;

		EXPECT_EQ(0, list.insert("0", "user"));
	}

	//  ID: 13
	//  �e�X�g����: ConstIterator���w�肵�đ}�����s�����ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataWithConstIterator) {
		DoublyLinkedList list;

		list.insert(3);

		//�����ɑ}��
		DoublyLinkedList::ConstIterator citr = list.getHeadConst();
		++citr;
		EXPECT_EQ(0, list.insert(citr, "0", "user0"));

		//�擪�ɑ}��
		citr = list.getHeadConst();
		EXPECT_EQ(0, list.insert(citr, "1", "user1"));

		//�����ɑ}��
		citr = list.getEndConst();
		EXPECT_EQ(0, list.insert(citr, "2", "user2"));
	}

	//  ID: 14
	//  �e�X�g����: �s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
	//  �z�肷��߂�l: -1(�ُ�I��)
	TEST(InsertDataTest, TestInsertDataNotWithWrongIterator) {
		//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ
		DoublyLinkedList list0;
		DoublyLinkedList::Iterator it;
		EXPECT_EQ(-1, list0.insert(it, "0", "user"));

		//�ʂ̃��X�g�̎Q�Ƃ����C�e���[�^��n�����ꍇ
		DoublyLinkedList list1;
		it = list0.getHead();
		EXPECT_EQ(-1, list1.insert(it, "0", "user"));
	}

	//  ID: 15
	//  �e�X�g����: ��const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢

	//=================================== �f�[�^�̍폜 ===================================

	//  ID: 16
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(DeleteDataTest, TestDeleteDataWhenEmpty) {
		DoublyLinkedList list;

		//�擪�C�e���[�^��n�����ꍇ
		DoublyLinkedList::Iterator it = list.getHead();
		EXPECT_EQ(0, list.remove(it));

		//�����C�e���[�^��n�����ꍇ
		it = list.getEnd();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 17
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(DeleteDataTest, TestDeleteDataHead) {
		DoublyLinkedList list;

		list.insert(2);

		DoublyLinkedList::Iterator it = list.getHead();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 18
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(DeleteDataTest, TestDeleteDataEnd) {
		DoublyLinkedList list;

		list.insert(2);

		DoublyLinkedList::Iterator it = list.getEnd();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 19
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(DeleteDataTest, TestDeleteDataNotHeadAndEnd) {
		DoublyLinkedList list;

		list.insert(3);

		DoublyLinkedList::ConstIterator cit = list.getHeadConst();
		++cit;

		EXPECT_EQ(0, list.remove(cit));
	}

	//  ID: 20
	//  �e�X�g����: ConstIterator���w�肵�č폜���s�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(InsertDataTest, TestDeleteDataWithConstIterator) {
		DoublyLinkedList list;

		list.insert(3);

		//�������폜
		DoublyLinkedList::ConstIterator citr = list.getHeadConst();
		++citr;
		EXPECT_EQ(0, list.remove(citr));

		//�擪���폜
		citr = list.getHeadConst();
		EXPECT_EQ(0, list.remove(citr));

		//�������폜
		citr = list.getEndConst();
		EXPECT_EQ(0, list.remove(citr));
	}

	//  ID: 21
	//  �e�X�g����: �s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
	//  �z�肷��߂�l: -1(�ُ�I��)
	TEST(DeleteDataTest, TestDeleteDataNotWithWrongIterator) {

		//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ
		DoublyLinkedList list0;
		list0.insert(1);

		DoublyLinkedList::Iterator it;
		EXPECT_EQ(-1, list0.remove(it));

		//�ʂ̃��X�g�̎Q�Ƃ����C�e���[�^��n�����ꍇ
		DoublyLinkedList list1;
		list1.insert(1);

		it = list0.getHead();
		EXPECT_EQ(-1, list1.remove(it));
	}

	//  ID: 22
	//  �e�X�g����: ��const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


	//=================================== �擪�C�e���[�^�̎擾 ===================================

	//  ID: 23
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataWhenEmpty) {
		DoublyLinkedList list;
		DoublyLinkedList::Iterator it;
		it = list.getHead();
		EXPECT_TRUE(it == list.getEnd());
	}

	//  ID: 24
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataWhenOneRecord) {
		DoublyLinkedList list;
		list.insert("0","user");

		DoublyLinkedList::Iterator it;
		it = list.getHead();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 25
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataWhenMoreThanTwo) {
		DoublyLinkedList list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList::Iterator it;
		it = list.getHead();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));
	}

	//  ID: 26
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataAfterPush) {
		DoublyLinkedList list;
		ASSERT_EQ(0, list.insert("0", "user"));

		DoublyLinkedList::Iterator it;
		it = list.getHead();

		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 27
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataAfterDelete) {
		DoublyLinkedList list;
		list.insert("0", "user");
		list.insert(1);

		DoublyLinkedList::Iterator it;
		it = list.getEnd();
		ASSERT_EQ(0, list.remove(it));

		it = list.getHead();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 28
	//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


	//=================================== �擪�R���X�g�C�e���[�^�̎擾 =============================

	//  ID: 29
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenEmpty) {
		DoublyLinkedList list;
		DoublyLinkedList::ConstIterator cit;
		cit = list.getHeadConst();
		EXPECT_TRUE(cit == list.getEndConst());
	}

	//  ID: 30
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenOneRecord) {
		DoublyLinkedList list;
		list.insert("0", "user");

		DoublyLinkedList::ConstIterator cit;
		cit = list.getHeadConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 31
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenMoreThanTwo) {
		DoublyLinkedList list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList::ConstIterator cit;
		cit = list.getHeadConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user0"));
	}

	//  ID: 32
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstAfterPush) {
		DoublyLinkedList list;
		ASSERT_EQ(0, list.insert("0", "user"));

		DoublyLinkedList::ConstIterator cit;
		cit = list.getHeadConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 33
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstAfterDelete) {
		DoublyLinkedList list;
		list.insert("0", "user");
		list.insert(1);

		DoublyLinkedList::ConstIterator cit;
		cit = list.getEndConst();
		ASSERT_EQ(0, list.remove(cit));

		cit = list.getHeadConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 34
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


	//=================================== �����C�e���[�^�̎擾 ===================================

	//  ID: 35
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetEndDataTest, TestGetEndDataWhenEmpty) {
		DoublyLinkedList list;
		DoublyLinkedList::Iterator it;
		it = list.getEnd();
		EXPECT_TRUE(it == list.getEnd());
	}

	//  ID: 36
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataWhenOneRecord) {
		DoublyLinkedList list;
		list.insert("0", "user");

		DoublyLinkedList::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 37
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataWhenMoreThanTwo) {
		DoublyLinkedList list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 1) && ((*it).userName == "user1"));
	}

	//  ID: 38
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataAfterPush) {
		DoublyLinkedList list;
		ASSERT_EQ(0, list.insert("0", "user"));

		DoublyLinkedList::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 39
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataAfterDelete) {
		DoublyLinkedList list;
		list.insert("0", "user");
		list.insert(1);

		DoublyLinkedList::Iterator it;
		it = list.getTail();
		ASSERT_EQ(0, list.remove(it));

		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 40
	//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢

	//=================================== �����R���X�g�C�e���[�^�̎擾 ==============================

	//  ID: 41
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenEmpty) {
		DoublyLinkedList list;
		DoublyLinkedList::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(cit == list.getTailConst());
	}

	//  ID: 42
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenOneRecord) {
		DoublyLinkedList list;
		list.insert("0", "user");

		DoublyLinkedList::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 43
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenMoreThanTwo) {
		DoublyLinkedList list;
		list.insert("0", "user0");
		list.insert("1", "user1");

		DoublyLinkedList::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 1) && ((*cit).userName == "user1"));
	}

	//  ID: 44
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstAfterPush) {
		DoublyLinkedList list;
		ASSERT_EQ(0, list.insert("0", "user"));

		DoublyLinkedList::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 45
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstAfterDelete) {
		DoublyLinkedList list;
		list.insert("0", "user");
		list.insert(1);

		DoublyLinkedList::ConstIterator cit;
		cit = list.getTailConst();
		ASSERT_EQ(0, list.remove(cit));

		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 46
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢

	//=================================================================================================
}