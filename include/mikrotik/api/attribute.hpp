// BSD 3-Clause License
//
// Copyright (c) 2020, bodand
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by bodand on 2020-06-27.
//

#pragma once

// stdlib
#include <string>
#include <string_view>

// project
#include <mikrotik_api_export.h>

namespace mikrotik::api {
    /**
     * \brief A little utility class containing an attribute name and a value
     *
     * A simple utility class, mostly used by the DSL.
     * Upon creation it formats the values into `=<name>=<value>`, where value
     * may be empty.
     *
     * \since v1.0.0
     */
    struct MIKROTIK_API_EXPORT attribute {
        /**
         * \brief A construct valueless attribute
         *
         * Constructs an attribute with the specified name with
         * the empty string as a value.
         *
         * The attribute will be in the form `=<name>=`.
         *
         * \param name The name of the attribute to create
         *
         * \since v1.0.0
         */
        attribute(std::string_view name);
        /**
         * \copydoc attribute(std::string_view)
         */
        attribute(const char* name);
        /**
         * \brief A construct an attribute with a specified value
         *
         * Constructs an attribute with the specified name with the
         * specified value.
         * The attribute will be in the form `=<name>=<value>`.
         *
         * \param name The name of the attribute to create
         * \param value The value of the attribute to create
         *
         * \since v1.0.0
         */
        attribute(std::string_view name, std::string_view value);
        /**
         * \copydoc attribute(std::string_view, std::string_view)
         */
        attribute(const char* name, const char* value);

        std::string value; ///< The attribute in the required format for MikroTik
    };
}
