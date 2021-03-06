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
 * e-mail: habdank AT gmail DOT com
 * e-mail: janusz.rybarski AT gmail DOT com
 *
 * File created: Tue 11 Apr 2006 15:01:26 CEST
 * Last modified: Sun 26 Nov 2006 09:28:46 CET
 */

#ifndef BASIC_NEURON_HPP_INCLUDED
#define BASIC_NEURON_HPP_INCLUDED

/**
 * \file basic_neuron.hpp
 * \brief File contains template class Basic_neuron.
 * \ingroup neural_net
 */

/**
 * \defgroup neural_net Neural network
 */

/**
 * \namespace neural_net
 * \brief Neural network namespace
 * \ingroup neural_net
 */

/**
 * \addtogroup neural_net
 */
/*\@{*/
namespace neural_net
{
    /**
     * \class Basic_neuron
     * \brief Basic_neuron template class.
     * \param Activation_function_type
     * is a functor type of activation function.
     * \param Binary_operation_type
     * is a type of binary operation used in neuron values.
     * \param Weigths_type is type of weights.
     */
    template
    <
        typename Activation_function_type,
        typename Binary_operation_type
    >
    class Basic_neuron
    {
    public:

        /** Weights type. */
        typedef typename Binary_operation_type::value_type weights_type;

        /** Activation function type. */
        typedef Activation_function_type activation_function_type;

        /** Binary operation type. */
        typedef Binary_operation_type binary_operation_type;
        typedef typename Binary_operation_type::value_type value_type;
        typedef typename Activation_function_type::result_type result_type;

        /** Activation function functor. */
        Activation_function_type activation_function;

        /** Weak and generalized distance function. */
        Binary_operation_type binary_operation;

        /** Weights. */
        weights_type weights;

        /**
         * Constructor.
         * \param weights_ are weights of the neuron.
         * \param activation_function_ is an activation
         *                              function of the neuron.
         * \param binary_operation_ is an operation calculated
         *                             on weights and data, before
         *                             activation function.
         */
        Basic_neuron
        (
            weights_type const & weights_,
            Activation_function_type const & activation_function_,
            Binary_operation_type const & binary_operation_
        )
        : activation_function ( activation_function_ ),
        binary_operation ( binary_operation_ ),
        weights ( weights_ )
        {}

        /**
         * Calculation function.
         * \param x input value for the neuron.
         * \return output from neuron.
         * \f[
         * y = f ( g ( w,x ) )
         * \f]
         * where: f is activation function, g is binary operation,
         * w is weight and x is input value.
         */
        typename Activation_function_type::result_type
        operator() ( value_type const & x ) const
        {
            // calculate output of the neuron as activation fuction
            // working on results from binary operation on weights and value
            // composition of activation and distance function
            return activation_function ( binary_operation ( weights, x ) );
        }

        /** Copy constructor. */
        template
        <
            typename Activation_function_type_2,
            typename Binary_operation_type_2
        >
        Basic_neuron
        (
            Basic_neuron
            <
                Activation_function_type_2,
                Binary_operation_type_2
            >
            const & neuron_
        )
        {
            activation_function = neuron_.activation_function;
            binary_operation = neuron_.binary_operation;
            weights = neuron_.weights;
        }

    protected:
        Basic_neuron();
    };
} // namespace neural_net
/*\@}*/

#endif // BASIC_NEURON_HPP_INCLUDED
