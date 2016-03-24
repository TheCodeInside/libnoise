#pragma once

#if defined(NOISE_BUILD)
#  if defined(NOISE_SHARED_LIB)
#    if defined(__GNUG__)
#      define NOISE_EXPORT __attribute__((__visibility__("default")))
#    elif defined(_MSC_VER)
#      define NOISE_EXPORT __declspec(dllexport)
#    else
#      error "Could not detect compiler for exporting."
#    endif
#  endif
#else
#  if defined(__GNUG__)
#    define NOISE_EXPORT __attribute__((__visibility__("default")))
#  elif defined(_MSC_VER)
#    define NOISE_EXPORT __declspec(dllimport)
#  endif
#endif

#if !defined(NOISE_EXPORT)
#  define NOISE_EXPORT
#endif
