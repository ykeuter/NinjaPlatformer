//
//  Capsule.h
//  NinjaPlatformer
//
//  Created by Yvo Keuter on 9/28/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#ifndef __NinjaPlatformer__Capsule__
#define __NinjaPlatformer__Capsule__

#include <Box2D/Box2D.h>
#include <glm/glm.hpp>
#include <GameEngine/DebugRenderer.h>

class Capsule {
public:
    void init(b2World* world,
              const glm::vec2& position,
              const glm::vec2& dimensions,
              float density,
              float friction,
              bool fixedRotation);
    
    void drawDebug(GameEngine::DebugRenderer& debugRenderer);
    
    b2Body* getBody() const { return m_body; }
    b2Fixture* getFixture(int index) const { return m_fixtures[index]; }
    const glm::vec2& getDimensions() const { return m_dimensions; }
private:
    b2Body* m_body = nullptr;
    b2Fixture* m_fixtures[3];
    glm::vec2 m_dimensions;
};

#endif /* defined(__NinjaPlatformer__Capsule__) */
