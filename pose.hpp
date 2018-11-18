#pragma once

#include "vec.hpp"

template<class T>
class Pose2
{
public:
	Pose2() = default;
	Pose2(Vec2<T>& v, double angle_) :
		coord(v),
		angle(angle)
	{}

	Pose2(const T& x_, const T& y_, double angle_) :
		coord(x_, y_),
		angle(angle_)
	{}

	Vec2<T> coord;
	double  angle;
};

using Pose2f = Pose2<double>;
