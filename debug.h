#ifndef __DEBUG_H__
#define __DEBUG_H__

#define DEBUG

#ifdef  DEBUG
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
    #define ERR(A,M,...)
    #define _INFO(M,...)
    #define INFO(M)
    
#endif

#endif /* __DEBUG_H__ */

