//
// Copyright (c) 2017 The nanoFramework project contributors
// Portions Copyright (c) Microsoft Corporation.  All rights reserved.
// See LICENSE file in the project root for full license information.
//
#ifndef _TINYCLR_PLATFORMDEF_H_
#define _TINYCLR_PLATFORMDEF_H_

//#include <CLR_Defines.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// PLATFORMS GENERAL DEFINITIONS
#if defined(_WIN32)
#define TINYCLR_STOP() ::DebugBreak()
#pragma warning( error : 4706 ) // error C4706: assignment within conditional expression
#elif defined(arm) || defined(__arm) || defined(__GNUC__)

#define PLATFORM_ARM
#define TINYCLR_STOP() HARD_BREAKPOINT()
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// DEFINITIONS
#define TINYCLR_VALIDATE_HEAP_0_None                0 // No Trace
#define TINYCLR_VALIDATE_HEAP_1_HeapBlocksAndUnlink 1 // Validate HeapBlocks and Unlink.
#define TINYCLR_VALIDATE_HEAP_2_DblLinkedList       2 // Validate a DblLinkedList before each operation.
#define TINYCLR_VALIDATE_HEAP_3_Compaction          3 // Trace Compaction
#define TINYCLR_VALIDATE_HEAP_4_CompactionPlus      4 // Trace Compaction Plus

#define TINYCLR_MAX_ASSEMBLY_NAME 128

////////////////////////////////////////////////////////////////////////////////////////////////////
// FEATURES


#if defined(PLATFORM_EMULATED_FLOATINGPOINT)
#define TINYCLR_EMULATED_FLOATINGPOINT    // use the fixed point floating point notation in the clr ocdes 
#endif

#if !defined(TINYCLR_NO_APPDOMAINS)
#define TINYCLR_APPDOMAINS           // enables application doman support
#endif
#define TINYCLR_TRACE_EXCEPTIONS     // enables exception dump support
#define TINYCLR_TRACE_ERRORS         // enables rich exception dump support
#if defined(DEBUG) || defined(_DEBUG)
#define TINYCLR_TRACE_STACK          // enables rich eval stack tracing  
#endif
//#define TINYCLR_TRACE_HRESULT        // enable tracing of HRESULTS from interop libraries 

//-o-//-o-//-o-//-o-//-o-//-o-//
// PLATFORMS
//-o-//-o-//-o-//-o-//-o-//-o-//


//--//
// Setting the threshold value to start Garbagge collector 
// PLATFORM_DEPENDENT_HEAP_SIZE_THRESHOLD should set in the file platform.settings file, eg sam7x_ek.settings. 
// defaults are 32Kb and 48 kb for lower and upper threshold respectively

#ifdef PLATFORM_DEPENDENT_HEAP_SIZE_THRESHOLD
#define HEAP_SIZE_THRESHOLD   PLATFORM_DEPENDENT_HEAP_SIZE_THRESHOLD
#else
#define HEAP_SIZE_THRESHOLD   48 * 1024
#endif

#ifdef PLATFORM_DEPENDENT_HEAP_SIZE_THRESHOLD_UPPER
#define HEAP_SIZE_THRESHOLD_UPPER   PLATFORM_DEPENDENT_HEAP_SIZE_THRESHOLD_UPPER
#else
#define HEAP_SIZE_THRESHOLD_UPPER   HEAP_SIZE_THRESHOLD + 16 * 1024
#endif

//--//

////////////////////////////////////////////////////////////////////////////////////////////////////
// WINDOWS
#if defined(_WIN32)
#define TINYCLR_GC_VERBOSE
#define TINYCLR_TRACE_MEMORY_STATS
#define TINYCLR_PROFILE_NEW
#define TINYCLR_PROFILE_NEW_CALLS
#define TINYCLR_PROFILE_NEW_ALLOCATIONS
#if defined(DEBUG) || defined(_DEBUG)
#define TINYCLR_VALIDATE_HEAP                   TINYCLR_VALIDATE_HEAP_2_DblLinkedList
//#define TINYCLR_TRACE_MALLOC
#define TINYCLR_FILL_MEMORY_WITH_DIRTY_PATTERN
#define TINYCLR_TRACE_EARLYCOLLECTION
#define TINYCLR_DELEGATE_PRESERVE_STACK
#define TINYCLR_VALIDATE_APPDOMAIN_ISOLATION
#define TINYCLR_TRACE_HRESULT        // enable tracing of HRESULTS from interop libraries 
#else //RELEASE
#define TINYCLR_VALIDATE_HEAP TINYCLR_VALIDATE_HEAP_0_None
#endif
#define TINYCLR_ENABLE_SOURCELEVELDEBUGGING
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// ARM
#if defined(PLATFORM_ARM)
#define TINYCLR_TRACE_MEMORY_STATS
#endif

//-o-//-o-//-o-//-o-//-o-//-o-//
// RULES AND DEPENDENCIES
//-o-//-o-//-o-//-o-//-o-//-o-//

////////////////////////////////////////////////////////////////////////////////////////////////////
// GENERAL RTM RULES
#if defined(BUILD_RTM) || defined(PLATFORM_NO_CLR_TRACE)
#undef TINYCLR_TRACE_MEMORY_STATS
#undef TINYCLR_TRACE_EXCEPTIONS 
#undef TINYCLR_TRACE_ERRORS
#undef TINYCLR_TRACE_EARLYCOLLECTION
#undef TINYCLR_VALIDATE_HEAP
#undef TINYCLR_FILL_MEMORY_WITH_DIRTY_PATTERN
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// TRACE DEPENDENCIES
#if defined(_WIN32)
#define TINYCLR_OPCODE_NAMES
#define TINYCLR_OPCODE_PARSER
#define TINYCLR_OPCODE_STACKCHANGES
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(TINYCLR_VALIDATE_HEAP)
#define      TINYCLR_VALIDATE_HEAP  TINYCLR_VALIDATE_HEAP_0_None
#endif

#if defined(TINYCLR_PROFILE_NEW_CALLS) && !defined(TINYCLR_PROFILE_HANDLER)
#define TINYCLR_PROFILE_HANDLER
#endif

//-o-//-o-//-o-//-o-//-o-//-o-//
// CODE
//-o-//-o-//-o-//-o-//-o-//-o-//

////////////////////////////////////////////////////////////////////////////////////////////////////
// LANGUAGE
#if defined(_WIN32)
#define PROHIBIT_ALL_CONSTRUCTORS(cls)   \
    private:                             \
        cls();                           \
        cls( cls& );                     \
        cls& operator=( const cls& )

#define PROHIBIT_COPY_CONSTRUCTORS(cls)  \
    public:                              \
        cls() {}                         \
    private:                             \
        cls( cls& );                     \
        cls& operator=( const cls& )

#define PROHIBIT_COPY_CONSTRUCTORS2(cls) \
    private:                             \
        cls( cls& );                     \
        cls& operator=( const cls& )

#define LONGLONGCONSTANT(v) (v##I64)
#define ULONGLONGCONSTANT(v) (v##UI64)
#endif

#if defined(PLATFORM_ARM)
#define PROHIBIT_ALL_CONSTRUCTORS(cls)   \
    private:                             \
        cls();                           \
        cls( cls& );                     \
        cls& operator=( const cls& )

#define PROHIBIT_COPY_CONSTRUCTORS(cls)  \
    public:                              \
        cls() {}                         \
    private:                             \
        cls( cls& );                     \
        cls& operator=( const cls& )

#define PROHIBIT_COPY_CONSTRUCTORS2(cls) \
    private:                             \
        cls( cls& );                     \
        cls& operator=( const cls& )

#define LONGLONGCONSTANT(v) (v##ll)
#define ULONGLONGCONSTANT(v) (v##ull)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#if defined(_WIN32)

#define _WIN32_WINNT 0x0501

//Unsafe string functions be avoided, but there isn't a safe crt for the arm, so 
//a bunch of macros, cleanup code needs to be done first

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

#include <crtdbg.h>

#include <string>
#include <list>
#include <vector>
#include <map>

#else

#include <tinyhal_types.h>

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef MAKE_HRESULT
#define MAKE_HRESULT(sev,fac,code) \
      ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )
#endif

#ifndef SEVERITY_SUCCESS
#define SEVERITY_SUCCESS    0
#endif

#ifndef SEVERITY_ERROR
#define SEVERITY_ERROR      1
#endif

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

#include <TinyHal.h>

///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(TINYCLR_PROFILE_NEW_CALLS) && !defined(TINYCLR_PROFILE_NEW)
!ERROR "TINYCLR_PROFILER_NEW is required for TINYCLR_PROFILE_NEW_CALLS"
#endif

#if defined(TINYCLR_PROFILE_NEW_ALLOCATIONS) && !defined(TINYCLR_PROFILE_NEW)
!ERROR "TINYCLR_PROFILER_NEW is required for TINYCLR_PROFILE_NEW_ALLOCATIONS"
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _TINYCLR_PLATFORMDEF_H_
