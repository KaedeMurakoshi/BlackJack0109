#pragma once

#include "Person.h"

//�v���C���[�N���X
class Player : public Person
{
public:
	Player(const char* pName);
protected:
	//�Q�[�����s
	void playBase(Shoe* shoe);
};