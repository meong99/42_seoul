#include "Serialize.hpp"

uintptr_t	serialize(t_Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

t_Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<t_Data *>(raw);
}