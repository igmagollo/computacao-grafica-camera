#include "../include/Vector3.hpp"
#include <math.h>
#include <limits>

using namespace cfs;

Vector3::Vector3() : sf::Vector3f() {};

Vector3::Vector3(float X, float Y, float Z) : sf::Vector3f(X, Y, Z) {};

Vector3::Vector3(const Vector3& vector) : sf::Vector3f(vector) {};

float Vector3::dot(const Vector3& A, const Vector3& B)
{
	return A.x * B.x + A.y * B.y + A.z * B.z;
}

double Vector3::mag() const
{
	return sqrt(Vector3::dot(*this, *this));
}

Vector3 Vector3::normalized() const
{
	const double mag = this->mag();
	if ( mag == 0 )
	{
		float inf = std::numeric_limits<float>::infinity();
		return Vector3(inf, inf, inf);
	}
	sf::Vector3f normalized((*this) * (1 / (float)mag));
	return Vector3(normalized.x, normalized.y, normalized.z);
}

Vector3 Vector3::cross(const Vector3& A, const Vector3& B)
{
	float x = (A.y * B.z - A.z * B.y);
	float y = (A.z * B.x - A.x * B.z);
	float z = (A.x * B.y - A.y * B.x);
	return Vector3(x, y, z);
}

double Vector3::angle(const Vector3& A, const Vector3& B)
{
	double pi = 3.14159265;
	return acos(Vector3::dot(A,B) / (A.mag() * B.mag())) * 180 / pi;
}
