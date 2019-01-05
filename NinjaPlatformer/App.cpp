//
//  App.cpp
//  NinjaPlatformer
//
//  Created by Yvo Keuter on 9/23/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#include "App.h"
#include <GameEngine/ScreenList.h>


App::App() {
    
}

App::~App() {
    
}

void App::onInit() {
    
}

void App::addScreens() {
    m_gameplayScreen = std::unique_ptr<GameplayScreen>(new GameplayScreen(&m_window));
    
    m_screenList->addScreen(m_gameplayScreen.get());
    m_screenList->setScreen(m_gameplayScreen->getScreenIndex());
}

void App::onExit() {
    
}
