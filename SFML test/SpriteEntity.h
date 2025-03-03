#pragma once
#include <string>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include "Entity.h"

class SpriteEntity : public Entity
{
public:
    SpriteEntity(const std::string& file_path, sf::Vector2f position, float rotation, int priority);

    void draw(sf::RenderTarget& texture) override;
    void update(sf::Time delta_time) override;

protected:
    sf::Texture texture_;
    sf::Sprite sprite_;
};