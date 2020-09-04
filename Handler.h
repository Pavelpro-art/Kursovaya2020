#pragma once
#include <string>
#include "Game.h"

using namespace std;

// ��������� ����������� ��������� ����� ���������� ������� ������������. �� ����� ��������� ����� ��� ���������� �������
class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual Game Handle(Game request) = 0;
};