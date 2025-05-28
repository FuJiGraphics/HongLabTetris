#include "GameScene.h"

PlayingScene::PlayingScene(
    ConsoleRenderer & renderer, 
    InputManager * im,
    UIManager* um,
    SceneManager * sm, 
    GameModeType mode)
    : Scene(renderer, im, um, sm), mCurrentMode(mode) {

	mRenderer.Clear();
	mFrame = mRenderer.AddFrame(10, 5, 40, 30);
    switch (mCurrentMode) {
    case GameModeType::Single: SetupSingleMode(); break;
    case GameModeType::Multiplayer: SetupMultiplayerMode(); break;
    }
}

void PlayingScene::Update(float deltaTime) {
    // 보드 업데이트
    for (auto& board : mBoards) {
        board->Update(deltaTime);
        if (board->IsFull()) {
            // Game Over
            mSceneManager->RequestSceneChange(SceneType::GameOver);
        }
    }
}

void PlayingScene::Draw() {
    for (auto& board : mBoards) {
        board->Draw();
    }
    mRenderer.Render();
}

void PlayingScene::SetupSingleMode() { /*...*/
    mBoards.emplace_back(std::make_shared<TetrisBoard>(mRenderer, 3, 3, 12, 24, mInputManager));
}

void PlayingScene::SetupMultiplayerMode() { /*...*/
}
