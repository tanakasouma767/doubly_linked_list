#include "pch.h"
#include "doubly_linked_list.h"

// ���X�g��
// sentinel -> head_record -> record -> ... -> end_record -> sentinel
// �Ƃ������R�[�h�̘A�Ȃ������
// 
// getHead()�� head_record �̃|�C���^��Ԃ�
// getEnd()�� end_record �̃|�C���^��Ԃ�
// 
// insert()�̈����ɃC�e���[�^���w�肵���ꍇ�A
// ���̏ꏊ�ɂ������v�f������ɂ��炵�ă��R�[�h��}������
//
// �}������v�f�𖖔��ɂ������ꍇ�A�C�e���[�^���w�肵�Ȃ���Ζ����ɑ}�������

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

	EXPECT_EQ(0, list.insert(it, 1));
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
	
	EXPECT_EQ(0, list.insert(1));
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

	DoublyLinkedList::Iterator it = list.getEnd();

	EXPECT_EQ(0, list.deleteRecord(it));
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
	list.deleteRecord(it);

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
	std::string score0 = "0";
	std::string userName0 = "user0";
	EXPECT_EQ(0, list0.insert(it0, score0, userName0));

	//�����ւ̑}��
	DoublyLinkedList list1;
	DoublyLinkedList::Iterator it1 = list1.getEnd();
	std::string score1 = "1";
	std::string userName1 = "user1";
	EXPECT_EQ(0, list1.insert(it1, score1, userName1));
}

//  ID: 10
//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
//  �z�肷��߂�l: 0 (����I��)
TEST(InsertDataTest, TestInsertDataHead) {

	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getHead();
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(0, list.insert(it, score, userName));
}

//  ID: 11
//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
//  �z�肷��߂�l: 0 (����I��)
TEST(InsertDataTest, TestInsertDataEnd) {
	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getEnd();
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(0, list.insert(it, score, userName));
}

//  ID: 12
//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
//  �z�肷��߂�l: 0 (����I��)
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
//  �e�X�g����: ConstIterator���w�肵�đ}�����s�����ۂ̋���
//  �z�肷��߂�l: 0 (����I��)
TEST(InsertDataTest, TestInsertDataWithConstIterator) {
	DoublyLinkedList list;

	list.insert(3);

	//�����ɑ}��
	DoublyLinkedList::ConstIterator citr = list.getHeadConst();
	++citr;
	std::string score0 = "0";
	std::string userName0 = "user0";
	EXPECT_EQ(0, list.insert(citr, score0, userName0));

	//�擪�ɑ}��
	citr = list.getHeadConst();
	std::string score1 = "1";
	std::string userName1 = "user1";
	EXPECT_EQ(0, list.insert(citr, score1, userName1));

	//�����ɑ}��
	citr = list.getEndConst();
	std::string score2 = "2";
	std::string userName2 = "user2";
	EXPECT_EQ(0, list.insert(citr, score2, userName2));
}

//  ID: 14
//  �e�X�g����: �s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
//  �z�肷��߂�l: -1(�ُ�I��)
TEST(InsertDataTest, TestInsertDataNotWithWrongIterator) {
	//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ
	DoublyLinkedList list0;
	DoublyLinkedList::Iterator it;
	std::string score = "0";
	std::string userName = "user";
	EXPECT_EQ(-1, list0.insert(it, score, userName));

	//�ʂ̃��X�g�̎Q�Ƃ����C�e���[�^��n�����ꍇ
	DoublyLinkedList list1;
	it = list0.getHead();
	EXPECT_EQ(-1, list1.insert(it, score, userName));
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
	EXPECT_EQ(0, list.deleteRecord(it));

	//�����C�e���[�^��n�����ꍇ
	it = list.getEnd();
	EXPECT_EQ(0, list.deleteRecord(it));
}

//  ID: 17
//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
//  �z�肷��߂�l: 0(����I��)
TEST(DeleteDataTest, TestDeleteDataHead) {
	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getHead();
	EXPECT_EQ(0, list.deleteRecord(it));
}

//  ID: 18
//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
//  �z�肷��߂�l: 0(����I��)
TEST(DeleteDataTest, TestDeleteDataEnd) {
	DoublyLinkedList list;

	list.insert(2);

	DoublyLinkedList::Iterator it = list.getEnd();
	EXPECT_EQ(0, list.deleteRecord(it));
}

//  ID: 19
//  �e�X�g����: ���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
//  �z�肷��߂�l: 0(����I��)
TEST(DeleteDataTest, TestDeleteDataNotHeadAndEnd) {
	DoublyLinkedList list;

	list.insert(3);

	DoublyLinkedList::ConstIterator cit = list.getHeadConst();
	++cit;

	EXPECT_EQ(0, list.deleteRecord(cit));
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
	EXPECT_EQ(0, list.deleteRecord(citr));

	//�擪���폜
	citr = list.getHeadConst();
	EXPECT_EQ(0, list.deleteRecord(citr));

	//�������폜
	citr = list.getEndConst();
	EXPECT_EQ(0, list.deleteRecord(citr));
}

//  ID: 21
//  �e�X�g����: �s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
//  �z�肷��߂�l: -1(�ُ�I��)
TEST(DeleteDataTest, TestDeleteDataNotWithWrongIterator) {
	
	//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ
	DoublyLinkedList list0;
	list0.insert(1);

	DoublyLinkedList::Iterator it;
	EXPECT_EQ(-1, list0.deleteRecord(it));

	//�ʂ̃��X�g�̎Q�Ƃ����C�e���[�^��n�����ꍇ
	DoublyLinkedList list1;
	list1.insert(1);

	it = list0.getHead();
	EXPECT_EQ(-1, list1.deleteRecord(it));
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
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 24
//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
TEST(GetHeadDataTest, TestGetHeadDataWhenOneRecord) {
	DoublyLinkedList list;
	list.insert(1);

	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 25
//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
TEST(GetHeadDataTest, TestGetHeadDataWhenMoreThanTwo) {
	DoublyLinkedList list;
	list.insert(2);

	DoublyLinkedList::Iterator it;
	EXPECT_FALSE(*it);
	it = list.getHead();
	EXPECT_TRUE(*it);
}

//  ID: 26
//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
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
//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: Iterator �擪�v�f���w���C�e���[�^���Ԃ�
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
//  �e�X�g����: const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


//=================================== �擪�R���X�g�C�e���[�^�̎擾 =============================

//  ID: 29
//  �e�X�g����: ���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: ConstIterator �_�~�[�m�[�h���w���C�e���[�^���Ԃ�
TEST(GetHeadDataTest, TestGetHeadDataConstWhenEmpty) {
	DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 30
//  �e�X�g����: ���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
TEST(GetHeadDataTest, TestGetHeadDataConstWhenOneRecord) {
	DoublyLinkedList list;
	list.insert(1);

	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 31
//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
TEST(GetHeadDataTest, TestGetHeadDataConstWhenMoreThanTwo) {
	DoublyLinkedList list;
	list.insert(2);

	DoublyLinkedList::ConstIterator it;
	EXPECT_FALSE(*it);
	it = list.getHeadConst();
	EXPECT_TRUE(*it);
}

//  ID: 32
//  �e�X�g����: �f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
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
//  �e�X�g����: �f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
//  �z�肷��߂�l: ConstIterator �擪�v�f���w���C�e���[�^���Ԃ�
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
//  �e�X�g����: const�̃��\�b�h�ł��邩
//  �z�肷��߂�l: �����e�X�g�����Ȃ��Ă悢


//=================================== �����C�e���[�^�̎擾 ===================================

//  ID: 35
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 36
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 37
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 38
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 39
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 40
//  �e�X�g����: 
//  �z�肷��߂�l: 

//=================================== �����R���X�g�C�e���[�^�̎擾 ==============================

//  ID: 41
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 42
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 43
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 44
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 45
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 46
//  �e�X�g����: 
//  �z�肷��߂�l: 

//=================================================================================================


//======================//
//    �@ Iterator       //
//======================//


//================================ �C�e���[�^�̎w���v�f���擾���� ============================

//  ID: 0
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 1
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 2
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 3
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 4
//  �e�X�g����: 
//  �z�肷��߂�l: 

//================================ �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� ================

//  ID: 5
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 6
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 7
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 8
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 9
//  �e�X�g����: 

//  ID: 10
//  �e�X�g����: 
//  �z�肷��߂�l:


//============================== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� ====================

//  ID: 11
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 12
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 13
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 14
//  �e�X�g����: 

//  ID: 15
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 16
//  �e�X�g����: 
//  �z�肷��߂�l: 


//=================================== �C�e���[�^�̃R�s�[���s�� ===================================

//  ID: 17
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 18
//  �e�X�g����: 
//  �z�肷��߂�l: 


//=================================== �C�e���[�^�̑�����s�� ===================================

//  ID: 19
//  �e�X�g����: 

//  ID: 20
//  �e�X�g����: 
//  �z�肷��߂�l: 


//=========================== ��̃C�e���[�^������̂��̂ł��邩�A��r���s��=========================

//  ID: 21
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 22
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 23
//  �e�X�g����: 
//  �z�肷��߂�l: 


//============================== ��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��=============

//  ID: 24
//  �e�X�g����: 

//  ID: 25
//  �e�X�g����: 
//  �z�肷��߂�l: 

//  ID: 26
//  �e�X�g����: 
//  �z�肷��߂�l: 

