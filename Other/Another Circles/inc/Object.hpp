#pragma once

#include <SFML/Graphics.hpp>

namespace nf {
	class Object {
	private:
		sf::Vector2f mPosition, mSpeed;
		float mRadius, mMass, mBounceCoefficient;
		sf::CircleShape mShape;
	public:
		Object(const sf::Vector2f& position, const sf::Vector2f& speed, const float radius, const float mass, const float bounceCoefficient, sf::Color color);

		void setPosition(const sf::Vector2f& position);
		void setSpeed(const sf::Vector2f& speed);
		void setRadius(const float radius);
		void setMass(const float mass);

		const sf::Vector2f& getPosition() const;
		const sf::Vector2f& getSpeed() const;
		const float getRadius() const;
		const float getMass() const;
		const sf::Shape& getShape() const;

		void update(const sf::Time& deltaTime);

		bool isCollidingWithTopWall();
		bool isCollidingWithBottomWall();
		bool isCollidingWithLeftWall();
		bool isCollidingWithRightWall();

		void ressolveCollisionWithTopWall();
		void ressolveCollisionWithBottomWall();
		void ressolveCollisionWithLeftWall();
		void ressolveCollisionWithRightWall();
	};
}