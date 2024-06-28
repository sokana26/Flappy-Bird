#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity() = default;
	Entity(sf::Vector2f p, float r, int priority);
	Entity() = default;

	int priority{};
	virtual void init() {}
	virtual void update(sf::Time delta_time);
	virtual void processEvents(const sf::Event &evnt) {}
	virtual void draw(sf::RenderTarget &texture) {}

	void setPosition(sf::Vector2f position) { entity_position_ = position; }
	sf::Vector2f getPosition() const { return entity_position_; }
	
	void setRotation(float rotation) { entity_rotation_ = rotation; }
	float getRotation() const { return entity_rotation_; }

	bool operator<(const Entity& p) const
	{
		return this->priority < p.priority;
	}
	
protected:
	sf::Vector2f entity_position_;
	sf::Vector2f entity_velocity_;
	float entity_rotation_;
};