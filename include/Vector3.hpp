#ifndef CFS_VECTOR3_HPP
#define CFS_VECTOR3_HPP

#include <SFML/System/Vector3.hpp>

namespace cfs
{
	class Vector3 : public sf::Vector3f
	{
	public:
		Vector3();

		Vector3(float X, float Y, float Z);

		Vector3(const Vector3& vector);

		static float dot(const Vector3& A, const Vector3& B);

		double mag() const;

		Vector3 normalized() const;

		static Vector3 cross(const Vector3& A, const Vector3& B);

		static double angle(const Vector3& A, const Vector3& B);
	};
}

#endif
