#include "pch.h"
#include "doubly_linked_list.inl"

namespace ListTest {

// ���X�g��
// sentinel -> head_record -> record -> ... -> tail_record -> sentinel
// �Ƃ����\���ŁA���R�[�h�̘A�Ȃ������
// 
// begin()�� head_record �̃C�e���[�^��Ԃ� (���X�g����ł���� sentinel )
// getTail()�� tail_record �̃C�e���[�^��Ԃ� (���X�g����ł���� sentinel )
// end()�� sentinel �̃C�e���[�^��Ԃ�
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
		DoublyLinkedList<Score> list;

		EXPECT_EQ(0, list.getSize());
	}


	//  ID: 1
	//  �e�X�g����: ���X�g�����ւ̑}�����s�����ۂ̖߂�l
	//  �z�肷��߂�l: 1
	TEST(GetDataNumTest, TestGetDataNumAfterPushEnd)
	{
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.end();

		ASSERT_EQ(0, list.insert(it, Score("0", "user")));
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
		DoublyLinkedList<Score> list;

		ASSERT_EQ(0, list.insert(Score("0", "user")));
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
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));
		ASSERT_EQ(1, list.getSize());

		DoublyLinkedList<Score>::Iterator it = list.begin();

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
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.begin();
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
		DoublyLinkedList<Score> list0;
		DoublyLinkedList<Score>::Iterator it0 = list0.begin();
		EXPECT_EQ(0, list0.insert(it0, Score("0", "user0")));

		//�����ւ̑}��
		DoublyLinkedList<Score> list1;
		DoublyLinkedList<Score>::Iterator it1 = list1.end();
		EXPECT_EQ(0, list1.insert(it1, Score("1", "user1")));
	}

	//  ID: 10
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
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
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataEnd) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it = list.end();
		EXPECT_EQ(0, list.insert(it, Score("2", "user2")));
	}

	//  ID: 12
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
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
	//  �e�X�g����: ConstIterator���w�肵�đ}�����s�����ۂ̋���
	//  �z�肷��߂�l: 0 (����I��)
	TEST(InsertDataTest, TestInsertDataWithConstIterator) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		list.insert(Score("2", "user2"));

		//�����ɑ}��
		DoublyLinkedList<Score>::ConstIterator citr = list.beginConst();
		++citr;
		EXPECT_EQ(0, list.insert(citr, Score("3", "user3")));

		//�擪�ɑ}��
		citr = list.beginConst();
		EXPECT_EQ(0, list.insert(citr, Score("4", "user4")));

		//�����ɑ}��
		citr = list.endConst();
		EXPECT_EQ(0, list.insert(citr, Score("5", "user5")));
	}

	//  ID: 14
	//  �e�X�g����: �s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
	//  �z�肷��߂�l: -1(�ُ�I��)
	TEST(InsertDataTest, TestInsertDataNotWithWrongIterator) {
		//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ
		DoublyLinkedList<Score> list0;
		DoublyLinkedList<Score>::Iterator it;
		EXPECT_EQ(-1, list0.insert(it, Score("0", "user")));

		//�ʂ̃��X�g�̎Q�Ƃ����C�e���[�^��n�����ꍇ
		DoublyLinkedList<Score> list1;
		it = list0.begin();
		EXPECT_EQ(-1, list1.insert(it, Score("0", "user")));
	}

	//  ID: 15
	//  �e�X�g����: ��const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢

	//=================================== �f�[�^�̍폜 ===================================

	//  ID: 16
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(DeleteDataTest, TestDeleteDataWhenEmpty) {
		DoublyLinkedList<Score> list;

		//�擪�C�e���[�^��n�����ꍇ
		DoublyLinkedList<Score>::Iterator it = list.begin();
		EXPECT_EQ(0, list.remove(it));

		//�����C�e���[�^��n�����ꍇ
		it = list.end();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 17
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(DeleteDataTest, TestDeleteDataHead) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it = list.begin();
		EXPECT_EQ(0, list.remove(it));
	}

	//  ID: 18
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��) (�����͔ԕ��Ȃ̂ŉ����N����Ȃ�)
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
	//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
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
	//  �e�X�g����: ConstIterator���w�肵�č폜���s�����ۂ̋���
	//  �z�肷��߂�l: 0(����I��)
	TEST(InsertDataTest, TestDeleteDataWithConstIterator) {
		DoublyLinkedList<Score> list;

		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));
		list.insert(Score("2", "user2"));

		//�������폜
		DoublyLinkedList<Score>::ConstIterator citr = list.beginConst();
		++citr;
		EXPECT_EQ(0, list.remove(citr));

		//�擪���폜
		citr = list.beginConst();
		EXPECT_EQ(0, list.remove(citr));

		//�������폜
		citr = list.endConst();
		EXPECT_EQ(0, list.remove(citr));
	}

	//  ID: 21
	//  �e�X�g����: �s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
	//  �z�肷��߂�l: -1(�ُ�I��)
	TEST(DeleteDataTest, TestDeleteDataNotWithWrongIterator) {

		//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ
		DoublyLinkedList<Score> list0;
		list0.insert(Score("0", "user"));

		DoublyLinkedList<Score>::Iterator it;
		EXPECT_EQ(-1, list0.remove(it));

		//�ʂ̃��X�g�̎Q�Ƃ����C�e���[�^��n�����ꍇ
		DoublyLinkedList<Score> list1;
		list1.insert(Score("0", "user"));

		it = list0.begin();
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
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();
		EXPECT_TRUE(it == list.end());
	}

	//  ID: 24
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0","user"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 25
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user0"));
	}

	//  ID: 26
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataTest, TestGetHeadDataAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::Iterator it;
		it = list.begin();

		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 27
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
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
	//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


	//=================================== �擪�R���X�g�C�e���[�^�̎擾 =============================

	//  ID: 29
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(cit == list.endConst());
	}

	//  ID: 30
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 31
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user0"));
	}

	//  ID: 32
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
	TEST(GetHeadDataConstTest, TestGetHeadDataConstAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.beginConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 33
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
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
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


	//=================================== �����C�e���[�^�̎擾 ===================================

	//  ID: 35
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGeTailDataWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(it == list.end());
	}

	//  ID: 36
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 37
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 1) && ((*it).userName == "user1"));
	}

	//  ID: 38
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataTest, TestGetTailDataAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::Iterator it;
		it = list.getTail();
		EXPECT_TRUE(((*it).score == 0) && ((*it).userName == "user"));
	}

	//  ID: 39
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: Iterator �����v�f���w���C�e���[�^���Ԃ�
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
	//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢

	//=================================== �����R���X�g�C�e���[�^�̎擾 ==============================

	//  ID: 41
	//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(cit == list.endConst());
	}

	//  ID: 42
	//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenOneRecord) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 43
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstWhenMoreThanTwo) {
		DoublyLinkedList<Score> list;
		list.insert(Score("0", "user0"));
		list.insert(Score("1", "user1"));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 1) && ((*cit).userName == "user1"));
	}

	//  ID: 44
	//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
	TEST(GetTailDataConstTest, TestGetTailDataConstAfterPush) {
		DoublyLinkedList<Score> list;
		ASSERT_EQ(0, list.insert(Score("0", "user")));

		DoublyLinkedList<Score>::ConstIterator cit;
		cit = list.getTailConst();
		EXPECT_TRUE(((*cit).score == 0) && ((*cit).userName == "user"));
	}

	//  ID: 45
	//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
	//  �z�肷��߂�l: ConstIterator �����v�f���w���C�e���[�^���Ԃ�
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
	//  �e�X�g����: const�̃��\�b�h�ł��邩
	//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢

	//=================================================================================================
}