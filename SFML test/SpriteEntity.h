#pragma once
#include "Entity.h"

class SpriteEntity : public Entity
{
public:
    SpriteEntity(const std::string& file_path, sf::Vector2f position, float rotation, int priority);

    void draw(sf::RenderTarget& texture) override;
    void update(sf::Time delta_time) override;

protected:
    sf::Sprite sprite_;
    sf::Texture texture_;
};