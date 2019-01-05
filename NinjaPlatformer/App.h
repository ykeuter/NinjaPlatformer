//
//  App.h
//  NinjaPlatformer
//
//  Created by Yvo Keuter on 9/23/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __NinjaPlatformer__App__
#define __NinjaPlatformer__App__

#include <GameEngine/IMainGame.h>
#include "GameplayScreen.h"
#include <memory>

// Our custom app that inherits from IMainGame
class App : public GameEngine::IMainGame{
public:
    App();
    ~App();
    
    // Called on initialization
    virtual void onInit() override;
    // For adding all screens
    virtual void addScreens() override;
    // Called when exiting
    virtual void onExit() override;
private:
    std::unique_ptr<GameplayScreen> m_gameplayScreen = nullptr;
};

#endif /* defined(__NinjaPlatformer__App__) */
