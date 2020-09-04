#pragma once
#include <string>
#include "Game.h"

using namespace std;

// Интерфейс Обработчика объявляет метод построения цепочки обработчиков. Он также объявляет метод для выполнения запроса
class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual Game Handle(Game request) = 0;
};