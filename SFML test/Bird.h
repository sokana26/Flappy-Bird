#pragma once
#include "SpriteEntity.h"

class Bird : public SpriteEntity
{
public:
    Bird(const std::string& file_path, sf::Vector2f position, float rotation, int priority);

    void update(sf::Time delta_time) override;
    void jump();

private:
    float max_down_speed_ { 400.f };
    float gravity_{ 2000.f };
    sf::IntRect bird_frame{ 314, 0, 314, 204 };

    float time_passed_ = 0.f;
    float switch_frame_time_ = 0.2f;
    int left_coord_ = 0;
    int frame_width_ = 314;
    int frame_number_ = 3;
};