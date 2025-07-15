#pragma once

#include <memory>

template <typename T>
class Singleton
{
public:
	static std::shared_ptr<T> instance()
	{
		static std::shared_ptr<T> self;

		if (self == nullptr)
		{
			self = std::make_shared<T>();
		}
		return self;
	}
};
