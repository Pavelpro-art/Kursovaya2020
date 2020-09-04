#pragma once
#include <vector>
#include "Handler.h"

// Поведение цепочки по умолчанию может быть реализовано внутри базового класса обработчика
class AbstractHandler : public Handler {
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {
    }
    Handler* SetNext(Handler* handler) override {
        this->next_handler_ = handler;
        // Возврат обработчика отсюда позволит связать обработчики простым способом: &Website->setNext($Shop)->setNext(&Warehouse)
        return handler;
    }
    Game Handle(Game request) override {
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }
        Game empty_object("", "", 0, Platform::PC, "", "", 0);
        return empty_object;
    }

    virtual void PuchGame() {}
    virtual void DeleteGame() {}
    virtual void ShowGame() {}
    virtual void EditGame() {}
    virtual void WriteInFile() {}
    virtual void ReadFile() {}
};
