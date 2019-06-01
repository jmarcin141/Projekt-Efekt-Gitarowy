#pragma once


#include "EffectBody.h"
#include "EchoBody.h"


//...#include "EffectBody.h"

#include <memory>

class EffectHandle
{
private:
	using BodyPtr = std::unique_ptr <EffectBody>;
	BodyPtr fBodyObj;

public:
	enum class EffectType
	{
		ECHO, DISTORTION, WAHWAH, EFFECTX
	};

	EffectHandle(EffectType type); 
	virtual void effect(std::vector<sf::Int16> &samples);

	virtual ~EffectHandle() = default;
};

