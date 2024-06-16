#pragma once
#include "SpriteEntity.h"

class Bird : public SpriteEntity
{
public:
    Bird(const std::string& file_path, sf::Vector2f position, float rotation);

    void update(sf::Time delta_time) override;
    void jump();

private:
    float max_down_speed_ { 400.f };
    float gravity_{ 1800.f };
    sf::IntRect bird_frame{ 314, 0, 314, 204 };
};