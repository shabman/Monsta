#ifndef __LIBMONSTA_PLATFORM_H__
#define __LIBMONSTA_PLATFORM_H__

#if defined(_WIN32) || defined(_WIN64)
#   define MONSTA_PLAT_WIN
#elif defined(__APPLE__)
#   define MONSTA_PLAT_MAC
#elif defined(unix) || defined(__unix) || defined(__UNIX__)
#   define MONSTA_PLAT_LIN
#endif

#endif /* __LIBMONSTA_PLATFORM_H__ */