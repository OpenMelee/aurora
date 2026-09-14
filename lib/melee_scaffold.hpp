#pragma once
/*
 * OpenMelee debug-scaffolding gate for the probes this fork adds to aurora.
 *
 * Deliberately self-contained: it pulls in nothing but <cstdio>, so aurora
 * still compiles standalone in its own CI, where OPENMELEE_SCAFFOLD is never
 * defined and every probe disappears.  OpenMelee defines the macro for its
 * Debug and RelWithDebInfo configurations only (see the parent CMakeLists.txt),
 * which keeps the OPENMELEE_TRACE_* / OPENMELEE_LIGHTLOG recipes working in
 * developer builds while Release ships none of the format strings.
 *
 * The format string and arguments are macro parameters the Release expansion
 * never uses, so nothing reaches the compiler at all -- the same guarantee as
 * include/openmelee_scaffold.h on the melee side.
 */
#include <cstdio>

#ifdef OPENMELEE_SCAFFOLD
#define OPENMELEE_PROBE(...) ((void) std::fprintf(stderr, __VA_ARGS__))
#else
#define OPENMELEE_PROBE(...) ((void) 0)
#endif
