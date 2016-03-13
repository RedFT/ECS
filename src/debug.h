#ifndef __DEBUG_H__
#define __DEBUG_H__

#ifdef DEBUG
    #if  DEBUG != 0 
        // pass in !A if A not a pointer
        #define ERR(A,M,...) \
            if (!A) {        \
                fprintf(stderr, "[!] ERROR: " M " \n", __VA_ARGS__);\
                goto error;\
            }
           
        #define _INFO(M,...) \
                fprintf(stdout, "[+] MSG: " M " \n", __VA_ARGS__)

        #define INFO(M) (_INFO("%s", M))
        
    #else
        #define ERR(A,M,...) if (A && (1 == 0)) goto error;
        #define _INFO(M,...)
        #define INFO(M)
    #endif

/* if DEBUG is not defined at all */
#else
    #define ERR(A,M,...) if (A && (1 == 0)) goto error;
    #define _INFO(M,...)
    #define INFO(M)
    
#endif

#endif /* __DEBUG_H__ */

