#include "Object.hpp"

#include "globalConstsAndVars.hpp"

namespace nf {
	Object::Object(const sf::Vector2f& position, const sf::Vector2f& speed, const float radius, const float mass, const float bounceCoefficient, sf::Color color):
		mPosition(position), mSpeed(speed), mRadius(radius), mMass(mass), mBounceCoefficient(bounceCoefficient), mShape(mRadius){
		mShape.setOrigin(mRadius, mRadius);
		mShape.setPosition(mPosition);
		mShape.setFillColor(color);
	}

	void Object::setPosition(const sf::Vector2f& position) {
		mPosition = position;
		mShape.setPosition(mPosition);
	}
	void Object::setSpeed(const sf::Vector2f& speed) {
		mSpeed = speed;
	}
	void Object::setRadius(const float radius) {
		mRadius = radius;
	}
	void Object::setMass(const float mass) {
		mMass = mass;
	}

	const sf::Vector2f& Object::getPosition() const {
		return mPosition;
	}
	const sf::Vector2f& Object::getSpeed() const {
		return mSpeed;
	}
	const float Object::getRadius() const {
		return mRadius;
	}
	const float Object::getMass() const {
		return mMass;
	}
	const sf::Shape& Object::getShape() const {
		return mShape;
	}

	void Object::update(const sf::Time& deltaTime) {
		mSpeed += Gravity * deltaTime.asSeconds();
		mSpeed -= mSpeed * mRadius * EnviromentDensity / mMass;
		mPosition += mSpeed * deltaTime.asSeconds();
		mShape.setPosition(mPosition);
	}

	bool Object::isCollidingWithTopWall() {
		if (mPosition.y - mRadius <= 0.f) {
			return true;
		}
		return false;
	}
	bool Object::isCollidingWithBottomWall() {
		if (mPosition.y + mRadius >= WindowHeight) {
			return true;
		}
		return false;
	}
	bool Object::isCollidingWithLeftWall() {
		if (mPosition.x - mRadius <= 0.f) {
			return true;
		}
		return false;
	}
	bool Object::isCollidingWithRightWall() {
		if (mPosition.x + mRadius >= WindowWidth) {
			return true;
		}
		return false;
	}

	void Object::ressolveCollisionWithTopWall() {
		mSpeed.x *= mBounceCoefficient;
		mSpeed.y *= -mBounceCoefficient;

		mPosition.y = mRadius;
	}
	void Object::ressolveCollisionWithBottomWall() {
		mSpeed.x *= mBounceCoefficient;
		mSpeed.y *= -mBounceCoefficient;

		mPosition.y = WindowHeight - mRadius;
	}
	void Object::ressolveCollisionWithLeftWall() {
		mSpeed.x *= -mBounceCoefficient;
		mSpeed.y *= mBounceCoefficient;

		mPosition.x = mRadius;
	}
	void Object::ressolveCollisionWithRightWall() {
		mSpeed.x *= -mBounceCoefficient;
		mSpeed.y *= mBounceCoefficient;

		mPosition.x = WindowWidth - mRadius;
	}
}