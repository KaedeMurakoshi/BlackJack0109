#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// ���_�ケ�ꂭ�炢���Ă�OK...�ɍ���͂����Ⴄ
	bool _calcUpdate;
	int _handNum;
	int _score;
	char* _pName;

public:
	// �R���X�g���N�^
	Person(const char* pName);

	//�f�X�g���N�^
	virtual ~Person();

	//�X�R�A�̎擾(hit���ꂽ���̂ݍČv�Z�����)
	int getScore();

	//�J�[�h�̒ǉ�
	void hit(Shoe& shoe);

	//��D��\��
	void showHand();

	//���O���擾
	char* getName();

	//�^�[������
	bool play(Shoe* shoe);

protected:
	//���̂����Ȃ��悤��
	virtual void playBase(Shoe* shoe) = 0;	//�^�[�������{��

};

