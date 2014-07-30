#ifndef NOISE_EXPORT_H
#define NOISE_EXPORT_H

#if defined( NOISE_BUILD ) || defined( NOISE_SHARED_LIB )
#  if defined( __GNUG__ )
#    define NOISE_EXPORT __attribute__((__visibility__("default")))
#  elif defined( _MSC_VER )
#    define NOISE_EXPORT __declspec(dllexport)
#  else
#    error Could not detect compiler for exporting
#  endif
#else
#  define NOISE_EXPORT
#endif

#endif