#pragma once
#include "AbstractHandler.h"

class Website : public AbstractHandler {
    vector<Game> game;

public:
    void PuchGame();
    void DeleteGame();
    void ShowGame();
    void EditGame();
    void WriteInFile();
    void ReadFile();

    Game Handle(Game request) override;
};