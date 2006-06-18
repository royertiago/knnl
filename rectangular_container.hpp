/*
 * Copyright (c) 2006, Seweryn Habdank-Wojewodzki
 * Copyright (c) 2006, Janusz Rybarski
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided
 * that the following conditions are met:
 *
 * Redistributions of source code must retain the above
 * copyright notice, this list of conditions and the
 * following disclaimer.
 *
 * Redistributions in binary form must reproduce the
 * above copyright notice, this list of conditions
 * and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS
 * AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * e-mail: habdank AT megapolis DOT pl
 * e-mail: janusz.rybarski AT ae DOT krakow DOT pl
 *
 * File created: Fri 14 Apr 2006 22:37:57 CEST
 * Last modified: Thu 08 Jun 2006 01:59:34 CEST
 */

#ifndef RECTANGULAR_CONTAINER_HPP_INCLUDED
#define RECTANGULAR_CONTAINER_HPP_INCLUDED

#include <vector>

/**
 * \file rectangular_container.hpp
 * \brief File contains class Rectangular_container
 * \ingroup neural_net
 */

namespace neural_net
{
	/**
	* \addtogroup neural_net
	*/
	/*\@{*/

	/**
	 * Stores size of container.
	 */
	typedef std::pair < size_t, size_t > Matrix_index;

	/**
	 * Rectangular_grid_container template class.
	 * \param Object_type is type of stored objects.
	 * \todo TODO: Rectangular_container class should be rewritten
	 * using new version of boost::matrix.
	 */
	template
	<
		typename Object_type
	>
	class Rectangular_container
	{
	public:

		typedef Object_type value_type;
		typedef typename std::vector < Object_type > column_type;
		typedef typename std::vector < column_type > row_type;

		typedef typename row_type::iterator row_iterator;
		typedef typename column_type::iterator column_iterator;

		/** Objects. */
		row_type objects;

		/**
		 * Constructor.
		 */
		Rectangular_container()
		{}

		/** Copy constructor. */
		template < typename Object_type_2 >
		Rectangular_container (
		const Rectangular_container < Object_type_2 > & rectangular_container )
		: objects ( rectangular_container.objects )
		{}

		inline const size_t get_no_columns() const
		{
			return objects.begin()->size();
		}

		inline const size_t get_no_rows() const
		{
			return objects.size();
		}

		inline const Matrix_index get_size() const
		{
			Matrix_index idx;
			idx.first = objects.size();
			idx.second = objects.begin()->size();

			return idx;
		}

	};
	/*\@}*/

} // namespace neural_net

#endif // RECTANGULAR_CONTAINER_HPP_INCLUDED

