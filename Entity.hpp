#pragma once
#include "pose.hpp"

class Entity
{
public:
	Entity() = default;

protected:
	Pose2f _pose;
};