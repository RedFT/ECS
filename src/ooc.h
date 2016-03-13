#ifndef __OOC_H__
#define __OOC_H__

#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"


/* - Struct creation shortcut -   
 */
#define CLASS(name,...) \
    typedef struct name \
    {                   \
        __VA_ARGS__     \
    } name;
    

/* - Struct extension shortctut -  
 * pass the 'parent' field of 
 * the struct when using 
 * functions for the 
 * "parent class"
 */
#define CLASS_EXT(name,super,...)   \
    typedef struct                  \
    {                               \
        union                       \
        {                           \
            struct super;           \
            super parent;           \
        };                          \
        __VA_ARGS__                 \
    } name; 

#endif /* __OOC_H__ */

