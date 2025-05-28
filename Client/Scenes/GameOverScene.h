#pragma once
#include "Scene.h"
#include "../GameModeType.h"
#include "../TetrisBoard.h"

class GameOverScene: public Scene {

    constexpr static int END_WIDTH = 20;
    constexpr static int END_HEIGHT = 10;
public:
    GameOverScene(
        ConsoleRenderer& renderer, 
        InputManager* im,
        UIManager* um,
        SceneManager* sm);

    void Update(float deltaTime) override;

    void Draw() override;

private:
    int posX, posY;

};