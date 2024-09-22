#include "intro.h"
#include "mainwindow.h"
#include "locator.hpp"

Intro::Intro()
    : win{ Locator<MainWindow>::get() }, background{ "D:/UTC2/FlappyBirdOOP/FlappyBird/FlappyBird/x64/Debug/flappy_assets/clouds.jpg" }, title{}, subtitle{}, f1{}, f2{}
{
    f1.loadFromFile("D:/UTC2/FlappyBirdOOP/FlappyBird/FlappyBird/x64/Debug/flappy_assets/CSFONT-TwistyPixel.ttf", 40);
    f2.loadFromFile("D:/UTC2/FlappyBirdOOP/FlappyBird/FlappyBird/x64/Debug/flappy_assets/CSFONT-TwistyPixel.ttf", 26);
    title.loadFromRenderedText("Flappy Bird - UTC2 Remake", f1, SDL_Color{ 0xFF,0,0,0xFF });
    subtitle.loadFromRenderedText("Press to continue...", f2, SDL_Color{ 0,0,0,0xFF });
    
} // nhấn là nó nhảy

void Intro::handle_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {        if (e.type == SDL_QUIT) {
            GameState::next_state = GameStates::Quit;
        }
        else if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_FINGERDOWN) {
            GameState::next_state = GameStates::Level;
        }
    }
}

void Intro::logic()
{
    background.scroll(3);
}

void Intro::render()
{
    win->clear();
    background.render();

    // Calculate title position (centered horizontally and vertically)
    int titleX = static_cast<int>((win->getWidth() - title.getWidth()) / 2);
    int titleY = static_cast<int>((win->getHeight() - title.getHeight()) / 2);

    // Render the title
    title.render(titleX, titleY);

    // Add spacing between title and subtitle
    int verticalSpacing = 50;  // Adjust this value to increase/decrease the space between the title and subtitle

    // Calculate subtitle position (centered horizontally, below the title)
    int subtitleX = static_cast<int>((win->getWidth() - subtitle.getWidth()) / 2);
    int subtitleY = titleY + title.getHeight() + verticalSpacing;

    // Render the subtitle
    subtitle.render(subtitleX, subtitleY);

    win->update();
}
