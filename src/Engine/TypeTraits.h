/**
 * @file TypeTraits.h
 *
 * @brief Set of the type related traits.
 */
#pragma once

template <typename OBJECT_TYPE>
struct IsVectorType
{
	static const bool Value = false;
};

template <typename OBJECT_TYPE>
struct IsVectorType<OBJECT_TYPE[]>
{
	static const bool Value = true;
};

/* eof */
