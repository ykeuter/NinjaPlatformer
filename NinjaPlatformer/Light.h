//
//  Light.h
//  NinjaPlatformer
//
//  Created by Yvo Keuter on 9/28/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __NinjaPlatformer__Light__
#define __NinjaPlatformer__Light__

#include <glm/glm.hpp>
#include <GameEngine/Vertex.h>
#include <GameEngine/SpriteBatch.h>

class Light {
public:
    void draw(GameEngine::SpriteBatch& spriteBatch) {
        glm::vec4 destRect;
        destRect.x = position.x - size / 2.0f;
        destRect.y = position.y - size / 2.0f;
        destRect.z = size;
        destRect.w = size;
        spriteBatch.draw(destRect, glm::vec4(-1.0f, -1.0f, 2.0f, 2.0f), 0, 0.0f, color, 0.0f);
    }
    
    GameEngine::ColorRGBA8 color;
    glm::vec2 position;
    float size;
};

#endif /* defined(__NinjaPlatformer__Light__) */
