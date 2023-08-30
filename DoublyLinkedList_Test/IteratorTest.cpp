#include "pch.h"
#include "doubly_linked_list.inl"


namespace IteratorTest {

//======================//
//    �@ Iterator       //
//======================//


//================================ �C�e���[�^�̎w���v�f���擾���� ============================

//  ID: 0
//  �e�X�g����: ���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(GetIteratorTest, TestGetIteratorWhenNoListRef) {
		DoublyLinkedList<Score>::Iterator it;
		
		EXPECT_DEATH(*it, "Assertion failed.*");
	}

	//  ID: 1
	//  �e�X�g����: Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
	//  �z�肷��߂�l: true
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
	//  �e�X�g����: ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
	//  �z�肷��߂�l: �R���p�C���G���[ �����e�X�g�����Ȃ��Ă悢


	//  ID: 3
	//  �e�X�g����: ���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	//  �z�肷��߂�l: ���̗v���F�Ȃ� (Assert����)
	TEST(GetIteratorTest, TestGetHeadIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.begin();

		EXPECT_DEATH(*it, "Assertion failed.*");
	}

	//  ID: 4
	//  �e�X�g����: �����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	//  �z�肷��߂�l: ���̗v���F�Ȃ� (Assert����)
	TEST(GetIteratorTest, TestGetEndIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.end();

		EXPECT_DEATH(*it, "Assertion failed.*");
	}

	//================================ �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� ================

	//  ID: 5
	//  �e�X�g����: ���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
	//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(IncrementIteratorTest, TestIncrementIteratorWhenNoListRef) {
		DoublyLinkedList<Score>::Iterator it;

		EXPECT_DEATH(++it, "Assertion failed.*");
	}

	//  ID: 6
	//  �e�X�g����: ���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(IncrementIteratorTest, TestIncrementHeadIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.begin();

		EXPECT_DEATH(++it, "Assertion failed.*");
	}

	//  ID: 7
	//  �e�X�g����: �����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(IncrementIteratorTest, TestIncrementEndIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user");
		DoublyLinkedList<Score>::Iterator it = list.end();

		EXPECT_DEATH(++it, "Assertion failed.*");
	}

	//  ID: 8
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
	//  �z�肷��߂�l: (���̗v�f���w��)
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
	//  �e�X�g����: �O�u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
	//�@�z�肷��߂�l: (���̗v�f���w��)
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
	//  �e�X�g����: ��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
	//  �z�肷��߂�l: (���̗v�f���w��)
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


	//============================== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� ====================

	//  ID: 11
	//  �e�X�g����: ���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
	//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(DecrementIteratorTest, TestDecrementIteratorWhenNoListRef) {
		DoublyLinkedList<Score>::Iterator it;

		EXPECT_DEATH(--it, "Assertion failed.*");
	}

	//  ID: 12
	//  �e�X�g����: ���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(DecrementIteratorTest, TestDecrementEndIteratorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it = list.end();

		EXPECT_DEATH(--it, "Assertion failed.*");
	}


	//  ID: 13
	//  �e�X�g����: �擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	//  �z�肷��߂�l: �Ȃ� (Assert����)
	TEST(DecrementIteratorTest, TestDecrementHeadIterator) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user");
		DoublyLinkedList<Score>::Iterator it = list.begin();

		EXPECT_DEATH(--it, "Assertion failed.*");
	}

	//  ID: 14
	//  �e�X�g����: ���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
	//  �z�肷��߂�l: (�O�̗v�f���w��)
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
	//  �e�X�g����: �O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
	//  �z�肷��߂�l:  (�O�̗v�f���w��)
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
	//  �e�X�g����: ��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
	//  �z�肷��߂�l:  (�O�̗v�f���w��)
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


	//=================================== �C�e���[�^�̃R�s�[���s�� ===================================

	//  ID: 17
	//  �e�X�g����: ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
	//  �z�肷��߂�l:  �R���p�C���G���[ �����e�X�g�����Ȃ��Ă悢

	//  ID: 18
	//  �e�X�g����: �R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
	//  �z�肷��߂�l: 
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

	//=================================== �C�e���[�^�̑�����s�� ===================================

	//  ID: 19
	//  �e�X�g����: Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
	//  �z�肷��߂�l: �R���p�C���G���[ �����e�X�g�����Ȃ��Ă悢


	//  ID: 20
	//  �e�X�g����: �����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
	//  �z�肷��߂�l: 
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


	//=========================== ��̃C�e���[�^������̂��̂ł��邩�A��r���s��=========================

	//  ID: 21
	//  �e�X�g����: ���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
	//  �z�肷��߂�l: true
	TEST(IteratorEqualityOperatorTest, TestIteratorEqualityOperatorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.end();
		EXPECT_TRUE(it0 == it1);
	}

	//  ID: 22
	//  �e�X�g����: ����̃C�e���[�^���r�����ۂ̋���
	//  �z�肷��߂�l: true
	TEST(IteratorEqualityOperatorTest, TestIteratorEqualityOperatorWhenEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.begin();
		EXPECT_TRUE(it0 == it1);
	}

	//  ID: 23
	//  �e�X�g����: �قȂ�C�e���[�^���r�����ۂ̋���
	//  �z�肷��߂�l: false
	TEST(IteratorEqualityOperatorTest, TestIteratorEqualityOperatorWhenNotEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.getTail();
		EXPECT_FALSE(it0 == it1);
	}


	//============================== ��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��=============

	//  ID: 24
	//  �e�X�g����: ���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
	//  �z�肷��߂�l: false
	TEST(IteratorNotEqualityOperatorTest, TestIteratorNotEqualityOperatorWhenEmpty) {
		DoublyLinkedList<Score> list;
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.end();
		EXPECT_FALSE(it0 != it1);
	}


	//  ID: 25
	//  �e�X�g����: ����̃C�e���[�^���r�����ۂ̋���
	//  �z�肷��߂�l: false
	TEST(IteratorNotEqualityOperatorTest, TestIteratorNotEqualityOperatorWhenEqual) {
		DoublyLinkedList<Score> list;
		list.insert("0", "user0");
		list.insert("1", "user1");
		DoublyLinkedList<Score>::Iterator it0 = list.begin();
		DoublyLinkedList<Score>::Iterator it1 = list.begin();
		EXPECT_FALSE(it0 != it1);
	}

	//  ID: 26
	//  �e�X�g����: �قȂ�C�e���[�^���r�����ۂ̋���
	//  �z�肷��߂�l: true
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