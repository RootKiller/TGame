/**
 * @brief MemFunctions.h
 *
 * @brief Set of the memory realted functions.
 */

#pragma once

#include "TypeTraits.h"

namespace Memory {

/**
 * @brief Delete function working with both vector and standard pointer types.
 *
 * @pre Make sure that the object provided to this method is not null pointer.
 * @note Causes compilation error in case we want to remove not complete object.
 * @post It is responsibility of the caller to set pointer to nullptr after removing it.
 *
 * @param[in] object The object to be removed.
 */
template <typename OBJECT_NAME>
static void DeleteCompleteObject(OBJECT_NAME *const object)
{
	static_assert(sizeof(OBJECT_NAME) > 0, "Tried to remove incomplete type object");
	assert(object);

	if (IsVectorType<OBJECT_NAME>::Value) {
		delete []object;
	}
	else {
		delete object;
	}
}

} /* namespace Memory */

/* eof */
