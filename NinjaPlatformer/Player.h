//
//  Player.h
//  NinjaPlatformer
//
//  Created by Yvo Keuter on 9/25/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __NinjaPlatformer__Player__
#define __NinjaPlatformer__Player__

#include "Capsule.h"
#include <GameEngine/InputManager.h>
#include <GameEngine/SpriteBatch.h>
#include <GameEngine/TileSheet.h>

enum class PlayerMoveState {STANDING, RUNNING, PUNCHING, IN_AIR };

class Player {
public:
    void init(b2World* world,
              const glm::vec2& position,
              const glm::vec2& drawDims,
              const glm::vec2& collisionDims,
              GameEngine::ColorRGBA8 color);
    
    void draw(GameEngine::SpriteBatch& spriteBatch);
    void drawDebug(GameEngine::DebugRenderer& debugRenderer);

    
    void update(GameEngine::InputManager& inputManager);
    
    const Capsule& getCapsule() const { return m_capsule; }
    
    glm::vec2 getPosition() const {
        glm::vec2 rv;
        rv.x = m_capsule.getBody()->GetPosition().x;
        rv.y = m_capsule.getBody()->GetPosition().y;
        return rv;
    }
    
private:
    glm::vec2 m_drawDims;
    GameEngine::ColorRGBA8 m_color;
    GameEngine::TileSheet m_texture;
    Capsule m_capsule;
    PlayerMoveState m_moveState = PlayerMoveState::STANDING;
    float m_animTime = 0.0f;
    int m_direction = 1; // 1 or -1
    bool m_onGround = false;
    bool m_isPunching = false;
};

#endif /* defined(__NinjaPlatformer__Player__) */
