//
// Created by Dustella on 12/11/2023.
//

#include "Application.h"
#include "views/MainMenu.h"
#include "stores/Store.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>

Application::Application() {

    auto studentStore = Store::getStudent();
    studentStore->loadStorage();
    bootstrap();
}

void Application::bootstrap() {
    UI *currentFrame = new MainMenu();
    while (currentFrame != nullptr) {
        if (system("cls")) system("clear");
        currentFrame->show();
        currentFrame = currentFrame->getNextFrame();
//        clear console
    }
}