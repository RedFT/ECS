#ifndef __HELPERS_H__
#define __HELPERS_H__

#define NEW(type)                       type##_new()
#define INIT(type,object)               type##_init((type *) &object);

// sf stands for speed factor
#define UPDATE(object,sf)               object.update(&object, sf); 
#define CLEAN(object)                   object.clean(&object);

#define REGISTER(registrar,object_type,object); registrar.register##object_type(&registrar,object);

#define FREE(object)            \
    if (object)                 \
        free(object);           \
    else                        \
        fprintf(stderr, "%s : %d :: Tried to free null ptr\n", __FILE__, __LINE__)



#define IN_RANGE_INC(x,min,max) (x >  min && x <  max)
#define IN_RANGE_EXC(x,min,max) (x >= min && x <= max)

#endif /* __HELPERS_H__ */

