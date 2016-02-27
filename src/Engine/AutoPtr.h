/**
 * @file AutoPtr.h
 *
 * @brief Auto pointer.
 */

#pragma once

#include <assert.h>

#include "Memory/MemFunctions.h"

/**
 * @brief Auto pointer class.
 *
 * Suitable for objects and arrays or vectors.
 */
template <typename OBJECT_TYPE>
class AutoPtr
{
private:
	OBJECT_TYPE		*m_object;

public:
			AutoPtr		()
		: m_object(nullptr)
	{
	}

			AutoPtr		(AutoPtr &ptr)
	{
		Transfer(ptr);
	}

explicit	AutoPtr		(OBJECT_TYPE *const object)
	{
		m_object = object;
	}

			~AutoPtr	()
	{
		Reset();
	}

	/**
	 * @brief Reset object hold by the pointer.
	 */
	void	Reset		(void)
	{
		if (m_object) {
			Memory::DeleteCompleteObject(m_object);
			m_object = nullptr;
		}
	}

	/**
	 * @brief Transfer object from different auto pointer.
	 *
	 * @param[in] ptr The auto pointer from which we take the object.
	 */
	void Transfer		(AutoPtr &ptr)
	{
		Reset();

		m_object = ptr;
		ptr.m_object = nullptr;
	}

	/**
	 * @brief Move assignment operator.
	 */
	void	operator=(AutoPtr &ptr)
	{
		Transfer(ptr);
	}

	/**
	 * @name Access operators and methods.
	 */
	//@{
	OBJECT_TYPE *Get	(void)
	{
		assert(m_object);
		return m_object;
	}

	OBJECT_TYPE *Get	(void) const
	{
		assert(m_object);
		return m_object;
	}

	OBJECT_TYPE *operator->(void)			{ return Get(); }
	OBJECT_TYPE *operator->(void)	const	{ return Get(); }
	OBJECT_TYPE *operator*(void)	const	{ return Get(); }

	operator OBJECT_TYPE*(void)				{ return Get(); }
	operator const OBJECT_TYPE*(void) const { return Get(); }
	//@}
};

/* eof */
