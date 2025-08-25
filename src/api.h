#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define Jvrcpd_DLLIMPORT __declspec(dllimport)
#  define Jvrcpd_DLLEXPORT __declspec(dllexport)
#  define Jvrcpd_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define Jvrcpd_DLLIMPORT __attribute__((visibility("default")))
#    define Jvrcpd_DLLEXPORT __attribute__((visibility("default")))
#    define Jvrcpd_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define Jvrcpd_DLLIMPORT
#    define Jvrcpd_DLLEXPORT
#    define Jvrcpd_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef Jvrcpd_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define Jvrcpd_DLLAPI
#  define Jvrcpd_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef Jvrcpd_EXPORTS
#    define Jvrcpd_DLLAPI Jvrcpd_DLLEXPORT
#  else
#    define Jvrcpd_DLLAPI Jvrcpd_DLLIMPORT
#  endif // Jvrcpd_EXPORTS
#  define Jvrcpd_LOCAL Jvrcpd_DLLLOCAL
#endif // Jvrcpd_STATIC