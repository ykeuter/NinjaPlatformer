//
//  Box.cpp
//  NinjaPlatformer
//
//  Created by Yvo Keuter on 9/24/15.
//  Copyright (c) 2015 blabla. All rights reserved.
//

#include "Box.h"


Box::Box() {
}


Box::~Box() {
}

void Box::init(b2World* world,
               const glm::vec2& position,
               const glm::vec2& dimensions,
               GameEngine::GLTexture texture,
               GameEngine::ColorRGBA8 color,
               bool fixedRotation,
               glm::vec4 uvRect /*= glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)*/) {
    m_dimensions = dimensions;
    m_color = color;
    m_texture = texture;
    m_uvRect = uvRect;
    // Make the body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = fixedRotation;
    m_body = world->CreateBody(&bodyDef);
    
    b2PolygonShape boxShape;
    boxShape.SetAsBox(dimensions.x / 2.0f, dimensions.y / 2.0f);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    m_fixture = m_body->CreateFixture(&fixtureDef);
}

void Box::draw(GameEngine::SpriteBatch& spriteBatch) {
    glm::vec4 destRect;
    destRect.x = m_body->GetPosition().x - m_dimensions.x / 2.0f;
    destRect.y = m_body->GetPosition().y - m_dimensions.y / 2.0f;
    destRect.z = m_dimensions.x;
    destRect.w = m_dimensions.y;
    spriteBatch.draw(destRect, m_uvRect, m_texture.id, 0.0f, m_color, m_body->GetAngle());
}
