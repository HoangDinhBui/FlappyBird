#include "mainwindow.h"
#include "gamestate.h"
#include "intro.h"
#include "music.h"

#include <SDL.h>
#include <memory>
#undef main
int main()
{
    // MainWindow must be the first object instanciated
    MainWindow win(640, 480, "Flappy Bird UTC2");
    win.setIcon("D:/UTC2/FlappyBirdOOP/FlappyBird/FlappyBird/x64/Debug/flappy_assets/flappy.png");

    Music mus{ "D:/UTC2/FlappyBirdOOP/FlappyBird/FlappyBird/x64/Debug/flappy_assets/y2mate.com-PokemonBlackWhiteMusicDriftveilCityMusic.mp3" };
    mus.play();

    std::unique_ptr<GameState> currentState{ std::make_unique<Intro>() };

    while (GameState::curr_state != GameStates::Quit) {
        currentState->handle_events();
        currentState->logic();
        currentState->render();

        changeState(currentState);
    }

    return 0;
}