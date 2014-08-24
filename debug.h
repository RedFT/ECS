#ifndef __DEBUG_H__
#define __DEBUG_H__

#define ERR(A,M,...) \
        if (!A) {\
            fprintf(stderr, "[!] ERROR: " M " \n", __VA_ARGS__);\
            goto error;\
        }
        
#define _INFO(M,...) \
        fprintf(stdout, "[+] MSG: " M " \n", __VA_ARGS__)

#define INFO(M) (_INFO("%s", M))

#endif /* __DEBUG_H__ */

