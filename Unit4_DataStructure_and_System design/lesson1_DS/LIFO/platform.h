#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <stdbool.h>
#include <stdint.h>

#ifndef _Bool
#define _Bool unsigned char
#endif


#ifndef FALSE
#define FALSE (boolean)false
#endif

#ifndef TRUE
#define TRUE (boolean)true
#endif

//symbols:
#define CPU_TYPE 	  		CPU_TYPE_32
#define CPU_BIT_ORDER 		LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

//types:
typedef		_Bool        boolean;

typedef 	char          int8;
typedef 	short		  int16;
typedef 	int 		  int32;
typedef 	long long int int64;

typedef 	signed char          sint8;
typedef 	signed short		 sint16;
typedef 	signed int 			 sint32;
typedef 	signed long long int sint64;

typedef 	unsigned char 		   uint8;
typedef 	unsigned short		   uint16;
typedef 	unsigned int 		   uint32;
typedef 	unsigned long long int uint64;

typedef 	volatile sint8  vint8;
typedef 	volatile sint16 vint16;
typedef 	volatile sint32 vint32;
typedef 	volatile sint64 vint64;

typedef 	volatile uint8  vuint8;
typedef 	volatile uint16 vuint16;
typedef 	volatile uint32 vuint32;
typedef 	volatile uint64 vuint64;

typedef 	const sint8  cint8;
typedef 	const sint16 cint16;
typedef 	const sint32 cint32;
typedef 	const sint64 cint64;

typedef 	const uint8  cuint8;
typedef 	const uint16 cuint16;
typedef 	const uint32 cuint32;
typedef 	const uint64 cuint64;

typedef 	float 		 float32;
typedef 	double  	 float64;

#endif
