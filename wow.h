/*
 * wow.h - Compilation attribute macros for better code optimization and safety
 *
 * This header defines macros to help with compiler-specific attributes,
 * such as symbol visibility, function inlining, deprecation warnings,
 * and other function or variable annotations to improve portability
 * and code clarity.
 *
 * Author: cpixou
 * Date: 2025
 */

#ifndef WOW_H
#define WOW_H

#if defined(_win32) || defined(__cygwin__)
#define export __declspec(dllexport)
#define import __declspec(dllimport)
#define local static
#define ainline __forceinline
#define noret __declspec(noreturn)
#define sassert static_assert
#define likely(x) (x)
#define unlikely(x) (x)
#elif defined(__GNUC__) || defined(__clang__)
#define export __attribute__((visibility("default")))
#define hidden __attribute__((visibility("hidden")))
#define local static __attribute__((visibility("hidden")))
#define ainline inline __attribute__((always_inline))
#define noret __attribute__((noreturn))
#define pure __attribute__((pure))
#define fconst __attribute__((const))
#define hot __attribute__((hot))
#define cold __attribute__((cold))
#define weak __attribute__((weak))
#define alias(x) __attribute__((alias(#x)))
#define constr __attribute__((constructor))
#define destr __attribute__((destructor))
#define fall __attribute__((fallthrough))
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define sassert _Static_assert
#define noreg __attribute__((regparm(0)))
#define flatten __attribute__((flatten))
#define noinline __attribute__((noinline))
#define retnnull __attribute__((returns_nonnull))
#define nnull(...) __attribute__((nonnull(__VA_ARGS__)))
#define dep __attribute__((deprecated))
#define used __attribute__((used))
#define unused __attribute__((unused))
#define cleanup(f) __attribute__((cleanup(f)))
#define error(msg) __attribute__((error(msg)))
#define warn(msg) __attribute__((warning(msg)))
#define transu __attribute__((transparent_union))
#else
#error "wow: compiler not supported"
#endif

#define packed __attribute__((packed))
#define aligned(n) __attribute__((aligned(n)))
#define section(n) __attribute__((section(n)))

#define reserved(id, n) unsigned char res##id : n
#define reserved8(id, n) unsigned char res8##id[n]

#endif
