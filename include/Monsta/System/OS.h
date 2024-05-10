//
// Created by Mustafa Malik on 07/05/2024.
//

#ifndef __LIBMONSTA_SYSTEM_OS_H__
#define __LIBMONSTA_SYSTEM_OS_H__

#include <cstring>
#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#   define MONSTA_OS    "win"
#elif defined(__unix__) || (__unix) || (unix)
#   define MONSTA_OS    "lin"
#elif defined(__APPLE__)
#   define MONSTA_OS    "mac"
#   include <CoreServices/CoreServices.h>
#endif

namespace Monsta::System
{

    inline static const char* os_name()
    {
        return MONSTA_OS;
    }

}


#endif /* __LIBMONSTA_SYSTEM_OS_H__ */
