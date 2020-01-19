#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 150 "/usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h" 3
typedef int ptrdiff_t;
#line 212
typedef unsigned int size_t;
#line 324
typedef int wchar_t;
# 8 "/usr/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
#line 17
  int dummy;
}  ;
# 37 "/usr/include/stdint.h" 3
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;



__extension__ 
typedef long long int int64_t;




typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;





__extension__ 
typedef unsigned long long int uint64_t;






typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;



__extension__ 
typedef long long int int_least64_t;



typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;



__extension__ 
typedef unsigned long long int uint_least64_t;






typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__ 
typedef long long int int_fast64_t;



typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__ 
typedef unsigned long long int uint_fast64_t;
#line 126
typedef int intptr_t;


typedef unsigned int uintptr_t;








__extension__ 
typedef long long int intmax_t;
__extension__ 
typedef unsigned long long int uintmax_t;
# 35 "/usr/include/inttypes.h" 3
typedef int __gwchar_t;
#line 292
#line 288
typedef struct __nesc_unnamed4242 {

  long long int quot;
  long long int rem;
} imaxdiv_t;
# 281 "/usr/lib/ncc/nesc_nx.h"
static __inline uint8_t __nesc_ntoh_uint8(const void * source)  ;




static __inline uint8_t __nesc_hton_uint8(void * target, uint8_t value)  ;
#line 303
static __inline int8_t __nesc_hton_int8(void * target, int8_t value)  ;






static __inline uint16_t __nesc_ntoh_uint16(const void * source)  ;




static __inline uint16_t __nesc_hton_uint16(void * target, uint16_t value)  ;
#line 431
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 44 "/usr/include/string.h" 3
extern void *memcpy(void *__restrict __dest, 
const void *__restrict __src, size_t __n) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 65
extern void *memset(void *__s, int __c, size_t __n) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;


extern int memcmp(const void *__s1, const void *__s2, size_t __n) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1, 2))) ;
#line 128
extern char *strcpy(char *__restrict __dest, const char *__restrict __src) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 143
extern int strcmp(const char *__s1, const char *__s2) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1, 2))) ;
# 40 "/usr/include/xlocale.h" 3
#line 28
typedef struct __locale_struct {


  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 262 "/usr/include/string.h"
extern char *strrchr(const char *__s, int __c) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1))) ;
#line 399
extern size_t strlen(const char *__s) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1))) ;
# 67 "/usr/include/i386-linux-gnu/bits/waitstatus.h" 3
union wait {

  int w_status;
  struct __nesc_unnamed4243 {


    unsigned int __w_termsig : 7;
    unsigned int __w_coredump : 1;
    unsigned int __w_retcode : 8;
    unsigned int  : 16;
  } 






  __wait_terminated;
  struct __nesc_unnamed4244 {


    unsigned int __w_stopval : 8;
    unsigned int __w_stopsig : 8;
    unsigned int  : 16;
  } 





  __wait_stopped;
};
# 72 "/usr/include/stdlib.h" 3
#line 68
typedef union __nesc_unnamed4245 {

  union wait *__uptr;
  int *__iptr;
} __WAIT_STATUS __attribute((__transparent_union__)) ;
#line 102
#line 98
typedef struct __nesc_unnamed4246 {

  int quot;
  int rem;
} div_t;







#line 106
typedef struct __nesc_unnamed4247 {

  long int quot;
  long int rem;
} ldiv_t;







__extension__ 



#line 118
typedef struct __nesc_unnamed4248 {

  long long int quot;
  long long int rem;
} lldiv_t;
#line 158
__extension__ 
#line 195
__extension__ 




__extension__ 








__extension__ 




__extension__ 
# 31 "/usr/include/i386-linux-gnu/bits/types.h" 3
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ 
#line 47
typedef signed long long int __int64_t;
__extension__ 
#line 48
typedef unsigned long long int __uint64_t;







__extension__ 
#line 56
typedef long long int __quad_t;
__extension__ 
#line 57
typedef unsigned long long int __u_quad_t;
#line 134
__extension__ 
#line 134
typedef __u_quad_t __dev_t;
__extension__ 
#line 135
typedef unsigned int __uid_t;
__extension__ 
#line 136
typedef unsigned int __gid_t;
__extension__ 
#line 137
typedef unsigned long int __ino_t;
__extension__ 
#line 138
typedef __u_quad_t __ino64_t;
__extension__ 
#line 139
typedef unsigned int __mode_t;
__extension__ 
#line 140
typedef unsigned int __nlink_t;
__extension__ 
#line 141
typedef long int __off_t;
__extension__ 
#line 142
typedef __quad_t __off64_t;
__extension__ 
#line 143
typedef int __pid_t;
__extension__ 
#line 144
typedef struct __nesc_unnamed4249 {
#line 144
  int __val[2];
} 
#line 144
__fsid_t;
__extension__ 
#line 145
typedef long int __clock_t;
__extension__ 
#line 146
typedef unsigned long int __rlim_t;
__extension__ 
#line 147
typedef __u_quad_t __rlim64_t;
__extension__ 
#line 148
typedef unsigned int __id_t;
__extension__ 
#line 149
typedef long int __time_t;
__extension__ 
#line 150
typedef unsigned int __useconds_t;
__extension__ 
#line 151
typedef long int __suseconds_t;

__extension__ 
#line 153
typedef int __daddr_t;
__extension__ 
#line 154
typedef long int __swblk_t;
__extension__ 
#line 155
typedef int __key_t;


__extension__ 
#line 158
typedef int __clockid_t;


__extension__ 
#line 161
typedef void *__timer_t;


__extension__ 
#line 164
typedef long int __blksize_t;




__extension__ 
#line 169
typedef long int __blkcnt_t;
__extension__ 
#line 170
typedef __quad_t __blkcnt64_t;


__extension__ 
#line 173
typedef unsigned long int __fsblkcnt_t;
__extension__ 
#line 174
typedef __u_quad_t __fsblkcnt64_t;


__extension__ 
#line 177
typedef unsigned long int __fsfilcnt_t;
__extension__ 
#line 178
typedef __u_quad_t __fsfilcnt64_t;

__extension__ 
#line 180
typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ 
#line 189
typedef int __intptr_t;


__extension__ 
#line 192
typedef unsigned int __socklen_t;
# 34 "/usr/include/i386-linux-gnu/sys/types.h" 3
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
#line 61
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
#line 99
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 60 "/usr/include/time.h" 3
typedef __clock_t clock_t;
#line 76
typedef __time_t time_t;
#line 92
typedef __clockid_t clockid_t;
#line 104
typedef __timer_t timer_t;
# 151 "/usr/include/i386-linux-gnu/sys/types.h" 3
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
#line 201
typedef unsigned int u_int8_t __attribute((__mode__(__QI__))) ;
typedef unsigned int u_int16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int u_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int u_int64_t __attribute((__mode__(__DI__))) ;

typedef int register_t __attribute((__mode__(__word__))) ;
# 24 "/usr/include/i386-linux-gnu/bits/sigset.h" 3
typedef int __sig_atomic_t;







#line 29
typedef struct __nesc_unnamed4250 {

  unsigned long int __val[1024 / (8 * sizeof(unsigned long int ))];
} __sigset_t;
# 38 "/usr/include/i386-linux-gnu/sys/select.h" 3
typedef __sigset_t sigset_t;
# 120 "/usr/include/time.h" 3
struct timespec {

  __time_t tv_sec;
  long int tv_nsec;
};
# 31 "/usr/include/i386-linux-gnu/bits/time.h" 3
struct timeval {

  __time_t tv_sec;
  __suseconds_t tv_usec;
};
# 49 "/usr/include/i386-linux-gnu/sys/select.h" 3
typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
#line 76
#line 65
typedef struct __nesc_unnamed4251 {







  __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))];
} 

fd_set;






typedef __fd_mask fd_mask;
# 32 "/usr/include/i386-linux-gnu/sys/sysmacros.h" 3
__extension__ 


__extension__ 


__extension__ 
# 229 "/usr/include/i386-linux-gnu/sys/types.h" 3
typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 36 "/usr/include/i386-linux-gnu/bits/pthreadtypes.h" 3
typedef unsigned long int pthread_t;






#line 39
typedef union __nesc_unnamed4252 {

  char __size[36];
  long int __align;
} pthread_attr_t;





#line 46
typedef struct __pthread_internal_slist {

  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
#line 73
#line 54
typedef union __nesc_unnamed4253 {

  struct __pthread_mutex_s {

    int __lock;
    unsigned int __count;
    int __owner;


    int __kind;
    unsigned int __nusers;
    __extension__ union  {

      int __spins;
      __pthread_slist_t __list;
    } ;
  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;





#line 75
typedef union __nesc_unnamed4254 {

  char __size[4];
  long int __align;
} pthread_mutexattr_t;
#line 99
#line 84
typedef union __nesc_unnamed4255 {

  struct __nesc_unnamed4256 {

    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





#line 101
typedef union __nesc_unnamed4257 {

  char __size[4];
  long int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;
#line 139
#line 119
typedef union __nesc_unnamed4258 {

  struct __nesc_unnamed4259 {

    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;


    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;





#line 141
typedef union __nesc_unnamed4260 {

  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;








#line 156
typedef union __nesc_unnamed4261 {

  char __size[20];
  long int __align;
} pthread_barrier_t;





#line 162
typedef union __nesc_unnamed4262 {

  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 349 "/usr/include/stdlib.h" 3
struct random_data {

  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
#line 418
struct drand48_data {

  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  unsigned long long int __a;
};
#line 471
extern void *malloc(size_t __size) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__malloc__)) ;
#line 488
extern void free(void *__ptr) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 742
typedef int (*__compar_fn_t)(const void *arg_0x40397a98, const void *arg_0x40397c30);
#line 776
__extension__ 
#line 793
__extension__ 
# 36 "/usr/include/i386-linux-gnu/bits/mathdef.h" 3
typedef long double float_t;

typedef long double double_t;
# 110 "/usr/include/i386-linux-gnu/bits/mathcalls.h" 3
extern double log(double __x) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 155
extern double pow(double __x, double __y) __attribute((__leaf__)) __attribute((__nothrow__)) ;


extern double sqrt(double __x) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 186
extern double floor(double __x) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((const)) ;
#line 252
extern double erfc(double arg_0x403e6da8) __attribute((__leaf__)) __attribute((__nothrow__)) ;
# 203 "/usr/include/math.h" 3
enum __nesc_unnamed4263 {

  FP_NAN, 

  FP_INFINITE, 

  FP_ZERO, 

  FP_SUBNORMAL, 

  FP_NORMAL
};
#line 303
#line 296
typedef enum __nesc_unnamed4264 {

  _IEEE_ = -1, 
  _SVID_, 
  _XOPEN_, 
  _POSIX_, 
  _ISOC_
} _LIB_VERSION_TYPE;
#line 321
struct exception {


  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
};
# 48 "/usr/include/ctype.h" 3
enum __nesc_unnamed4265 {

  _ISupper = 0 < 8 ? (1 << 0) << 8 : (1 << 0) >> 8, 
  _ISlower = 1 < 8 ? (1 << 1) << 8 : (1 << 1) >> 8, 
  _ISalpha = 2 < 8 ? (1 << 2) << 8 : (1 << 2) >> 8, 
  _ISdigit = 3 < 8 ? (1 << 3) << 8 : (1 << 3) >> 8, 
  _ISxdigit = 4 < 8 ? (1 << 4) << 8 : (1 << 4) >> 8, 
  _ISspace = 5 < 8 ? (1 << 5) << 8 : (1 << 5) >> 8, 
  _ISprint = 6 < 8 ? (1 << 6) << 8 : (1 << 6) >> 8, 
  _ISgraph = 7 < 8 ? (1 << 7) << 8 : (1 << 7) >> 8, 
  _ISblank = 8 < 8 ? (1 << 8) << 8 : (1 << 8) >> 8, 
  _IScntrl = 9 < 8 ? (1 << 9) << 8 : (1 << 9) >> 8, 
  _ISpunct = 10 < 8 ? (1 << 10) << 8 : (1 << 10) >> 8, 
  _ISalnum = 11 < 8 ? (1 << 11) << 8 : (1 << 11) >> 8
};
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;



typedef struct _IO_FILE FILE;
#line 65
typedef struct _IO_FILE __FILE;
# 95 "/usr/include/wchar.h" 3
#line 83
typedef struct __nesc_unnamed4266 {

  int __count;
  union __nesc_unnamed4267 {


    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 26 "/usr/include/_G_config.h" 3
#line 22
typedef struct __nesc_unnamed4268 {

  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;




#line 27
typedef struct __nesc_unnamed4269 {

  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
#line 53
typedef int _G_int16_t __attribute((__mode__(__HI__))) ;
typedef int _G_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int _G_uint16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int _G_uint32_t __attribute((__mode__(__SI__))) ;
# 40 "/usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 172 "/usr/include/libio.h" 3
struct _IO_jump_t;
#line 172
struct _IO_FILE;









typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
};
#line 208
enum __codecvt_result {

  __codecvt_ok, 
  __codecvt_partial, 
  __codecvt_error, 
  __codecvt_noconv
};
#line 273
struct _IO_FILE {
  int _flags;




  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;








  __off64_t _offset;








  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof(int ) - 4 * sizeof(void *) - sizeof(size_t )];
};



typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

struct _IO_FILE_plus;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
#line 366
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, 
size_t __n);







typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn(void *__cookie);
# 80 "/usr/include/stdio.h" 3
typedef __gnuc_va_list va_list;
#line 111
typedef _G_fpos_t fpos_t;
#line 169
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
#line 243
extern int fflush(FILE *__stream);
#line 307
extern FILE *fdopen(int __fd, const char *__modes) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 357
extern int fprintf(FILE *__restrict __stream, 
const char *__restrict __format, ...);




extern int printf(const char *__restrict __format, ...);








extern int vfprintf(FILE *__restrict __s, const char *__restrict __format, 
__gnuc_va_list __arg);
#line 387
extern int snprintf(char *__restrict __s, size_t __maxlen, 
const char *__restrict __format, ...) 
__attribute((__nothrow__)) __attribute((__format__(__printf__, 3, 4))) ;
#line 855
extern int fileno(FILE *__stream) __attribute((__leaf__)) __attribute((__nothrow__)) ;
# 74 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/tos.h"
typedef uint8_t bool;


enum __nesc_unnamed4270 {
#line 77
  FALSE = 0, TRUE = 1
};
extern uint16_t TOS_NODE_ID;
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.h"
typedef long long int sim_time_t;

void sim_init();

void sim_end();

void sim_random_seed(int seed);
int sim_random();

sim_time_t sim_time();
void sim_set_time(sim_time_t time);
sim_time_t sim_ticks_per_sec();

unsigned long sim_node();
void sim_set_node(unsigned long node);

int sim_print_time(char *buf, int bufLen, sim_time_t time);
int sim_print_now(char *buf, int bufLen);
char *sim_time_string();

void sim_add_channel(char *channel, FILE *file);
bool sim_remove_channel(char *channel, FILE *file);

bool sim_run_next_event();
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.h"
struct sim_event;
typedef struct sim_event sim_event_t;

struct sim_event {
  sim_time_t time;
  unsigned long mote;
  bool force;

  bool cancelled;
  void *data;

  void (*handle)(sim_event_t *e);
  void (*cleanup)(sim_event_t *e);
};

static sim_event_t *sim_queue_allocate_event();

void sim_queue_init();
void sim_queue_insert(sim_event_t *event);
bool sim_queue_is_empty();
long long int sim_queue_peek_time();
sim_event_t *sim_queue_pop();

void sim_queue_cleanup_none(sim_event_t *e);
void sim_queue_cleanup_event(sim_event_t *e);
void sim_queue_cleanup_data(sim_event_t *e);
void sim_queue_cleanup_total(sim_event_t *e);
# 53 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_mote.h"
long long int sim_mote_euid(int mote);
void sim_mote_set_euid(int mote, long long int euid);

long long int sim_mote_start_time(int mote);
void sim_mote_set_start_time(int mote, long long int t);

bool sim_mote_is_on(int mote);
void sim_mote_turn_on(int mote);
void sim_mote_turn_off(int mote);
int sim_mote_get_variable_info(int mote, char *name, void **addr, size_t *len);
void sim_mote_enqueue_boot_event(int mote);
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.h"
static inline void sim_log_init();
static inline void sim_log_add_channel(char *output, FILE *file);
static inline bool sim_log_remove_channel(char *output, FILE *file);
static void sim_log_commit_change();

static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
# 98 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/tos.h"
struct __nesc_attr_atmostonce {
};
#line 99
struct __nesc_attr_atleastonce {
};
#line 100
struct __nesc_attr_exactlyonce {
};
# 9 "/opt/tinyos-2.1.2/tos/lib/tossim/hashtable.h"
struct hashtable;
typedef struct hashtable hashtable_t;
#line 78
struct hashtable *
create_hashtable(unsigned int minsize, 
unsigned int (*hashfunction)(void *arg_0x40542320), 
int (*key_eq_fn)(void *arg_0x40542768, void *arg_0x405428e0));
#line 103
#line 102
int 
hashtable_insert(struct hashtable *h, void *k, void *v);
#line 120
void *
hashtable_search(struct hashtable *h, void *k);
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
enum __nesc_unnamed4271 {
  DEFAULT_CHANNEL_SIZE = 8
};




#line 51
typedef struct sim_log_output {
  int num;
  FILE **files;
} sim_log_output_t;






#line 56
typedef struct sim_log_channel {
  const char *name;
  int numOutputs;
  int size;
  FILE **outputs;
} sim_log_channel_t;

enum __nesc_unnamed4272 {
  SIM_LOG_OUTPUT_COUNT = 215U
};

sim_log_output_t outputs[SIM_LOG_OUTPUT_COUNT];
struct hashtable *channelTable = (void *)0;


inline static unsigned int sim_log_hash(void *key);
inline static int sim_log_eq(void *key1, void *key2);
#line 84
static void fillInOutput(int id, char *name);
#line 159
static inline void sim_log_init();
#line 172
static inline void sim_log_add_channel(char *name, FILE *file);
#line 212
static inline bool sim_log_remove_channel(char *output, FILE *file);
#line 234
static void sim_log_commit_change();
#line 246
static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
#line 261
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
#line 276
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
#line 306
inline static unsigned int sim_log_hash(void *key);










inline static int sim_log_eq(void *key1, void *key2);
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.h"
#line 61
typedef struct heap {
  int size;
  void *data;
  int private_size;
} heap_t;

static inline void init_heap(heap_t *heap);

static inline int heap_is_empty(heap_t *heap);

static inline long long int heap_get_min_key(heap_t *heap);

static void *heap_pop_min_data(heap_t *heap, long long int *key);
static inline void heap_insert(heap_t *heap, void *data, long long int key);
# 58 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
const int STARTING_SIZE = 511;






#line 62
typedef struct node {
  void *data;
  long long int key;
} node_t;

static void down_heap(heap_t *heap, int findex);
static void up_heap(heap_t *heap, int findex);
static void swap(node_t *first, node_t *second);








static inline void init_heap(heap_t *heap);









static inline int is_empty(heap_t *heap);



static inline int heap_is_empty(heap_t *heap);



static inline long long int heap_get_min_key(heap_t *heap);
#line 114
static void *heap_pop_min_data(heap_t *heap, long long int *key);
#line 130
static inline void expand_heap(heap_t *heap);
#line 144
static inline void heap_insert(heap_t *heap, void *data, long long int key);
#line 158
static void swap(node_t *first, node_t *second);
#line 171
static void down_heap(heap_t *heap, int findex);
#line 197
static void up_heap(heap_t *heap, int findex);
# 44 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
static heap_t eventHeap;

void sim_queue_init()   ;



void sim_queue_insert(sim_event_t *event)   ;




sim_event_t *sim_queue_pop()   ;




bool sim_queue_is_empty()   ;



long long int sim_queue_peek_time()   ;









void sim_queue_cleanup_none(sim_event_t *event)   ;




void sim_queue_cleanup_event(sim_event_t *event)   ;




void sim_queue_cleanup_data(sim_event_t *event)   ;





void sim_queue_cleanup_total(sim_event_t *event)   ;






static sim_event_t *sim_queue_allocate_event();
# 57 "/usr/include/i386-linux-gnu/sys/time.h" 3
struct timezone {

  int tz_minuteswest;
  int tz_dsttime;
};

typedef struct timezone *__restrict __timezone_ptr_t;









extern int gettimeofday(struct timeval *__restrict __tv, 
__timezone_ptr_t __tz) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;
#line 93
enum __itimer_which {


  ITIMER_REAL = 0, 


  ITIMER_VIRTUAL = 1, 



  ITIMER_PROF = 2
};




struct itimerval {


  struct timeval it_interval;

  struct timeval it_value;
};






typedef int __itimer_which_t;
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.h"
enum __nesc_unnamed4273 {
  NOISE_MIN = -115, 
  NOISE_MAX = -5, 
  NOISE_MIN_QUANTIZE = -115, 
  NOISE_QUANTIZE_INTERVAL = 5, 
  NOISE_BIN_SIZE = (NOISE_MAX - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1, 
  NOISE_HISTORY = 20, 
  NOISE_DEFAULT_ELEMENT_SIZE = 8, 
  NOISE_HASHTABLE_SIZE = 128, 
  NOISE_MIN_TRACE = 128, 
  NOISE_NUM_VALUES = NOISE_MAX - NOISE_MIN + 1
};








#line 64
typedef struct sim_noise_hash_t {
  char key[NOISE_HISTORY];
  int numElements;
  int size;
  char *elements;
  char flag;
  float dist[NOISE_NUM_VALUES];
} sim_noise_hash_t;
#line 83
#line 73
typedef struct sim_noise_node_t {
  char key[NOISE_HISTORY];
  char freqKey[NOISE_HISTORY];
  char lastNoiseVal;
  uint32_t noiseGenTime;
  struct hashtable *noiseTable;
  char *noiseTrace;
  uint32_t noiseTraceLen;
  uint32_t noiseTraceIndex;
  bool generated;
} sim_noise_node_t;

void sim_noise_init();

char sim_noise_generate(uint16_t node_id, uint32_t cur_t);
void sim_noise_trace_add(uint16_t node_id, char val);
void sim_noise_create_model(uint16_t node_id);
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
static sim_time_t sim_ticks;
static unsigned long current_node;
static int sim_seed;

static int __nesc_nido_resolve(int mote, char *varname, uintptr_t *addr, size_t *size);

void sim_init()   ;
#line 80
void sim_end()   ;





int sim_random()   ;
#line 102
void sim_random_seed(int seed)   ;







sim_time_t sim_time()   ;


void sim_set_time(sim_time_t t)   ;



sim_time_t sim_ticks_per_sec()   ;



unsigned long sim_node()   ;


void sim_set_node(unsigned long node)   ;




bool sim_run_next_event()   ;
#line 156
int sim_print_time(char *buf, int len, sim_time_t ftime)   ;
#line 179
int sim_print_now(char *buf, int len)   ;



char simTimeBuf[128];
char *sim_time_string()   ;




void sim_add_channel(char *channel, FILE *file)   ;



bool sim_remove_channel(char *channel, FILE *file)   ;
# 99 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_csma.h"
int sim_csma_init_high();
int sim_csma_init_low();
int sim_csma_high();
int sim_csma_low();
int sim_csma_symbols_per_sec();
int sim_csma_bits_per_symbol();
int sim_csma_preamble_length();
int sim_csma_exponent_base();
int sim_csma_max_iterations();
int sim_csma_min_free_samples();
int sim_csma_rxtx_delay();
int sim_csma_ack_time();

void sim_csma_set_init_high(int val);
void sim_csma_set_init_low(int val);
void sim_csma_set_high(int val);
void sim_csma_set_low(int val);
void sim_csma_set_symbols_per_sec(int val);
void sim_csma_set_bits_per_symbol(int val);
void sim_csma_set_preamble_length(int val);
void sim_csma_set_exponent_base(int val);
void sim_csma_set_max_iterations(int val);
void sim_csma_set_min_free_samples(int val);
void sim_csma_set_rxtx_delay(int val);
void sim_csma_set_ack_time(int val);
# 44 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_csma.c"
int csmaInitHigh = 640;
int csmaInitLow = 20;
int csmaHigh = 160;
int csmaLow = 20;
int csmaSymbolsPerSec = 65536;
int csmaBitsPerSymbol = 4;
int csmaPreambleLength = 12;
int csmaExponentBase = 1;
int csmaMaxIterations = 0;
int csmaMinFreeSamples = 1;
int csmaRxTxDelay = 11;
int csmaAckTime = 34;

int sim_csma_init_high()   ;


int sim_csma_init_low()   ;


int sim_csma_high()   ;


int sim_csma_low()   ;


int sim_csma_symbols_per_sec()   ;


int sim_csma_bits_per_symbol()   ;


int sim_csma_preamble_length()   ;


int sim_csma_exponent_base()   ;


int sim_csma_max_iterations()   ;


int sim_csma_min_free_samples()   ;


int sim_csma_rxtx_delay()   ;


int sim_csma_ack_time()   ;





void sim_csma_set_init_high(int val)   ;


void sim_csma_set_init_low(int val)   ;


void sim_csma_set_high(int val)   ;


void sim_csma_set_low(int val)   ;


void sim_csma_set_symbols_per_sec(int val)   ;


void sim_csma_set_bits_per_symbol(int val)   ;


void sim_csma_set_preamble_length(int val)   ;


void sim_csma_set_exponent_base(int val)   ;


void sim_csma_set_max_iterations(int val)   ;


void sim_csma_set_min_free_samples(int val)   ;


void sim_csma_set_rxtx_delay(int val)   ;


void sim_csma_set_ack_time(int val)   ;
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.h"
#line 53
typedef struct gain_entry {
  int mote;
  double gain;
  struct gain_entry *next;
} gain_entry_t;

void sim_gain_add(int src, int dest, double gain);
double sim_gain_value(int src, int dest);
bool sim_gain_connected(int src, int dest);
void sim_gain_remove(int src, int dest);
void sim_gain_set_noise_floor(int node, double mean, double range);
double sim_gain_sample_noise(int node);



void sim_gain_set_sensitivity(double value);
double sim_gain_sensitivity();

gain_entry_t *sim_gain_first(int src);
gain_entry_t *sim_gain_next(gain_entry_t *e);
# 6 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.c"
#line 3
typedef struct sim_gain_noise {
  double mean;
  double range;
} sim_gain_noise_t;


gain_entry_t *connectivity[1000 + 1];
sim_gain_noise_t localNoise[1000 + 1];
double sensitivity = 4.0;

static inline gain_entry_t *sim_gain_allocate_link(int mote);
void sim_gain_deallocate_link(gain_entry_t *linkToDelete);

gain_entry_t *sim_gain_first(int src)   ;






gain_entry_t *sim_gain_next(gain_entry_t *currentLink)   ;



void sim_gain_add(int src, int dest, double gain)   ;
#line 55
double sim_gain_value(int src, int dest)   ;
#line 73
bool sim_gain_connected(int src, int dest)   ;
#line 89
void sim_gain_remove(int src, int dest)   ;
#line 124
void sim_gain_set_noise_floor(int node, double mean, double range)   ;
#line 148
double sim_gain_sample_noise(int node)   ;
#line 161
static inline gain_entry_t *sim_gain_allocate_link(int mote);







void sim_gain_deallocate_link(gain_entry_t *linkToDelete)   ;



void sim_gain_set_sensitivity(double s)   ;



double sim_gain_sensitivity()   ;
# 39 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.c"
static double randU[97];
#line 39
static double randC;
#line 39
static double randCD;
#line 39
static double randCM;
static int i97;
#line 40
static int j97;
static int test = FALSE;
#line 55
static inline void RandomInitialise(int ij, int kl);
#line 103
static double RandomUniform(void );
# 133 "/usr/include/time.h" 3
struct tm {

  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;
};
#line 161
struct itimerspec {

  struct timespec it_interval;
  struct timespec it_value;
};


struct sigevent;
# 233 "/usr/include/time.h"
struct tm;



struct tm;





struct tm;




struct tm;
# 46 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.h"
static inline void RandomInitialise(int arg_0x40676558, int arg_0x406766b0);
static double RandomUniform(void );
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
int numCase1 = 0;
int numCase2 = 0;
int numTotal = 0;


uint32_t FreqKeyNum = 0;

sim_noise_node_t noiseData[1000];

inline static unsigned int sim_noise_hash(void *key);
inline static int sim_noise_eq(void *key1, void *key2);

void makeNoiseModel(uint16_t node_id);
void makePmfDistr(uint16_t node_id);
uint8_t search_bin_num(char noise);

void sim_noise_init()   ;
#line 84
void sim_noise_create_model(uint16_t node_id)   ;
#line 97
void sim_noise_trace_add(uint16_t node_id, char noiseVal)   ;
#line 113
uint8_t search_bin_num(char noise)   ;









char search_noise_from_bin_num(int i)   ;






inline static unsigned int sim_noise_hash(void *key);









inline static int sim_noise_eq(void *key1, void *key2);



void sim_noise_add(uint16_t node_id, char noise)   ;
#line 192
void sim_noise_dist(uint16_t node_id)   ;
#line 245
void arrangeKey(uint16_t node_id)   ;









void makePmfDistr(uint16_t node_id)   ;
#line 283
int dummy;
static inline void sim_noise_alarm();



char sim_noise_gen(uint16_t node_id)   ;
#line 364
char sim_noise_generate(uint16_t node_id, uint32_t cur_t)   ;
#line 419
void makeNoiseModel(uint16_t node_id)   ;
# 59 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.h"
typedef struct sim_packet {
} 
#line 59
sim_packet_t;

void sim_packet_set_source(sim_packet_t *msg, uint16_t src);
uint16_t sim_packet_source(sim_packet_t *msg);

void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest);
uint16_t sim_packet_destination(sim_packet_t *msg);

void sim_packet_set_length(sim_packet_t *msg, uint8_t len);
uint16_t sim_packet_length(sim_packet_t *msg);

void sim_packet_set_type(sim_packet_t *msg, uint8_t type);
uint8_t sim_packet_type(sim_packet_t *msg);

uint8_t *sim_packet_data(sim_packet_t *msg);
void sim_packet_set_strength(sim_packet_t *msg, uint16_t str);

void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t);
uint8_t sim_packet_max_length(sim_packet_t *msg);

sim_packet_t *sim_packet_allocate();
void sim_packet_free(sim_packet_t *m);
# 6 "/opt/tinyos-2.1.2/tos/types/AM.h"
typedef nx_uint8_t nx_am_id_t;
typedef nx_uint8_t nx_am_group_t;
typedef nx_uint16_t nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4274 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4275 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 12 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimRadioMsg.h"
#line 6
typedef nx_struct tossim_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) tossim_header_t;



#line 14
typedef nx_struct tossim_footer {
  nxle_uint16_t crc;
} __attribute__((packed)) tossim_footer_t;





#line 18
typedef nx_struct tossim_metadata {
  nx_int8_t strength;
  nx_uint8_t ack;
  nx_uint16_t time;
} __attribute__((packed)) tossim_metadata_t;
# 83 "/opt/tinyos-2.1.2/tos/lib/serial/Serial.h"
typedef uint8_t uart_id_t;



enum __nesc_unnamed4276 {
  HDLC_FLAG_BYTE = 0x7e, 
  HDLC_CTLESC_BYTE = 0x7d
};



enum __nesc_unnamed4277 {
  TOS_SERIAL_ACTIVE_MESSAGE_ID = 0, 
  TOS_SERIAL_CC1000_ID = 1, 
  TOS_SERIAL_802_15_4_ID = 2, 
  TOS_SERIAL_UNKNOWN_ID = 255
};


enum __nesc_unnamed4278 {
  SERIAL_PROTO_ACK = 67, 
  SERIAL_PROTO_PACKET_ACK = 68, 
  SERIAL_PROTO_PACKET_NOACK = 69, 
  SERIAL_PROTO_PACKET_UNKNOWN = 255
};
#line 121
#line 109
typedef struct radio_stats {
  uint8_t version;
  uint8_t flags;
  uint8_t reserved;
  uint8_t platform;
  uint16_t MTU;
  uint16_t radio_crc_fail;
  uint16_t radio_queue_drops;
  uint16_t serial_crc_fail;
  uint16_t serial_tx_fail;
  uint16_t serial_short_packets;
  uint16_t serial_proto_drops;
} radio_stats_t;







#line 123
typedef nx_struct serial_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) serial_header_t;




#line 131
typedef nx_struct serial_packet {
  serial_header_t header;
  nx_uint8_t data[];
} __attribute__((packed)) serial_packet_t;



#line 136
typedef nx_struct serial_metadata {
  nx_uint8_t ack;
} __attribute__((packed)) serial_metadata_t;
# 53 "/opt/tinyos-2.1.2/tos/lib/tossim/platform_message.h"
#line 50
typedef union message_header {
  tossim_header_t tossim;
  serial_header_t serial;
} message_header_t;



#line 55
typedef union message_footer {
  tossim_footer_t tossim;
} message_footer_t;



#line 59
typedef union message_metadata {
  tossim_metadata_t tossim;
} message_metadata_t;
# 19 "/opt/tinyos-2.1.2/tos/types/message.h"
#line 14
typedef nx_struct message_t {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[28];
  nx_uint8_t footer[sizeof(message_footer_t )];
  nx_uint8_t metadata[sizeof(message_metadata_t )];
} __attribute__((packed)) message_t;
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
void active_message_deliver(int node, message_t *m, sim_time_t t);

inline static tossim_header_t *getHeader(message_t *msg);



void sim_packet_set_source(sim_packet_t *msg, uint16_t src)   ;




uint16_t sim_packet_source(sim_packet_t *msg)   ;




void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)   ;




uint16_t sim_packet_destination(sim_packet_t *msg)   ;




void sim_packet_set_length(sim_packet_t *msg, uint8_t length)   ;



uint16_t sim_packet_length(sim_packet_t *msg)   ;




void sim_packet_set_type(sim_packet_t *msg, uint8_t type)   ;




uint8_t sim_packet_type(sim_packet_t *msg)   ;




uint8_t *sim_packet_data(sim_packet_t *p)   ;



void sim_packet_set_strength(sim_packet_t *p, uint16_t str)   ;




void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)   ;







uint8_t sim_packet_max_length(sim_packet_t *msg)   ;



sim_packet_t *sim_packet_allocate()   ;



void sim_packet_free(sim_packet_t *p)   ;
# 63 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim_serial_packet.h"
typedef struct sim_serial_packet {
} 
#line 63
sim_serial_packet_t;

void sim_serial_packet_set_destination(sim_serial_packet_t *msg, uint16_t dest);
uint16_t sim_serial_packet_destination(sim_serial_packet_t *msg);

void sim_serial_packet_set_source(sim_serial_packet_t *msg, uint16_t src);
uint16_t sim_serial_packet_source(sim_serial_packet_t *msg);

void sim_serial_packet_set_length(sim_serial_packet_t *msg, uint8_t len);
uint16_t sim_serial_packet_length(sim_serial_packet_t *msg);

void sim_serial_packet_set_type(sim_serial_packet_t *msg, uint8_t type);
uint8_t sim_serial_packet_type(sim_serial_packet_t *msg);

uint8_t *sim_serial_packet_data(sim_serial_packet_t *msg);

void sim_serial_packet_deliver(int node, sim_serial_packet_t *msg, sim_time_t t);
uint8_t sim_serial_packet_max_length(sim_serial_packet_t *msg);

sim_serial_packet_t *sim_serial_packet_allocate();
void sim_serial_packet_free(sim_serial_packet_t *m);
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim_serial_packet.c"
void serial_active_message_deliver(int node, message_t *m, sim_time_t t);

inline static serial_header_t *getSerialHeader(message_t *msg);



void sim_serial_packet_set_destination(sim_serial_packet_t *msg, uint16_t dest)   ;




  uint16_t sim_serial_packet_destination(sim_serial_packet_t *msg)   ;




void sim_serial_packet_set_source(sim_serial_packet_t *msg, uint16_t src)   ;




  uint16_t sim_serial_packet_source(sim_serial_packet_t *msg)   ;




void sim_serial_packet_set_length(sim_serial_packet_t *msg, uint8_t length)   ;



uint16_t sim_serial_packet_length(sim_serial_packet_t *msg)   ;




void sim_serial_packet_set_type(sim_serial_packet_t *msg, uint8_t type)   ;




uint8_t sim_serial_packet_type(sim_serial_packet_t *msg)   ;




uint8_t *sim_serial_packet_data(sim_serial_packet_t *p)   ;




void sim_serial_packet_deliver(int node, sim_serial_packet_t *msg, sim_time_t t)   ;







uint8_t sim_serial_packet_max_length(sim_serial_packet_t *msg)   ;



sim_serial_packet_t *sim_serial_packet_allocate()   ;



void sim_serial_packet_free(sim_serial_packet_t *p)   ;
# 51 "/opt/tinyos-2.1.2/tos/types/TinyError.h"
enum __nesc_unnamed4279 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 4 "QueryRadioFlooding.h"
enum __nesc_unnamed4280 {
  AM_QYERY_FLOODING_MSG = 45
};









#line 8
typedef nx_struct query_flooding_msg {
  nx_uint16_t source_id;
  nx_uint16_t sequence_number;
  nx_uint16_t forwarder_id;
  nx_uint16_t hops;
  nx_uint16_t sampling_period;
  nx_uint16_t query_lifetime;
  nx_uint16_t propagation_mode;
} __attribute__((packed)) query_flooding_msg_t;
# 4 "QueryPacket.h"
enum __nesc_unnamed4281 {
  AM_QUERY_MSG = 6
};





#line 8
typedef nx_struct query_msg {
  nx_uint16_t sampling_period;
  nx_uint16_t query_lifetime;
  nx_uint16_t propagation_mode;
} __attribute__((packed)) query_msg_t;
# 4 "SamplingPacket.h"
enum __nesc_unnamed4282 {
  AM_SAMPLING_MSG = 36
};









#line 8
typedef nx_struct sampling_msg {
  nx_uint16_t source_id;
  nx_uint16_t data_id;
  nx_uint16_t forwarder_id;
  nx_uint16_t sensor_data;
  nx_uint16_t destination_id;
  nx_uint16_t sequence_number;
  nx_uint8_t count_contributed_nodes;
} __attribute__((packed)) sampling_msg_t;
# 25 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128_sim.h"
enum __nesc_unnamed4283 {

  ATM128_PINF = 0x00, 


  ATM128_PINE = 0x01, 


  ATM128_DDRE = 0x02, 


  ATM128_PORTE = 0x03, 


  ATM128_ADCW = 0x04, 

  ATM128_ADC = 0x04, 

  ATM128_ADCL = 0x04, 
  ATM128_ADCH = 0x05, 


  ATM128_ADCSR = 0x06, 
  ATM128_ADCSRA = 0x06, 


  ATM128_ADMUX = 0x07, 


  ATM128_ACSR = 0x08, 


  ATM128_UBRR0L = 0x09, 


  ATM128_UCSR0B = 0x0A, 


  ATM128_UCSR0A = 0x0B, 


  ATM128_UDR0 = 0x0C, 


  ATM128_SPCR = 0x0D, 


  ATM128_SPSR = 0x0E, 


  ATM128_SPDR = 0x0F, 


  ATM128_PIND = 0x10, 


  ATM128_DDRD = 0x11, 


  ATM128_PORTD = 0x12, 


  ATM128_PINC = 0x13, 


  ATM128_DDRC = 0x14, 


  ATM128_PORTC = 0x15, 


  ATM128_PINB = 0x16, 


  ATM128_DDRB = 0x17, 


  ATM128_PORTB = 0x18, 


  ATM128_PINA = 0x19, 


  ATM128_DDRA = 0x1A, 


  ATM128_PORTA = 0x1B, 




  ATM128_SFIOR = 0x20, 


  ATM128_WDTCR = 0x21, 


  ATM128_OCDR = 0x22, 


  ATM128_OCR2 = 0x23, 


  ATM128_TCNT2 = 0x24, 


  ATM128_TCCR2 = 0x25, 


  ATM128_ICR1 = 0x26, 
  ATM128_ICR1L = 0x26, 
  ATM128_ICR1H = 0x27, 


  ATM128_OCR1B = 0x28, 
  ATM128_OCR1BL = 0x28, 
  ATM128_OCR1BH = 0x29, 


  ATM128_OCR1A = 0x2A, 
  ATM128_OCR1AL = 0x2A, 
  ATM128_OCR1AH = 0x2B, 


  ATM128_TCNT1 = 0x2C, 
  ATM128_TCNT1L = 0x2C, 
  ATM128_TCNT1H = 0x2D, 


  ATM128_TCCR1B = 0x2E, 


  ATM128_TCCR1A = 0x2F, 


  ATM128_ASSR = 0x30, 


  ATM128_OCR0 = 0x31, 


  ATM128_TCNT0 = 0x32, 


  ATM128_TCCR0 = 0x33, 


  ATM128_MCUSR = 0x34, 
  ATM128_MCUCSR = 0x34, 


  ATM128_MCUCR = 0x35, 


  ATM128_TIFR = 0x36, 


  ATM128_TIMSK = 0x37, 


  ATM128_EIFR = 0x38, 


  ATM128_EIMSK = 0x39, 


  ATM128_EICRB = 0x3A, 


  ATM128_RAMPZ = 0x3B, 


  ATM128_XDIV = 0x3C, 




  ATM128_SREG = 0x3F, 




  ATM128_DDRF = 0x61, 


  ATM128_PORTF = 0x62, 


  ATM128_PING = 0x63, 


  ATM128_DDRG = 0x64, 


  ATM128_PORTG = 0x65, 


  ATM128_SPMCR = 0x68, 
  ATM128_SPMCSR = 0x68, 


  ATM128_EICRA = 0x6A, 


  ATM128_XMCRB = 0x6C, 


  ATM128_XMCRA = 0x6D, 


  ATM128_OSCCAL = 0x6F, 


  ATM128_TWBR = 0x70, 


  ATM128_TWSR = 0x71, 


  ATM128_TWAR = 0x72, 


  ATM128_TWDR = 0x73, 


  ATM128_TWCR = 0x74, 


  ATM128_OCR1C = 0x78, 
  ATM128_OCR1CL = 0x78, 
  ATM128_OCR1CH = 0x79, 


  ATM128_TCCR1C = 0x7A, 


  ATM128_ETIFR = 0x7C, 


  ATM128_ETIMSK = 0x7D, 


  ATM128_ICR3 = 0x80, 
  ATM128_ICR3L = 0x80, 
  ATM128_ICR3H = 0x81, 


  ATM128_OCR3C = 0x82, 
  ATM128_OCR3CL = 0x82, 
  ATM128_OCR3CH = 0x83, 


  ATM128_OCR3B = 0x84, 
  ATM128_OCR3BL = 0x84, 
  ATM128_OCR3BH = 0x85, 


  ATM128_OCR3A = 0x86, 
  ATM128_OCR3AL = 0x86, 
  ATM128_OCR3AH = 0x87, 


  ATM128_TCNT3 = 0x88, 
  ATM128_TCNT3L = 0x88, 
  ATM128_TCNT3H = 0x89, 


  ATM128_TCCR3B = 0x8A, 


  ATM128_TCCR3A = 0x8B, 


  ATM128_TCCR3C = 0x8C, 


  ATM128_UBRR0H = 0x90, 


  ATM128_UCSR0C = 0x95, 


  ATM128_UBRR1H = 0x98, 


  ATM128_UBRR1L = 0x99, 


  ATM128_UCSR1B = 0x9A, 


  ATM128_UCSR1A = 0x9B, 


  ATM128_UDR1 = 0x9C, 


  ATM128_UCSR1C = 0x9D
};
#line 673
enum __nesc_unnamed4284 {

  TWINT = 7, 
  TWEA = 6, 
  TWSTA = 5, 
  TWSTO = 4, 
  TWWC = 3, 
  TWEN = 2, 
  TWIE = 0, 


  TWA6 = 7, 
  TWA5 = 6, 
  TWA4 = 5, 
  TWA3 = 4, 
  TWA2 = 3, 
  TWA1 = 2, 
  TWA0 = 1, 
  TWGCE = 0, 


  TWS7 = 7, 
  TWS6 = 6, 
  TWS5 = 5, 
  TWS4 = 4, 
  TWS3 = 3, 
  TWPS1 = 1, 
  TWPS0 = 0, 


  SRL2 = 6, 
  SRL1 = 5, 
  SRL0 = 4, 
  SRW01 = 3, 
  SRW00 = 2, 
  SRW11 = 1, 


  XMBK = 7, 
  XMM2 = 2, 
  XMM1 = 1, 
  XMM0 = 0, 


  XDIVEN = 7, 
  XDIV6 = 6, 
  XDIV5 = 5, 
  XDIV4 = 4, 
  XDIV3 = 3, 
  XDIV2 = 2, 
  XDIV1 = 1, 
  XDIV0 = 0, 


  RAMPZ0 = 0, 


  ISC31 = 7, 
  ISC30 = 6, 
  ISC21 = 5, 
  ISC20 = 4, 
  ISC11 = 3, 
  ISC10 = 2, 
  ISC01 = 1, 
  ISC00 = 0, 


  ISC71 = 7, 
  ISC70 = 6, 
  ISC61 = 5, 
  ISC60 = 4, 
  ISC51 = 3, 
  ISC50 = 2, 
  ISC41 = 1, 
  ISC40 = 0, 


  SPMIE = 7, 
  RWWSB = 6, 
  RWWSRE = 4, 
  BLBSET = 3, 
  PGWRT = 2, 
  PGERS = 1, 
  SPMEN = 0, 


  INT7 = 7, 
  INT6 = 6, 
  INT5 = 5, 
  INT4 = 4, 
  INT3 = 3, 
  INT2 = 2, 
  INT1 = 1, 
  INT0 = 0, 


  INTF7 = 7, 
  INTF6 = 6, 
  INTF5 = 5, 
  INTF4 = 4, 
  INTF3 = 3, 
  INTF2 = 2, 
  INTF1 = 1, 
  INTF0 = 0, 


  OCIE2 = 7, 
  TOIE2 = 6, 
  TICIE1 = 5, 
  OCIE1A = 4, 
  OCIE1B = 3, 
  TOIE1 = 2, 
  OCIE0 = 1, 
  TOIE0 = 0, 


  OCF2 = 7, 
  TOV2 = 6, 
  ICF1 = 5, 
  OCF1A = 4, 
  OCF1B = 3, 
  TOV1 = 2, 
  OCF0 = 1, 
  TOV0 = 0, 


  TICIE3 = 5, 
  OCIE3A = 4, 
  OCIE3B = 3, 
  TOIE3 = 2, 
  OCIE3C = 1, 
  OCIE1C = 0, 


  ICF3 = 5, 
  OCF3A = 4, 
  OCF3B = 3, 
  TOV3 = 2, 
  OCF3C = 1, 
  OCF1C = 0, 


  SRE = 7, 
  SRW = 6, 
  SRW10 = 6, 
  SE = 5, 
  SM1 = 4, 
  SM0 = 3, 
  SM2 = 2, 
  IVSEL = 1, 
  IVCE = 0, 


  JTD = 7, 
  JTRF = 4, 
  WDRF = 3, 
  BORF = 2, 
  EXTRF = 1, 
  PORF = 0, 


  FOC = 7, 
  WGM0 = 6, 
  COM1 = 5, 
  COM0 = 4, 
  WGM1 = 3, 
  CS2 = 2, 
  CS1 = 1, 
  CS0 = 0, 


  FOC0 = 7, 
  WGM00 = 6, 
  COM01 = 5, 
  COM00 = 4, 
  WGM01 = 3, 
  CS02 = 2, 
  CS01 = 1, 
  CS00 = 0, 


  FOC2 = 7, 
  WGM20 = 6, 
  COM21 = 5, 
  COM20 = 4, 
  WGM21 = 3, 
  CS22 = 2, 
  CS21 = 1, 
  CS20 = 0, 


  AS0 = 3, 
  TCN0UB = 2, 
  OCR0UB = 1, 
  TCR0UB = 0, 


  COMA1 = 7, 
  COMA0 = 6, 
  COMB1 = 5, 
  COMB0 = 4, 
  COMC1 = 3, 
  COMC0 = 2, 
  WGMA1 = 1, 
  WGMA0 = 0, 


  COM1A1 = 7, 
  COM1A0 = 6, 
  COM1B1 = 5, 
  COM1B0 = 4, 
  COM1C1 = 3, 
  COM1C0 = 2, 
  WGM11 = 1, 
  WGM10 = 0, 


  COM3A1 = 7, 
  COM3A0 = 6, 
  COM3B1 = 5, 
  COM3B0 = 4, 
  COM3C1 = 3, 
  COM3C0 = 2, 
  WGM31 = 1, 
  WGM30 = 0, 


  ICNC = 7, 
  ICES = 6, 
  WGMB3 = 4, 
  WGMB2 = 3, 
  CSB2 = 2, 
  CSB1 = 1, 
  CSB0 = 0, 


  ICNC1 = 7, 
  ICES1 = 6, 
  WGM13 = 4, 
  WGM12 = 3, 
  CS12 = 2, 
  CS11 = 1, 
  CS10 = 0, 


  ICNC3 = 7, 
  ICES3 = 6, 
  WGM33 = 4, 
  WGM32 = 3, 
  CS32 = 2, 
  CS31 = 1, 
  CS30 = 0, 


  FOCA = 7, 
  FOCB = 6, 
  FOCC = 5, 


  FOC3A = 7, 
  FOC3B = 6, 
  FOC3C = 5, 


  FOC1A = 7, 
  FOC1B = 6, 
  FOC1C = 5, 


  IDRD = 7, 
  OCDR7 = 7, 
  OCDR6 = 6, 
  OCDR5 = 5, 
  OCDR4 = 4, 
  OCDR3 = 3, 
  OCDR2 = 2, 
  OCDR1 = 1, 
  OCDR0 = 0, 


  WDCE = 4, 
  WDE = 3, 
  WDP2 = 2, 
  WDP1 = 1, 
  WDP0 = 0, 


  TSM = 7, 
  ADHSM = 4, 
  ACME = 3, 
  PUD = 2, 
  PSR0 = 1, 
  PSR321 = 0, 


  SPIF = 7, 
  WCOL = 6, 
  SPI2X = 0, 


  SPIE = 7, 
  SPE = 6, 
  DORD = 5, 
  MSTR = 4, 
  CPOL = 3, 
  CPHA = 2, 
  SPR1 = 1, 
  SPR0 = 0, 


  UMSEL = 6, 
  UPM1 = 5, 
  UPM0 = 4, 
  USBS = 3, 
  UCSZ1 = 2, 
  UCSZ0 = 1, 
  UCPOL = 0, 


  UMSEL1 = 6, 
  UPM11 = 5, 
  UPM10 = 4, 
  USBS1 = 3, 
  UCSZ11 = 2, 
  UCSZ10 = 1, 
  UCPOL1 = 0, 


  UMSEL0 = 6, 
  UPM01 = 5, 
  UPM00 = 4, 
  USBS0 = 3, 
  UCSZ01 = 2, 
  UCSZ00 = 1, 
  UCPOL0 = 0, 


  RXC = 7, 
  TXC = 6, 
  UDRE = 5, 
  FE = 4, 
  DOR = 3, 
  UPE = 2, 
  U2X = 1, 
  MPCM = 0, 


  RXC1 = 7, 
  TXC1 = 6, 
  UDRE1 = 5, 
  FE1 = 4, 
  DOR1 = 3, 
  UPE1 = 2, 
  U2X1 = 1, 
  MPCM1 = 0, 


  RXC0 = 7, 
  TXC0 = 6, 
  UDRE0 = 5, 
  FE0 = 4, 
  DOR0 = 3, 
  UPE0 = 2, 
  U2X0 = 1, 
  MPCM0 = 0, 


  RXCIE = 7, 
  TXCIE = 6, 
  UDRIE = 5, 
  RXEN = 4, 
  TXEN = 3, 
  UCSZ = 2, 
  UCSZ2 = 2, 
  RXB8 = 1, 
  TXB8 = 0, 


  RXCIE1 = 7, 
  TXCIE1 = 6, 
  UDRIE1 = 5, 
  RXEN1 = 4, 
  TXEN1 = 3, 
  UCSZ12 = 2, 
  RXB81 = 1, 
  TXB81 = 0, 


  RXCIE0 = 7, 
  TXCIE0 = 6, 
  UDRIE0 = 5, 
  RXEN0 = 4, 
  TXEN0 = 3, 
  UCSZ02 = 2, 
  RXB80 = 1, 
  TXB80 = 0, 


  ACD = 7, 
  ACBG = 6, 
  ACO = 5, 
  ACI = 4, 
  ACIE = 3, 
  ACIC = 2, 
  ACIS1 = 1, 
  ACIS0 = 0, 


  ADEN = 7, 
  ADSC = 6, 
  ADFR = 5, 
  ADIF = 4, 
  ADIE = 3, 
  ADPS2 = 2, 
  ADPS1 = 1, 
  ADPS0 = 0, 


  REFS1 = 7, 
  REFS0 = 6, 
  ADLAR = 5, 
  MUX4 = 4, 
  MUX3 = 3, 
  MUX2 = 2, 
  MUX1 = 1, 
  MUX0 = 0, 


  PA7 = 7, 
  PA6 = 6, 
  PA5 = 5, 
  PA4 = 4, 
  PA3 = 3, 
  PA2 = 2, 
  PA1 = 1, 
  PA0 = 0, 


  DDA7 = 7, 
  DDA6 = 6, 
  DDA5 = 5, 
  DDA4 = 4, 
  DDA3 = 3, 
  DDA2 = 2, 
  DDA1 = 1, 
  DDA0 = 0, 


  PINA7 = 7, 
  PINA6 = 6, 
  PINA5 = 5, 
  PINA4 = 4, 
  PINA3 = 3, 
  PINA2 = 2, 
  PINA1 = 1, 
  PINA0 = 0, 


  PB7 = 7, 
  PB6 = 6, 
  PB5 = 5, 
  PB4 = 4, 
  PB3 = 3, 
  PB2 = 2, 
  PB1 = 1, 
  PB0 = 0, 


  DDB7 = 7, 
  DDB6 = 6, 
  DDB5 = 5, 
  DDB4 = 4, 
  DDB3 = 3, 
  DDB2 = 2, 
  DDB1 = 1, 
  DDB0 = 0, 


  PINB7 = 7, 
  PINB6 = 6, 
  PINB5 = 5, 
  PINB4 = 4, 
  PINB3 = 3, 
  PINB2 = 2, 
  PINB1 = 1, 
  PINB0 = 0, 


  PC7 = 7, 
  PC6 = 6, 
  PC5 = 5, 
  PC4 = 4, 
  PC3 = 3, 
  PC2 = 2, 
  PC1 = 1, 
  PC0 = 0, 


  DDC7 = 7, 
  DDC6 = 6, 
  DDC5 = 5, 
  DDC4 = 4, 
  DDC3 = 3, 
  DDC2 = 2, 
  DDC1 = 1, 
  DDC0 = 0, 


  PINC7 = 7, 
  PINC6 = 6, 
  PINC5 = 5, 
  PINC4 = 4, 
  PINC3 = 3, 
  PINC2 = 2, 
  PINC1 = 1, 
  PINC0 = 0, 


  PD7 = 7, 
  PD6 = 6, 
  PD5 = 5, 
  PD4 = 4, 
  PD3 = 3, 
  PD2 = 2, 
  PD1 = 1, 
  PD0 = 0, 


  DDD7 = 7, 
  DDD6 = 6, 
  DDD5 = 5, 
  DDD4 = 4, 
  DDD3 = 3, 
  DDD2 = 2, 
  DDD1 = 1, 
  DDD0 = 0, 


  PIND7 = 7, 
  PIND6 = 6, 
  PIND5 = 5, 
  PIND4 = 4, 
  PIND3 = 3, 
  PIND2 = 2, 
  PIND1 = 1, 
  PIND0 = 0, 


  PE7 = 7, 
  PE6 = 6, 
  PE5 = 5, 
  PE4 = 4, 
  PE3 = 3, 
  PE2 = 2, 
  PE1 = 1, 
  PE0 = 0, 


  DDE7 = 7, 
  DDE6 = 6, 
  DDE5 = 5, 
  DDE4 = 4, 
  DDE3 = 3, 
  DDE2 = 2, 
  DDE1 = 1, 
  DDE0 = 0, 


  PINE7 = 7, 
  PINE6 = 6, 
  PINE5 = 5, 
  PINE4 = 4, 
  PINE3 = 3, 
  PINE2 = 2, 
  PINE1 = 1, 
  PINE0 = 0, 


  PF7 = 7, 
  PF6 = 6, 
  PF5 = 5, 
  PF4 = 4, 
  PF3 = 3, 
  PF2 = 2, 
  PF1 = 1, 
  PF0 = 0, 


  DDF7 = 7, 
  DDF6 = 6, 
  DDF5 = 5, 
  DDF4 = 4, 
  DDF3 = 3, 
  DDF2 = 2, 
  DDF1 = 1, 
  DDF0 = 0, 


  PINF7 = 7, 
  PINF6 = 6, 
  PINF5 = 5, 
  PINF4 = 4, 
  PINF3 = 3, 
  PINF2 = 2, 
  PINF1 = 1, 
  PINF0 = 0, 


  PG4 = 4, 
  PG3 = 3, 
  PG2 = 2, 
  PG1 = 1, 
  PG0 = 0, 


  DDG4 = 4, 
  DDG3 = 3, 
  DDG2 = 2, 
  DDG1 = 1, 
  DDG0 = 0, 


  PING4 = 4, 
  PING3 = 3, 
  PING2 = 2, 
  PING1 = 1, 
  PING0 = 0
};
# 51 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128hardware.h"
uint8_t atm128RegFile[1000][0xa0];
#line 85
static __inline void __nesc_enable_interrupt();



static __inline void __nesc_disable_interrupt();




typedef uint8_t __nesc_atomic_t;



#line 97
__inline __nesc_atomic_t 
__nesc_atomic_start(void )  ;








#line 106
__inline void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)  ;
#line 120
typedef uint8_t mcu_power_t  ;





enum __nesc_unnamed4285 {
  ATM128_POWER_IDLE = 0, 
  ATM128_POWER_ADC_NR = 1, 
  ATM128_POWER_EXT_STANDBY = 2, 
  ATM128_POWER_SAVE = 3, 
  ATM128_POWER_STANDBY = 4, 
  ATM128_POWER_DOWN = 5
};
# 43 "/opt/tinyos-2.1.2/tos/chips/atm128/adc/Atm128Adc.h"
enum __nesc_unnamed4286 {
  ATM128_ADC_VREF_OFF = 0, 
  ATM128_ADC_VREF_AVCC = 1, 
  ATM128_ADC_VREF_RSVD, 
  ATM128_ADC_VREF_2_56 = 3
};


enum __nesc_unnamed4287 {
  ATM128_ADC_RIGHT_ADJUST = 0, 
  ATM128_ADC_LEFT_ADJUST = 1
};



enum __nesc_unnamed4288 {
  ATM128_ADC_SNGL_ADC0 = 0, 
  ATM128_ADC_SNGL_ADC1, 
  ATM128_ADC_SNGL_ADC2, 
  ATM128_ADC_SNGL_ADC3, 
  ATM128_ADC_SNGL_ADC4, 
  ATM128_ADC_SNGL_ADC5, 
  ATM128_ADC_SNGL_ADC6, 
  ATM128_ADC_SNGL_ADC7, 
  ATM128_ADC_DIFF_ADC00_10x, 
  ATM128_ADC_DIFF_ADC10_10x, 
  ATM128_ADC_DIFF_ADC00_200x, 
  ATM128_ADC_DIFF_ADC10_200x, 
  ATM128_ADC_DIFF_ADC22_10x, 
  ATM128_ADC_DIFF_ADC32_10x, 
  ATM128_ADC_DIFF_ADC22_200x, 
  ATM128_ADC_DIFF_ADC32_200x, 
  ATM128_ADC_DIFF_ADC01_1x, 
  ATM128_ADC_DIFF_ADC11_1x, 
  ATM128_ADC_DIFF_ADC21_1x, 
  ATM128_ADC_DIFF_ADC31_1x, 
  ATM128_ADC_DIFF_ADC41_1x, 
  ATM128_ADC_DIFF_ADC51_1x, 
  ATM128_ADC_DIFF_ADC61_1x, 
  ATM128_ADC_DIFF_ADC71_1x, 
  ATM128_ADC_DIFF_ADC02_1x, 
  ATM128_ADC_DIFF_ADC12_1x, 
  ATM128_ADC_DIFF_ADC22_1x, 
  ATM128_ADC_DIFF_ADC32_1x, 
  ATM128_ADC_DIFF_ADC42_1x, 
  ATM128_ADC_DIFF_ADC52_1x, 
  ATM128_ADC_SNGL_1_23, 
  ATM128_ADC_SNGL_GND
};







#line 94
typedef struct __nesc_unnamed4289 {

  uint8_t mux : 5;
  uint8_t adlar : 1;
  uint8_t refs : 2;
} Atm128Admux_t;




enum __nesc_unnamed4290 {
  ATM128_ADC_PRESCALE_2 = 0, 
  ATM128_ADC_PRESCALE_2b, 
  ATM128_ADC_PRESCALE_4, 
  ATM128_ADC_PRESCALE_8, 
  ATM128_ADC_PRESCALE_16, 
  ATM128_ADC_PRESCALE_32, 
  ATM128_ADC_PRESCALE_64, 
  ATM128_ADC_PRESCALE_128, 



  ATM128_ADC_PRESCALE
};


enum __nesc_unnamed4291 {
  ATM128_ADC_ENABLE_OFF = 0, 
  ATM128_ADC_ENABLE_ON
};


enum __nesc_unnamed4292 {
  ATM128_ADC_START_CONVERSION_OFF = 0, 
  ATM128_ADC_START_CONVERSION_ON
};


enum __nesc_unnamed4293 {
  ATM128_ADC_FREE_RUNNING_OFF = 0, 
  ATM128_ADC_FREE_RUNNING_ON
};


enum __nesc_unnamed4294 {
  ATM128_ADC_INT_FLAG_OFF = 0, 
  ATM128_ADC_INT_FLAG_ON
};


enum __nesc_unnamed4295 {
  ATM128_ADC_INT_ENABLE_OFF = 0, 
  ATM128_ADC_INT_ENABLE_ON
};










#line 150
typedef struct __nesc_unnamed4296 {

  uint8_t adps : 3;
  uint8_t adie : 1;
  uint8_t adif : 1;
  uint8_t adfr : 1;
  uint8_t adsc : 1;
  uint8_t aden : 1;
} Atm128Adcsra_t;

typedef uint8_t Atm128_ADCH_t;
typedef uint8_t Atm128_ADCL_t;
# 54 "/opt/tinyos-2.1.2/tos/platforms/micaz/sim/platform_hardware.h"
enum __nesc_unnamed4297 {
  CHANNEL_RSSI = ATM128_ADC_SNGL_ADC0, 
  CHANNEL_THERMISTOR = ATM128_ADC_SNGL_ADC1, 
  CHANNEL_BATTERY = ATM128_ADC_SNGL_ADC7, 
  CHANNEL_BANDGAP = 30, 
  CHANNEL_GND = 31, 

  ATM128_TIMER0_TICKSPPS = 32768
};
# 41 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMainP.nc"
static void __nesc_nido_initialise(int node);
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim_serial_forwarder.h"
struct sim_sf_client_list {

  struct sim_sf_client_list *next;
  int fd;
};


void sim_sf_dispatch_packet(const void *packet, int len);
# 43 "/opt/tinyos-2.1.2/tos/types/Leds.h"
enum __nesc_unnamed4298 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 41 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4299 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4300 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4301 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4302 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 52 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128Timer.h"
enum __nesc_unnamed4303 {
  ATM128_CLK8_OFF = 0x0, 
  ATM128_CLK8_NORMAL = 0x1, 
  ATM128_CLK8_DIVIDE_8 = 0x2, 
  ATM128_CLK8_DIVIDE_32 = 0x3, 
  ATM128_CLK8_DIVIDE_64 = 0x4, 
  ATM128_CLK8_DIVIDE_128 = 0x5, 
  ATM128_CLK8_DIVIDE_256 = 0x6, 
  ATM128_CLK8_DIVIDE_1024 = 0x7
};

enum __nesc_unnamed4304 {
  ATM128_CLK16_OFF = 0x0, 
  ATM128_CLK16_NORMAL = 0x1, 
  ATM128_CLK16_DIVIDE_8 = 0x2, 
  ATM128_CLK16_DIVIDE_64 = 0x3, 
  ATM128_CLK16_DIVIDE_256 = 0x4, 
  ATM128_CLK16_DIVIDE_1024 = 0x5, 
  ATM128_CLK16_EXTERNAL_FALL = 0x6, 
  ATM128_CLK16_EXTERNAL_RISE = 0x7
};


enum __nesc_unnamed4305 {
  AVR_CLOCK_OFF = 0, 
  AVR_CLOCK_ON = 1, 
  AVR_CLOCK_DIVIDE_8 = 2
};


enum __nesc_unnamed4306 {
  ATM128_WAVE8_NORMAL = 0, 
  ATM128_WAVE8_PWM, 
  ATM128_WAVE8_CTC, 
  ATM128_WAVE8_PWM_FAST
};


enum __nesc_unnamed4307 {
  ATM128_COMPARE_OFF = 0, 
  ATM128_COMPARE_TOGGLE, 
  ATM128_COMPARE_CLEAR, 
  ATM128_COMPARE_SET
};
#line 108
#line 98
typedef union __nesc_unnamed4308 {

  uint8_t flat;
  struct __nesc_unnamed4309 {
    uint8_t cs : 3;
    uint8_t wgm1 : 1;
    uint8_t com : 2;
    uint8_t wgm0 : 1;
    uint8_t foc : 1;
  } bits;
} Atm128TimerControl_t;

typedef Atm128TimerControl_t Atm128_TCCR0_t;
typedef uint8_t Atm128_TCNT0_t;
typedef uint8_t Atm128_OCR0_t;

typedef Atm128TimerControl_t Atm128_TCCR2_t;
typedef uint8_t Atm128_TCNT2_t;
typedef uint8_t Atm128_OCR2_t;
#line 130
#line 120
typedef union __nesc_unnamed4310 {

  uint8_t flat;
  struct __nesc_unnamed4311 {
    uint8_t tcr0ub : 1;
    uint8_t ocr0ub : 1;
    uint8_t tcn0ub : 1;
    uint8_t as0 : 1;
    uint8_t rsvd : 4;
  } bits;
} Atm128Assr_t;
#line 146
#line 133
typedef union __nesc_unnamed4312 {

  uint8_t flat;
  struct __nesc_unnamed4313 {
    uint8_t toie0 : 1;
    uint8_t ocie0 : 1;
    uint8_t toie1 : 1;
    uint8_t ocie1b : 1;
    uint8_t ocie1a : 1;
    uint8_t ticie1 : 1;
    uint8_t toie2 : 1;
    uint8_t ocie2 : 1;
  } bits;
} Atm128_TIMSK_t;
#line 163
#line 150
typedef union __nesc_unnamed4314 {

  uint8_t flat;
  struct __nesc_unnamed4315 {
    uint8_t tov0 : 1;
    uint8_t ocf0 : 1;
    uint8_t tov1 : 1;
    uint8_t ocf1b : 1;
    uint8_t ocf1a : 1;
    uint8_t icf1 : 1;
    uint8_t tov2 : 1;
    uint8_t ocf2 : 1;
  } bits;
} Atm128_TIFR_t;
#line 178
#line 167
typedef union __nesc_unnamed4316 {

  uint8_t flat;
  struct __nesc_unnamed4317 {
    uint8_t psr321 : 1;
    uint8_t psr0 : 1;
    uint8_t pud : 1;
    uint8_t acme : 1;
    uint8_t rsvd : 3;
    uint8_t tsm : 1;
  } bits;
} Atm128_SFIOR_t;






enum __nesc_unnamed4318 {
  ATM128_TIMER_COMPARE_NORMAL = 0, 
  ATM128_TIMER_COMPARE_TOGGLE, 
  ATM128_TIMER_COMPARE_CLEAR, 
  ATM128_TIMER_COMPARE_SET
};
#line 202
#line 193
typedef union __nesc_unnamed4319 {

  uint8_t flat;
  struct __nesc_unnamed4320 {
    uint8_t wgm10 : 2;
    uint8_t comC : 2;
    uint8_t comB : 2;
    uint8_t comA : 2;
  } bits;
} Atm128TimerCtrlCompare_t;


typedef Atm128TimerCtrlCompare_t Atm128_TCCR1A_t;


typedef Atm128TimerCtrlCompare_t Atm128_TCCR3A_t;


enum __nesc_unnamed4321 {
  ATM128_WAVE16_NORMAL = 0, 
  ATM128_WAVE16_PWM_8BIT, 
  ATM128_WAVE16_PWM_9BIT, 
  ATM128_WAVE16_PWM_10BIT, 
  ATM128_WAVE16_CTC_COMPARE, 
  ATM128_WAVE16_PWM_FAST_8BIT, 
  ATM128_WAVE16_PWM_FAST_9BIT, 
  ATM128_WAVE16_PWM_FAST_10BIT, 
  ATM128_WAVE16_PWM_CAPTURE_LOW, 
  ATM128_WAVE16_PWM_COMPARE_LOW, 
  ATM128_WAVE16_PWM_CAPTURE_HIGH, 
  ATM128_WAVE16_PWM_COMPARE_HIGH, 
  ATM128_WAVE16_CTC_CAPTURE, 
  ATM128_WAVE16_RESERVED, 
  ATM128_WAVE16_PWM_FAST_CAPTURE, 
  ATM128_WAVE16_PWM_FAST_COMPARE
};
#line 241
#line 231
typedef union __nesc_unnamed4322 {

  uint8_t flat;
  struct __nesc_unnamed4323 {
    uint8_t cs : 3;
    uint8_t wgm32 : 2;
    uint8_t rsvd : 1;
    uint8_t ices1 : 1;
    uint8_t icnc1 : 1;
  } bits;
} Atm128TimerCtrlCapture_t;


typedef Atm128TimerCtrlCapture_t Atm128_TCCR1B_t;


typedef Atm128TimerCtrlCapture_t Atm128_TCCR3B_t;
#line 259
#line 250
typedef union __nesc_unnamed4324 {

  uint8_t flat;
  struct __nesc_unnamed4325 {
    uint8_t rsvd : 5;
    uint8_t focC : 1;
    uint8_t focB : 1;
    uint8_t focA : 1;
  } bits;
} Atm128TimerCtrlClock_t;


typedef Atm128TimerCtrlClock_t Atm128_TCCR1C_t;


typedef Atm128TimerCtrlClock_t Atm128_TCCR3C_t;



typedef uint8_t Atm128_TCNT1H_t;
typedef uint8_t Atm128_TCNT1L_t;
typedef uint8_t Atm128_TCNT3H_t;
typedef uint8_t Atm128_TCNT3L_t;


typedef uint8_t Atm128_OCR1AH_t;
typedef uint8_t Atm128_OCR1AL_t;
typedef uint8_t Atm128_OCR1BH_t;
typedef uint8_t Atm128_OCR1BL_t;
typedef uint8_t Atm128_OCR1CH_t;
typedef uint8_t Atm128_OCR1CL_t;


typedef uint8_t Atm128_OCR3AH_t;
typedef uint8_t Atm128_OCR3AL_t;
typedef uint8_t Atm128_OCR3BH_t;
typedef uint8_t Atm128_OCR3BL_t;
typedef uint8_t Atm128_OCR3CH_t;
typedef uint8_t Atm128_OCR3CL_t;


typedef uint8_t Atm128_ICR1H_t;
typedef uint8_t Atm128_ICR1L_t;
typedef uint8_t Atm128_ICR3H_t;
typedef uint8_t Atm128_ICR3L_t;
#line 309
#line 297
typedef union __nesc_unnamed4326 {

  uint8_t flat;
  struct __nesc_unnamed4327 {
    uint8_t ocie1c : 1;
    uint8_t ocie3c : 1;
    uint8_t toie3 : 1;
    uint8_t ocie3b : 1;
    uint8_t ocie3a : 1;
    uint8_t ticie3 : 1;
    uint8_t rsvd : 2;
  } bits;
} Atm128_ETIMSK_t;
#line 324
#line 312
typedef union __nesc_unnamed4328 {

  uint8_t flat;
  struct __nesc_unnamed4329 {
    uint8_t ocf1c : 1;
    uint8_t ocf3c : 1;
    uint8_t tov3 : 1;
    uint8_t ocf3b : 1;
    uint8_t ocf3a : 1;
    uint8_t icf3 : 1;
    uint8_t rsvd : 2;
  } bits;
} Atm128_ETIFR_t;
# 13 "ActiveQueryQueue.h"
#line 4
typedef nx_struct ActiveQueryQueue {
  nx_uint16_t source_id;
  nx_uint16_t sequence_number;
  nx_uint16_t forwarder_id;
  nx_uint16_t hops;
  nx_uint16_t sampling_period;
  nx_uint16_t query_lifetime;
  nx_uint16_t propagation_mode;
  nx_uint16_t state;
} __attribute__((packed)) ActiveQueryQueue_t;
# 8 "SendersHistory.h"
#line 4
typedef nx_struct SendersHistory {
  nx_uint16_t source_id;

  nx_uint16_t sequence_number;
} __attribute__((packed)) SendersHistory_t;
typedef TMilli /*AlarmCounterMilliP.Atm128AlarmAsyncC*/Atm128AlarmAsyncC$0$precision;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC*/Atm128AlarmAsyncC$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size;
typedef uint8_t HplAtm128Timer0AsyncP$Timer0$timer_size;
typedef uint8_t HplAtm128Timer0AsyncP$Compare$size_type;
typedef TMilli /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$precision_tag;
typedef uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$precision_tag;
typedef TMilli /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$precision_tag;
typedef TMilli /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$LocalTime$precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$precision_tag;
typedef uint32_t /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$size_type;
typedef uint16_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$width_t;
typedef /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$width_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$val_t;
typedef TMilli QueryPropagationC$Timer0$precision_tag;
typedef TMilli QueryPropagationC$Timer3$precision_tag;
typedef uint16_t QueryPropagationC$Read$val_t;
typedef TMilli QueryPropagationC$Timer1$precision_tag;
typedef TMilli QueryPropagationC$Timer4$precision_tag;
typedef TMilli QueryPropagationC$Timer2$precision_tag;
typedef TMilli QueryPropagationC$Timer5$precision_tag;
enum AMQueueP$__nesc_unnamed4330 {
  AMQueueP$NUM_CLIENTS = 2U
};
enum SerialAMQueueP$__nesc_unnamed4331 {
  SerialAMQueueP$NUM_CLIENTS = 1U
};
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t PlatformP$Init$init(void );
#line 62
static error_t MotePlatformP$SubInit$default$init(void );
#line 62
static error_t MotePlatformP$PlatformInit$init(void );
# 43 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
static bool /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$get(void );


static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set(void );
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$clr(void );

static bool /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$get(void );


static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set(void );
static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$clr(void );

static bool /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$get(void );


static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set(void );
static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$clr(void );


static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void );
#line 41
static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t MeasureClockC$Init$init(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t SimSchedulerBasicP$TaskBasic$postTask(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x40734970);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP$TaskBasic$default$runTask(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x40734970);
# 57 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
static void SimSchedulerBasicP$Scheduler$init(void );







static bool SimSchedulerBasicP$Scheduler$runNextTask(void );
# 44 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMote.nc"
static void SimMoteP$SimMote$setEuid(long long int euid);


static int SimMoteP$SimMote$getVariableInfo(char *name, void **ptr, size_t *len);

static void SimMoteP$SimMote$turnOff(void );
#line 48
static void SimMoteP$SimMote$turnOn(void );
#line 43
static long long int SimMoteP$SimMote$getEuid(void );


static bool SimMoteP$SimMote$isOn(void );
#line 45
static long long int SimMoteP$SimMote$getStartTime(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t TossimActiveMessageC$AMSend$send(
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408fb108, 
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Snoop$default$receive(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408f9178, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t TossimActiveMessageC$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


TossimActiveMessageC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void );
#line 94
static void TossimActiveMessageC$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Receive$default$receive(
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408fbac8, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static void TossimActiveMessageC$Model$receive(message_t *msg);
#line 76
static void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t error);










static bool TossimActiveMessageC$Model$shouldAck(message_t *msg);
# 68 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t TossimActiveMessageC$AMPacket$address(void );









static am_addr_t TossimActiveMessageC$AMPacket$destination(
#line 74
message_t * amsg);
#line 103
static void TossimActiveMessageC$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t TossimActiveMessageC$AMPacket$type(
#line 143
message_t * amsg);
#line 162
static void TossimActiveMessageC$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
#line 136
static bool TossimActiveMessageC$AMPacket$isForMe(
#line 133
message_t * amsg);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$stopDoneTask$runTask(void );
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimPacketModelC$Packet$send(int node, message_t *msg, uint8_t len);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$sendDoneTask$runTask(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t TossimPacketModelC$Init$init(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$startDoneTask$runTask(void );
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static error_t TossimPacketModelC$Control$start(void );
# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC$GainRadioModel$receive(message_t *msg);
#line 59
static void TossimPacketModelC$GainRadioModel$acked(message_t *msg);

static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg);
#line 48
static void CpmModelC$Model$putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain);


static bool CpmModelC$Model$clearChannel(void );
static void CpmModelC$Model$setPendingTransmission(void );
# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$amAddress(void );
# 50 "/opt/tinyos-2.1.2/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static error_t SerialActiveMessageC$SplitControl$start(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t SerialActiveMessageC$AMSend$send(
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
am_id_t arg_0x40a0dae8, 
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t SerialActiveMessageC$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


SerialActiveMessageC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t SerialActiveMessageC$Packet$maxPayloadLength(void );
#line 94
static void SerialActiveMessageC$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SerialActiveMessageC$startDone$runTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



SerialActiveMessageC$Receive$default$receive(
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
am_id_t arg_0x40a0c548, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SerialActiveMessageC$stopDone$runTask(void );
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static error_t SerialActiveMessageC$Model$default$send(int node, message_t *msg, uint8_t len);
#line 85
static void SerialActiveMessageC$Model$receive(message_t *msg);
#line 76
static void SerialActiveMessageC$Model$sendDone(message_t *msg, error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SerialActiveMessageC$modelSendDone$runTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t SerialActiveMessageC$AMPacket$destination(
#line 74
message_t * amsg);
#line 103
static void SerialActiveMessageC$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t SerialActiveMessageC$AMPacket$type(
#line 143
message_t * amsg);
#line 162
static void SerialActiveMessageC$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t LedsP$Init$init(void );
# 61 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
static void LedsP$Leds$led0Off(void );










static void LedsP$Leds$led1On(void );




static void LedsP$Leds$led1Off(void );
#line 94
static void LedsP$Leds$led2Off(void );
#line 56
static void LedsP$Leds$led0On(void );
#line 89
static void LedsP$Leds$led2On(void );
# 109 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void );
#line 103
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type t0, /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type dt);
#line 116
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void );
#line 73
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void );
# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void );
# 58 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void );
# 70 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void );
#line 61
static HplAtm128Timer0AsyncP$Timer0$timer_size HplAtm128Timer0AsyncP$Timer0$get(void );
#line 110
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void );
#line 67
static void HplAtm128Timer0AsyncP$Timer0$set(HplAtm128Timer0AsyncP$Timer0$timer_size t);
# 44 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
static int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void );
#line 32
static void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void );
# 53 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void );
#line 46
static void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t control);
# 48 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static HplAtm128Timer0AsyncP$Compare$size_type HplAtm128Timer0AsyncP$Compare$get(void );





static void HplAtm128Timer0AsyncP$Compare$set(HplAtm128Timer0AsyncP$Compare$size_type t);










static void HplAtm128Timer0AsyncP$Compare$start(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void );
# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void );
# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void );
#line 129
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );
#line 136
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
# 151 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getdt(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
# 144 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$gett0(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70, 
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
uint32_t dt);




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
# 82 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void );
# 55 "/opt/tinyos-2.1.2/tos/interfaces/Read.nc"
static error_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$read(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$runTask(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer0$fired(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void QueryPropagationC$SamplingRadioAMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void QueryPropagationC$init_StateMessages$runTask(void );
# 60 "/opt/tinyos-2.1.2/tos/interfaces/Boot.nc"
static void QueryPropagationC$Boot$booted(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer3$fired(void );
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void QueryPropagationC$RadioAMControl$startDone(error_t error);
#line 138
static void QueryPropagationC$RadioAMControl$stopDone(error_t error);
# 63 "/opt/tinyos-2.1.2/tos/interfaces/Read.nc"
static void QueryPropagationC$Read$readDone(error_t result, QueryPropagationC$Read$val_t val);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void QueryPropagationC$init_ActiveQueryQ$runTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



QueryPropagationC$SamplingRadioReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



QueryPropagationC$RadioReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer1$fired(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void QueryPropagationC$RadioAMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void QueryPropagationC$SerialAMControl$startDone(error_t error);
#line 138
static void QueryPropagationC$SerialAMControl$stopDone(error_t error);
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer4$fired(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



QueryPropagationC$SerialReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer2$fired(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void QueryPropagationC$SerialAMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void QueryPropagationC$QueryScheduling$runTask(void );
#line 75
static void QueryPropagationC$MeasurementScheduling$runTask(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer5$fired(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40d082b0, 
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40d098a8, 
# 67 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 100
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40d098a8, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );
#line 75
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$sendDone(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40d082b0, 
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$send(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40d098a8, 
# 67 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 100
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$default$sendDone(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40d098a8, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$runTask(void );
#line 75
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$CancelTask$runTask(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t PlatformP$MoteInit$init(void );
#line 62
static error_t PlatformP$MeasureClock$init(void );
# 51 "/opt/tinyos-2.1.2/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP$Init$init(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t MotePlatformP$SubInit$init(void );
# 44 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
static void MotePlatformP$SerialIdPin$makeInput(void );
#line 41
static void MotePlatformP$SerialIdPin$clr(void );
# 49 "/opt/tinyos-2.1.2/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$PlatformInit$init(void );
#line 61
static inline error_t MotePlatformP$SubInit$default$init(void );
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline bool /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$get(void );
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set(void );



static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$clr(void );



static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput(void );
#line 54
static __inline bool /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$get(void );
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set(void );



static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$clr(void );



static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput(void );
#line 54
static __inline bool /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$get(void );
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set(void );



static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$clr(void );



static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput(void );
#line 59
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void );


static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void );
# 21 "/opt/tinyos-2.1.2/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC$Init$init(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t SimMainP$SoftwareInit$init(void );
# 60 "/opt/tinyos-2.1.2/tos/interfaces/Boot.nc"
static void SimMainP$Boot$booted(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t SimMainP$PlatformInit$init(void );
# 57 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
static void SimMainP$Scheduler$init(void );







static bool SimMainP$Scheduler$runNextTask(void );
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMainP.nc"
int sim_main_start_mote(void )   ;
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP$TaskBasic$runTask(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x40734970);



enum SimSchedulerBasicP$__nesc_unnamed4332 {

  SimSchedulerBasicP$NUM_TASKS = 17U, 
  SimSchedulerBasicP$NO_TASK = 255
};

uint8_t SimSchedulerBasicP$m_head[1000];
uint8_t SimSchedulerBasicP$m_tail[1000];
uint8_t SimSchedulerBasicP$m_next[1000][SimSchedulerBasicP$NUM_TASKS];




bool SimSchedulerBasicP$sim_scheduler_event_pending[1000];
sim_event_t SimSchedulerBasicP$sim_scheduler_event[1000];

static inline int SimSchedulerBasicP$sim_config_task_latency(void );







static void SimSchedulerBasicP$sim_scheduler_submit_event(void );







static inline void SimSchedulerBasicP$sim_scheduler_event_handle(sim_event_t *e);
#line 103
static inline void SimSchedulerBasicP$sim_scheduler_event_init(sim_event_t *e);
#line 120
static inline uint8_t SimSchedulerBasicP$popTask(void );
#line 139
static inline bool SimSchedulerBasicP$isWaiting(uint8_t id);




static inline bool SimSchedulerBasicP$pushTask(uint8_t id);
#line 166
static inline void SimSchedulerBasicP$Scheduler$init(void );
#line 180
static bool SimSchedulerBasicP$Scheduler$runNextTask(void );
#line 205
static error_t SimSchedulerBasicP$TaskBasic$postTask(uint8_t id);
#line 221
static inline void SimSchedulerBasicP$TaskBasic$default$runTask(uint8_t id);
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
long long int SimMoteP$euid[1000];
long long int SimMoteP$startTime[1000];
bool SimMoteP$isOn[1000];
sim_event_t *SimMoteP$bootEvent[1000];

static inline long long int SimMoteP$SimMote$getEuid(void );


static inline void SimMoteP$SimMote$setEuid(long long int e);


static inline long long int SimMoteP$SimMote$getStartTime(void );


static inline bool SimMoteP$SimMote$isOn(void );



static inline int SimMoteP$SimMote$getVariableInfo(char *name, void **addr, size_t *size);



static void SimMoteP$SimMote$turnOn(void );
#line 85
static inline void SimMoteP$SimMote$turnOff(void );




long long int sim_mote_euid(int mote)   ;








void sim_mote_set_euid(int mote, long long int id)   ;






long long int sim_mote_start_time(int mote)   ;








int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)   ;









void sim_mote_set_start_time(int mote, long long int t)   ;








bool sim_mote_is_on(int mote)   ;








void sim_mote_turn_on(int mote)   ;






void sim_mote_turn_off(int mote)   ;






static inline void SimMoteP$sim_mote_boot_handle(sim_event_t *e);








void sim_mote_enqueue_boot_event(int mote)   ;
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static am_addr_t TossimActiveMessageC$amAddress(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void TossimActiveMessageC$AMSend$sendDone(
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408fb108, 
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Snoop$receive(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408f9178, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



TossimActiveMessageC$Receive$receive(
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408fbac8, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimActiveMessageC$Model$send(int node, message_t *msg, uint8_t len);
# 62 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
message_t TossimActiveMessageC$buffer[1000];
message_t *TossimActiveMessageC$bufferPointer[1000];

static inline tossim_header_t *TossimActiveMessageC$getHeader(message_t *amsg);







static error_t TossimActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len);
#line 103
static inline void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t result);





static void TossimActiveMessageC$Model$receive(message_t *msg);
#line 127
static inline bool TossimActiveMessageC$Model$shouldAck(message_t *msg);








static inline am_addr_t TossimActiveMessageC$AMPacket$address(void );



static am_addr_t TossimActiveMessageC$AMPacket$destination(message_t *amsg);




static void TossimActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr);
#line 160
static inline bool TossimActiveMessageC$AMPacket$isForMe(message_t *amsg);




static am_id_t TossimActiveMessageC$AMPacket$type(message_t *amsg);




static void TossimActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t);






static inline uint8_t TossimActiveMessageC$Packet$payloadLength(message_t *msg);



static inline void TossimActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len);



static inline uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void );



static inline void *TossimActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len);
#line 212
static inline message_t *TossimActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);



static inline message_t *TossimActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
#line 236
static inline void TossimActiveMessageC$active_message_deliver_handle(sim_event_t *evt);





static inline sim_event_t *TossimActiveMessageC$allocate_deliver_event(int node, message_t *msg, sim_time_t t);
#line 254
void active_message_deliver(int node, message_t *msg, sim_time_t t)   ;
# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static void TossimPacketModelC$Packet$receive(message_t *msg);
#line 76
static void TossimPacketModelC$Packet$sendDone(message_t *msg, error_t error);










static bool TossimPacketModelC$Packet$shouldAck(message_t *msg);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t TossimPacketModelC$startDoneTask$postTask(void );
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void TossimPacketModelC$Control$startDone(error_t error);
#line 138
static void TossimPacketModelC$Control$stopDone(error_t error);
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC$GainRadioModel$putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain);


static bool TossimPacketModelC$GainRadioModel$clearChannel(void );
static void TossimPacketModelC$GainRadioModel$setPendingTransmission(void );
# 96 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
enum TossimPacketModelC$__nesc_unnamed4333 {
#line 96
  TossimPacketModelC$startDoneTask = 0U
};
#line 96
typedef int TossimPacketModelC$__nesc_sillytask_startDoneTask[TossimPacketModelC$startDoneTask];




enum TossimPacketModelC$__nesc_unnamed4334 {
#line 101
  TossimPacketModelC$stopDoneTask = 1U
};
#line 101
typedef int TossimPacketModelC$__nesc_sillytask_stopDoneTask[TossimPacketModelC$stopDoneTask];
#line 145
enum TossimPacketModelC$__nesc_unnamed4335 {
#line 145
  TossimPacketModelC$sendDoneTask = 2U
};
#line 145
typedef int TossimPacketModelC$__nesc_sillytask_sendDoneTask[TossimPacketModelC$sendDoneTask];
#line 70
bool TossimPacketModelC$initialized[1000];
bool TossimPacketModelC$running[1000];
uint8_t TossimPacketModelC$backoffCount[1000];
uint8_t TossimPacketModelC$neededFreeSamples[1000];
message_t *TossimPacketModelC$sending[1000];
bool TossimPacketModelC$transmitting[1000];
uint8_t TossimPacketModelC$sendingLength[1000];
int TossimPacketModelC$destNode[1000];
sim_event_t TossimPacketModelC$sendEvent[1000];



static inline tossim_metadata_t *TossimPacketModelC$getMetadata(message_t *msg);



static inline error_t TossimPacketModelC$Init$init(void );









static inline void TossimPacketModelC$startDoneTask$runTask(void );




static inline void TossimPacketModelC$stopDoneTask$runTask(void );




static error_t TossimPacketModelC$Control$start(void );
#line 145
static inline void TossimPacketModelC$sendDoneTask$runTask(void );
#line 159
static inline void TossimPacketModelC$start_csma(void );

static inline error_t TossimPacketModelC$Packet$send(int dest, message_t *msg, uint8_t len);
#line 183
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt);
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt);
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt);

static inline void TossimPacketModelC$start_csma(void );
#line 211
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt);
#line 253
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt);
#line 280
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt);







static inline void TossimPacketModelC$GainRadioModel$receive(message_t *msg);





uint8_t TossimPacketModelC$error[1000];

static inline void TossimPacketModelC$GainRadioModel$acked(message_t *msg);










static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg);
# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
static void CpmModelC$Model$receive(message_t *msg);
#line 59
static void CpmModelC$Model$acked(message_t *msg);

static bool CpmModelC$Model$shouldAck(message_t *msg);
# 58 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
message_t *CpmModelC$outgoing[1000];
bool CpmModelC$requestAck[1000];
bool CpmModelC$receiving[1000];
bool CpmModelC$transmitting[1000];
sim_time_t CpmModelC$transmissionEndTime[1000];
struct CpmModelC$receive_message;
typedef struct CpmModelC$receive_message CpmModelC$receive_message_t;

struct CpmModelC$receive_message {
  int source;
  sim_time_t start;
  sim_time_t end;
  double power;
  double reversePower;
  int8_t strength;
  bool lost;
  bool ack;
  message_t *msg;
  CpmModelC$receive_message_t *next;
};

CpmModelC$receive_message_t *CpmModelC$outstandingReceptionHead[1000];

static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void );
static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg);
static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t t, CpmModelC$receive_message_t *m);

static bool CpmModelC$shouldReceive(double SNR);
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg);
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg);


static inline double CpmModelC$timeInMs(void );
#line 126
static double CpmModelC$noise_hash_generation(void );
#line 151
static inline double CpmModelC$arr_estimate_from_snr(double SNR);
#line 166
static inline int CpmModelC$shouldAckReceive(double snr);
#line 178
static inline void CpmModelC$sim_gain_ack_handle(sim_event_t *evt);
#line 200
double CpmModelC$clearThreshold[1000];










static inline bool CpmModelC$Model$clearChannel(void );




static void CpmModelC$sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC$receive_message_t *r);
#line 230
static inline double CpmModelC$prr_estimate_from_snr(double SNR);
#line 248
static bool CpmModelC$shouldReceive(double SNR);
#line 260
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg);
#line 274
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg);
#line 296
static inline void CpmModelC$sim_gain_receive_handle(sim_event_t *evt);
#line 369
static inline void CpmModelC$enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower);
#line 428
static inline void CpmModelC$sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower);







static inline void CpmModelC$Model$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower);
#line 459
static inline void CpmModelC$Model$setPendingTransmission(void );







static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t endTime, CpmModelC$receive_message_t *msg);
#line 479
static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void );



static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg);
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
bool ActiveMessageAddressC$set[1000];
am_addr_t ActiveMessageAddressC$addr[1000];









static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );
#line 88
static inline am_addr_t ActiveMessageAddressC$amAddress(void );
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void SerialActiveMessageC$SplitControl$startDone(error_t error);
#line 138
static void SerialActiveMessageC$SplitControl$stopDone(error_t error);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void SerialActiveMessageC$AMSend$sendDone(
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
am_id_t arg_0x40a0dae8, 
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t SerialActiveMessageC$startDone$postTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



SerialActiveMessageC$Receive$receive(
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
am_id_t arg_0x40a0c548, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static error_t SerialActiveMessageC$Model$send(int node, message_t *msg, uint8_t len);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t SerialActiveMessageC$modelSendDone$postTask(void );
# 74 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
enum SerialActiveMessageC$__nesc_unnamed4336 {
#line 74
  SerialActiveMessageC$startDone = 3U
};
#line 74
typedef int SerialActiveMessageC$__nesc_sillytask_startDone[SerialActiveMessageC$startDone];
enum SerialActiveMessageC$__nesc_unnamed4337 {
#line 75
  SerialActiveMessageC$stopDone = 4U
};
#line 75
typedef int SerialActiveMessageC$__nesc_sillytask_stopDone[SerialActiveMessageC$stopDone];
#line 119
enum SerialActiveMessageC$__nesc_unnamed4338 {
#line 119
  SerialActiveMessageC$modelSendDone = 5U
};
#line 119
typedef int SerialActiveMessageC$__nesc_sillytask_modelSendDone[SerialActiveMessageC$modelSendDone];
#line 65
message_t SerialActiveMessageC$buffer[1000];
message_t *SerialActiveMessageC$bufferPointer[1000];

message_t *SerialActiveMessageC$sendMsgPtr[1000];

static inline serial_header_t *SerialActiveMessageC$getHeader(message_t *amsg);



static inline void SerialActiveMessageC$startDone$runTask(void );
static inline void SerialActiveMessageC$stopDone$runTask(void );

static inline error_t SerialActiveMessageC$SplitControl$start(void );









static error_t SerialActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len);
#line 115
static inline void SerialActiveMessageC$Model$sendDone(message_t *msg, error_t result);



static inline void SerialActiveMessageC$modelSendDone$runTask(void );




static inline error_t SerialActiveMessageC$Model$default$send(int node, message_t *msg, uint8_t len);
#line 139
static inline void SerialActiveMessageC$Model$receive(message_t *msg);
#line 171
static am_addr_t SerialActiveMessageC$AMPacket$destination(message_t *amsg);




static inline void SerialActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr);
#line 196
static am_id_t SerialActiveMessageC$AMPacket$type(message_t *amsg);




static inline void SerialActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t);
#line 221
static inline void *SerialActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len);







static inline void SerialActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len);



static inline uint8_t SerialActiveMessageC$Packet$maxPayloadLength(void );



static uint8_t SerialActiveMessageC$Packet$payloadLength(message_t *msg);
#line 252
static inline message_t *SerialActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
#line 272
static inline void SerialActiveMessageC$serial_active_message_deliver_handle(sim_event_t *evt);




static inline sim_event_t *SerialActiveMessageC$allocate_serial_deliver_event(int node, message_t *msg, sim_time_t t);
#line 293
void serial_active_message_deliver(int node, message_t *msg, sim_time_t t)   ;
# 43 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
static bool LedsP$Led0$get(void );


static void LedsP$Led0$makeOutput(void );
#line 40
static void LedsP$Led0$set(void );
static void LedsP$Led0$clr(void );

static bool LedsP$Led1$get(void );


static void LedsP$Led1$makeOutput(void );
#line 40
static void LedsP$Led1$set(void );
static void LedsP$Led1$clr(void );

static bool LedsP$Led2$get(void );


static void LedsP$Led2$makeOutput(void );
#line 40
static void LedsP$Led2$set(void );
static void LedsP$Led2$clr(void );
# 56 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static inline error_t LedsP$Init$init(void );
#line 74
static inline void LedsP$Leds$led0On(void );




static void LedsP$Leds$led0Off(void );









static inline void LedsP$Leds$led1On(void );




static void LedsP$Leds$led1Off(void );









static void LedsP$Leds$led2On(void );




static void LedsP$Leds$led2Off(void );
# 53 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
static Atm128_TIFR_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag(void );
#line 46
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(Atm128TimerControl_t control);
# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired(void );
# 82 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow(void );
# 44 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
static int /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy(void );
#line 32
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous(void );
# 48 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get(void );





static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type t);










static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start(void );
# 61 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get(void );
# 38 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[1000];
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[1000];
#line 39
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[1000];
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[1000];



enum /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$__nesc_unnamed4339 {
  Atm128AlarmAsyncP$0$MINDT = 2, 
  Atm128AlarmAsyncP$0$MAXT = 230
};



static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void );


static inline error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void );
#line 74
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(uint8_t n);
#line 90
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void );
#line 149
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void );
#line 161
static uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void );
#line 204
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void );







static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(uint32_t nt0, uint32_t ndt);









static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void );



static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void );



static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void );
# 70 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void HplAtm128Timer0AsyncP$Timer0$overflow(void );
# 58 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void HplAtm128Timer0AsyncP$Compare$fired(void );
# 57 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
bool HplAtm128Timer0AsyncP$inOverflow[1000];




static inline void HplAtm128Timer0AsyncP$cancel_overflow(void );
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void );
static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *e);
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void );

static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );




sim_time_t HplAtm128Timer0AsyncP$lastZero[1000];





uint8_t HplAtm128Timer0AsyncP$oldScale[1000];



static inline void HplAtm128Timer0AsyncP$cancel_compare(void );
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void );
static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *e);
static void HplAtm128Timer0AsyncP$schedule_new_compare(void );

static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );


void INTERRUPT_15(void )   ;





void INTERRUPT_16(void )   ;







static sim_time_t HplAtm128Timer0AsyncP$last_zero(void );







static inline void HplAtm128Timer0AsyncP$notify_changed(void );










static inline sim_time_t HplAtm128Timer0AsyncP$notify_clockTicksPerSec(void );
#line 148
static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);





static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);





static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );
#line 185
sim_event_t *HplAtm128Timer0AsyncP$compare[1000];

static inline void HplAtm128Timer0AsyncP$timer0_compare_handle(sim_event_t *evt);
#line 223
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void );







static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *evt);
#line 267
static void HplAtm128Timer0AsyncP$schedule_new_compare(void );
#line 282
static uint8_t HplAtm128Timer0AsyncP$Timer0$get(void );
#line 297
static inline void HplAtm128Timer0AsyncP$Timer0$set(uint8_t newVal);
#line 321
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void );
#line 364
static inline void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t x);
#line 383
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void );
#line 447
static inline void HplAtm128Timer0AsyncP$Compare$start(void );









static uint8_t HplAtm128Timer0AsyncP$Compare$get(void );





static void HplAtm128Timer0AsyncP$Compare$set(uint8_t t);
#line 480
sim_event_t *HplAtm128Timer0AsyncP$overflow[1000];
static inline void HplAtm128Timer0AsyncP$timer0_overflow_handle(sim_event_t *evt);
#line 500
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void );







static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *evt);
#line 534
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void );










static inline void HplAtm128Timer0AsyncP$cancel_overflow(void );
#line 561
static inline void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void );







static inline int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void );







static inline void HplAtm128Timer0AsyncP$cancel_compare(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask(void );
# 109 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type dt);
#line 116
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired(void );
# 74 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$__nesc_unnamed4340 {
#line 74
  AlarmToTimerC$0$fired = 6U
};
#line 74
typedef int /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$__nesc_sillytask_fired[/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired];
#line 55
uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[1000];
bool /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[1000];

static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(uint32_t t0, uint32_t dt, bool oneshot);
#line 71
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void );


static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void );






static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void );
#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt);


static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void );
# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40be2c70);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4341 {
#line 71
  VirtualizeTimerC$0$updateFromTimer = 7U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4342 {

  VirtualizeTimerC$0$NUM_TIMERS = 6U, 
  VirtualizeTimerC$0$END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4343 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[1000][/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now);
#line 100
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
#line 139
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot);
#line 159
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(uint8_t num, uint32_t dt);




static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(uint8_t num);




static inline bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(uint8_t num);
#line 189
static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(uint8_t num);




static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$gett0(uint8_t num);




static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getdt(uint8_t num);




static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num);
# 58 "/opt/tinyos-2.1.2/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void );
# 63 "/opt/tinyos-2.1.2/tos/interfaces/Read.nc"
static void /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$readDone(error_t result, /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$val_t val);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$postTask(void );
# 47 "/opt/tinyos-2.1.2/tos/system/ConstantSensorC.nc"
enum /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$__nesc_unnamed4344 {
#line 47
  ConstantSensorC$0$senseResult = 8U
};
#line 47
typedef int /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$__nesc_sillytask_senseResult[/*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult];
#line 47
static inline void /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$runTask(void );



static inline error_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$read(void );
# 151 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t QueryPropagationC$Timer0$getdt(void );
#line 144
static uint32_t QueryPropagationC$Timer0$gett0(void );
#line 92
static bool QueryPropagationC$Timer0$isRunning(void );
#line 73
static void QueryPropagationC$Timer0$startOneShot(uint32_t dt);
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t QueryPropagationC$SamplingRadioAMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t QueryPropagationC$init_StateMessages$postTask(void );
# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t QueryPropagationC$Timer3$getNow(void );
#line 92
static bool QueryPropagationC$Timer3$isRunning(void );
#line 73
static void QueryPropagationC$Timer3$startOneShot(uint32_t dt);
# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static 
#line 123
void * 


QueryPropagationC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 126
static 
#line 123
void * 


QueryPropagationC$SamplingAMPacket$getPayload(
#line 121
message_t * msg, 




uint8_t len);
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static error_t QueryPropagationC$RadioAMControl$start(void );
# 55 "/opt/tinyos-2.1.2/tos/interfaces/Read.nc"
static error_t QueryPropagationC$Read$read(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t QueryPropagationC$init_ActiveQueryQ$postTask(void );
# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t QueryPropagationC$Timer1$getNow(void );
#line 92
static bool QueryPropagationC$Timer1$isRunning(void );
#line 73
static void QueryPropagationC$Timer1$startOneShot(uint32_t dt);




static void QueryPropagationC$Timer1$stop(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t QueryPropagationC$RadioAMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static 
#line 123
void * 


QueryPropagationC$SerialPacket$getPayload(
#line 121
message_t * msg, 




uint8_t len);
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static error_t QueryPropagationC$SerialAMControl$start(void );
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer4$startOneShot(uint32_t dt);
# 61 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
static void QueryPropagationC$Leds$led0Off(void );










static void QueryPropagationC$Leds$led1On(void );




static void QueryPropagationC$Leds$led1Off(void );
#line 94
static void QueryPropagationC$Leds$led2Off(void );
#line 56
static void QueryPropagationC$Leds$led0On(void );
#line 89
static void QueryPropagationC$Leds$led2On(void );
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer2$startOneShot(uint32_t dt);
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t QueryPropagationC$SerialAMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t QueryPropagationC$QueryScheduling$postTask(void );
#line 67
static error_t QueryPropagationC$MeasurementScheduling$postTask(void );
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer5$startOneShot(uint32_t dt);
# 113 "QueryPropagationC.nc"
enum QueryPropagationC$__nesc_unnamed4345 {
#line 113
  QueryPropagationC$init_StateMessages = 9U
};
#line 113
typedef int QueryPropagationC$__nesc_sillytask_init_StateMessages[QueryPropagationC$init_StateMessages];






enum QueryPropagationC$__nesc_unnamed4346 {
#line 120
  QueryPropagationC$init_ActiveQueryQ = 10U
};
#line 120
typedef int QueryPropagationC$__nesc_sillytask_init_ActiveQueryQ[QueryPropagationC$init_ActiveQueryQ];






enum QueryPropagationC$__nesc_unnamed4347 {
#line 127
  QueryPropagationC$QueryScheduling = 11U
};
#line 127
typedef int QueryPropagationC$__nesc_sillytask_QueryScheduling[QueryPropagationC$QueryScheduling];
#line 171
enum QueryPropagationC$__nesc_unnamed4348 {
#line 171
  QueryPropagationC$MeasurementScheduling = 12U
};
#line 171
typedef int QueryPropagationC$__nesc_sillytask_MeasurementScheduling[QueryPropagationC$MeasurementScheduling];
#line 54
query_flooding_msg_t *QueryPropagationC$r_pkt[1000];
#line 54
query_flooding_msg_t *QueryPropagationC$bcast_pkt[1000];
sampling_msg_t *QueryPropagationC$r_sampling_pkt[1000];
#line 55
sampling_msg_t *QueryPropagationC$s_sampling_pkt[1000];
#line 55
sampling_msg_t *QueryPropagationC$ucast_pkt[1000];
query_msg_t *QueryPropagationC$s_pkt[1000];

message_t QueryPropagationC$pkt[1000];
#line 58
message_t QueryPropagationC$serial_pkt[1000];


uint16_t QueryPropagationC$sequence_number[1000];







uint8_t QueryPropagationC$send[1000];
#line 69
uint8_t QueryPropagationC$save[1000];
uint8_t QueryPropagationC$sampling_send[1000];
#line 70
uint8_t QueryPropagationC$sampling_save[1000];
uint8_t QueryPropagationC$number_Of_queries[1000];
uint8_t QueryPropagationC$next[1000];
uint8_t QueryPropagationC$count_contributed_nodes[1000];


uint16_t QueryPropagationC$t0[1000];
#line 76
uint16_t QueryPropagationC$dt[1000];
uint16_t QueryPropagationC$start[1000];
uint16_t QueryPropagationC$HoldTimer[1000];
uint16_t QueryPropagationC$query_pos[1000];
uint16_t QueryPropagationC$minQuery[1000];
uint16_t QueryPropagationC$expiredQuery[1000];
uint16_t QueryPropagationC$sendQuery[1000];

uint16_t QueryPropagationC$runningTime[1000];
uint16_t QueryPropagationC$checkTimer[1000];
uint16_t QueryPropagationC$timerStartAt[1000];
uint16_t QueryPropagationC$time4MeasurementStartAt[1000];
uint16_t QueryPropagationC$Hold_Sampling_Timer[1000];
uint16_t QueryPropagationC$minPeriod[1000];
uint16_t QueryPropagationC$sendTofather[1000];
uint16_t QueryPropagationC$sensor_data[1000];
uint16_t QueryPropagationC$source_id[1000];
uint16_t QueryPropagationC$sequence_number[1000];
uint16_t QueryPropagationC$data_id[1000];
uint16_t QueryPropagationC$s_data_id[1000];
uint16_t QueryPropagationC$forwarder_id[1000];
uint16_t QueryPropagationC$destination_id[1000];


bool QueryPropagationC$busy[1000];
bool QueryPropagationC$unicast_busy[1000];
bool QueryPropagationC$serial_busy[1000];


uint16_t QueryPropagationC$TimeToMeasure[1000][3];
message_t QueryPropagationC$PacketBuffer[1000][30];
#line 106
message_t QueryPropagationC$SamplingPacketBuffer[1000][30];
ActiveQueryQueue_t QueryPropagationC$AQQ[1000][3];
SendersHistory_t QueryPropagationC$QuerySendersHistory[1000][5];




static inline void QueryPropagationC$init_StateMessages$runTask(void );






static inline void QueryPropagationC$init_ActiveQueryQ$runTask(void );






static inline void QueryPropagationC$QueryScheduling$runTask(void );
#line 171
static inline void QueryPropagationC$MeasurementScheduling$runTask(void );
#line 206
static inline void QueryPropagationC$Boot$booted(void );
#line 230
static inline void QueryPropagationC$RadioAMControl$startDone(error_t err);








static inline void QueryPropagationC$RadioAMControl$stopDone(error_t err);


static inline void QueryPropagationC$SerialAMControl$startDone(error_t err);








static inline void QueryPropagationC$SerialAMControl$stopDone(error_t err);


static inline void QueryPropagationC$Timer0$fired(void );
#line 276
static inline void QueryPropagationC$Timer1$fired(void );










static inline void QueryPropagationC$Read$readDone(error_t result, uint16_t data);
#line 364
static inline void QueryPropagationC$Timer2$fired(void );
#line 386
static inline void QueryPropagationC$Timer3$fired(void );
#line 418
static inline void QueryPropagationC$Timer4$fired(void );
#line 437
static inline void QueryPropagationC$Timer5$fired(void );
#line 457
static inline message_t *QueryPropagationC$SamplingRadioReceive$receive(message_t *msg, void *payload, uint8_t len);
#line 508
static inline message_t *QueryPropagationC$RadioReceive$receive(message_t *msg, void *payload, uint8_t len);
#line 590
static inline message_t *QueryPropagationC$SerialReceive$receive(message_t *msg, void *payload, uint8_t len);
#line 645
static void QueryPropagationC$RadioAMSend$sendDone(message_t *msg, error_t err);
#line 657
static void QueryPropagationC$SamplingRadioAMSend$sendDone(message_t *msg, error_t err);
#line 670
static inline void QueryPropagationC$SerialAMSend$sendDone(message_t *msg, error_t err);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(
#line 67
message_t * msg, 







uint8_t len);
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err);
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40d082b0, 
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40d098a8, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(
#line 74
message_t * msg);
#line 94
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(
#line 143
message_t * amsg);
# 126 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4349 {
#line 126
  AMQueueImplP$0$CancelTask = 13U
};
#line 126
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_CancelTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask];
#line 169
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4350 {
#line 169
  AMQueueImplP$0$errorTask = 14U
};
#line 169
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask];
#line 57
#line 55
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4351 {
  message_t * msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[1000];
/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[1000][2];
uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[1000][2 / 8 + 1];

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void );
#line 90
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
#line 163
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );




static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );
#line 189
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err);
#line 215
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$send(
#line 67
message_t * msg, 







uint8_t len);
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static error_t /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(message_t *m, error_t err);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$send(
#line 67
message_t * msg, 







uint8_t len);
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$sendDone(message_t *m, error_t err);
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$send(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40d082b0, 
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$sendDone(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40d098a8, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Packet$payloadLength(
#line 74
message_t * msg);
#line 94
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$postTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$type(
#line 143
message_t * amsg);
# 126 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
enum /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$__nesc_unnamed4352 {
#line 126
  AMQueueImplP$1$CancelTask = 15U
};
#line 126
typedef int /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$__nesc_sillytask_CancelTask[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$CancelTask];
#line 169
enum /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$__nesc_unnamed4353 {
#line 169
  AMQueueImplP$1$errorTask = 16U
};
#line 169
typedef int /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$__nesc_sillytask_errorTask[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask];
#line 57
#line 55
typedef struct /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$__nesc_unnamed4354 {
  message_t * msg;
} /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue_entry_t;

uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[1000];
/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue_entry_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[1000][1];
uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[1000][1 / 8 + 1];

static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$tryToSend(void );

static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$nextPacket(void );
#line 90
static inline error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$CancelTask$runTask(void );
#line 163
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$runTask(void );




static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$tryToSend(void );
#line 189
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$sendDone(am_id_t id, message_t *msg, error_t err);
#line 215
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$default$sendDone(uint8_t id, message_t *msg, error_t err);
# 78 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
static inline void init_heap(heap_t *heap)
#line 78
{
  heap->size = 0;
  heap->private_size = STARTING_SIZE;
  heap->data = malloc(sizeof(node_t ) * heap->private_size);
}

#line 130
static inline void expand_heap(heap_t *heap)
#line 130
{
  int new_size = heap->private_size * 2 + 1;
  void *new_data = malloc(sizeof(node_t ) * new_size);



  memcpy(new_data, heap->data, sizeof(node_t ) * heap->private_size);
  free(heap->data);

  heap->data = new_data;
  heap->private_size = new_size;
}


static inline void heap_insert(heap_t *heap, void *data, long long int key)
#line 144
{
  int findex = heap->size;

#line 146
  if (findex == heap->private_size) {
      expand_heap(heap);
    }

  findex = heap->size;
  ((node_t *)heap->data)[findex].key = key;
  ((node_t *)heap->data)[findex].data = data;
  up_heap(heap, findex);

  heap->size++;
}

#line 88
static inline int is_empty(heap_t *heap)
#line 88
{
  return heap->size == 0;
}

static inline int heap_is_empty(heap_t *heap)
#line 92
{
  return is_empty(heap);
}

static inline long long int heap_get_min_key(heap_t *heap)
#line 96
{
  if (is_empty(heap)) {
      return -1;
    }
  else {
      return ((node_t *)heap->data)[0].key;
    }
}

# 317 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
inline static int sim_log_eq(void *key1, void *key2)
#line 317
{
  return strcmp((char *)key1, (char *)key2) == 0;
}

#line 306
inline static unsigned int sim_log_hash(void *key)
#line 306
{
  char *str = (char *)key;
  unsigned int hashVal = 0;
  int hashChar;

  while ((hashChar = * str++)) 
    hashVal = hashChar + (hashVal << 6) + (hashVal << 16) - hashVal;

  return hashVal;
}

#line 159
static inline void sim_log_init()
#line 159
{
  int i;

  channelTable = create_hashtable(128, sim_log_hash, sim_log_eq);

  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      outputs[i].num = 1;
      outputs[i].files = (FILE **)malloc(sizeof(FILE *));
      outputs[i].files[0] = fdopen(1, "w");
    }
}

# 130 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
inline static unsigned int sim_noise_hash(void *key)
#line 130
{
  char *pt = (char *)key;
  unsigned int hashVal = 0;
  int i;

#line 134
  for (i = 0; i < NOISE_HISTORY; i++) {
      hashVal = pt[i] + (hashVal << 6) + (hashVal << 16) - hashVal;
    }
  return hashVal;
}

inline static int sim_noise_eq(void *key1, void *key2)
#line 140
{
  return memcmp((void *)key1, (void *)key2, NOISE_HISTORY) == 0;
}

# 64 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
static inline bool SimMoteP$SimMote$isOn(void )
#line 64
{
  return SimMoteP$isOn[sim_node()];
}

# 172 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static inline void sim_log_add_channel(char *name, FILE *file)
#line 172
{
  sim_log_channel_t *channel;

#line 174
  channel = (sim_log_channel_t *)hashtable_search(channelTable, name);



  if (channel == (void *)0) {
      char *newName = (char *)malloc(strlen(name) + 1);

#line 180
      strcpy(newName, name);
      newName[strlen(name)] = 0;

      channel = (sim_log_channel_t *)malloc(sizeof(sim_log_channel_t ));
      channel->name = newName;
      channel->numOutputs = 0;
      channel->size = DEFAULT_CHANNEL_SIZE;
      channel->outputs = (FILE **)malloc(sizeof(FILE *) * channel->size);
      memset(channel->outputs, 0, sizeof(FILE *) * channel->size);
      hashtable_insert(channelTable, newName, channel);
    }



  if (channel->numOutputs == channel->size) {
      FILE **newOutputs;
      int newSize = channel->size * 2;

      newOutputs = (FILE **)malloc(sizeof(FILE *) * newSize);
      memcpy(newOutputs, channel->outputs, channel->size * sizeof(FILE **));

      free(channel->outputs);

      channel->outputs = newOutputs;
      channel->size = newSize;
    }

  channel->outputs[channel->numOutputs] = file;
  channel->numOutputs++;
  sim_log_commit_change();
}

static inline bool sim_log_remove_channel(char *output, FILE *file)
#line 212
{
  sim_log_channel_t *channel;
  int i;

#line 215
  channel = (sim_log_channel_t *)hashtable_search(channelTable, output);

  if (channel == (void *)0) {
      return FALSE;
    }


  for (i = 0; i < channel->numOutputs; i++) {
      FILE *f = channel->outputs[i];

#line 224
      if (file == f) {
          memcpy(&channel->outputs[i], &channel->outputs[i + 1], channel->numOutputs - (i + 1));
          channel->outputs[channel->numOutputs - 1] = (void *)0;
          channel->numOutputs--;
        }
    }

  return TRUE;
}

# 161 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.c"
static inline gain_entry_t *sim_gain_allocate_link(int mote)
#line 161
{
  gain_entry_t *newLink = (gain_entry_t *)malloc(sizeof(gain_entry_t ));

#line 163
  newLink->next = (void *)0;
  newLink->mote = mote;
  newLink->gain = -10000000.0;
  return newLink;
}

# 55 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.c"
static inline void RandomInitialise(int ij, int kl)
{
  double s;
#line 57
  double t;
  int ii;
#line 58
  int i;
#line 58
  int j;
#line 58
  int k;
#line 58
  int l;
#line 58
  int jj;
#line 58
  int m;






  if (((ij < 0 || ij > 31328) || kl < 0) || kl > 30081) {
      ij = 1802;
      kl = 9373;
    }

  i = ij / 177 % 177 + 2;
  j = ij % 177 + 2;
  k = kl / 169 % 178 + 1;
  l = kl % 169;

  for (ii = 0; ii < 97; ii++) {
      s = 0.0;
      t = 0.5;
      for (jj = 0; jj < 24; jj++) {
          m = i * j % 179 * k % 179;
          i = j;
          j = k;
          k = m;
          l = (53 * l + 1) % 169;
          if (l * m % 64 >= 32) {
            s += t;
            }
#line 86
          t *= 0.5;
        }
      randU[ii] = s;
    }

  randC = 362436.0 / 16777216.0;
  randCD = 7654321.0 / 16777216.0;
  randCM = 16777213.0 / 16777216.0;
  i97 = 97;
  j97 = 33;
  test = TRUE;
}

# 284 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
static inline void sim_noise_alarm()
#line 284
{
  dummy = 5;
}

# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
inline static tossim_header_t *getHeader(message_t *msg)
#line 50
{
  return (tossim_header_t *)(msg->data - sizeof(tossim_header_t ));
}

# 236 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$active_message_deliver_handle(sim_event_t *evt)
#line 236
{
  message_t *m = (message_t *)evt->data;

#line 238
  sim_log_debug(109U, "Packet", "Delivering packet to %i at %s\n", (int )sim_node(), sim_time_string());
  TossimActiveMessageC$Model$receive(m);
}

static inline sim_event_t *TossimActiveMessageC$allocate_deliver_event(int node, message_t *msg, sim_time_t t)
#line 242
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 244
  evt->mote = node;
  evt->time = t;
  evt->handle = TossimActiveMessageC$active_message_deliver_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 0;
  evt->data = msg;
  return evt;
}

#line 185
static inline uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void )
#line 185
{
  return 28;
}

# 88 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
static inline am_addr_t ActiveMessageAddressC$amAddress(void )
#line 88
{
  return ActiveMessageAddressC$ActiveMessageAddress$amAddress();
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
inline static am_addr_t TossimActiveMessageC$amAddress(void ){
#line 57
  unsigned short __nesc_result;
#line 57

#line 57
  __nesc_result = ActiveMessageAddressC$amAddress();
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
#line 136
static inline am_addr_t TossimActiveMessageC$AMPacket$address(void )
#line 136
{
  return TossimActiveMessageC$amAddress();
}

#line 160
static inline bool TossimActiveMessageC$AMPacket$isForMe(message_t *amsg)
#line 160
{
  return TossimActiveMessageC$AMPacket$destination(amsg) == TossimActiveMessageC$AMPacket$address() || 
  TossimActiveMessageC$AMPacket$destination(amsg) == AM_BROADCAST_ADDR;
}

# 310 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_ntoh_uint16(const void * source)
#line 310
{
  const uint8_t *base = source;

#line 312
  return ((uint16_t )base[0] << 8) | base[1];
}

static __inline  uint16_t __nesc_hton_uint16(void * target, uint16_t value)
#line 315
{
  uint8_t *base = target;

#line 317
  base[1] = value;
  base[0] = value >> 8;
  return value;
}

# 189 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void *TossimActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len)
#line 189
{
  if (len <= 28) {
      return msg->data;
    }
  else {
      return (void *)0;
    }
}

# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void * QueryPropagationC$Packet$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = TossimActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t QueryPropagationC$MeasurementScheduling$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(QueryPropagationC$MeasurementScheduling);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t QueryPropagationC$QueryScheduling$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(QueryPropagationC$QueryScheduling);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 508 "QueryPropagationC.nc"
static inline message_t *QueryPropagationC$RadioReceive$receive(message_t *msg, void *payload, uint8_t len)
#line 508
{
  unsigned short __nesc_temp43;
  unsigned char *__nesc_temp42;

#line 509
  if (len == sizeof(query_flooding_msg_t )) {
      QueryPropagationC$r_pkt[sim_node()] = (query_flooding_msg_t *)payload;


      QueryPropagationC$query_pos[sim_node()] = 0;
      while (QueryPropagationC$query_pos[sim_node()] < 5 && __nesc_ntoh_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$query_pos[sim_node()]].source_id.nxdata) != __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->source_id.nxdata)) {
          QueryPropagationC$query_pos[sim_node()]++;
        }

      if (QueryPropagationC$query_pos[sim_node()] == 5) {
          QueryPropagationC$next[sim_node()] = QueryPropagationC$next[sim_node()] % 5;
          __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$next[sim_node()]].source_id.nxdata, 0);
          __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$next[sim_node()]].sequence_number.nxdata, 0);
          __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$next[sim_node()]].source_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->source_id.nxdata));
          QueryPropagationC$query_pos[sim_node()] = QueryPropagationC$next[sim_node()];
        }

      if (QueryPropagationC$query_pos[sim_node()] < 5 && __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->sequence_number.nxdata) > __nesc_ntoh_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$query_pos[sim_node()]].sequence_number.nxdata)) {
          QueryPropagationC$next[sim_node()]++;
          __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$query_pos[sim_node()]].sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->sequence_number.nxdata));

          if (QueryPropagationC$number_Of_queries[sim_node()] < 3) {
              QueryPropagationC$number_Of_queries[sim_node()]++;

              sim_log_debug(201U, "ReceiveC", "NEW Radio Received QUERY_ID: %hu, SOURCE_ID: %hu, FORWARDER_ID: %hu ,@ %s \n\n", __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->sequence_number.nxdata), __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->source_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->forwarder_id.nxdata), sim_time_string());

              QueryPropagationC$query_pos[sim_node()] = 0;
              while (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata) == 1 && QueryPropagationC$query_pos[sim_node()] < 3) {
                  QueryPropagationC$query_pos[sim_node()]++;
                }

              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].source_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->source_id.nxdata));
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->sequence_number.nxdata));
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].forwarder_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->forwarder_id.nxdata));
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].hops.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->hops.nxdata) + 1);
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].sampling_period.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->sampling_period.nxdata));
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->query_lifetime.nxdata));
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].propagation_mode.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->propagation_mode.nxdata));
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata, 1);

              QueryPropagationC$sendQuery[sim_node()] = QueryPropagationC$query_pos[sim_node()];

              QueryPropagationC$QueryScheduling$postTask();

              QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$sendQuery[sim_node()]] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sampling_period.nxdata);

              QueryPropagationC$MeasurementScheduling$postTask();

              QueryPropagationC$save[sim_node()] = QueryPropagationC$save[sim_node()] % 30;
              QueryPropagationC$bcast_pkt[sim_node()] = (query_flooding_msg_t *)QueryPropagationC$Packet$getPayload(&QueryPropagationC$PacketBuffer[sim_node()][QueryPropagationC$save[sim_node()]], sizeof(query_flooding_msg_t ));
              if (QueryPropagationC$bcast_pkt[sim_node()] == (void *)0) {
                  return;
                }
              QueryPropagationC$save[sim_node()]++;

              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->source_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].source_id.nxdata));
              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sequence_number.nxdata));
              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->forwarder_id.nxdata, TOS_NODE_ID);
              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->hops.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].hops.nxdata));
              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->sampling_period.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sampling_period.nxdata));
              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->query_lifetime.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].query_lifetime.nxdata));
              __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->propagation_mode.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].propagation_mode.nxdata));
            }
        }
      else {
#line 573
        if (QueryPropagationC$query_pos[sim_node()] < 3 && __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->sequence_number.nxdata) == __nesc_ntoh_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$query_pos[sim_node()]].sequence_number.nxdata)) {

            (__nesc_temp42 = QueryPropagationC$r_pkt[sim_node()]->hops.nxdata, __nesc_hton_uint16(__nesc_temp42, (__nesc_temp43 = __nesc_ntoh_uint16(__nesc_temp42)) + 1), __nesc_temp43);
            QueryPropagationC$query_pos[sim_node()] = 0;
            while (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata) == 1 && QueryPropagationC$query_pos[sim_node()] < 3) {
                if (__nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->source_id.nxdata) == __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].source_id.nxdata) && __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->hops.nxdata) < __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].hops.nxdata)) {
                    __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].forwarder_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->forwarder_id.nxdata));
                    __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].hops.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_pkt[sim_node()]->hops.nxdata));
                  }
                QueryPropagationC$query_pos[sim_node()]++;
              }
          }
        }
    }
#line 586
  return msg;
}

# 281 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_ntoh_uint8(const void * source)
#line 281
{
  const uint8_t *base = source;

#line 283
  return base[0];
}

static __inline  uint8_t __nesc_hton_uint8(void * target, uint8_t value)
#line 286
{
  uint8_t *base = target;

#line 288
  base[0] = value;
  return value;
}

# 222 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void )
#line 222
{
  return /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get();
}

# 109 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow(void ){
#line 109
  unsigned int __nesc_result;
#line 109

#line 109
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow();
#line 109

#line 109
  return __nesc_result;
#line 109
}
#line 109
# 96 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void )
{
#line 97
  return /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow();
}

# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow();
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 159 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(), dt, TRUE);
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void QueryPropagationC$Timer4$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(4U, dt);
#line 73
}
#line 73
# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void * QueryPropagationC$SamplingAMPacket$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = TossimActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 457 "QueryPropagationC.nc"
static inline message_t *QueryPropagationC$SamplingRadioReceive$receive(message_t *msg, void *payload, uint8_t len)
#line 457
{
  if (len == sizeof(sampling_msg_t )) {
      QueryPropagationC$r_sampling_pkt[sim_node()] = (sampling_msg_t *)payload;

      sim_log_debug(198U, "ReceiveC", "Measurement_Sampling Message Received \n");
      sim_log_debug(199U, "ReceiveC", "SOURCE_ID: %hu, FORWARDER_ID: %hu, SAMPLING_ID: %hu  QUERY_ID: %hu \n", __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->source_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->forwarder_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->data_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->sequence_number.nxdata));
      sim_log_debug(200U, "ReceiveC", "Contributed Nodes: %hu \n", __nesc_ntoh_uint8(QueryPropagationC$r_sampling_pkt[sim_node()]->count_contributed_nodes.nxdata));

      if (__nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->destination_id.nxdata) != TOS_NODE_ID) {

          QueryPropagationC$sampling_save[sim_node()] = QueryPropagationC$sampling_save[sim_node()] % 30;
          QueryPropagationC$ucast_pkt[sim_node()] = (sampling_msg_t *)QueryPropagationC$SamplingAMPacket$getPayload(&QueryPropagationC$SamplingPacketBuffer[sim_node()][QueryPropagationC$sampling_save[sim_node()]], sizeof(sampling_msg_t ));
          if (QueryPropagationC$ucast_pkt[sim_node()] == (void *)0) {
              return;
            }
          QueryPropagationC$sampling_save[sim_node()]++;

          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->source_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->source_id.nxdata));
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->data_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->data_id.nxdata));
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->forwarder_id.nxdata, TOS_NODE_ID);
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->sensor_data.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->sensor_data.nxdata));
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->destination_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->destination_id.nxdata));
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->sequence_number.nxdata));
          __nesc_hton_uint8(QueryPropagationC$ucast_pkt[sim_node()]->count_contributed_nodes.nxdata, __nesc_ntoh_uint8(QueryPropagationC$r_sampling_pkt[sim_node()]->count_contributed_nodes.nxdata) + 1);

          QueryPropagationC$query_pos[sim_node()] = 0;
          while (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].source_id.nxdata) != __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->destination_id.nxdata) && __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].sequence_number.nxdata) != __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->sequence_number.nxdata) && QueryPropagationC$query_pos[sim_node()] < 3) {
              QueryPropagationC$query_pos[sim_node()]++;
            }
          if (QueryPropagationC$query_pos[sim_node()] < 3) {
              QueryPropagationC$sendTofather[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].forwarder_id.nxdata);
            }

          QueryPropagationC$Timer4$startOneShot(TOS_NODE_ID * 15);
        }
      else {
          QueryPropagationC$source_id[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->source_id.nxdata);
          QueryPropagationC$s_data_id[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->data_id.nxdata);
          QueryPropagationC$forwarder_id[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->forwarder_id.nxdata);
          QueryPropagationC$sensor_data[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->sensor_data.nxdata);
          QueryPropagationC$destination_id[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->destination_id.nxdata);
          QueryPropagationC$sequence_number[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$r_sampling_pkt[sim_node()]->sequence_number.nxdata);
          QueryPropagationC$count_contributed_nodes[sim_node()] = __nesc_ntoh_uint8(QueryPropagationC$r_sampling_pkt[sim_node()]->count_contributed_nodes.nxdata) + 1;

          QueryPropagationC$Timer2$startOneShot(20);
        }
    }
  return msg;
}

# 212 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 212
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC$Receive$receive(am_id_t arg_0x408fbac8, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x408fbac8) {
#line 78
    case 36:
#line 78
      __nesc_result = QueryPropagationC$SamplingRadioReceive$receive(msg, payload, len);
#line 78
      break;
#line 78
    case 45:
#line 78
      __nesc_result = QueryPropagationC$RadioReceive$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = TossimActiveMessageC$Receive$default$receive(arg_0x408fbac8, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 139 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline bool SimSchedulerBasicP$isWaiting(uint8_t id)
{
  return SimSchedulerBasicP$m_next[sim_node()][id] != SimSchedulerBasicP$NO_TASK || SimSchedulerBasicP$m_tail[sim_node()] == id;
}

static inline bool SimSchedulerBasicP$pushTask(uint8_t id)
{
  if (!SimSchedulerBasicP$isWaiting(id)) 
    {
      if (SimSchedulerBasicP$m_head[sim_node()] == SimSchedulerBasicP$NO_TASK) 
        {
          SimSchedulerBasicP$m_head[sim_node()] = id;
          SimSchedulerBasicP$m_tail[sim_node()] = id;
        }
      else 
        {
          SimSchedulerBasicP$m_next[sim_node()][SimSchedulerBasicP$m_tail[sim_node()]] = id;
          SimSchedulerBasicP$m_tail[sim_node()] = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

#line 69
static inline int SimSchedulerBasicP$sim_config_task_latency(void )
#line 69
{
#line 69
  return 100;
}

# 61 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP$SimMote$getStartTime(void )
#line 61
{
  return SimMoteP$startTime[sim_node()];
}

# 127 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline sim_time_t HplAtm128Timer0AsyncP$notify_clockTicksPerSec(void )
#line 127
{
  return ATM128_TIMER0_TICKSPPS;
}

#line 154
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t)
#line 154
{
  t *= HplAtm128Timer0AsyncP$notify_clockTicksPerSec();
  t /= sim_ticks_per_sec();
  return t;
}

# 53 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
inline static Atm128_TIFR_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag(void ){
#line 53
  union __nesc_unnamed4314 __nesc_result;
#line 53

#line 53
  __nesc_result = HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 216 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 216
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC$Snoop$receive(am_id_t arg_0x408f9178, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = TossimActiveMessageC$Snoop$default$receive(arg_0x408f9178, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 52 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim_serial_packet.c"
inline static serial_header_t *getSerialHeader(message_t *msg)
#line 52
{
  return (serial_header_t *)(msg->data - sizeof(serial_header_t ));
}

# 590 "QueryPropagationC.nc"
static inline message_t *QueryPropagationC$SerialReceive$receive(message_t *msg, void *payload, uint8_t len)
#line 590
{
  if (len == sizeof(query_msg_t )) {
      QueryPropagationC$s_pkt[sim_node()] = (query_msg_t *)payload;

      if (QueryPropagationC$number_Of_queries[sim_node()] < 3) {
          QueryPropagationC$number_Of_queries[sim_node()]++;
          QueryPropagationC$sequence_number[sim_node()]++;

          sim_log_debug(202U, "ReceiveC", "Serial Received QUERY_ID: %hu ,@ %s \n\n", QueryPropagationC$sequence_number[sim_node()], sim_time_string());

          QueryPropagationC$query_pos[sim_node()] = 0;
          while (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata) == 1 && QueryPropagationC$query_pos[sim_node()] < 3) {
              QueryPropagationC$query_pos[sim_node()]++;
            }

          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].source_id.nxdata, TOS_NODE_ID);
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].sequence_number.nxdata, QueryPropagationC$sequence_number[sim_node()]);
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].forwarder_id.nxdata, TOS_NODE_ID);
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].hops.nxdata, 0);
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].sampling_period.nxdata, __nesc_ntoh_uint16(QueryPropagationC$s_pkt[sim_node()]->sampling_period.nxdata));
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata, __nesc_ntoh_uint16(QueryPropagationC$s_pkt[sim_node()]->query_lifetime.nxdata));
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].propagation_mode.nxdata, __nesc_ntoh_uint16(QueryPropagationC$s_pkt[sim_node()]->propagation_mode.nxdata));
          __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata, 1);

          QueryPropagationC$sendQuery[sim_node()] = QueryPropagationC$query_pos[sim_node()];

          QueryPropagationC$QueryScheduling$postTask();

          QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$sendQuery[sim_node()]] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sampling_period.nxdata);

          sim_log_debug(203U, "ReceiveC", "The Sampling Period for query_id: %hu is T: %hu \n", __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sequence_number.nxdata), __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sampling_period.nxdata));

          QueryPropagationC$MeasurementScheduling$postTask();


          QueryPropagationC$save[sim_node()] = QueryPropagationC$save[sim_node()] % 30;
          QueryPropagationC$bcast_pkt[sim_node()] = (query_flooding_msg_t *)QueryPropagationC$Packet$getPayload(&QueryPropagationC$PacketBuffer[sim_node()][QueryPropagationC$save[sim_node()]], sizeof(query_flooding_msg_t ));
          if (QueryPropagationC$bcast_pkt[sim_node()] == (void *)0) {
              return;
            }
          QueryPropagationC$save[sim_node()]++;

          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->source_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].source_id.nxdata));
          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sequence_number.nxdata));
          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->forwarder_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].forwarder_id.nxdata));
          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->hops.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].hops.nxdata));
          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->sampling_period.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].sampling_period.nxdata));
          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->query_lifetime.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].query_lifetime.nxdata));
          __nesc_hton_uint16(QueryPropagationC$bcast_pkt[sim_node()]->propagation_mode.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].propagation_mode.nxdata));
        }
    }
  return msg;
}

# 252 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline message_t *SerialActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 252
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * SerialActiveMessageC$Receive$receive(am_id_t arg_0x40a0c548, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x40a0c548) {
#line 78
    case 6:
#line 78
      __nesc_result = QueryPropagationC$SerialReceive$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = SerialActiveMessageC$Receive$default$receive(arg_0x40a0c548, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 233 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline uint8_t SerialActiveMessageC$Packet$maxPayloadLength(void )
#line 233
{
  return 28;
}

#line 221
static inline void *SerialActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len)
#line 221
{
  if (len <= 28) {
      return msg->data;
    }
  else 
#line 224
    {
      return (void *)0;
    }
}

#line 139
static inline void SerialActiveMessageC$Model$receive(message_t *msg)
#line 139
{
  uint8_t len;
  void *payload;

  memcpy(SerialActiveMessageC$bufferPointer[sim_node()], msg, sizeof(message_t ));

  if (msg != (void *)0) {
      free(msg);
    }

  payload = SerialActiveMessageC$Packet$getPayload(SerialActiveMessageC$bufferPointer[sim_node()], SerialActiveMessageC$Packet$maxPayloadLength());
  len = SerialActiveMessageC$Packet$payloadLength(SerialActiveMessageC$bufferPointer[sim_node()]);

  sim_log_debug(151U, "Serial", "Received serial message (%p) of type %hhu and length %hhu @ %s.\n", SerialActiveMessageC$bufferPointer[sim_node()], SerialActiveMessageC$AMPacket$type(SerialActiveMessageC$bufferPointer[sim_node()]), len, sim_time_string());

  SerialActiveMessageC$bufferPointer[sim_node()] = SerialActiveMessageC$Receive$receive(SerialActiveMessageC$AMPacket$type(SerialActiveMessageC$bufferPointer[sim_node()]), 
  SerialActiveMessageC$bufferPointer[sim_node()], payload, len);
}

#line 272
static inline void SerialActiveMessageC$serial_active_message_deliver_handle(sim_event_t *evt)
#line 272
{
  message_t *m = (message_t *)evt->data;

#line 274
  SerialActiveMessageC$Model$receive(m);
}

#line 70
static inline serial_header_t *SerialActiveMessageC$getHeader(message_t *amsg)
#line 70
{
  return (serial_header_t *)(amsg->data - sizeof(serial_header_t ));
}

#line 277
static inline sim_event_t *SerialActiveMessageC$allocate_serial_deliver_event(int node, message_t *msg, sim_time_t t)
#line 277
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));
  message_t *newMsg = (message_t *)malloc(sizeof(message_t ));
  uint8_t payloadLength = __nesc_ntoh_uint8(((serial_header_t *)msg->header)->length.nxdata);

#line 281
  memcpy(SerialActiveMessageC$getHeader(newMsg), msg, sizeof(serial_header_t ) + payloadLength);

  evt->mote = node;
  evt->time = t;
  evt->handle = SerialActiveMessageC$serial_active_message_deliver_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 0;
  evt->data = newMsg;
  return evt;
}

# 89 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_disable_interrupt()
#line 89
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] &= ~(1 << 7);
}






#line 97
__inline  __nesc_atomic_t 
__nesc_atomic_start(void )
{
  __nesc_atomic_t result = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F];

#line 101
  __nesc_disable_interrupt();
  return result;
}



#line 106
__inline  void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F] = original_SREG;
}

# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP$sim_scheduler_event_handle(sim_event_t *e)
#line 85
{
  SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = FALSE;








  if (SimSchedulerBasicP$Scheduler$runNextTask()) {
      SimSchedulerBasicP$sim_scheduler_submit_event();
    }
}




static inline void SimSchedulerBasicP$sim_scheduler_event_init(sim_event_t *e)
#line 103
{
  e->mote = sim_node();
  e->force = 0;
  e->data = (void *)0;
  e->handle = SimSchedulerBasicP$sim_scheduler_event_handle;
  e->cleanup = sim_queue_cleanup_none;
}

#line 166
static inline void SimSchedulerBasicP$Scheduler$init(void )
{
  sim_log_debug(96U, "Scheduler", "Initializing scheduler.\n");
  /* atomic removed: atomic calls only */
  {
    memset(SimSchedulerBasicP$m_next[sim_node()], SimSchedulerBasicP$NO_TASK, sizeof SimSchedulerBasicP$m_next[sim_node()]);
    SimSchedulerBasicP$m_head[sim_node()] = SimSchedulerBasicP$NO_TASK;
    SimSchedulerBasicP$m_tail[sim_node()] = SimSchedulerBasicP$NO_TASK;

    SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = FALSE;
    SimSchedulerBasicP$sim_scheduler_event_init(&SimSchedulerBasicP$sim_scheduler_event[sim_node()]);
  }
}

# 57 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
inline static void SimMainP$Scheduler$init(void ){
#line 57
  SimSchedulerBasicP$Scheduler$init();
#line 57
}
#line 57
# 120 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline uint8_t SimSchedulerBasicP$popTask(void )
{
  if (SimSchedulerBasicP$m_head[sim_node()] != SimSchedulerBasicP$NO_TASK) 
    {
      uint8_t id = SimSchedulerBasicP$m_head[sim_node()];

#line 125
      SimSchedulerBasicP$m_head[sim_node()] = SimSchedulerBasicP$m_next[sim_node()][SimSchedulerBasicP$m_head[sim_node()]];
      if (SimSchedulerBasicP$m_head[sim_node()] == SimSchedulerBasicP$NO_TASK) 
        {
          SimSchedulerBasicP$m_tail[sim_node()] = SimSchedulerBasicP$NO_TASK;
        }
      SimSchedulerBasicP$m_next[sim_node()][id] = SimSchedulerBasicP$NO_TASK;
      return id;
    }
  else 
    {
      return SimSchedulerBasicP$NO_TASK;
    }
}

# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static error_t QueryPropagationC$RadioAMControl$start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = TossimPacketModelC$Control$start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 230 "QueryPropagationC.nc"
static inline void QueryPropagationC$RadioAMControl$startDone(error_t err)
#line 230
{
  if (err == SUCCESS) {
      sim_log_debug(191U, "RadioC", "RADIO_CONTROL = OK %s.\n", sim_time_string());
    }
  else {
      QueryPropagationC$RadioAMControl$start();
    }
}

# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC$Control$startDone(error_t error){
#line 113
  QueryPropagationC$RadioAMControl$startDone(error);
#line 113
}
#line 113
# 96 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$startDoneTask$runTask(void )
#line 96
{
  TossimPacketModelC$running[sim_node()] = TRUE;
  TossimPacketModelC$Control$startDone(SUCCESS);
}

# 239 "QueryPropagationC.nc"
static inline void QueryPropagationC$RadioAMControl$stopDone(error_t err)
#line 239
{
}

# 138 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC$Control$stopDone(error_t error){
#line 138
  QueryPropagationC$RadioAMControl$stopDone(error);
#line 138
}
#line 138
# 101 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$stopDoneTask$runTask(void )
#line 101
{
  TossimPacketModelC$running[sim_node()] = FALSE;
  TossimPacketModelC$Control$stopDone(SUCCESS);
}

# 303 "/usr/lib/ncc/nesc_nx.h"
static __inline  int8_t __nesc_hton_int8(void * target, int8_t value)
#line 303
{
#line 303
  __nesc_hton_uint8(target, value);
#line 303
  return value;
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void TossimActiveMessageC$AMSend$sendDone(am_id_t arg_0x408fb108, message_t * msg, error_t error){
#line 110
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(arg_0x408fb108, msg, error);
#line 110
}
#line 110
# 103 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t result)
#line 103
{
  TossimActiveMessageC$AMSend$sendDone(TossimActiveMessageC$AMPacket$type(msg), msg, result);
}

# 76 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC$Packet$sendDone(message_t *msg, error_t error){
#line 76
  TossimActiveMessageC$Model$sendDone(msg, error);
#line 76
}
#line 76
# 82 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline tossim_metadata_t *TossimPacketModelC$getMetadata(message_t *msg)
#line 82
{
  return (tossim_metadata_t *)& msg->metadata;
}

#line 145
static inline void TossimPacketModelC$sendDoneTask$runTask(void )
#line 145
{
  message_t *msg = TossimPacketModelC$sending[sim_node()];
  tossim_metadata_t *meta = TossimPacketModelC$getMetadata(msg);

#line 148
  __nesc_hton_uint8(meta->ack.nxdata, 0);
  __nesc_hton_int8(meta->strength.nxdata, 0);
  __nesc_hton_uint16(meta->time.nxdata, 0);
  TossimPacketModelC$sending[sim_node()] = FALSE;
  TossimPacketModelC$Packet$sendDone(msg, TossimPacketModelC$running[sim_node()] ? SUCCESS : EOFF);
}

# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t SerialActiveMessageC$startDone$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(SerialActiveMessageC$startDone);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 77 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline error_t SerialActiveMessageC$SplitControl$start(void )
#line 77
{
  SerialActiveMessageC$startDone$postTask();
  return SUCCESS;
}

# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static error_t QueryPropagationC$SerialAMControl$start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = SerialActiveMessageC$SplitControl$start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 242 "QueryPropagationC.nc"
static inline void QueryPropagationC$SerialAMControl$startDone(error_t err)
#line 242
{
  if (err == SUCCESS) {
      sim_log_debug(192U, "RadioC", "SERIAL_CONTROL = OK %s.\n", sim_time_string());
    }
  else {
      QueryPropagationC$SerialAMControl$start();
    }
}

# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static void SerialActiveMessageC$SplitControl$startDone(error_t error){
#line 113
  QueryPropagationC$SerialAMControl$startDone(error);
#line 113
}
#line 113
# 74 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline void SerialActiveMessageC$startDone$runTask(void )
#line 74
{
#line 74
  SerialActiveMessageC$SplitControl$startDone(SUCCESS);
}

# 251 "QueryPropagationC.nc"
static inline void QueryPropagationC$SerialAMControl$stopDone(error_t err)
#line 251
{
}

# 138 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static void SerialActiveMessageC$SplitControl$stopDone(error_t error){
#line 138
  QueryPropagationC$SerialAMControl$stopDone(error);
#line 138
}
#line 138
# 75 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline void SerialActiveMessageC$stopDone$runTask(void )
#line 75
{
#line 75
  SerialActiveMessageC$SplitControl$stopDone(SUCCESS);
}

# 189 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] >= 1) {
      return;
    }
  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()]].msg == msg) {
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$sendDone(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()], msg, err);
    }
  else {
      sim_log_debug(214U, "PointerBug", "%s received send done for %p, signaling for %p.\n", __FUNCTION__, msg, /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()]].msg);
    }
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void SerialActiveMessageC$AMSend$sendDone(am_id_t arg_0x40a0dae8, message_t * msg, error_t error){
#line 110
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$sendDone(arg_0x40a0dae8, msg, error);
#line 110
}
#line 110
# 115 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline void SerialActiveMessageC$Model$sendDone(message_t *msg, error_t result)
#line 115
{
  SerialActiveMessageC$AMSend$sendDone(SerialActiveMessageC$AMPacket$type(msg), msg, result);
}

static inline void SerialActiveMessageC$modelSendDone$runTask(void )
{
  SerialActiveMessageC$Model$sendDone(SerialActiveMessageC$sendMsgPtr[sim_node()], SUCCESS);
}

# 139 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow());
}

# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired();
#line 83
}
#line 83
# 226 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void )
#line 226
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 227
    {
      unsigned int __nesc_temp = 
#line 227
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()];

      {
#line 227
        __nesc_atomic_end(__nesc_atomic); 
#line 227
        return __nesc_temp;
      }
    }
#line 229
    __nesc_atomic_end(__nesc_atomic); }
}

# 116 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(void ){
#line 116
  unsigned int __nesc_result;
#line 116

#line 116
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm();
#line 116

#line 116
  return __nesc_result;
#line 116
}
#line 116
#line 103
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type dt){
#line 103
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(t0, dt);
#line 103
}
#line 103
# 58 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(uint32_t t0, uint32_t dt, bool oneshot)
{
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[sim_node()] = dt;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[sim_node()] = oneshot;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(t0, dt);
}










static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[sim_node()] == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[sim_node()], FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired();
}

#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt)
{
#line 94
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(t0, dt, TRUE);
}

# 129 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(t0, dt);
#line 129
}
#line 129
# 204 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void )
#line 204
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 205
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = FALSE;
#line 205
    __nesc_atomic_end(__nesc_atomic); }
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop(void ){
#line 73
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop();
#line 73
}
#line 73
# 71 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void )
{
#line 72
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop();
}

# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop();
#line 78
}
#line 78
# 100 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void )
{




  uint32_t now = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint16_t num;

  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop();

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;
          int32_t remaining = timer->dt - elapsed;

          if (remaining < min_remaining) 
            {
              min_remaining = remaining;
              min_remaining_isset = TRUE;
            }
        }
    }

  if (min_remaining_isset) 
    {
      if (min_remaining <= 0) {
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(now);
        }
      else {
#line 135
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(now, min_remaining);
        }
    }
}

#line 189
static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow();
}

# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static uint32_t QueryPropagationC$Timer1$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(1U);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
#line 73
inline static void QueryPropagationC$Timer5$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(5U, dt);
#line 73
}
#line 73
# 287 "QueryPropagationC.nc"
static inline void QueryPropagationC$Read$readDone(error_t result, uint16_t data)
#line 287
{
  if (result == SUCCESS) {

      QueryPropagationC$count_contributed_nodes[sim_node()] = 0;

      if (TOS_NODE_ID == __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].source_id.nxdata)) {

          QueryPropagationC$source_id[sim_node()] = TOS_NODE_ID;
          QueryPropagationC$s_data_id[sim_node()] = QueryPropagationC$data_id[sim_node()];
          QueryPropagationC$forwarder_id[sim_node()] = TOS_NODE_ID;
          QueryPropagationC$sensor_data[sim_node()] = data;
          QueryPropagationC$destination_id[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].source_id.nxdata);
          QueryPropagationC$sequence_number[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].sequence_number.nxdata);
          QueryPropagationC$count_contributed_nodes[sim_node()]++;

          QueryPropagationC$Timer2$startOneShot(20);
        }
      else {
          QueryPropagationC$sampling_save[sim_node()] = QueryPropagationC$sampling_save[sim_node()] % 30;
          QueryPropagationC$ucast_pkt[sim_node()] = (sampling_msg_t *)QueryPropagationC$SamplingAMPacket$getPayload(&QueryPropagationC$SamplingPacketBuffer[sim_node()][QueryPropagationC$sampling_save[sim_node()]], sizeof(sampling_msg_t ));
          if (QueryPropagationC$ucast_pkt[sim_node()] == (void *)0) {
              return;
            }
          QueryPropagationC$sampling_save[sim_node()]++;

          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->source_id.nxdata, TOS_NODE_ID);
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->data_id.nxdata, QueryPropagationC$data_id[sim_node()]);
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->forwarder_id.nxdata, TOS_NODE_ID);
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->sensor_data.nxdata, data);
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->destination_id.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].source_id.nxdata));
          __nesc_hton_uint16(QueryPropagationC$ucast_pkt[sim_node()]->sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].sequence_number.nxdata));
          __nesc_hton_uint8(QueryPropagationC$ucast_pkt[sim_node()]->count_contributed_nodes.nxdata, QueryPropagationC$count_contributed_nodes[sim_node()]++);

          QueryPropagationC$sendTofather[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].forwarder_id.nxdata);

          QueryPropagationC$Timer5$startOneShot(TOS_NODE_ID * 20);
        }

      QueryPropagationC$data_id[sim_node()]++;

      if (QueryPropagationC$number_Of_queries[sim_node()] > 0) {

          QueryPropagationC$expiredQuery[sim_node()] = QueryPropagationC$Hold_Sampling_Timer[sim_node()];
          QueryPropagationC$runningTime[sim_node()] = QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$expiredQuery[sim_node()]];

          sim_log_debug(194U, "ReceiveC", "Period: %hu \n", QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]]);
          QueryPropagationC$minPeriod[sim_node()] = 0;
          QueryPropagationC$start[sim_node()] = 0;
          while (QueryPropagationC$start[sim_node()] < 3) {

              if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$start[sim_node()]].state.nxdata) == 1) {
                  if (QueryPropagationC$start[sim_node()] == QueryPropagationC$expiredQuery[sim_node()]) {
                      QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$start[sim_node()]] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$start[sim_node()]].sampling_period.nxdata);
                    }
                  else {
                      QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$start[sim_node()]] = QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$start[sim_node()]] - QueryPropagationC$runningTime[sim_node()];
                    }

                  if (QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$start[sim_node()]] <= QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$minPeriod[sim_node()]] && QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$start[sim_node()]] != 0) {
                      QueryPropagationC$Hold_Sampling_Timer[sim_node()] = QueryPropagationC$start[sim_node()];
                    }
                }
              else {
                  QueryPropagationC$minPeriod[sim_node()]++;
                }
              QueryPropagationC$start[sim_node()]++;
            }

          if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].state.nxdata) != 0) {
              QueryPropagationC$Timer1$startOneShot(QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]]);
              QueryPropagationC$time4MeasurementStartAt[sim_node()] = QueryPropagationC$Timer1$getNow();
            }
        }
    }
}

# 63 "/opt/tinyos-2.1.2/tos/interfaces/Read.nc"
inline static void /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$readDone(error_t result, /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$val_t val){
#line 63
  QueryPropagationC$Read$readDone(result, val);
#line 63
}
#line 63
# 47 "/opt/tinyos-2.1.2/tos/system/ConstantSensorC.nc"
static inline void /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$runTask(void )
#line 47
{
  /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$readDone(SUCCESS, 48879U);
}

# 113 "QueryPropagationC.nc"
static inline void QueryPropagationC$init_StateMessages$runTask(void )
#line 113
{
  for (QueryPropagationC$start[sim_node()] = 0; QueryPropagationC$start[sim_node()] < 5; QueryPropagationC$start[sim_node()]++) {
      __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$start[sim_node()]].source_id.nxdata, 0);
      __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$start[sim_node()]].sequence_number.nxdata, 0);
    }
}

static inline void QueryPropagationC$init_ActiveQueryQ$runTask(void )
#line 120
{
  for (QueryPropagationC$start[sim_node()] = 0; QueryPropagationC$start[sim_node()] < 3; QueryPropagationC$start[sim_node()]++) {
      __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$start[sim_node()]].state.nxdata, 0);
    }
}

# 199 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getdt(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].dt;
}

# 151 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static uint32_t QueryPropagationC$Timer0$getdt(void ){
#line 151
  unsigned int __nesc_result;
#line 151

#line 151
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getdt(0U);
#line 151

#line 151
  return __nesc_result;
#line 151
}
#line 151
# 194 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$gett0(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].t0;
}

# 144 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static uint32_t QueryPropagationC$Timer0$gett0(void ){
#line 144
  unsigned int __nesc_result;
#line 144

#line 144
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$gett0(0U);
#line 144

#line 144
  return __nesc_result;
#line 144
}
#line 144
# 169 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].isrunning;
}

# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static bool QueryPropagationC$Timer0$isRunning(void ){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(0U);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline bool /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$get(void )
#line 54
{
#line 54
  return (atm128RegFile[sim_node()][27U] & (1 << 2)) != 0;
}

# 43 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static bool LedsP$Led0$get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 59 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$clr(void )
#line 59
{
#line 59
  atm128RegFile[sim_node()][27U] &= ~(1 << 2);
}

# 41 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led0$clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$clr();
#line 41
}
#line 41
# 74 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static inline void LedsP$Leds$led0On(void )
#line 74
{
  LedsP$Led0$clr();
  sim_log_debug(154U, "LedsC", "LEDS: Led""0"" %s.\n", LedsP$Led0$get() ? "off" : "on");
#line 76
  ;
}

# 56 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
inline static void QueryPropagationC$Leds$led0On(void ){
#line 56
  LedsP$Leds$led0On();
#line 56
}
#line 56
# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static bool QueryPropagationC$Timer3$isRunning(void ){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(3U);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
# 127 "QueryPropagationC.nc"
static inline void QueryPropagationC$QueryScheduling$runTask(void )
#line 127
{

  if (QueryPropagationC$Timer3$isRunning() == TRUE) {
      QueryPropagationC$checkTimer[sim_node()] = QueryPropagationC$Timer3$getNow();
      QueryPropagationC$runningTime[sim_node()] = QueryPropagationC$checkTimer[sim_node()] - QueryPropagationC$timerStartAt[sim_node()];
      QueryPropagationC$dt[sim_node()] = __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$HoldTimer[sim_node()]].query_lifetime.nxdata) - QueryPropagationC$runningTime[sim_node()];

      if (QueryPropagationC$dt[sim_node()] > __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$sendQuery[sim_node()]].query_lifetime.nxdata)) {
          QueryPropagationC$HoldTimer[sim_node()] = QueryPropagationC$sendQuery[sim_node()];
          QueryPropagationC$Timer3$startOneShot(__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$HoldTimer[sim_node()]].query_lifetime.nxdata));
          QueryPropagationC$timerStartAt[sim_node()] = QueryPropagationC$Timer3$getNow();
        }
      else {
          QueryPropagationC$timerStartAt[sim_node()] = QueryPropagationC$Timer3$getNow();
        }

      QueryPropagationC$query_pos[sim_node()] = 0;
      while (QueryPropagationC$query_pos[sim_node()] < 3) {
          if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata) == 1 && QueryPropagationC$query_pos[sim_node()] != QueryPropagationC$sendQuery[sim_node()]) {
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata) - QueryPropagationC$runningTime[sim_node()]);
            }
          QueryPropagationC$query_pos[sim_node()]++;
        }
    }
  else {
      QueryPropagationC$HoldTimer[sim_node()] = QueryPropagationC$sendQuery[sim_node()];
      QueryPropagationC$Timer3$startOneShot(__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$HoldTimer[sim_node()]].query_lifetime.nxdata));
      QueryPropagationC$timerStartAt[sim_node()] = QueryPropagationC$Timer3$getNow();
      QueryPropagationC$Leds$led0On();
    }


  if (QueryPropagationC$Timer0$isRunning() == TRUE) {
      QueryPropagationC$t0[sim_node()] = QueryPropagationC$Timer0$gett0();
      QueryPropagationC$dt[sim_node()] = QueryPropagationC$Timer0$getdt();
      QueryPropagationC$Timer0$startOneShot(QueryPropagationC$t0[sim_node()] + QueryPropagationC$dt[sim_node()]);
    }
  else {
      QueryPropagationC$Timer0$startOneShot(TOS_NODE_ID * 50);
    }
}

# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static bool QueryPropagationC$Timer1$isRunning(void ){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(1U);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
# 171 "QueryPropagationC.nc"
static inline void QueryPropagationC$MeasurementScheduling$runTask(void )
#line 171
{
  if (QueryPropagationC$Timer1$isRunning() == TRUE) {
      QueryPropagationC$checkTimer[sim_node()] = QueryPropagationC$Timer1$getNow();
      QueryPropagationC$runningTime[sim_node()] = QueryPropagationC$checkTimer[sim_node()] - QueryPropagationC$time4MeasurementStartAt[sim_node()];
      QueryPropagationC$dt[sim_node()] = QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]] - QueryPropagationC$runningTime[sim_node()];

      if (QueryPropagationC$dt[sim_node()] > QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$sendQuery[sim_node()]]) {
          QueryPropagationC$Hold_Sampling_Timer[sim_node()] = QueryPropagationC$sendQuery[sim_node()];
          QueryPropagationC$Timer1$startOneShot(QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]]);
          QueryPropagationC$time4MeasurementStartAt[sim_node()] = QueryPropagationC$Timer1$getNow();
        }
      else {
          QueryPropagationC$time4MeasurementStartAt[sim_node()] = QueryPropagationC$Timer1$getNow();
        }

      QueryPropagationC$query_pos[sim_node()] = 0;
      while (QueryPropagationC$query_pos[sim_node()] < 3) {
          if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata) == 1 && QueryPropagationC$query_pos[sim_node()] != QueryPropagationC$sendQuery[sim_node()]) {
              QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$query_pos[sim_node()]] = QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$query_pos[sim_node()]] - QueryPropagationC$runningTime[sim_node()];
            }
          QueryPropagationC$query_pos[sim_node()]++;
        }
    }
  else {


      QueryPropagationC$Hold_Sampling_Timer[sim_node()] = QueryPropagationC$sendQuery[sim_node()];
      sim_log_debug(190U, "ReceiveC", "TASK Sampling Period: %hu \n", QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]]);
      QueryPropagationC$Timer1$startOneShot(QueryPropagationC$TimeToMeasure[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]]);
      QueryPropagationC$time4MeasurementStartAt[sim_node()] = QueryPropagationC$Timer1$getNow();
    }
}

# 169 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void )
#line 169
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()], /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg, FAIL);
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  QueryPropagationC$RadioAMSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(m, err);
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  QueryPropagationC$SamplingRadioAMSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$sendDone(m, err);
}

# 215 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(uint8_t arg_0x40d098a8, message_t * msg, error_t error){
#line 100
  switch (arg_0x40d098a8) {
#line 100
    case 0U:
#line 100
      /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    case 1U:
#line 100
      /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(arg_0x40d098a8, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 126 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 2 / 8 + 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i] & mask) {
                  last = i * 8 + j;
                  msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg = (void *)0;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i] &= ~mask;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

#line 169
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$runTask(void )
#line 169
{
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$sendDone(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()], /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()]].msg, FAIL);
}

# 670 "QueryPropagationC.nc"
static inline void QueryPropagationC$SerialAMSend$sendDone(message_t *msg, error_t err)
#line 670
{
  if (&QueryPropagationC$serial_pkt[sim_node()] == msg) {
      QueryPropagationC$serial_busy[sim_node()] = FALSE;
      sim_log_debug(204U, "BroadcastingC", "Serial message Done\n\n");
    }
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  QueryPropagationC$SerialAMSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$sendDone(m, err);
}

# 215 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$default$sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$sendDone(uint8_t arg_0x40d098a8, message_t * msg, error_t error){
#line 100
  switch (arg_0x40d098a8) {
#line 100
    case 0U:
#line 100
      /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$default$sendDone(arg_0x40d098a8, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 126 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$CancelTask$runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 1 / 8 + 1; i++) {
      if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[sim_node()][i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[sim_node()][i] & mask) {
                  last = i * 8 + j;
                  msg = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][last].msg;
                  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][last].msg = (void *)0;
                  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[sim_node()][i] &= ~mask;
                  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

# 221 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP$TaskBasic$default$runTask(uint8_t id)
{
}

# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static void SimSchedulerBasicP$TaskBasic$runTask(uint8_t arg_0x40734970){
#line 75
  switch (arg_0x40734970) {
#line 75
    case TossimPacketModelC$startDoneTask:
#line 75
      TossimPacketModelC$startDoneTask$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$stopDoneTask:
#line 75
      TossimPacketModelC$stopDoneTask$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$sendDoneTask:
#line 75
      TossimPacketModelC$sendDoneTask$runTask();
#line 75
      break;
#line 75
    case SerialActiveMessageC$startDone:
#line 75
      SerialActiveMessageC$startDone$runTask();
#line 75
      break;
#line 75
    case SerialActiveMessageC$stopDone:
#line 75
      SerialActiveMessageC$stopDone$runTask();
#line 75
      break;
#line 75
    case SerialActiveMessageC$modelSendDone:
#line 75
      SerialActiveMessageC$modelSendDone$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired:
#line 75
      /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer:
#line 75
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask();
#line 75
      break;
#line 75
    case /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult:
#line 75
      /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$runTask();
#line 75
      break;
#line 75
    case QueryPropagationC$init_StateMessages:
#line 75
      QueryPropagationC$init_StateMessages$runTask();
#line 75
      break;
#line 75
    case QueryPropagationC$init_ActiveQueryQ:
#line 75
      QueryPropagationC$init_ActiveQueryQ$runTask();
#line 75
      break;
#line 75
    case QueryPropagationC$QueryScheduling:
#line 75
      QueryPropagationC$QueryScheduling$runTask();
#line 75
      break;
#line 75
    case QueryPropagationC$MeasurementScheduling:
#line 75
      QueryPropagationC$MeasurementScheduling$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask();
#line 75
      break;
#line 75
    case /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$CancelTask:
#line 75
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$CancelTask$runTask();
#line 75
      break;
#line 75
    case /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask:
#line 75
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SimSchedulerBasicP$TaskBasic$default$runTask(arg_0x40734970);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
#line 67
inline static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$send(am_id_t arg_0x40d082b0, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = SerialActiveMessageC$AMSend$send(arg_0x40d082b0, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Packet$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = SerialActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = SerialActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
#line 147
inline static am_id_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = SerialActiveMessageC$AMPacket$type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] = (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] + 1) % 1;
  for (i = 0; i < 1; i++) {
      if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()]].msg == (void *)0 || 
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[sim_node()][/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] / 8] & (1 << /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] % 8)) 
        {
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] = (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] + 1) % 1;
        }
      else {
          break;
        }
    }
  if (i >= 1) {
#line 78
    /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] = 1;
    }
}

#line 174
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$tryToSend(void )
#line 174
{
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$nextPacket();
  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] < 1) {
      error_t nextErr;
      message_t *nextMsg = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()]].msg;
      am_id_t nextId = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$type(nextMsg);
      am_addr_t nextDest = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$destination(nextMsg);
      uint8_t len = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Packet$payloadLength(nextMsg);

#line 182
      nextErr = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$errorTask$postTask();
        }
    }
}

# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t SerialActiveMessageC$modelSendDone$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(SerialActiveMessageC$modelSendDone);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 124 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline error_t SerialActiveMessageC$Model$default$send(int node, message_t *msg, uint8_t len)
#line 124
{

  SerialActiveMessageC$sendMsgPtr[sim_node()] = msg;

  sim_log_debug(150U, "Serial", "Sending serial message (%p) of type %hhu and length %hhu @ %s.\n", msg, SerialActiveMessageC$AMPacket$type(msg), len, sim_time_string());

  sim_sf_dispatch_packet((void *)msg, len);

  SerialActiveMessageC$modelSendDone$postTask();

  return SUCCESS;
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static error_t SerialActiveMessageC$Model$send(int node, message_t *msg, uint8_t len){
#line 57
  unsigned char __nesc_result;
#line 57

#line 57
  __nesc_result = SerialActiveMessageC$Model$default$send(node, msg, len);
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline bool /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$get(void )
#line 54
{
#line 54
  return (atm128RegFile[sim_node()][27U] & (1 << 0)) != 0;
}

# 43 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static bool LedsP$Led2$get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(am_id_t arg_0x40d082b0, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = TossimActiveMessageC$AMSend$send(arg_0x40d082b0, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline tossim_header_t *TossimActiveMessageC$getHeader(message_t *amsg)
#line 65
{
  return (tossim_header_t *)(amsg->data - sizeof(tossim_header_t ));
}

#line 177
static inline uint8_t TossimActiveMessageC$Packet$payloadLength(message_t *msg)
#line 177
{
  return __nesc_ntoh_uint8(TossimActiveMessageC$getHeader(msg)->length.nxdata);
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
#line 147
inline static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = TossimActiveMessageC$AMPacket$type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] + 1) % 2;
  for (i = 0; i < 2; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg == (void *)0 || 
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] / 8] & (1 << /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] % 8)) 
        {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] + 1) % 2;
        }
      else {
          break;
        }
    }
  if (i >= 2) {
#line 78
    /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = 2;
    }
}

#line 174
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void )
#line 174
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] < 2) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(nextMsg);

#line 182
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask();
        }
    }
}

# 483 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg)
#line 483
{
  free(msg);
}

# 61 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static bool CpmModelC$Model$shouldAck(message_t *msg){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = TossimPacketModelC$GainRadioModel$shouldAck(msg);
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC$Packet$receive(message_t *msg){
#line 85
  TossimActiveMessageC$Model$receive(msg);
#line 85
}
#line 85
# 288 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$GainRadioModel$receive(message_t *msg)
#line 288
{
  if (TossimPacketModelC$running[sim_node()] && !TossimPacketModelC$transmitting[sim_node()]) {
      TossimPacketModelC$Packet$receive(msg);
    }
}

# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC$Model$receive(message_t *msg){
#line 60
  TossimPacketModelC$GainRadioModel$receive(msg);
#line 60
}
#line 60
# 260 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg)
#line 260
{
  double noise = CpmModelC$noise_hash_generation();
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

#line 263
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  return CpmModelC$shouldReceive(msg->power - noise);
}

#line 296
static inline void CpmModelC$sim_gain_receive_handle(sim_event_t *evt)
#line 296
{
  CpmModelC$receive_message_t *mine = (CpmModelC$receive_message_t *)evt->data;
  CpmModelC$receive_message_t *predecessor = (void *)0;
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

  sim_log_debug(129U, "CpmModelC", "Handling reception event @ %s.\n", sim_time_string());
  while (list != (void *)0) {
      if (list->next == mine) {
          predecessor = list;
        }
      list = list->next;
    }
  if (predecessor) {
      predecessor->next = mine->next;
    }
  else {
#line 311
    if (mine == CpmModelC$outstandingReceptionHead[sim_node()]) {
        CpmModelC$outstandingReceptionHead[sim_node()] = mine->next;
      }
    else {
        sim_log_error(130U, "CpmModelC", "Incoming packet list structure is corrupted: entry is not the head and no entry points to it.\n");
      }
    }
#line 317
  sim_log_debug(131U, "CpmModelC,SNRLoss", "Packet from %i to %i\n", (int )mine->source, (int )sim_node());
  if (!CpmModelC$checkReceive(mine)) {
      sim_log_debug(132U, "CpmModelC,SNRLoss", " - lost packet from %i as SNR was too low.\n", (int )mine->source);
      mine->lost = 1;
    }
  if (! mine->lost) {



      tossim_metadata_t *meta = (tossim_metadata_t *)& mine->msg->metadata;

#line 327
      __nesc_hton_int8(meta->strength.nxdata, mine->strength);

      sim_log_debug_clear(133U, "CpmModelC,SNRLoss", "  -signaling reception\n");
      CpmModelC$Model$receive(mine->msg);
      if (mine->ack) {
          sim_log_debug_clear(134U, "CpmModelC", " acknowledgment requested, ");
        }
      else {
          sim_log_debug_clear(135U, "CpmModelC", " no acknowledgment requested.\n");
        }

      if (mine->ack && CpmModelC$Model$shouldAck(mine->msg)) {
          sim_log_debug_clear(136U, "CpmModelC", " scheduling ack.\n");
          CpmModelC$sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
        }
      else {
          CpmModelC$free_receive_message(mine);
        }

      CpmModelC$receiving[sim_node()] = 0;
    }
  else {
      if (RandomUniform() < 0.001) {
          sim_log_debug(137U, "CpmModelC,SNRLoss", "Packet was technically lost, but TOSSIM introduces an ack false positive rate.\n");
          if (mine->ack && CpmModelC$Model$shouldAck(mine->msg)) {
              sim_log_debug_clear(138U, "CpmModelC", " scheduling ack.\n");
              CpmModelC$sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
            }
          else {
              CpmModelC$free_receive_message(mine);
            }
        }
      else {
          CpmModelC$free_receive_message(mine);
        }
      CpmModelC$receiving[sim_node()] = 0;
      sim_log_debug_clear(139U, "CpmModelC,SNRLoss", "  -packet was lost.\n");
    }
}

#line 467
static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t endTime, CpmModelC$receive_message_t *msg)
#line 467
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 469
  evt->mote = sim_node();
  evt->time = endTime;
  evt->handle = CpmModelC$sim_gain_receive_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 1;
  evt->data = msg;
  return evt;
}

static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void )
#line 479
{
  return (CpmModelC$receive_message_t *)malloc(sizeof(CpmModelC$receive_message_t ));
}

#line 369
static inline void CpmModelC$enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower)
#line 369
{
  sim_event_t *evt;
  CpmModelC$receive_message_t *list;
  CpmModelC$receive_message_t *rcv = CpmModelC$allocate_receive_message();
  double noiseStr = CpmModelC$packetNoise(rcv);

#line 374
  rcv->source = source;
  rcv->start = sim_time();
  rcv->end = endTime;
  rcv->power = power;
  rcv->reversePower = reversePower;




  rcv->strength = (int8_t )floor(10.0 * log(pow(10.0, power / 10.0) + pow(10.0, noiseStr / 10.0)) / log(10.0));
  rcv->msg = msg;
  rcv->lost = 0;
  rcv->ack = receive;





  if (!sim_mote_is_on(sim_node())) {
      sim_log_debug(140U, "CpmModelC", "Lost packet from %i due to %i being off\n", source, sim_node());
      rcv->lost = 1;
    }
  else {
#line 396
    if (!CpmModelC$shouldReceive(power - noiseStr)) {
        sim_log_debug(141U, "CpmModelC,SNRLoss", "Lost packet from %i to %i due to SNR being too low (%i)\n", source, sim_node(), (int )(power - noiseStr));
        rcv->lost = 1;
      }
    else {
#line 400
      if (CpmModelC$receiving[sim_node()]) {
          sim_log_debug(142U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-reception\n", source, sim_node());
          rcv->lost = 1;
        }
      else {
#line 404
        if (CpmModelC$transmitting[sim_node()] && rcv->start < CpmModelC$transmissionEndTime[sim_node()] && CpmModelC$transmissionEndTime[sim_node()] <= rcv->end) {
            sim_log_debug(143U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-transmission, transmissionEndTime %llu\n", source, sim_node(), CpmModelC$transmissionEndTime[sim_node()]);
            rcv->lost = 1;
          }
        else {
            CpmModelC$receiving[sim_node()] = 1;
          }
        }
      }
    }
#line 412
  list = CpmModelC$outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      if (!CpmModelC$shouldReceive(list->power - rcv->power)) {
          sim_log_debug(144U, "Gain,SNRLoss", "Going to lose packet from %i with signal %lf as am receiving a packet from %i with signal %lf\n", list->source, list->power, source, rcv->power);
          list->lost = 1;
        }
      list = list->next;
    }

  rcv->next = CpmModelC$outstandingReceptionHead[sim_node()];
  CpmModelC$outstandingReceptionHead[sim_node()] = rcv;
  evt = CpmModelC$allocate_receive_event(endTime, rcv);
  sim_queue_insert(evt);
}


static inline void CpmModelC$sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower)
#line 428
{
  int prevNode = sim_node();

#line 430
  sim_log_debug(145U, "CpmModelC", "Enqueing reception event for %i at %llu with power %lf.\n", dest, endTime, power);
  sim_set_node(dest);
  CpmModelC$enqueue_receive_event(prevNode, endTime, msg, receive, power, reversePower);
  sim_set_node(prevNode);
}

static inline void CpmModelC$Model$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower)
#line 436
{
  CpmModelC$receive_message_t *list;
  gain_entry_t *neighborEntry = sim_gain_first(sim_node());

#line 439
  CpmModelC$requestAck[sim_node()] = ack;
  CpmModelC$outgoing[sim_node()] = msg;
  CpmModelC$transmissionEndTime[sim_node()] = endTime;
  sim_log_debug(146U, "CpmModelC", "Node %i transmitting to %i, finishes at %llu.\n", sim_node(), dest, endTime);

  while (neighborEntry != (void *)0) {
      int other = neighborEntry->mote;

#line 446
      CpmModelC$sim_gain_put(other, msg, endTime, ack, power + sim_gain_value(sim_node(), other), reversePower + sim_gain_value(other, sim_node()));
      neighborEntry = sim_gain_next(neighborEntry);
    }

  list = CpmModelC$outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      list->lost = 1;
      sim_log_debug(147U, "CpmModelC,SNRLoss", "Lost packet from %i because %i has outstanding reception, startTime %llu endTime %llu\n", list->source, sim_node(), list->start, list->end);
      list = list->next;
    }
}

# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC$GainRadioModel$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double gain, double reverseGain){
#line 48
  CpmModelC$Model$putOnAirTo(dest, msg, ack, endTime, gain, reverseGain);
#line 48
}
#line 48
# 280 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt)
#line 280
{
  message_t *rval = TossimPacketModelC$sending[sim_node()];

#line 282
  TossimPacketModelC$sending[sim_node()] = (void *)0;
  TossimPacketModelC$transmitting[sim_node()] = FALSE;
  sim_log_debug(121U, "TossimPacketModelC", "PACKET: Signaling send done at %llu.\n", sim_time());
  TossimPacketModelC$Packet$sendDone(rval, TossimPacketModelC$running[sim_node()] ? SUCCESS : EOFF);
}

#line 253
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt)
#line 253
{
  sim_time_t duration;
  tossim_metadata_t *metadata = TossimPacketModelC$getMetadata(TossimPacketModelC$sending[sim_node()]);

  duration = 8 * TossimPacketModelC$sendingLength[sim_node()];
  duration /= sim_csma_bits_per_symbol();
  duration += sim_csma_preamble_length();

  if (__nesc_ntoh_uint8(metadata->ack.nxdata)) {
      duration += sim_csma_ack_time();
    }
  duration *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();

  evt->time += duration;
  evt->handle = TossimPacketModelC$send_transmit_done;

  sim_log_debug(119U, "TossimPacketModelC", "PACKET: Broadcasting packet to everyone.\n");
  TossimPacketModelC$GainRadioModel$putOnAirTo(TossimPacketModelC$destNode[sim_node()], TossimPacketModelC$sending[sim_node()], __nesc_ntoh_uint8(metadata->ack.nxdata), evt->time, 0.0, 0.0);
  __nesc_hton_uint8(metadata->ack.nxdata, 0);

  evt->time += sim_csma_rxtx_delay() * (sim_ticks_per_sec() / sim_csma_symbols_per_sec());

  sim_log_debug(120U, "TossimPacketModelC", "PACKET: Send done at %llu.\n", evt->time);

  sim_queue_insert(evt);
}

# 459 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC$Model$setPendingTransmission(void )
#line 459
{
  CpmModelC$transmitting[sim_node()] = TRUE;
  sim_log_debug(148U, "CpmModelC", "setPendingTransmission: transmitting %i @ %s\n", CpmModelC$transmitting[sim_node()], sim_time_string());
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC$GainRadioModel$setPendingTransmission(void ){
#line 57
  CpmModelC$Model$setPendingTransmission();
#line 57
}
#line 57
# 211 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC$Model$clearChannel(void )
#line 211
{
  sim_log_debug(127U, "CpmModelC", "Checking clear channel @ %s: %f <= %f \n", sim_time_string(), (double )CpmModelC$packetNoise((void *)0), CpmModelC$clearThreshold[sim_node()]);
  return CpmModelC$packetNoise((void *)0) < CpmModelC$clearThreshold[sim_node()];
}

# 56 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static bool TossimPacketModelC$GainRadioModel$clearChannel(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = CpmModelC$Model$clearChannel();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 211 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt)
#line 211
{
  TossimPacketModelC$backoffCount[sim_node()]++;
  if (TossimPacketModelC$GainRadioModel$clearChannel()) {
      TossimPacketModelC$neededFreeSamples[sim_node()]--;
    }
  else {
      TossimPacketModelC$neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
    }
  if (TossimPacketModelC$neededFreeSamples[sim_node()] == 0) {
      sim_time_t delay;

#line 221
      delay = sim_csma_rxtx_delay();
      delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
      evt->time += delay;
      TossimPacketModelC$transmitting[sim_node()] = TRUE;
      TossimPacketModelC$GainRadioModel$setPendingTransmission();
      evt->handle = TossimPacketModelC$send_transmit;
      sim_queue_insert(evt);
    }
  else {
#line 229
    if (sim_csma_max_iterations() == 0 || 
    TossimPacketModelC$backoffCount[sim_node()] <= sim_csma_max_iterations()) {
        sim_time_t backoff = sim_random();
        sim_time_t modulo = sim_csma_high() - sim_csma_low();

#line 233
        modulo *= pow(sim_csma_exponent_base(), TossimPacketModelC$backoffCount[sim_node()]);
        backoff %= modulo;

        backoff += sim_csma_init_low();
        backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
        evt->time += backoff;
        sim_queue_insert(evt);
      }
    else {
        message_t *rval = TossimPacketModelC$sending[sim_node()];

#line 243
        TossimPacketModelC$sending[sim_node()] = (void *)0;
        sim_log_debug(118U, "TossimPacketModelC", "PACKET: Failed to send packet due to busy channel.\n");
        TossimPacketModelC$Packet$sendDone(rval, EBUSY);
      }
    }
}

#line 187
static inline void TossimPacketModelC$start_csma(void )
#line 187
{
  sim_time_t first_sample;




  sim_time_t backoff = sim_random();

#line 194
  backoff %= sim_csma_init_high() - sim_csma_init_low();
  backoff += sim_csma_init_low();
  backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  sim_log_debug(117U, "TossimPacketModelC", "Starting CMSA with %lli.\n", backoff);
  first_sample = sim_time() + backoff;

  TossimPacketModelC$sendEvent[sim_node()].mote = sim_node();
  TossimPacketModelC$sendEvent[sim_node()].time = first_sample;
  TossimPacketModelC$sendEvent[sim_node()].force = 0;
  TossimPacketModelC$sendEvent[sim_node()].cancelled = 0;

  TossimPacketModelC$sendEvent[sim_node()].handle = TossimPacketModelC$send_backoff;
  TossimPacketModelC$sendEvent[sim_node()].cleanup = sim_queue_cleanup_none;
  sim_queue_insert(&TossimPacketModelC$sendEvent[sim_node()]);
}

#line 161
static inline error_t TossimPacketModelC$Packet$send(int dest, message_t *msg, uint8_t len)
#line 161
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(115U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not initialized!\n");
      return EOFF;
    }
  if (!TossimPacketModelC$running[sim_node()]) {
      sim_log_error(116U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not running!\n");
      return EOFF;
    }

  if (TossimPacketModelC$sending[sim_node()] != (void *)0) {
      return EBUSY;
    }
  TossimPacketModelC$sendingLength[sim_node()] = len;
  TossimPacketModelC$sending[sim_node()] = msg;
  TossimPacketModelC$destNode[sim_node()] = dest;
  TossimPacketModelC$backoffCount[sim_node()] = 0;
  TossimPacketModelC$neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
  TossimPacketModelC$start_csma();
  return SUCCESS;
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static error_t TossimActiveMessageC$Model$send(int node, message_t *msg, uint8_t len){
#line 57
  unsigned char __nesc_result;
#line 57

#line 57
  __nesc_result = TossimPacketModelC$Packet$send(node, msg, len);
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
# 90 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$timeInMs(void )
#line 90
{
  sim_time_t ftime = sim_time();
  int hours;
#line 92
  int minutes;
#line 92
  int seconds;
  sim_time_t secondBillionths;
  int temp_time;
  double ms_time;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }
  temp_time = (int )(secondBillionths / 10000);

  if (temp_time % 10 >= 5) {
      temp_time += 10 - temp_time % 10;
    }
  else {
      temp_time -= temp_time % 10;
    }
  ms_time = (float )(temp_time / 100.0);

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;

  ms_time += (hours * 3600 + minutes * 60 + seconds) * 1000;

  return ms_time;
}

#line 230
static inline double CpmModelC$prr_estimate_from_snr(double SNR)
#line 230
{



  double beta1 = 0.9794;
  double beta2 = 2.3851;
  double X = SNR - beta2;
  double PSE = 0.5 * erfc(beta1 * X / sqrt(2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 239
  sim_log_debug(128U, "CpmModelC,SNR", "SNR is %lf, PRR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1.1;
    }
  else {
#line 242
    if (prr_hat < 0) {
      prr_hat = -0.1;
      }
    }
#line 245
  return prr_hat;
}

# 127 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline bool TossimActiveMessageC$Model$shouldAck(message_t *msg)
#line 127
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(msg);

#line 129
  if (__nesc_ntoh_uint16(header->dest.nxdata) == TossimActiveMessageC$amAddress()) {
      sim_log_debug(108U, "Acks", "Received packet addressed to me so ack it\n");
      return TRUE;
    }
  return FALSE;
}

# 87 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static bool TossimPacketModelC$Packet$shouldAck(message_t *msg){
#line 87
  unsigned char __nesc_result;
#line 87

#line 87
  __nesc_result = TossimActiveMessageC$Model$shouldAck(msg);
#line 87

#line 87
  return __nesc_result;
#line 87
}
#line 87
# 296 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$GainRadioModel$acked(message_t *msg)
#line 296
{
  if (TossimPacketModelC$running[sim_node()]) {
      tossim_metadata_t *metadata = TossimPacketModelC$getMetadata(TossimPacketModelC$sending[sim_node()]);

#line 299
      __nesc_hton_uint8(metadata->ack.nxdata, 1);
      if (msg != TossimPacketModelC$sending[sim_node()]) {
          TossimPacketModelC$error[sim_node()] = 1;
          sim_log_debug(122U, "TossimPacketModelC", "Requested ack for 0x%x, but outgoing packet is 0x%x.\n", msg, TossimPacketModelC$sending[sim_node()]);
        }
    }
}

# 59 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC$Model$acked(message_t *msg){
#line 59
  TossimPacketModelC$GainRadioModel$acked(msg);
#line 59
}
#line 59
# 151 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$arr_estimate_from_snr(double SNR)
#line 151
{
  double beta1 = 0.9794;
  double beta2 = 2.3851;
  double X = SNR - beta2;
  double PSE = 0.5 * erfc(beta1 * X / sqrt(2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 157
  sim_log_debug(125U, "CpmModelC,SNRLoss", "SNR is %lf, ARR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1.1;
    }
  else {
#line 160
    if (prr_hat < 0) {
      prr_hat = -0.1;
      }
    }
#line 163
  return prr_hat;
}

static inline int CpmModelC$shouldAckReceive(double snr)
#line 166
{
  double prr = CpmModelC$arr_estimate_from_snr(snr);
  double coin = RandomUniform();

#line 169
  if (prr >= 0 && prr <= 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 173
        prr = 0.0;
        }
    }
#line 175
  return (int )prr;
}

static inline void CpmModelC$sim_gain_ack_handle(sim_event_t *evt)
#line 178
{






  if (
#line 184
  CpmModelC$requestAck[sim_node()] && 
  CpmModelC$outgoing[sim_node()] != (void *)0 && 
  sim_mote_is_on(sim_node())) {
      CpmModelC$receive_message_t *rcv = (CpmModelC$receive_message_t *)evt->data;
      double power = rcv->reversePower;
      double noise = CpmModelC$packetNoise(rcv);
      double snr = power - noise;

#line 191
      if (CpmModelC$shouldAckReceive(snr)) {
          CpmModelC$Model$acked(CpmModelC$outgoing[sim_node()]);
        }
    }
  CpmModelC$free_receive_message((CpmModelC$receive_message_t *)evt->data);
}

# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline bool /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$get(void )
#line 54
{
#line 54
  return (atm128RegFile[sim_node()][27U] & (1 << 1)) != 0;
}

# 43 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static bool LedsP$Led1$get(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$get();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 59 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$clr(void )
#line 59
{
#line 59
  atm128RegFile[sim_node()][27U] &= ~(1 << 1);
}

# 41 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led1$clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$clr();
#line 41
}
#line 41
# 89 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static inline void LedsP$Leds$led1On(void )
#line 89
{
  LedsP$Led1$clr();
  sim_log_debug(157U, "LedsC", "LEDS: Led""1"" %s.\n", LedsP$Led1$get() ? "off" : "on");
#line 91
  ;
}

# 72 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
inline static void QueryPropagationC$Leds$led1On(void ){
#line 72
  LedsP$Leds$led1On();
#line 72
}
#line 72
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static error_t /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 162 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  TossimActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
#line 103
inline static void /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  TossimActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(msg, dest);
  /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(msg, 45);
  return /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(msg, len);
}

# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t QueryPropagationC$RadioAMSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*QueryPropagationAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 254 "QueryPropagationC.nc"
static inline void QueryPropagationC$Timer0$fired(void )
#line 254
{
  sim_log_debug(193U, "BroadcastingC", "BROADCASTING QUERY_ID: %hu ,@ %s.\n", __nesc_ntoh_uint16(QueryPropagationC$bcast_pkt[sim_node()]->sequence_number.nxdata), sim_time_string());


  if (TOS_NODE_ID == __nesc_ntoh_uint16(QueryPropagationC$bcast_pkt[sim_node()]->source_id.nxdata)) {
      QueryPropagationC$next[sim_node()] = QueryPropagationC$next[sim_node()] % 5;
      __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$next[sim_node()]].source_id.nxdata, TOS_NODE_ID);
      __nesc_hton_uint16(QueryPropagationC$QuerySendersHistory[sim_node()][QueryPropagationC$next[sim_node()]].sequence_number.nxdata, __nesc_ntoh_uint16(QueryPropagationC$bcast_pkt[sim_node()]->sequence_number.nxdata));
      QueryPropagationC$next[sim_node()]++;
    }

  if (!QueryPropagationC$busy[sim_node()]) {
      memcpy(&QueryPropagationC$pkt[sim_node()], &QueryPropagationC$PacketBuffer[sim_node()][QueryPropagationC$send[sim_node()]], sizeof(message_t ));

      if (QueryPropagationC$RadioAMSend$send(AM_BROADCAST_ADDR, &QueryPropagationC$pkt[sim_node()], sizeof(query_flooding_msg_t )) == SUCCESS) {
          QueryPropagationC$busy[sim_node()] = TRUE;
          QueryPropagationC$Leds$led1On();
        }
    }
}

# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 51 "/opt/tinyos-2.1.2/tos/system/ConstantSensorC.nc"
static inline error_t /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$read(void )
#line 51
{
  return /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$senseResult$postTask();
}

# 55 "/opt/tinyos-2.1.2/tos/interfaces/Read.nc"
inline static error_t QueryPropagationC$Read$read(void ){
#line 55
  unsigned char __nesc_result;
#line 55

#line 55
  __nesc_result = /*QueryPropagationAppC.Sensor.ConstantSensorC*/ConstantSensorC$0$Read$read();
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 164 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(uint8_t num)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].isrunning = FALSE;
}

# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void QueryPropagationC$Timer1$stop(void ){
#line 78
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(1U);
#line 78
}
#line 78
# 276 "QueryPropagationC.nc"
static inline void QueryPropagationC$Timer1$fired(void )
#line 276
{

  if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$Hold_Sampling_Timer[sim_node()]].state.nxdata) == 0) {
      QueryPropagationC$Timer1$stop();
    }
  else {
      QueryPropagationC$Read$read();
    }
}

# 229 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline void SerialActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len)
#line 229
{
  __nesc_hton_uint8(SerialActiveMessageC$getHeader(msg)->length.nxdata, len);
}

# 94 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Packet$setPayloadLength(message_t * msg, uint8_t len){
#line 94
  SerialActiveMessageC$Packet$setPayloadLength(msg, len);
#line 94
}
#line 94
# 90 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 1) {
      return FAIL;
    }
  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][clientId].msg != (void *)0) {
      return EBUSY;
    }
  sim_log_debug(210U, "AMQueue", "AMQueue: request to send from %hhu (%p): passed checks\n", clientId, msg);

  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][clientId].msg = msg;
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Packet$setPayloadLength(msg, len);

  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] >= 1) {
      error_t err;
      am_id_t amId = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$type(msg);
      am_addr_t dest = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMPacket$destination(msg);

      sim_log_debug(211U, "AMQueue", "%s: request to send from %hhu (%p): queue empty\n", __FUNCTION__, clientId, msg);
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] = clientId;

      err = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$AMSend$send(amId, dest, msg, len);
      if (err != SUCCESS) {
          sim_log_debug(212U, "AMQueue", "%s: underlying send failed.\n", __FUNCTION__);
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[sim_node()] = 1;
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][clientId].msg = (void *)0;
        }

      return err;
    }
  else {
      sim_log_debug(213U, "AMQueue", "AMQueue: request to send from %hhu (%p): queue not empty\n", clientId, msg);
    }
  return SUCCESS;
}

# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static error_t /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 201 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline void SerialActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t)
#line 201
{
  serial_header_t *header = SerialActiveMessageC$getHeader(amsg);

#line 203
  __nesc_hton_uint8(header->type.nxdata, t);
}

# 162 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  SerialActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
# 176 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static inline void SerialActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr)
#line 176
{
  serial_header_t *header = SerialActiveMessageC$getHeader(amsg);

#line 178
  __nesc_hton_uint16(header->dest.nxdata, addr);
}

# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static void /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  SerialActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMPacket$setDestination(msg, dest);
  /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMPacket$setType(msg, 6);
  return /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$Send$send(msg, len);
}

# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t QueryPropagationC$SerialAMSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*QueryPropagationAppC.SerialAMSenderC.AMQueueEntryP*/AMQueueEntryP$2$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void * QueryPropagationC$SerialPacket$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = SerialActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 364 "QueryPropagationC.nc"
static inline void QueryPropagationC$Timer2$fired(void )
#line 364
{
  if (!QueryPropagationC$serial_busy[sim_node()]) {

      QueryPropagationC$s_sampling_pkt[sim_node()] = (sampling_msg_t *)QueryPropagationC$SerialPacket$getPayload(&QueryPropagationC$serial_pkt[sim_node()], sizeof(sampling_msg_t ));
      if (QueryPropagationC$s_sampling_pkt[sim_node()] == (void *)0) {
          return;
        }

      __nesc_hton_uint16(QueryPropagationC$s_sampling_pkt[sim_node()]->source_id.nxdata, QueryPropagationC$source_id[sim_node()]);
      __nesc_hton_uint16(QueryPropagationC$s_sampling_pkt[sim_node()]->data_id.nxdata, QueryPropagationC$s_data_id[sim_node()]);
      __nesc_hton_uint16(QueryPropagationC$s_sampling_pkt[sim_node()]->forwarder_id.nxdata, QueryPropagationC$forwarder_id[sim_node()]);
      __nesc_hton_uint16(QueryPropagationC$s_sampling_pkt[sim_node()]->sensor_data.nxdata, QueryPropagationC$sensor_data[sim_node()]);
      __nesc_hton_uint16(QueryPropagationC$s_sampling_pkt[sim_node()]->destination_id.nxdata, QueryPropagationC$destination_id[sim_node()]);
      __nesc_hton_uint16(QueryPropagationC$s_sampling_pkt[sim_node()]->sequence_number.nxdata, QueryPropagationC$sequence_number[sim_node()]);

      if (QueryPropagationC$SerialAMSend$send(AM_BROADCAST_ADDR, &QueryPropagationC$serial_pkt[sim_node()], sizeof(sampling_msg_t )) == SUCCESS) {
          QueryPropagationC$serial_busy[sim_node()] = TRUE;
        }
    }
}

# 61 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
inline static void QueryPropagationC$Leds$led0Off(void ){
#line 61
  LedsP$Leds$led0Off();
#line 61
}
#line 61
# 386 "QueryPropagationC.nc"
static inline void QueryPropagationC$Timer3$fired(void )
#line 386
{
  sim_log_debug(195U, "QueryC", "QUERY_ID: %hu => EXPIRED!!! @ %s \n", __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$HoldTimer[sim_node()]].sequence_number.nxdata), sim_time_string());


  QueryPropagationC$number_Of_queries[sim_node()]--;
  __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$HoldTimer[sim_node()]].state.nxdata, 0);

  if (QueryPropagationC$number_Of_queries[sim_node()] > 0) {
      QueryPropagationC$expiredQuery[sim_node()] = QueryPropagationC$HoldTimer[sim_node()];
      QueryPropagationC$minQuery[sim_node()] = 0;
      QueryPropagationC$query_pos[sim_node()] = 0;
      while (QueryPropagationC$query_pos[sim_node()] < 3) {
          if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].state.nxdata) == 1) {
              __nesc_hton_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata, __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata) - __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$expiredQuery[sim_node()]].query_lifetime.nxdata));
              if (__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata) <= __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$minQuery[sim_node()]].query_lifetime.nxdata) && __nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$query_pos[sim_node()]].query_lifetime.nxdata) != 0) {
                  QueryPropagationC$HoldTimer[sim_node()] = QueryPropagationC$query_pos[sim_node()];
                }
            }
          else {
              QueryPropagationC$minQuery[sim_node()]++;
            }
          QueryPropagationC$query_pos[sim_node()]++;
        }
      QueryPropagationC$Timer3$startOneShot(__nesc_ntoh_uint16(QueryPropagationC$AQQ[sim_node()][QueryPropagationC$HoldTimer[sim_node()]].query_lifetime.nxdata));
      QueryPropagationC$timerStartAt[sim_node()] = QueryPropagationC$Timer3$getNow();
    }
  else {
      QueryPropagationC$Leds$led0Off();
    }
}

# 89 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
inline static void QueryPropagationC$Leds$led2On(void ){
#line 89
  LedsP$Leds$led2On();
#line 89
}
#line 89
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t QueryPropagationC$SamplingRadioAMSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 418 "QueryPropagationC.nc"
static inline void QueryPropagationC$Timer4$fired(void )
#line 418
{
  if (!QueryPropagationC$unicast_busy[sim_node()]) {
      QueryPropagationC$ucast_pkt[sim_node()] = (sampling_msg_t *)QueryPropagationC$SamplingAMPacket$getPayload(&QueryPropagationC$SamplingPacketBuffer[sim_node()][QueryPropagationC$sampling_send[sim_node()]], sizeof(sampling_msg_t ));
      if (QueryPropagationC$ucast_pkt[sim_node()] == (void *)0) {
          return;
        }

      memcpy(&QueryPropagationC$pkt[sim_node()], &QueryPropagationC$SamplingPacketBuffer[sim_node()][QueryPropagationC$sampling_send[sim_node()]], sizeof(message_t ));

      sim_log_debug(196U, "RadioC", "RE-UNICAST TRANSMISSION \n SOURCE_ID: %hu, FORWARDER_ID: %hu, FATHER_ID: %hu, DATA_ID: %hu QUERY_ID: %hu \n\n", __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->source_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->forwarder_id.nxdata), QueryPropagationC$sendTofather[sim_node()], __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->data_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->sequence_number.nxdata));

      if (QueryPropagationC$SamplingRadioAMSend$send(QueryPropagationC$sendTofather[sim_node()], &QueryPropagationC$pkt[sim_node()], sizeof(sampling_msg_t )) == SUCCESS) {
          QueryPropagationC$unicast_busy[sim_node()] = TRUE;
          QueryPropagationC$Leds$led2On();
        }
    }
}


static inline void QueryPropagationC$Timer5$fired(void )
#line 437
{
  if (!QueryPropagationC$unicast_busy[sim_node()]) {

      QueryPropagationC$ucast_pkt[sim_node()] = (sampling_msg_t *)QueryPropagationC$SamplingAMPacket$getPayload(&QueryPropagationC$SamplingPacketBuffer[sim_node()][QueryPropagationC$sampling_send[sim_node()]], sizeof(sampling_msg_t ));
      if (QueryPropagationC$ucast_pkt[sim_node()] == (void *)0) {
          return;
        }

      sim_log_debug(197U, "RadioC", "UNICAST TRANSMISSION \n SOURCE_ID: %hu, FORWARDER_ID: %hu, FATHER_ID: %hu, DATA_ID: %hu QUERY_ID: %hu \n\n", __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->source_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->forwarder_id.nxdata), QueryPropagationC$sendTofather[sim_node()], __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->data_id.nxdata), __nesc_ntoh_uint16(QueryPropagationC$ucast_pkt[sim_node()]->sequence_number.nxdata));

      memcpy(&QueryPropagationC$pkt[sim_node()], &QueryPropagationC$SamplingPacketBuffer[sim_node()][QueryPropagationC$sampling_send[sim_node()]], sizeof(message_t ));

      if (QueryPropagationC$SamplingRadioAMSend$send(QueryPropagationC$sendTofather[sim_node()], &QueryPropagationC$pkt[sim_node()], sizeof(sampling_msg_t )) == SUCCESS) {
          QueryPropagationC$unicast_busy[sim_node()] = TRUE;
          QueryPropagationC$Leds$led2On();
        }
    }
}

# 204 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num)
{
}

# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(uint8_t arg_0x40be2c70){
#line 83
  switch (arg_0x40be2c70) {
#line 83
    case 0U:
#line 83
      QueryPropagationC$Timer0$fired();
#line 83
      break;
#line 83
    case 1U:
#line 83
      QueryPropagationC$Timer1$fired();
#line 83
      break;
#line 83
    case 2U:
#line 83
      QueryPropagationC$Timer2$fired();
#line 83
      break;
#line 83
    case 3U:
#line 83
      QueryPropagationC$Timer3$fired();
#line 83
      break;
#line 83
    case 4U:
#line 83
      QueryPropagationC$Timer4$fired();
#line 83
      break;
#line 83
    case 5U:
#line 83
      QueryPropagationC$Timer5$fired();
#line 83
      break;
#line 83
    default:
#line 83
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(arg_0x40be2c70);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  TossimActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
#line 162
inline static void /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  TossimActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static error_t /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(1U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 181 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len)
#line 181
{
  __nesc_hton_uint8(TossimActiveMessageC$getHeader(msg)->length.nxdata, len);
}

# 94 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(message_t * msg, uint8_t len){
#line 94
  TossimActiveMessageC$Packet$setPayloadLength(msg, len);
#line 94
}
#line 94
# 59 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$clr(void )
#line 59
{
#line 59
  atm128RegFile[sim_node()][27U] &= ~(1 << 0);
}

# 41 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led2$clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$clr();
#line 41
}
#line 41
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type t){
#line 54
  HplAtm128Timer0AsyncP$Compare$set(t);
#line 54
}
#line 54
# 61 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = HplAtm128Timer0AsyncP$Timer0$get();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 569 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void )
#line 569
{
  return (* (volatile uint8_t *)&atm128RegFile[sim_node()][0x30] & (1 << OCR0UB)) != 0;
}

# 44 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
inline static int /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy(void ){
#line 44
  int __nesc_result;
#line 44

#line 44
  __nesc_result = HplAtm128Timer0AsyncP$TimerAsync$compareBusy();
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 74 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(uint8_t n)
#line 74
{
  while (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy()) 
    ;
  if (n == /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get()) {
    n++;
    }


  if (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + n + 1 < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()]) {
    n = -/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] - 1;
    }
#line 84
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(n);
}

# 577 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$cancel_compare(void )
#line 577
{
  sim_log_debug(189U, "HplAtm128CompareC", "Cancelling compare at 0x%p\n", HplAtm128Timer0AsyncP$compare[sim_node()]);
  if (HplAtm128Timer0AsyncP$compare[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$compare[sim_node()]->cancelled = 1;
      HplAtm128Timer0AsyncP$compare[sim_node()]->cleanup = sim_queue_cleanup_total;
    }
}

#line 116
static inline void HplAtm128Timer0AsyncP$notify_changed(void )
#line 116
{
  uint8_t newScale = HplAtm128Timer0AsyncP$Timer0$getScale();

#line 118
  if (newScale != AVR_CLOCK_OFF && 
  HplAtm128Timer0AsyncP$oldScale[sim_node()] == AVR_CLOCK_OFF) {
      HplAtm128Timer0AsyncP$lastZero[sim_node()] = sim_time();
    }
  HplAtm128Timer0AsyncP$oldScale[sim_node()] = newScale;

  HplAtm128Timer0AsyncP$schedule_new_compare();
}

#line 545
static inline void HplAtm128Timer0AsyncP$cancel_overflow(void )
#line 545
{
  if (HplAtm128Timer0AsyncP$overflow[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$overflow[sim_node()]->cancelled = 1;
      sim_log_debug(188U, "HplAtm128Timer0AsyncP", "Cancelling overflow %p.\n", HplAtm128Timer0AsyncP$overflow[sim_node()]);
      HplAtm128Timer0AsyncP$overflow[sim_node()]->cleanup = sim_queue_cleanup_total;
    }
}

#line 481
static inline void HplAtm128Timer0AsyncP$timer0_overflow_handle(sim_event_t *evt)
#line 481
{
  if (evt->cancelled) {
      return;
    }
  else {
      if ((atm128RegFile[sim_node()][ATM128_TIMSK] & (1 << TOIE0)) != 0) {
          atm128RegFile[sim_node()][ATM128_TIFR] &= ~(1 << TOV0);
          sim_log_debug(185U, "HplAtm128Timer0AsyncP", "Overflow interrupt at %s\n", sim_time_string());
          INTERRUPT_16();
        }
      else {
          sim_log_debug(186U, "HplAtm128Timer0AsyncP", "Setting overflow bit at %s\n", sim_time_string());
          atm128RegFile[sim_node()][ATM128_TIFR] |= 1 << TOV0;
        }
      HplAtm128Timer0AsyncP$configure_overflow(evt);
      sim_queue_insert(evt);
    }
}

static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void )
#line 500
{
  sim_event_t *newEvent = sim_queue_allocate_event();

  newEvent->handle = HplAtm128Timer0AsyncP$timer0_overflow_handle;
  newEvent->cleanup = sim_queue_cleanup_none;
  return newEvent;
}

#line 534
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void )
#line 534
{
  sim_event_t *newEvent = HplAtm128Timer0AsyncP$allocate_overflow();

#line 536
  HplAtm128Timer0AsyncP$configure_overflow(newEvent);

  if (HplAtm128Timer0AsyncP$overflow[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$cancel_overflow();
    }
  HplAtm128Timer0AsyncP$overflow[sim_node()] = newEvent;
  sim_queue_insert(newEvent);
}

#line 148
static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t)
#line 148
{
  t *= sim_ticks_per_sec();
  t /= HplAtm128Timer0AsyncP$notify_clockTicksPerSec();
  return t;
}

#line 297
static inline void HplAtm128Timer0AsyncP$Timer0$set(uint8_t newVal)
#line 297
{
  uint8_t curVal = HplAtm128Timer0AsyncP$Timer0$get();

#line 299
  sim_log_debug(178U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Setting timer: %hhu\n", newVal);
  if (newVal == curVal) {
      return;
    }
  else {
      sim_time_t adjustment = curVal - newVal;

#line 305
      adjustment = adjustment << HplAtm128Timer0AsyncP$shiftFromScale();
      adjustment = HplAtm128Timer0AsyncP$clock_to_sim(adjustment);

      if (newVal < curVal) {
          HplAtm128Timer0AsyncP$lastZero[sim_node()] += adjustment;
        }
      else {
          HplAtm128Timer0AsyncP$lastZero[sim_node()] -= adjustment;
        }

      HplAtm128Timer0AsyncP$schedule_new_overflow();
      HplAtm128Timer0AsyncP$notify_changed();
    }
}

#line 187
static inline void HplAtm128Timer0AsyncP$timer0_compare_handle(sim_event_t *evt)
#line 187
{
  sim_log_debug(168U, "HplAtm128Timer0AsyncP", "Beginning compare 0x%p at %s\n", evt, sim_time_string());
  if (evt->cancelled) {
      return;
    }
  else {
      char timeStr[128];

#line 194
      sim_print_now(timeStr, 128);
      sim_log_debug(169U, "HplAtm128Timer0AsyncP", "Handling compare at 0x%p @ %s\n", evt, sim_time_string());

      if ((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM01)) != 0 && !((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM00)) != 0)) {
          sim_log_debug(170U, "HplAtm128Timer0AsyncP", "%s: CTC is set, clear timer.\n", __FUNCTION__);
          HplAtm128Timer0AsyncP$Timer0$set(0);
        }
      else {
          sim_log_debug(171U, "HplAtm128Timer0AsyncP", "%s: TCCR is 0x%hhx, %i, %i\n", __FUNCTION__, * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33], (int )((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM01)) != 0), (int )((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM00)) != 0));
        }

      if ((atm128RegFile[sim_node()][ATM128_TIMSK] & (1 << OCIE0)) != 0) {
          sim_log_debug(172U, "HplAtm128Timer0AsyncP", "TIFR is %hhx\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36]);
          atm128RegFile[sim_node()][ATM128_TIFR] &= ~(1 << OCF0);
          sim_log_debug(173U, "HplAtm128Timer0AsyncP", "TIFR is %hhx\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36]);
          sim_log_debug(174U, "HplAtm128Timer0AsyncP", "Compare interrupt @ %s\n", timeStr);
          INTERRUPT_15();
        }
      else {
          atm128RegFile[sim_node()][ATM128_TIFR] |= 1 << OCF0;
        }

      if (! evt->cancelled) {
          HplAtm128Timer0AsyncP$configure_compare(evt);
          sim_queue_insert(evt);
        }
    }
}

static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void )
#line 223
{
  sim_event_t *newEvent = sim_queue_allocate_event();

#line 225
  sim_log_debug(175U, "HplAtm128Timer0AsyncP", "Allocated compare at 0x%p\n", newEvent);
  newEvent->handle = HplAtm128Timer0AsyncP$timer0_compare_handle;
  newEvent->cleanup = sim_queue_cleanup_none;
  return newEvent;
}

# 230 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void )
#line 230
{
}

# 70 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static void HplAtm128Timer0AsyncP$Timer0$overflow(void ){
#line 70
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow();
#line 70
}
#line 70
# 58 "/opt/tinyos-2.1.2/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void )
{
}

# 82 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow(void ){
#line 82
  /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow();
#line 82
}
#line 82
# 85 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_enable_interrupt()
#line 85
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] |= 1 << 7;
}

# 48 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get(void ){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = HplAtm128Timer0AsyncP$Compare$get();
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 149 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void )
#line 149
{
  int overflowed;


  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] += /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() + 1U;
  overflowed = !/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()];
  __nesc_enable_interrupt();
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
  if (overflowed) {
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow();
    }
}

# 58 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void HplAtm128Timer0AsyncP$Compare$fired(void ){
#line 58
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired();
#line 58
}
#line 58
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 81 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void )
{
#line 82
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask();
}

# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired();
#line 78
}
#line 78
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t TossimPacketModelC$startDoneTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(TossimPacketModelC$startDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 69 "/opt/tinyos-2.1.2/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 61 "/opt/tinyos-2.1.2/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$SubInit$default$init(void )
#line 61
{
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t MotePlatformP$SubInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MotePlatformP$SubInit$default$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 59 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void )
#line 59
{
#line 59
  atm128RegFile[sim_node()][27U] &= ~(1 << 4);
}

# 41 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP$SerialIdPin$clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr();
#line 41
}
#line 41
# 62 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void )
#line 62
{
#line 62
  atm128RegFile[sim_node()][26U] &= ~(1 << 4);
}

# 44 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP$SerialIdPin$makeInput(void ){
#line 44
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput();
#line 44
}
#line 44
# 49 "/opt/tinyos-2.1.2/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$PlatformInit$init(void )
#line 49
{

  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x15] = 0;
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x14] = 0xff;


  MotePlatformP$SerialIdPin$makeInput();
  MotePlatformP$SerialIdPin$clr();

  return MotePlatformP$SubInit$init();
}

# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set(void )
#line 55
{
  sim_log_debug(47U, "Pins", "Setting bit %i of port %i.\n", (int )0, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 0;
}

# 40 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led2$set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set();
#line 40
}
#line 40
# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set(void )
#line 55
{
  sim_log_debug(48U, "Pins", "Setting bit %i of port %i.\n", (int )1, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 1;
}

# 40 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led1$set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set();
#line 40
}
#line 40
# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set(void )
#line 55
{
  sim_log_debug(49U, "Pins", "Setting bit %i of port %i.\n", (int )2, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 2;
}

# 40 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led0$set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set();
#line 40
}
#line 40
# 63 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput(void )
#line 63
{
#line 63
  atm128RegFile[sim_node()][26U] |= 1 << 0;
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led2$makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput();
#line 46
}
#line 46
# 63 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput(void )
#line 63
{
#line 63
  atm128RegFile[sim_node()][26U] |= 1 << 1;
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led1$makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput();
#line 46
}
#line 46
# 63 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput(void )
#line 63
{
#line 63
  atm128RegFile[sim_node()][26U] |= 1 << 2;
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led0$makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput();
#line 46
}
#line 46
# 56 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static inline error_t LedsP$Init$init(void )
#line 56
{
  /* atomic removed: atomic calls only */
#line 57
  {
    sim_log_debug(153U, "Init", "LEDS: initialized.\n");
    LedsP$Led0$makeOutput();
    LedsP$Led1$makeOutput();
    LedsP$Led2$makeOutput();
    LedsP$Led0$set();
    LedsP$Led1$set();
    LedsP$Led2$set();
  }
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t PlatformP$MoteInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = LedsP$Init$init();
#line 62
  __nesc_result = ecombine(__nesc_result, MotePlatformP$PlatformInit$init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 21 "/opt/tinyos-2.1.2/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC$Init$init(void )
#line 21
{
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t PlatformP$MeasureClock$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MeasureClockC$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 51 "/opt/tinyos-2.1.2/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP$Init$init(void )
{
  error_t ok;


  ok = PlatformP$MeasureClock$init();
  ok = ecombine(ok, PlatformP$MoteInit$init());

  return ok;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t SimMainP$PlatformInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 65 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
inline static bool SimMainP$Scheduler$runNextTask(void ){
#line 65
  unsigned char __nesc_result;
#line 65

#line 65
  __nesc_result = SimSchedulerBasicP$Scheduler$runNextTask();
#line 65

#line 65
  return __nesc_result;
#line 65
}
#line 65
# 86 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC$Init$init(void )
#line 86
{
  sim_log_debug(110U, "TossimPacketModelC", "TossimPacketModelC: Init.init() called\n");
  TossimPacketModelC$initialized[sim_node()] = TRUE;



  TossimPacketModelC$sendEvent[sim_node()].cancelled = 1;
  return SUCCESS;
}

# 447 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$Compare$start(void )
#line 447
{
#line 447
  atm128RegFile[sim_node()][ATM128_TIMSK] |= 1 << OCIE0;
}

# 65 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start(void ){
#line 65
  HplAtm128Timer0AsyncP$Compare$start();
#line 65
}
#line 65
# 364 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t x)
#line 364
{
  sim_log_debug(180U, "HplAtm128Timer0AsyncP", "Setting control to be 0x%hhx\n", x.flat);
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33] = x.flat;
}

# 46 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(Atm128TimerControl_t control){
#line 46
  HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(control);
#line 46
}
#line 46
# 561 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void )
#line 561
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x30] |= 1 << AS0;
}

# 32 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous(void ){
#line 32
  HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous();
#line 32
}
#line 32
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void )
#line 54
{
  /* atomic removed: atomic calls only */
  {
    Atm128TimerControl_t x;

    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous();
    x.flat = 0;
    x.bits.cs = 3;
    x.bits.wgm1 = 1;
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(x);
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT);
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start();
  }
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t SimMainP$SoftwareInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init();
#line 62
  __nesc_result = ecombine(__nesc_result, TossimPacketModelC$Init$init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t QueryPropagationC$init_ActiveQueryQ$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(QueryPropagationC$init_ActiveQueryQ);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t QueryPropagationC$init_StateMessages$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(QueryPropagationC$init_StateMessages);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 94 "/opt/tinyos-2.1.2/tos/interfaces/Leds.nc"
inline static void QueryPropagationC$Leds$led2Off(void ){
#line 94
  LedsP$Leds$led2Off();
#line 94
}
#line 94
#line 77
inline static void QueryPropagationC$Leds$led1Off(void ){
#line 77
  LedsP$Leds$led1Off();
#line 77
}
#line 77
# 206 "QueryPropagationC.nc"
static inline void QueryPropagationC$Boot$booted(void )
#line 206
{

  QueryPropagationC$send[sim_node()] = 0;
  QueryPropagationC$save[sim_node()] = 0;
  QueryPropagationC$next[sim_node()] = 0;
  QueryPropagationC$data_id[sim_node()] = 0;
  QueryPropagationC$query_pos[sim_node()] = 0;
  QueryPropagationC$sequence_number[sim_node()] = 0;
  QueryPropagationC$sampling_save[sim_node()] = 0;
  QueryPropagationC$sampling_send[sim_node()] = 0;
  QueryPropagationC$number_Of_queries[sim_node()] = 0;

  QueryPropagationC$Leds$led0Off();
  QueryPropagationC$Leds$led1Off();
  QueryPropagationC$Leds$led2Off();

  QueryPropagationC$init_StateMessages$postTask();
  QueryPropagationC$init_ActiveQueryQ$postTask();

  QueryPropagationC$RadioAMControl$start();
  QueryPropagationC$SerialAMControl$start();
}

# 60 "/opt/tinyos-2.1.2/tos/interfaces/Boot.nc"
inline static void SimMainP$Boot$booted(void ){
#line 60
  QueryPropagationC$Boot$booted();
#line 60
}
#line 60
# 55 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP$SimMote$getEuid(void )
#line 55
{
  return SimMoteP$euid[sim_node()];
}

#line 58
static inline void SimMoteP$SimMote$setEuid(long long int e)
#line 58
{
  SimMoteP$euid[sim_node()] = e;
}







static inline int SimMoteP$SimMote$getVariableInfo(char *name, void **addr, size_t *size)
#line 68
{
  return __nesc_nido_resolve(sim_node(), name, (uintptr_t *)addr, (size_t *)size);
}

#line 85
static inline void SimMoteP$SimMote$turnOff(void )
#line 85
{
  SimMoteP$isOn[sim_node()] = FALSE;
}

#line 157
static inline void SimMoteP$sim_mote_boot_handle(sim_event_t *e)
#line 157
{
  char buf[128];

#line 159
  sim_print_now(buf, 128);

  SimMoteP$bootEvent[sim_node()] = (sim_event_t *)(void *)0;
  sim_log_debug(104U, "SimMoteP", "Turning on mote %i at time %s.\n", (int )sim_node(), buf);
  SimMoteP$SimMote$turnOn();
}

# 46 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
  void sim_queue_init()
#line 46
{
  init_heap(&eventHeap);
}

  void sim_queue_insert(sim_event_t *event)
#line 50
{
  sim_log_debug(0U, "Queue", "Inserting 0x%p\n", event);
  heap_insert(&eventHeap, event, event->time);
}

# 246 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_debug(uint16_t id, char *string, const char *format, ...)
#line 246
{
  va_list args;
  int i;

#line 249
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 254
      __builtin_va_start(args, format);
      fprintf(file, "DEBUG (%i): ", (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

#line 84
static void fillInOutput(int id, char *name)
#line 84
{
  char *termination = name;
  char *namePos = name;
  int count = 0;
  char *newName = (char *)malloc(strlen(name) + 1);

#line 89
  memset(newName, 0, strlen(name) + 1);

  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          strcpy(newName, namePos);
        }
      else 
        {
          memcpy(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, newName);
      if (channel != (void *)0) {
          count += channel->numOutputs;
        }

      namePos = termination + 1;
    }

  termination = name;
  namePos = name;


  outputs[id].files = (FILE **)malloc(sizeof(FILE *) * count);
  outputs[id].num = 0;


  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          strcpy(newName, namePos);
        }
      else 
        {
          memcpy(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, newName);
      if (channel != (void *)0) {
          int i;
#line 137
          int j;

#line 138
          for (i = 0; i < channel->numOutputs; i++) {
              int duplicate = 0;
              int outputCount = outputs[id].num;


              for (j = 0; j < outputCount; j++) {
                  if (fileno(outputs[id].files[j]) == fileno(channel->outputs[i])) {
                      duplicate = 1;
                      j = outputCount;
                    }
                }
              if (!duplicate) {
                  outputs[id].files[outputCount] = channel->outputs[i];
                  outputs[id].num++;
                }
            }
        }
      namePos = termination + 1;
    }
}

# 121 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  unsigned long sim_node()
#line 121
{
  return current_node;
}

# 197 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
static void up_heap(heap_t *heap, int findex)
#line 197
{
  int parent_index;

#line 199
  if (findex == 0) {
      return;
    }

  parent_index = (findex - 1) / 2;

  if (((node_t *)heap->data)[parent_index].key > ((node_t *)heap->data)[findex].key) {
      swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[parent_index]);
      up_heap(heap, parent_index);
    }
}

#line 158
static void swap(node_t *first, node_t *second)
#line 158
{
  long long int key;
  void *data;

  key = first->key;
  first->key = second->key;
  second->key = key;

  data = first->data;
  first->data = second->data;
  second->data = data;
}

# 55 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
  sim_event_t *sim_queue_pop()
#line 55
{
  long long int key;

#line 57
  return (sim_event_t *)heap_pop_min_data(&eventHeap, &key);
}

# 114 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
static void *heap_pop_min_data(heap_t *heap, long long int *key)
#line 114
{
  int last_index = heap->size - 1;
  void *data = ((node_t *)heap->data)[0].data;

#line 117
  if (key != (void *)0) {
      *key = ((node_t *)heap->data)[0].key;
    }
  ((node_t *)heap->data)[0].data = ((node_t *)heap->data)[last_index].data;
  ((node_t *)heap->data)[0].key = ((node_t *)heap->data)[last_index].key;

  heap->size--;

  down_heap(heap, 0);

  return data;
}

#line 171
static void down_heap(heap_t *heap, int findex)
#line 171
{
  int right_index = (findex + 1) * 2;
  int left_index = findex * 2 + 1;

  if (right_index < heap->size) {
      long long int left_key = ((node_t *)heap->data)[left_index].key;
      long long int right_key = ((node_t *)heap->data)[right_index].key;
      int min_key_index = left_key < right_key ? left_index : right_index;

      if (((node_t *)heap->data)[min_key_index].key < ((node_t *)heap->data)[findex].key) {
          swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[min_key_index]);
          down_heap(heap, min_key_index);
        }
    }
  else {
#line 185
    if (left_index >= heap->size) {
        return;
      }
    else {
        long long int left_key = ((node_t *)heap->data)[left_index].key;

#line 190
        if (left_key < ((node_t *)heap->data)[findex].key) {
            swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[left_index]);
            return;
          }
      }
    }
}

# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
  bool sim_queue_is_empty()
#line 60
{
  return heap_is_empty(&eventHeap);
}

  long long int sim_queue_peek_time()
#line 64
{
  if (heap_is_empty(&eventHeap)) {
      return -1;
    }
  else {
      return heap_get_min_key(&eventHeap);
    }
}


  void sim_queue_cleanup_none(sim_event_t *event)
#line 74
{
  sim_log_debug(1U, "Queue", "cleanup_none: 0x%p\n", event);
}


  void sim_queue_cleanup_event(sim_event_t *event)
#line 79
{
  sim_log_debug(2U, "Queue", "cleanup_event: 0x%p\n", event);
  free(event);
}

  void sim_queue_cleanup_data(sim_event_t *event)
#line 84
{
  sim_log_debug(3U, "Queue", "cleanup_data: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
}

  void sim_queue_cleanup_total(sim_event_t *event)
#line 90
{
  sim_log_debug(4U, "Queue", "cleanup_total: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
  free(event);
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  void sim_init()
#line 57
{
  sim_queue_init();
  sim_log_init();
  sim_log_commit_change();
  sim_noise_init();

  {
    struct timeval tv;

#line 65
    gettimeofday(&tv, (void *)0);





    if (tv.tv_usec != 0) {
        sim_random_seed(tv.tv_usec);
      }
    else {
        sim_random_seed(tv.tv_sec);
      }
  }
}

# 234 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_commit_change()
#line 234
{
  int i;

#line 236
  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      if (outputs[i].files != (void *)0) {
          outputs[i].num = 0;
          free(outputs[i].files);
          outputs[i].files = (void *)0;
        }
    }
}

# 67 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
  void sim_noise_init()
{
  int j;



  for (j = 0; j < 1000; j++) {
      noiseData[j].noiseTable = create_hashtable(NOISE_HASHTABLE_SIZE, sim_noise_hash, sim_noise_eq);
      noiseData[j].noiseGenTime = 0;
      noiseData[j].noiseTrace = (char *)malloc(sizeof(char ) * NOISE_MIN_TRACE);
      noiseData[j].noiseTraceLen = NOISE_MIN_TRACE;
      noiseData[j].noiseTraceIndex = 0;
    }
}

# 102 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  void sim_random_seed(int seed)
#line 102
{

  if (seed == 0) {
      seed = 1;
    }
  sim_seed = seed;
}

#line 80
  void sim_end()
#line 80
{
  sim_queue_init();
}



  int sim_random()
#line 86
{
  uint32_t mlcg;
#line 87
  uint32_t p;
#line 87
  uint32_t q;
  uint64_t tmpseed;

#line 89
  tmpseed = (uint64_t )33614U * (uint64_t )sim_seed;
  q = tmpseed;
  q = q >> 1;
  p = tmpseed >> 32;
  mlcg = p + q;
  if (mlcg & 0x80000000) {
      mlcg = mlcg & 0x7FFFFFFF;
      mlcg++;
    }
  sim_seed = mlcg;
  return mlcg;
}









  sim_time_t sim_time()
#line 110
{
  return sim_ticks;
}

#line 113
  void sim_set_time(sim_time_t t)
#line 113
{
  sim_ticks = t;
}

  sim_time_t sim_ticks_per_sec()
#line 117
{
  return 10000000000ULL;
}




  void sim_set_node(unsigned long node)
#line 124
{
  current_node = node;
  TOS_NODE_ID = node;
}

  bool sim_run_next_event()
#line 129
{
  bool result = FALSE;

#line 131
  if (!sim_queue_is_empty()) {
      sim_event_t *event = sim_queue_pop();

#line 133
      sim_set_time(event->time);
      sim_set_node(event->mote);



      sim_log_debug(5U, "Tossim", "CORE: popping event 0x%p for %i at %llu with handler %p... ", event, sim_node(), sim_time(), event->handle);
      if ((sim_mote_is_on(event->mote) || event->force) && 
      event->handle != (void *)0) {
          result = TRUE;
          sim_log_debug_clear(6U, "Tossim", " mote is on (or forced event), run it.\n");
          event->handle(event);
        }
      else {
          sim_log_debug_clear(7U, "Tossim", "\n");
        }
      if (event->cleanup != (void *)0) {
          event->cleanup(event);
        }
    }

  return result;
}

# 134 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
  bool sim_mote_is_on(int mote)
#line 134
{
  bool result;
  int tmp = sim_node();

#line 137
  sim_set_node(mote);
  result = SimMoteP$SimMote$isOn();
  sim_set_node(tmp);
  return result;
}

# 276 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...)
#line 276
{
  va_list args;
  int i;

#line 279
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 284
      __builtin_va_start(args, format);
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 156 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  int sim_print_time(char *buf, int len, sim_time_t ftime)
#line 156
{
  int hours;
  int minutes;
  int seconds;
  sim_time_t secondBillionths;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;
  buf[len - 1] = 0;
  return snprintf(buf, len - 1, "%i:%i:%i.%09llu", hours, minutes, seconds, secondBillionths);
}

  int sim_print_now(char *buf, int len)
#line 179
{
  return sim_print_time(buf, len, sim_time());
}


  char *sim_time_string()
#line 184
{
  sim_print_now(simTimeBuf, 128);
  return simTimeBuf;
}

  void sim_add_channel(char *channel, FILE *file)
#line 189
{
  sim_log_add_channel(channel, file);
}

  bool sim_remove_channel(char *channel, FILE *file)
#line 193
{
  return sim_log_remove_channel(channel, file);
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_csma.c"
  int sim_csma_init_high()
#line 57
{
  return csmaInitHigh;
}

#line 60
  int sim_csma_init_low()
#line 60
{
  return csmaInitLow;
}

#line 63
  int sim_csma_high()
#line 63
{
  return csmaHigh;
}

#line 66
  int sim_csma_low()
#line 66
{
  return csmaLow;
}

#line 69
  int sim_csma_symbols_per_sec()
#line 69
{
  return csmaSymbolsPerSec;
}

#line 72
  int sim_csma_bits_per_symbol()
#line 72
{
  return csmaBitsPerSymbol;
}

#line 75
  int sim_csma_preamble_length()
#line 75
{
  return csmaPreambleLength;
}

#line 78
  int sim_csma_exponent_base()
#line 78
{
  return csmaExponentBase;
#line 79
  ;
}

#line 81
  int sim_csma_max_iterations()
#line 81
{
  return csmaMaxIterations;
}

#line 84
  int sim_csma_min_free_samples()
#line 84
{
  return csmaMinFreeSamples;
}

#line 87
  int sim_csma_rxtx_delay()
#line 87
{
  return csmaRxTxDelay;
}

#line 90
  int sim_csma_ack_time()
#line 90
{
  return csmaAckTime;
}



  void sim_csma_set_init_high(int val)
#line 96
{
  csmaInitHigh = val;
}

#line 99
  void sim_csma_set_init_low(int val)
#line 99
{
  csmaInitLow = val;
}

#line 102
  void sim_csma_set_high(int val)
#line 102
{
  csmaHigh = val;
}

#line 105
  void sim_csma_set_low(int val)
#line 105
{
  csmaLow = val;
}

#line 108
  void sim_csma_set_symbols_per_sec(int val)
#line 108
{
  csmaSymbolsPerSec = val;
}

#line 111
  void sim_csma_set_bits_per_symbol(int val)
#line 111
{
  csmaBitsPerSymbol = val;
}

#line 114
  void sim_csma_set_preamble_length(int val)
#line 114
{
  csmaPreambleLength = val;
}

#line 117
  void sim_csma_set_exponent_base(int val)
#line 117
{
  csmaExponentBase = val;
}

#line 120
  void sim_csma_set_max_iterations(int val)
#line 120
{
  csmaMaxIterations = val;
}

#line 123
  void sim_csma_set_min_free_samples(int val)
#line 123
{
  csmaMinFreeSamples = val;
}

#line 126
  void sim_csma_set_rxtx_delay(int val)
#line 126
{
  csmaRxTxDelay = val;
}

#line 129
  void sim_csma_set_ack_time(int val)
#line 129
{
  csmaAckTime = val;
}

# 16 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.c"
  gain_entry_t *sim_gain_first(int src)
#line 16
{
  if (src > 1000) {
      return connectivity[1000];
    }
  return connectivity[src];
}

  gain_entry_t *sim_gain_next(gain_entry_t *currentLink)
#line 23
{
  return currentLink->next;
}

  void sim_gain_add(int src, int dest, double gain)
#line 27
{
  gain_entry_t *current;
  int temp = sim_node();

#line 30
  if (src > 1000) {
      src = 1000;
    }
  sim_set_node(src);

  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          break;
        }
      current = current->next;
    }

  if (current == (void *)0) {
      current = sim_gain_allocate_link(dest);
      current->next = connectivity[src];
      connectivity[src] = current;
    }
  current->mote = dest;
  current->gain = gain;
  sim_log_debug(8U, "Gain", "Adding link from %i to %i with gain %f\n", src, dest, gain);
  sim_set_node(temp);
}

  double sim_gain_value(int src, int dest)
#line 55
{
  gain_entry_t *current;
  int temp = sim_node();

#line 58
  sim_set_node(src);
  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          sim_log_debug(9U, "Gain", "Getting link from %i to %i with gain %f\n", src, dest, current->gain);
          return current->gain;
        }
      current = current->next;
    }
  sim_set_node(temp);
  sim_log_debug(10U, "Gain", "Getting default link from %i to %i with gain %f\n", src, dest, 1.0);
  return 1.0;
}

  bool sim_gain_connected(int src, int dest)
#line 73
{
  gain_entry_t *current;
  int temp = sim_node();

#line 76
  sim_set_node(src);
  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          return TRUE;
        }
      current = current->next;
    }
  sim_set_node(temp);
  return FALSE;
}

  void sim_gain_remove(int src, int dest)
#line 89
{
  gain_entry_t *current;
  gain_entry_t *prevLink;
  int temp = sim_node();

  if (src > 1000) {
      src = 1000;
    }

  sim_set_node(src);

  current = sim_gain_first(src);
  prevLink = (void *)0;

  while (current != (void *)0) {
      gain_entry_t *tmp;

#line 105
      if (current->mote == dest) {
          if (prevLink == (void *)0) {
              connectivity[src] = current->next;
            }
          else {
              prevLink->next = current->next;
            }
          tmp = current->next;
          sim_gain_deallocate_link(current);
          current = tmp;
        }
      else {
          prevLink = current;
          current = current->next;
        }
    }
  sim_set_node(temp);
}

#line 169
  void sim_gain_deallocate_link(gain_entry_t *linkToDelete)
#line 169
{
  free(linkToDelete);
}

#line 124
  void sim_gain_set_noise_floor(int node, double mean, double range)
#line 124
{
  if (node > 1000) {
      node = 1000;
    }
  localNoise[node].mean = mean;
  localNoise[node].range = range;
}

#line 148
  double sim_gain_sample_noise(int node)
#line 148
{
  double val;
#line 149
  double adjust;

#line 150
  if (node > 1000) {
      node = 1000;
    }
  val = localNoise[node].mean;
  adjust = sim_random() % 2000000;
  adjust /= 1000000.0;
  adjust -= 1.0;
  adjust *= localNoise[node].range;
  return val + adjust;
}

#line 173
  void sim_gain_set_sensitivity(double s)
#line 173
{
  sensitivity = s;
}

  double sim_gain_sensitivity()
#line 177
{
  return sensitivity;
}

# 84 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
  void sim_noise_create_model(uint16_t node_id)
#line 84
{
  makeNoiseModel(node_id);
  makePmfDistr(node_id);
}

#line 419
  void makeNoiseModel(uint16_t node_id)
#line 419
{
  int i;

#line 421
  for (i = 0; i < NOISE_HISTORY; i++) {
      noiseData[node_id].key[i] = search_bin_num(noiseData[node_id].noiseTrace[i]);
      sim_log_debug(44U, "Insert", "Setting history %i to be %i\n", (int )i, (int )noiseData[node_id].key[i]);
    }




  for (i = NOISE_HISTORY; i < noiseData[node_id].noiseTraceIndex; i++) {
      sim_noise_add(node_id, noiseData[node_id].noiseTrace[i]);
      arrangeKey(node_id);
      noiseData[node_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }
  noiseData[node_id].generated = 1;
}

#line 113
  uint8_t search_bin_num(char noise)
{
  uint8_t bin;

#line 116
  if (noise > NOISE_MAX || noise < NOISE_MIN) {
      noise = NOISE_MIN;
    }
  bin = (noise - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1;
  return bin;
}

#line 144
  void sim_noise_add(uint16_t node_id, char noise)
{
  int i;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *key = noiseData[node_id].key;
  sim_noise_hash_t *noise_hash;

#line 150
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);
  sim_log_debug(13U, "Insert", "Adding noise value %hhi\n", noise);
  if (noise_hash == (void *)0) {
      noise_hash = (sim_noise_hash_t *)malloc(sizeof(sim_noise_hash_t ));
      memcpy((void *)noise_hash->key, (void *)key, NOISE_HISTORY);

      noise_hash->numElements = 0;
      noise_hash->size = NOISE_DEFAULT_ELEMENT_SIZE;
      noise_hash->elements = (char *)malloc(sizeof(char ) * noise_hash->size);
      memset((void *)noise_hash->elements, 0, sizeof(char ) * noise_hash->size);

      noise_hash->flag = 0;
      for (i = 0; i < NOISE_NUM_VALUES; i++) {
          noise_hash->dist[i] = 0;
        }
      hashtable_insert(pnoiseTable, key, noise_hash);
      sim_log_debug(14U, "Insert", "Inserting %p into table %p with key ", noise_hash, pnoiseTable);
      {
        int ctr;

#line 169
        for (ctr = 0; ctr < NOISE_HISTORY; ctr++) 
          sim_log_debug_clear(15U, "Insert", "%0.3hhi ", key[ctr]);
      }
      sim_log_debug_clear(16U, "Insert", "\n");
    }

  if (noise_hash->numElements == noise_hash->size) 
    {
      char *newElements;
      int newSize = noise_hash->size * 2;

      newElements = (char *)malloc(sizeof(char ) * newSize);
      memcpy(newElements, noise_hash->elements, noise_hash->size);
      free(noise_hash->elements);
      noise_hash->elements = newElements;
      noise_hash->size = newSize;
    }

  noise_hash->elements[noise_hash->numElements] = noise;

  noise_hash->numElements++;
}

#line 245
  void arrangeKey(uint16_t node_id)
{
  char *pKey = noiseData[node_id].key;

#line 248
  memcpy(pKey, pKey + 1, NOISE_HISTORY - 1);
}





  void makePmfDistr(uint16_t node_id)
{
  int i;
  char *pKey = noiseData[node_id].key;
  char *fKey = noiseData[node_id].freqKey;

  FreqKeyNum = 0;
  for (i = 0; i < NOISE_HISTORY; i++) {
      pKey[i] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }

  for (i = NOISE_HISTORY; i < noiseData[node_id].noiseTraceIndex; i++) {
      if (i == NOISE_HISTORY) {
        }

      sim_noise_dist(node_id);
      arrangeKey(node_id);
      pKey[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }

  sim_log_debug_clear(21U, "HASH", "FreqKey = ");
  for (i = 0; i < NOISE_HISTORY; i++) 
    {
      sim_log_debug_clear(22U, "HASH", "%d,", fKey[i]);
    }
  sim_log_debug_clear(23U, "HASH", "\n");
}

#line 192
  void sim_noise_dist(uint16_t node_id)
{
  int i;
  uint8_t bin;
  float cmf = 0;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *key = noiseData[node_id].key;
  char *freqKey = noiseData[node_id].freqKey;
  sim_noise_hash_t *noise_hash;

#line 201
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);



  if (noise_hash->flag == 1) {
    return;
    }
  for (i = 0; i < NOISE_NUM_VALUES; i++) {
      noise_hash->dist[i] = 0.0;
    }

  for (i = 0; i < noise_hash->numElements; i++) 
    {
      float val;

#line 215
      sim_log_debug(17U, "Noise_output", "Noise is found to be %i\n", noise_hash->elements[i]);
      bin = noise_hash->elements[i] - NOISE_MIN_QUANTIZE;

      val = noise_hash->dist[bin];
      val += (float )1.0;
      noise_hash->dist[bin] = val;
    }

  for (i = 0; i < NOISE_NUM_VALUES; i++) 
    {
      noise_hash->dist[i] = noise_hash->dist[i] / noise_hash->numElements;
      cmf += noise_hash->dist[i];
      noise_hash->dist[i] = cmf;
    }
  noise_hash->flag = 1;


  if (noise_hash->numElements > FreqKeyNum) 
    {
      int j;

#line 235
      FreqKeyNum = noise_hash->numElements;
      memcpy((void *)freqKey, (void *)key, NOISE_HISTORY);
      sim_log_debug(18U, "HashZeroDebug", "Setting most frequent key (%i): ", (int )FreqKeyNum);
      for (j = 0; j < NOISE_HISTORY; j++) {
          sim_log_debug_clear(19U, "HashZeroDebug", "[%hhu] ", key[j]);
        }
      sim_log_debug_clear(20U, "HashZeroDebug", "\n");
    }
}

#line 97
  void sim_noise_trace_add(uint16_t node_id, char noiseVal)
#line 97
{

  if (noiseData[node_id].noiseTraceIndex == 
  noiseData[node_id].noiseTraceLen) {
      char *data = (char *)malloc(sizeof(char ) * noiseData[node_id].noiseTraceLen * 2);

#line 102
      memcpy(data, noiseData[node_id].noiseTrace, noiseData[node_id].noiseTraceLen);
      free(noiseData[node_id].noiseTrace);
      noiseData[node_id].noiseTraceLen *= 2;
      noiseData[node_id].noiseTrace = data;
    }
  noiseData[node_id].noiseTrace[noiseData[node_id].noiseTraceIndex] = noiseVal;
  noiseData[node_id].noiseTraceIndex++;
  sim_log_debug(12U, "Insert", "Adding noise value %i for %i of %i\n", (int )noiseData[node_id].noiseTraceIndex, (int )node_id, (int )noiseVal);
}

#line 123
  char search_noise_from_bin_num(int i)
{
  char noise;

#line 126
  noise = NOISE_MIN + (i - 1) * NOISE_QUANTIZE_INTERVAL;
  return noise;
}

#line 288
  char sim_noise_gen(uint16_t node_id)
{
  int i;
  int noiseIndex = 0;
  char noise;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *pKey = noiseData[node_id].key;
  char *fKey = noiseData[node_id].freqKey;
  double ranNum = RandomUniform();
  sim_noise_hash_t *noise_hash;

#line 298
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);

  if (noise_hash == (void *)0) {

      sim_log_debug(24U, "Noise_c", "Did not pattern match");

      sim_noise_alarm();
      noise = 0;
      sim_log_debug_clear(25U, "HASH", "(N)Noise\n");
      sim_log_debug(26U, "HashZeroDebug", "Defaulting to common hash.\n");
      memcpy((void *)pKey, (void *)fKey, NOISE_HISTORY);
      noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);
    }

  sim_log_debug_clear(27U, "HASH", "Key = ");
  for (i = 0; i < NOISE_HISTORY; i++) {
      sim_log_debug_clear(28U, "HASH", "%d,", pKey[i]);
    }
  sim_log_debug_clear(29U, "HASH", "\n");

  sim_log_debug(30U, "HASH", "Printing Key\n");
  sim_log_debug(31U, "HASH", "noise_hash->numElements=%d\n", noise_hash->numElements);


  numTotal++;


  if (noise_hash->numElements == 1) {
      noise = noise_hash->elements[0];
      sim_log_debug_clear(32U, "HASH", "(E)Noise = %d\n", noise);

      numCase1++;
      sim_log_debug(33U, "Noise_c", "In case 1: %i of %i\n", numCase1, numTotal);

      sim_log_debug(34U, "NoiseAudit", "Noise: %i\n", noise);
      return noise;
    }


  numCase2++;
  sim_log_debug(35U, "Noise_c", "In case 2: %i of %i\n", numCase2, numTotal);


  for (i = 0; i < NOISE_NUM_VALUES - 1; i++) {
      sim_log_debug(36U, "HASH", "IN:for i=%d\n", i);
      if (i == 0) {
          if (ranNum <= noise_hash->dist[i]) {
              noiseIndex = i;
              sim_log_debug_clear(37U, "HASH", "Selected Bin = %d -> ", i + 1);
              break;
            }
        }
      else {
#line 350
        if (noise_hash->dist[i - 1] < ranNum && 
        ranNum <= noise_hash->dist[i]) {
            noiseIndex = i;
            sim_log_debug_clear(38U, "HASH", "Selected Bin = %d -> ", i + 1);
            break;
          }
        }
    }
#line 357
  sim_log_debug(39U, "HASH", "OUT:for i=%d\n", i);

  noise = NOISE_MIN_QUANTIZE + i;
  sim_log_debug(40U, "NoiseAudit", "Noise: %i\n", noise);
  return noise;
}

# 103 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.c"
static double RandomUniform(void )
{
  double uni;
  int seed1;
#line 106
  int seed2;


  if (!test) 
    {



      seed1 = sim_random() % 31329;
      seed2 = sim_random() % 30082;
      RandomInitialise(seed1, seed2);
    }

  uni = randU[i97 - 1] - randU[j97 - 1];
  if (uni <= 0.0) {
    uni++;
    }
#line 122
  randU[i97 - 1] = uni;
  i97--;
  if (i97 == 0) {
    i97 = 97;
    }
#line 126
  j97--;
  if (j97 == 0) {
    j97 = 97;
    }
#line 129
  randC -= randCD;
  if (randC < 0.0) {
    randC += randCM;
    }
#line 132
  uni -= randC;
  if (uni < 0.0) {
    uni++;
    }
  return uni;
}

# 364 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
  char sim_noise_generate(uint16_t node_id, uint32_t cur_t)
#line 364
{
  uint32_t i;
  uint32_t prev_t;
  uint32_t delta_t;
  char *noiseG;
  char noise;

  prev_t = noiseData[node_id].noiseGenTime;

  if (noiseData[node_id].generated == 0) {
      sim_log_error(41U, "TOSSIM", "Tried to generate noise from an uninitialized radio model of node %hu.\n", node_id);
      return 127;
    }

  if (0 <= cur_t && cur_t < NOISE_HISTORY) {
      noiseData[node_id].noiseGenTime = cur_t;
      noiseData[node_id].key[cur_t] = search_bin_num(noiseData[node_id].noiseTrace[cur_t]);
      noiseData[node_id].lastNoiseVal = noiseData[node_id].noiseTrace[cur_t];
      return noiseData[node_id].noiseTrace[cur_t];
    }

  if (prev_t == 0) {
    delta_t = cur_t - (NOISE_HISTORY - 1);
    }
  else {
#line 388
    delta_t = cur_t - prev_t;
    }
  sim_log_debug_clear(42U, "HASH", "delta_t = %d\n", delta_t);

  if (delta_t == 0) {
    noise = noiseData[node_id].lastNoiseVal;
    }
  else 
#line 394
    {
      noiseG = (char *)malloc(sizeof(char ) * delta_t);

      for (i = 0; i < delta_t; i++) {
          noiseG[i] = sim_noise_gen(node_id);
          arrangeKey(node_id);
          noiseData[node_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseG[i]);
        }
      noise = noiseG[delta_t - 1];
      noiseData[node_id].lastNoiseVal = noise;

      free(noiseG);
    }
  noiseData[node_id].noiseGenTime = cur_t;
  if (noise == 0) {
      sim_log_debug(43U, "HashZeroDebug", "Generated noise of zero.\n");
    }

  return noise;
}

# 261 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_error(uint16_t id, char *string, const char *format, ...)
#line 261
{
  va_list args;
  int i;

#line 264
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 269
      __builtin_va_start(args, format);
      fprintf(file, "ERROR (%i): ", (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 54 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
  void sim_packet_set_source(sim_packet_t *msg, uint16_t src)
#line 54
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 56
  __nesc_hton_uint16(hdr->src.nxdata, src);
}

  uint16_t sim_packet_source(sim_packet_t *msg)
#line 59
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 61
  return __nesc_ntoh_uint16(hdr->src.nxdata);
}

  void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)
#line 64
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 66
  __nesc_hton_uint16(hdr->dest.nxdata, dest);
}

  uint16_t sim_packet_destination(sim_packet_t *msg)
#line 69
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 71
  return __nesc_ntoh_uint16(hdr->dest.nxdata);
}

  void sim_packet_set_length(sim_packet_t *msg, uint8_t length)
#line 74
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 76
  __nesc_hton_uint8(hdr->length.nxdata, length);
}

#line 78
  uint16_t sim_packet_length(sim_packet_t *msg)
#line 78
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 80
  return __nesc_ntoh_uint8(hdr->length.nxdata);
}

  void sim_packet_set_type(sim_packet_t *msg, uint8_t type)
#line 83
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 85
  __nesc_hton_uint8(hdr->type.nxdata, type);
}

  uint8_t sim_packet_type(sim_packet_t *msg)
#line 88
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 90
  return __nesc_ntoh_uint8(hdr->type.nxdata);
}

  uint8_t *sim_packet_data(sim_packet_t *p)
#line 93
{
  message_t *msg = (message_t *)p;

#line 95
  return (uint8_t *)& msg->data;
}

#line 97
  void sim_packet_set_strength(sim_packet_t *p, uint16_t str)
#line 97
{
  message_t *msg = (message_t *)p;
  tossim_metadata_t *md = (tossim_metadata_t *)& msg->metadata;

#line 100
  __nesc_hton_int8(md->strength.nxdata, str);
}

#line 102
  void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)
#line 102
{
  if (t < sim_time()) {
      t = sim_time();
    }
  sim_log_debug(45U, "Packet", "sim_packet.c: Delivering packet %p to %i at %llu\n", msg, node, t);
  active_message_deliver(node, (message_t *)msg, t);
}

# 254 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
  void active_message_deliver(int node, message_t *msg, sim_time_t t)
#line 254
{
  sim_event_t *evt = TossimActiveMessageC$allocate_deliver_event(node, msg, t);

#line 256
  sim_queue_insert(evt);
}

#line 109
static void TossimActiveMessageC$Model$receive(message_t *msg)
#line 109
{
  uint8_t len;
  void *payload;

  memcpy(TossimActiveMessageC$bufferPointer[sim_node()], msg, sizeof(message_t ));
  len = TossimActiveMessageC$Packet$payloadLength(TossimActiveMessageC$bufferPointer[sim_node()]);
  payload = TossimActiveMessageC$Packet$getPayload(TossimActiveMessageC$bufferPointer[sim_node()], TossimActiveMessageC$Packet$maxPayloadLength());

  if (TossimActiveMessageC$AMPacket$isForMe(msg)) {
      sim_log_debug(106U, "AM", "Received active message (%p) of type %hhu and length %hhu for me @ %s.\n", TossimActiveMessageC$bufferPointer[sim_node()], TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), len, sim_time_string());
      TossimActiveMessageC$bufferPointer[sim_node()] = TossimActiveMessageC$Receive$receive(TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), TossimActiveMessageC$bufferPointer[sim_node()], payload, len);
    }
  else {
      sim_log_debug(107U, "AM", "Snooped on active message of type %hhu and length %hhu for %hu @ %s.\n", TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), len, TossimActiveMessageC$AMPacket$destination(TossimActiveMessageC$bufferPointer[sim_node()]), sim_time_string());
      TossimActiveMessageC$bufferPointer[sim_node()] = TossimActiveMessageC$Snoop$receive(TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), TossimActiveMessageC$bufferPointer[sim_node()], payload, len);
    }
}

#line 140
static am_addr_t TossimActiveMessageC$AMPacket$destination(message_t *amsg)
#line 140
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 142
  return __nesc_ntoh_uint16(header->dest.nxdata);
}

# 76 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void )
#line 76
{
  if (!ActiveMessageAddressC$set[sim_node()]) {
      ActiveMessageAddressC$addr[sim_node()] = TOS_NODE_ID;
      ActiveMessageAddressC$set[sim_node()] = TRUE;
    }
  return ActiveMessageAddressC$addr[sim_node()];
}

# 165 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static am_id_t TossimActiveMessageC$AMPacket$type(message_t *amsg)
#line 165
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 167
  return __nesc_ntoh_uint8(header->type.nxdata);
}

# 144 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

#line 147
  timer->t0 = t0;
  timer->dt = dt;
  timer->isoneshot = isoneshot;
  timer->isrunning = TRUE;
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 205 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static error_t SimSchedulerBasicP$TaskBasic$postTask(uint8_t id)
{
  error_t result;

#line 208
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 208
    {
      result = SimSchedulerBasicP$pushTask(id) ? SUCCESS : EBUSY;
    }
#line 210
    __nesc_atomic_end(__nesc_atomic); }
  if (result == SUCCESS) {
      sim_log_debug(99U, "Scheduler", "Posting task %hhu.\n", id);
      SimSchedulerBasicP$sim_scheduler_submit_event();
    }
  else {
      sim_log_debug(100U, "Scheduler", "Posting task %hhu, but already posted.\n", id);
    }
  return result;
}

#line 77
static void SimSchedulerBasicP$sim_scheduler_submit_event(void )
#line 77
{
  if (SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] == FALSE) {
      SimSchedulerBasicP$sim_scheduler_event[sim_node()].time = sim_time() + SimSchedulerBasicP$sim_config_task_latency();
      sim_queue_insert(&SimSchedulerBasicP$sim_scheduler_event[sim_node()]);
      SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = TRUE;
    }
}

# 161 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void )
#line 161
{
  uint32_t now;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {


      uint8_t now8 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();

      if (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag().bits.ocf0) {


        now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() + 1 + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();
        }
      else {

        now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + now8;
        }
    }
#line 179
    __nesc_atomic_end(__nesc_atomic); }
#line 179
  return now;
}

# 282 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static uint8_t HplAtm128Timer0AsyncP$Timer0$get(void )
#line 282
{
  uint8_t rval;
  sim_time_t elapsed = sim_time() - HplAtm128Timer0AsyncP$last_zero();

#line 285
  elapsed = HplAtm128Timer0AsyncP$sim_to_clock(elapsed);
  elapsed = elapsed >> HplAtm128Timer0AsyncP$shiftFromScale();
  rval = (uint8_t )(elapsed & 0xff);
  sim_log_debug(177U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Getting timer: %hhu\n", rval);
  return rval;
}

#line 108
static sim_time_t HplAtm128Timer0AsyncP$last_zero(void )
#line 108
{
  if (HplAtm128Timer0AsyncP$lastZero[sim_node()] == 0) {
      HplAtm128Timer0AsyncP$lastZero[sim_node()] = sim_mote_start_time(sim_node());
    }
  return HplAtm128Timer0AsyncP$lastZero[sim_node()];
}

# 106 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_start_time(int mote)
#line 106
{
  long long int result;
  int tmp = sim_node();

#line 109
  sim_set_node(mote);
  result = SimMoteP$SimMote$getStartTime();
  sim_set_node(tmp);
  return result;
}

# 160 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void )
#line 160
{
  uint8_t scale = HplAtm128Timer0AsyncP$Timer0$getScale();

#line 162
  switch (scale) {
      case 0: 
        return 0;
      case 1: 
        return 0;
      case 2: 
        return 3;
      case 3: 
        return 5;
      case 4: 
        return 6;
      case 5: 
        return 7;
      case 6: 
        return 8;
      case 7: 
        return 10;
      default: 
        return 255;
    }
}

#line 321
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void )
#line 321
{
  return * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33] & 0x7;
}

#line 383
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void )
#line 383
{
  Atm128_TIFR_t at;

#line 385
  at.flat = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36];
  return at;
}

#line 457
static uint8_t HplAtm128Timer0AsyncP$Compare$get(void )
#line 457
{
  sim_log_debug(183U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Getting compare: %hhu\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31]);
  return * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31];
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer2$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(2U, dt);
#line 73
}
#line 73
# 110 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
  uint8_t sim_packet_max_length(sim_packet_t *msg)
#line 110
{
  return 28;
}

  sim_packet_t *sim_packet_allocate()
#line 114
{
  return (sim_packet_t *)malloc(sizeof(message_t ));
}

  void sim_packet_free(sim_packet_t *p)
#line 118
{
  printf("sim_packet.c: Freeing packet %p\n", p);
  free(p);
}

# 56 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim_serial_packet.c"
  void sim_serial_packet_set_destination(sim_serial_packet_t *msg, uint16_t dest)
#line 56
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 58
  __nesc_hton_uint16(hdr->dest.nxdata, dest);
}

    uint16_t sim_serial_packet_destination(sim_serial_packet_t *msg)
#line 61
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 63
  return __nesc_ntoh_uint16(hdr->dest.nxdata);
}

  void sim_serial_packet_set_source(sim_serial_packet_t *msg, uint16_t src)
#line 66
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 68
  __nesc_hton_uint16(hdr->src.nxdata, src);
}

    uint16_t sim_serial_packet_source(sim_serial_packet_t *msg)
#line 71
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 73
  return __nesc_ntoh_uint16(hdr->src.nxdata);
}

  void sim_serial_packet_set_length(sim_serial_packet_t *msg, uint8_t length)
#line 76
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 78
  __nesc_hton_uint8(hdr->length.nxdata, length);
}

#line 80
  uint16_t sim_serial_packet_length(sim_serial_packet_t *msg)
#line 80
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 82
  return __nesc_ntoh_uint8(hdr->length.nxdata);
}

  void sim_serial_packet_set_type(sim_serial_packet_t *msg, uint8_t type)
#line 85
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 87
  __nesc_hton_uint8(hdr->type.nxdata, type);
}

  uint8_t sim_serial_packet_type(sim_serial_packet_t *msg)
#line 90
{
  serial_header_t *hdr = getSerialHeader((message_t *)msg);

#line 92
  return __nesc_ntoh_uint8(hdr->type.nxdata);
}

  uint8_t *sim_serial_packet_data(sim_serial_packet_t *p)
#line 95
{
  message_t *msg = (message_t *)p;

#line 97
  return (uint8_t *)& msg->data;
}

  void sim_serial_packet_deliver(int node, sim_serial_packet_t *msg, sim_time_t t)
#line 100
{
  if (t < sim_time()) {
      t = sim_time();
    }
  sim_log_debug(46U, "Packet", "sim_serial_packet.c: Delivering packet %p to %i at %llu\n", msg, node, t);
  serial_active_message_deliver(node, (message_t *)msg, t);
}

# 293 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
  void serial_active_message_deliver(int node, message_t *msg, sim_time_t t)
#line 293
{
  sim_event_t *evt = SerialActiveMessageC$allocate_serial_deliver_event(node, msg, t);

#line 295
  sim_queue_insert(evt);
}

#line 237
static uint8_t SerialActiveMessageC$Packet$payloadLength(message_t *msg)
#line 237
{
  return __nesc_ntoh_uint8(SerialActiveMessageC$getHeader(msg)->length.nxdata);
}

#line 196
static am_id_t SerialActiveMessageC$AMPacket$type(message_t *amsg)
#line 196
{
  serial_header_t *header = SerialActiveMessageC$getHeader(amsg);

#line 198
  return __nesc_ntoh_uint8(header->type.nxdata);
}

# 108 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim_serial_packet.c"
  uint8_t sim_serial_packet_max_length(sim_serial_packet_t *msg)
#line 108
{
  return 28;
}

  sim_serial_packet_t *sim_serial_packet_allocate()
#line 112
{
  return (sim_serial_packet_t *)malloc(sizeof(message_t ));
}

  void sim_serial_packet_free(sim_serial_packet_t *p)
#line 116
{
  printf("sim_serial_packet.c: Freeing packet %p\n", p);
  free(p);
}

# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMainP.nc"
  int sim_main_start_mote(void )
#line 51
{
  char timeBuf[128];

#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    {






      SimMainP$Scheduler$init();





      SimMainP$PlatformInit$init();
      while (SimMainP$Scheduler$runNextTask()) ;





      SimMainP$SoftwareInit$init();
      while (SimMainP$Scheduler$runNextTask()) ;
    }
#line 75
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  sim_print_now(timeBuf, 128);
  sim_log_debug(95U, "SimMainP", "Mote %li signaling boot at time %s.\n", sim_node(), timeBuf);
  SimMainP$Boot$booted();





  return 0;
}

# 180 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static bool SimSchedulerBasicP$Scheduler$runNextTask(void )
{
  uint8_t nextTask;

#line 183
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      nextTask = SimSchedulerBasicP$popTask();
      if (nextTask == SimSchedulerBasicP$NO_TASK) 
        {
          sim_log_debug(97U, "Scheduler", "Told to run next task, but no task to run.\n");
          {
            unsigned char __nesc_temp = 
#line 189
            FALSE;

            {
#line 189
              __nesc_atomic_end(__nesc_atomic); 
#line 189
              return __nesc_temp;
            }
          }
        }
    }
#line 193
    __nesc_atomic_end(__nesc_atomic); }
#line 192
  sim_log_debug(98U, "Scheduler", "Running task %hhu.\n", nextTask);
  SimSchedulerBasicP$TaskBasic$runTask(nextTask);
  return TRUE;
}

# 163 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[sim_node()][last].msg = (void *)0;
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$tryToSend();
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$Send$sendDone(last, msg, err);
}

# 171 "/opt/tinyos-2.1.2/tos/lib/tossim/sf/sim/SerialActiveMessageC.nc"
static am_addr_t SerialActiveMessageC$AMPacket$destination(message_t *amsg)
#line 171
{
  serial_header_t *header = SerialActiveMessageC$getHeader(amsg);

#line 173
  return __nesc_ntoh_uint16(header->dest.nxdata);
}

#line 87
static error_t SerialActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len)
#line 89
{
  error_t err;
  serial_header_t *header = SerialActiveMessageC$getHeader(amsg);

  __nesc_hton_uint8(header->type.nxdata, id);
  __nesc_hton_uint16(header->dest.nxdata, addr);

  __nesc_hton_uint16(header->src.nxdata, TOS_NODE_ID);
  __nesc_hton_uint8(header->length.nxdata, len);
  err = SerialActiveMessageC$Model$send((int )addr, amsg, len + sizeof(serial_header_t ));
  return err;
}

# 657 "QueryPropagationC.nc"
static void QueryPropagationC$SamplingRadioAMSend$sendDone(message_t *msg, error_t err)
#line 657
{
  if (&QueryPropagationC$pkt[sim_node()] == msg) {
      QueryPropagationC$unicast_busy[sim_node()] = FALSE;

      QueryPropagationC$Leds$led2Off();
      QueryPropagationC$sampling_send[sim_node()]++;
      if (QueryPropagationC$sampling_send[sim_node()] > 30) {
          QueryPropagationC$sampling_send[sim_node()] = 0;
        }
    }
}

# 109 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static void LedsP$Leds$led2Off(void )
#line 109
{
  LedsP$Led2$set();
  sim_log_debug(161U, "LedsC", "LEDS: Led""2"" %s.\n", LedsP$Led2$get() ? "off" : "on");
#line 111
  ;
}

# 645 "QueryPropagationC.nc"
static void QueryPropagationC$RadioAMSend$sendDone(message_t *msg, error_t err)
#line 645
{
  if (&QueryPropagationC$pkt[sim_node()] == msg) {
      QueryPropagationC$busy[sim_node()] = FALSE;

      QueryPropagationC$Leds$led1Off();
      QueryPropagationC$send[sim_node()]++;
      if (QueryPropagationC$send[sim_node()] > 30) {
          QueryPropagationC$send[sim_node()] = 0;
        }
    }
}

# 94 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static void LedsP$Leds$led1Off(void )
#line 94
{
  LedsP$Led1$set();
  sim_log_debug(158U, "LedsC", "LEDS: Led""1"" %s.\n", LedsP$Led1$get() ? "off" : "on");
#line 96
  ;
}

# 163 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg = (void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend();
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, err);
}

# 73 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static error_t TossimActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len)
#line 75
{
  error_t err;
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 78
  sim_log_debug(105U, "AM", "AM: Sending packet (id=%hhu, len=%hhu) to %hu\n", id, len, addr);
  __nesc_hton_uint8(header->type.nxdata, id);
  __nesc_hton_uint16(header->dest.nxdata, addr);
  __nesc_hton_uint16(header->src.nxdata, TossimActiveMessageC$AMPacket$address());
  __nesc_hton_uint8(header->length.nxdata, len);
  err = TossimActiveMessageC$Model$send((int )addr, amsg, len + sizeof(tossim_header_t ) + sizeof(tossim_footer_t ));
  return err;
}

# 274 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg)
#line 274
{
  double noise = CpmModelC$noise_hash_generation();
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

#line 277
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  return noise;
}

#line 126
static double CpmModelC$noise_hash_generation(void )
#line 126
{
  double CT = CpmModelC$timeInMs();
  uint32_t quotient = (sim_time_t )(CT * 10) / 10;
  uint8_t remain = (uint8_t )((sim_time_t )(CT * 10) % 10);
  double noise_val;
  uint16_t node_id = sim_node();

  sim_log_debug(123U, "CpmModelC", "IN: noise_hash_generation()\n");
  if (5 <= remain && remain < 10) {
      noise_val = (double )sim_noise_generate(node_id, quotient + 1);
    }
  else {
      noise_val = (double )sim_noise_generate(node_id, quotient);
    }
  sim_log_debug(124U, "CpmModelC,Tal", "%s: OUT: noise_hash_generation(): %lf\n", sim_time_string(), noise_val);

  return noise_val;
}

# 189 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] >= 2) {
      return;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg == msg) {
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()], msg, err);
    }
  else {
      sim_log_debug(209U, "PointerBug", "%s received send done for %p, signaling for %p.\n", __FUNCTION__, msg, /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg);
    }
}

# 248 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static bool CpmModelC$shouldReceive(double SNR)
#line 248
{
  double prr = CpmModelC$prr_estimate_from_snr(SNR);
  double coin = RandomUniform();

#line 251
  if (prr >= 0 && prr <= 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 255
        prr = 0.0;
        }
    }
#line 257
  return prr;
}

# 307 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg)
#line 307
{
  if (TossimPacketModelC$running[sim_node()] && !TossimPacketModelC$transmitting[sim_node()]) {
      return TossimPacketModelC$Packet$shouldAck(msg);
    }
  else {
      return FALSE;
    }
}

# 216 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static void CpmModelC$sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC$receive_message_t *r)
#line 216
{
  sim_event_t *ackEvent = (sim_event_t *)malloc(sizeof(sim_event_t ));

  ackEvent->mote = source;
  ackEvent->force = 1;
  ackEvent->cancelled = 0;
  ackEvent->time = t;
  ackEvent->handle = CpmModelC$sim_gain_ack_handle;
  ackEvent->cleanup = sim_queue_cleanup_event;
  ackEvent->data = r;

  sim_queue_insert(ackEvent);
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void QueryPropagationC$Timer1$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(1U, dt);
#line 73
}
#line 73
#line 136
static uint32_t QueryPropagationC$Timer3$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$getNow(3U);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
#line 73
static void QueryPropagationC$Timer3$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(3U, dt);
#line 73
}
#line 73
static void QueryPropagationC$Timer0$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(0U, dt);
#line 73
}
#line 73
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now)
{
  uint16_t num;

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;

          if (elapsed >= timer->dt) 
            {
              if (timer->isoneshot) {
                timer->isrunning = FALSE;
                }
              else {
#line 90
                timer->t0 += timer->dt;
                }
              /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(num);
              break;
            }
        }
    }
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static error_t /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setDestination(msg, dest);
  /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setType(msg, 36);
  return /*QueryPropagationAppC.SamplingAMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$send(msg, len);
}

# 145 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static void TossimActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr)
#line 145
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 147
  __nesc_hton_uint16(header->dest.nxdata, addr);
}

#line 170
static void TossimActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t)
#line 170
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 172
  __nesc_hton_uint8(header->type.nxdata, t);
}

# 90 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 2) {
      return FAIL;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg != (void *)0) {
      return EBUSY;
    }
  sim_log_debug(205U, "AMQueue", "AMQueue: request to send from %hhu (%p): passed checks\n", clientId, msg);

  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg = msg;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(msg, len);

  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] >= 2) {
      error_t err;
      am_id_t amId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(msg);
      am_addr_t dest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(msg);

      sim_log_debug(206U, "AMQueue", "%s: request to send from %hhu (%p): queue empty\n", __FUNCTION__, clientId, msg);
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = clientId;

      err = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(amId, dest, msg, len);
      if (err != SUCCESS) {
          sim_log_debug(207U, "AMQueue", "%s: underlying send failed.\n", __FUNCTION__);
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = 2;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg = (void *)0;
        }

      return err;
    }
  else {
      sim_log_debug(208U, "AMQueue", "AMQueue: request to send from %hhu (%p): queue not empty\n", clientId, msg);
    }
  return SUCCESS;
}

# 104 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static void LedsP$Leds$led2On(void )
#line 104
{
  LedsP$Led2$clr();
  sim_log_debug(160U, "LedsC", "LEDS: Led""2"" %s.\n", LedsP$Led2$get() ? "off" : "on");
#line 106
  ;
}

#line 79
static void LedsP$Leds$led0Off(void )
#line 79
{
  LedsP$Led0$set();
  sim_log_debug(155U, "LedsC", "LEDS: Led""0"" %s.\n", LedsP$Led0$get() ? "off" : "on");
#line 81
  ;
}

# 212 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(uint32_t nt0, uint32_t ndt)
#line 212
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = TRUE;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] = nt0;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()] = ndt;
    }
#line 218
    __nesc_atomic_end(__nesc_atomic); }
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
}

#line 90
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void )
#line 90
{
  bool fired = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {



      uint8_t interrupt_in = 1 + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();
      uint8_t newOcr0;
      uint8_t tifr = (uint8_t )/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag().flat;

#line 101
      sim_log_debug(163U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: TIFR is %hhx\n", tifr);
      if ((interrupt_in != 0 && interrupt_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) || tifr & (1 << OCF0)) {
          if (interrupt_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) {
              sim_log_debug(164U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: under min: %hhu.\n", interrupt_in);
            }
          else {
              sim_log_debug(165U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: OCF set.\n");
            }
          {
#line 109
            __nesc_atomic_end(__nesc_atomic); 
#line 109
            return;
          }
        }

      if (!/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()]) {
          newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
          sim_log_debug(166U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: no alarm set, set at max.\n");
        }
      else 
        {
          uint32_t now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get();

#line 120
          sim_log_debug(167U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: now-t0 = %llu, dt = %llu\n", now - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()], /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()]);

          if ((uint32_t )(now - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()]) >= /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()]) 
            {
              /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = FALSE;
              fired = TRUE;
              newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
            }
          else 
            {


              uint32_t alarm_in = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()] - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()];

              if (alarm_in > /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT) {
                newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
                }
              else {
#line 136
                if ((uint8_t )alarm_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) {
                  newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT;
                  }
                else {
#line 139
                  newOcr0 = alarm_in;
                  }
                }
            }
        }
#line 142
      newOcr0--;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(newOcr0);
    }
#line 144
    __nesc_atomic_end(__nesc_atomic); }
  if (fired) {
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired();
    }
}

# 463 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static void HplAtm128Timer0AsyncP$Compare$set(uint8_t t)
#line 463
{
  sim_log_debug(184U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Setting compare: %hhu\n", t);
  /* atomic removed: atomic calls only */
#line 465
  {




    if (t == 0 || t >= 0xfe) {
      t = 1;
      }
    if (t != * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31]) {
        * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31] = t;
        HplAtm128Timer0AsyncP$schedule_new_compare();
      }
  }
}

#line 267
static void HplAtm128Timer0AsyncP$schedule_new_compare(void )
#line 267
{
  if (HplAtm128Timer0AsyncP$compare[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$cancel_compare();
    }
  if (HplAtm128Timer0AsyncP$Timer0$getScale() != AVR_CLOCK_OFF) {
      sim_event_t *newEvent = HplAtm128Timer0AsyncP$allocate_compare();

#line 273
      HplAtm128Timer0AsyncP$configure_compare(newEvent);

      HplAtm128Timer0AsyncP$compare[sim_node()] = newEvent;
      sim_queue_insert(newEvent);
    }
}

# 97 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
static sim_event_t *sim_queue_allocate_event()
#line 97
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 99
  memset(evt, 0, sizeof(sim_event_t ));
  evt->mote = sim_node();
  return evt;
}

# 100 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
  void INTERRUPT_16(void )
#line 100
{
  HplAtm128Timer0AsyncP$inOverflow[sim_node()] = TRUE;
  HplAtm128Timer0AsyncP$Timer0$overflow();
  HplAtm128Timer0AsyncP$inOverflow[sim_node()] = FALSE;
}

#line 508
static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *evt)
#line 508
{
  sim_time_t overflowTime = 0;
  uint8_t timerVal = HplAtm128Timer0AsyncP$Timer0$get();
  uint8_t overflowVal = 0;




  overflowTime = (overflowVal - timerVal) & 0xff;
  if (overflowTime == 0) {
      overflowTime = 256;
    }




  overflowTime = overflowTime << HplAtm128Timer0AsyncP$shiftFromScale();
  overflowTime = HplAtm128Timer0AsyncP$clock_to_sim(overflowTime);
  overflowTime += sim_time();
  overflowTime -= (sim_time() - HplAtm128Timer0AsyncP$last_zero()) % (1 << HplAtm128Timer0AsyncP$shiftFromScale());

  sim_log_debug(187U, "HplAtm128Timer0AsyncP", "Scheduling new overflow for %i at time %llu\n", sim_node(), overflowTime);

  evt->time = overflowTime;
}

#line 94
  void INTERRUPT_15(void )
#line 94
{

  HplAtm128Timer0AsyncP$Compare$fired();
}

#line 231
static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *evt)
#line 231
{
  sim_time_t compareTime = 0;
  sim_time_t phaseOffset = 0;
  uint8_t timerVal = HplAtm128Timer0AsyncP$Timer0$get();
  uint8_t compareVal = HplAtm128Timer0AsyncP$Compare$get();




  compareTime = (compareVal - timerVal) & 0xff;
  if (compareTime == 0) {
      compareTime = 256;
    }






  compareTime = (compareTime + 1) << HplAtm128Timer0AsyncP$shiftFromScale();
  compareTime = HplAtm128Timer0AsyncP$clock_to_sim(compareTime);
  compareTime += sim_time();




  phaseOffset = sim_time();
  phaseOffset -= HplAtm128Timer0AsyncP$last_zero();
  phaseOffset %= HplAtm128Timer0AsyncP$clock_to_sim(1 << HplAtm128Timer0AsyncP$shiftFromScale());
  compareTime -= phaseOffset;

  sim_log_debug(176U, "HplAtm128Timer0AsyncP", "Configuring new compare of %i for %i at time %llu  (@ %llu)\n", (int )compareVal, sim_node(), compareTime, sim_time());

  evt->time = compareTime;
}

# 106 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static error_t TossimPacketModelC$Control$start(void )
#line 106
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(111U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called before initialization!\n");
      return FAIL;
    }
  sim_log_debug(112U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called.\n");
  TossimPacketModelC$startDoneTask$postTask();
  return SUCCESS;
}

# 90 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_euid(int mote)
#line 90
{
  long long int result;
  int tmp = sim_node();

#line 93
  sim_set_node(mote);
  result = SimMoteP$SimMote$getEuid();
  sim_set_node(tmp);
  return result;
}

  void sim_mote_set_euid(int mote, long long int id)
#line 99
{
  int tmp = sim_node();

#line 101
  sim_set_node(mote);
  SimMoteP$SimMote$setEuid(id);
  sim_set_node(tmp);
}










  int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)
#line 115
{
  int result;
  int tmpID = sim_node();

#line 118
  sim_set_node(mote);
  result = SimMoteP$SimMote$getVariableInfo(name, ptr, len);
  sim_log_debug(102U, "SimMoteP", "Fetched %s of %i to be %p with len %i (result %i)\n", name, mote, *ptr, *len, result);
  sim_set_node(tmpID);
  return result;
}

  void sim_mote_set_start_time(int mote, long long int t)
#line 125
{
  int tmpID = sim_node();

#line 127
  sim_set_node(mote);
  SimMoteP$startTime[sim_node()] = t;
  sim_log_debug(103U, "SimMoteP", "Setting start time to %llu\n", SimMoteP$startTime[sim_node()]);
  sim_set_node(tmpID);
  return;
}










  void sim_mote_turn_on(int mote)
#line 143
{
  int tmp = sim_node();

#line 145
  sim_set_node(mote);
  SimMoteP$SimMote$turnOn();
  sim_set_node(tmp);
}

#line 72
static void SimMoteP$SimMote$turnOn(void )
#line 72
{
  if (!SimMoteP$isOn[sim_node()]) {
      if (SimMoteP$bootEvent[sim_node()] != (void *)0) {
          SimMoteP$bootEvent[sim_node()]->cancelled = TRUE;
        }
      __nesc_nido_initialise(sim_node());
      SimMoteP$startTime[sim_node()] = sim_time();
      sim_log_debug(101U, "SimMoteP", "Setting start time to %llu\n", SimMoteP$startTime[sim_node()]);
      SimMoteP$isOn[sim_node()] = TRUE;
      sim_main_start_mote();
    }
}

#line 150
  void sim_mote_turn_off(int mote)
#line 150
{
  int tmp = sim_node();

#line 152
  sim_set_node(mote);
  SimMoteP$SimMote$turnOff();
  sim_set_node(tmp);
}










  void sim_mote_enqueue_boot_event(int mote)
#line 166
{
  int tmp = sim_node();

#line 168
  sim_set_node(mote);

  if (SimMoteP$bootEvent[sim_node()] != (void *)0) {
      if (SimMoteP$bootEvent[sim_node()]->time == SimMoteP$startTime[sim_node()]) {

          SimMoteP$bootEvent[sim_node()]->cancelled = FALSE;
          return;
        }
      else {
          SimMoteP$bootEvent[sim_node()]->cancelled = TRUE;
        }
    }

  SimMoteP$bootEvent[sim_node()] = (sim_event_t *)malloc(sizeof(sim_event_t ));
  SimMoteP$bootEvent[sim_node()]->time = SimMoteP$startTime[sim_node()];
  SimMoteP$bootEvent[sim_node()]->mote = mote;
  SimMoteP$bootEvent[sim_node()]->force = TRUE;
  SimMoteP$bootEvent[sim_node()]->data = (void *)0;
  SimMoteP$bootEvent[sim_node()]->handle = SimMoteP$sim_mote_boot_handle;
  SimMoteP$bootEvent[sim_node()]->cleanup = sim_queue_cleanup_event;
  sim_queue_insert(SimMoteP$bootEvent[sim_node()]);

  sim_set_node(tmp);
}

/* Nido variable resolver function */

static int __nesc_nido_resolve(int __nesc_mote,
                               char* varname,
                               uintptr_t* addr, size_t* size)
{
  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP$0 */

  /* Module HplAtm128GeneralIOPinP$1 */

  /* Module HplAtm128GeneralIOPinP$2 */

  /* Module HplAtm128GeneralIOPinP$3 */

  /* Module HplAtm128GeneralIOPinP$4 */

  /* Module HplAtm128GeneralIOPinP$5 */

  /* Module HplAtm128GeneralIOPinP$6 */

  /* Module HplAtm128GeneralIOPinP$7 */

  /* Module HplAtm128GeneralIOPinP$8 */

  /* Module HplAtm128GeneralIOPinP$9 */

  /* Module HplAtm128GeneralIOPinP$10 */

  /* Module HplAtm128GeneralIOPinP$11 */

  /* Module HplAtm128GeneralIOPinP$12 */

  /* Module HplAtm128GeneralIOPinP$13 */

  /* Module HplAtm128GeneralIOPinP$14 */

  /* Module HplAtm128GeneralIOPinP$15 */

  /* Module HplAtm128GeneralIOPinP$16 */

  /* Module HplAtm128GeneralIOPinP$17 */

  /* Module HplAtm128GeneralIOPinP$18 */

  /* Module HplAtm128GeneralIOPinP$19 */

  /* Module HplAtm128GeneralIOPinP$20 */

  /* Module HplAtm128GeneralIOPinP$21 */

  /* Module HplAtm128GeneralIOPinP$22 */

  /* Module HplAtm128GeneralIOPinP$23 */

  /* Module HplAtm128GeneralIOPinP$24 */

  /* Module HplAtm128GeneralIOPinP$25 */

  /* Module HplAtm128GeneralIOPinP$26 */

  /* Module HplAtm128GeneralIOPinP$27 */

  /* Module HplAtm128GeneralIOPinP$28 */

  /* Module HplAtm128GeneralIOPinP$29 */

  /* Module HplAtm128GeneralIOPinP$30 */

  /* Module HplAtm128GeneralIOPinP$31 */

  /* Module HplAtm128GeneralIOPinP$32 */

  /* Module HplAtm128GeneralIOPinP$33 */

  /* Module HplAtm128GeneralIOPinP$34 */

  /* Module HplAtm128GeneralIOPinP$35 */

  /* Module HplAtm128GeneralIOPinP$36 */

  /* Module HplAtm128GeneralIOPinP$37 */

  /* Module HplAtm128GeneralIOPinP$38 */

  /* Module HplAtm128GeneralIOPinP$39 */

  /* Module HplAtm128GeneralIOPinP$40 */

  /* Module HplAtm128GeneralIOPinP$41 */

  /* Module HplAtm128GeneralIOPinP$42 */

  /* Module HplAtm128GeneralIOPinP$43 */

  /* Module HplAtm128GeneralIOPinP$44 */

  /* Module HplAtm128GeneralIOPinP$45 */

  /* Module HplAtm128GeneralIOPinP$46 */

  /* Module HplAtm128GeneralIOPinP$47 */

  /* Module HplAtm128GeneralIOSlowPinP$0 */

  /* Module HplAtm128GeneralIOSlowPinP$1 */

  /* Module HplAtm128GeneralIOSlowPinP$2 */

  /* Module HplAtm128GeneralIOSlowPinP$3 */

  /* Module HplAtm128GeneralIOSlowPinP$4 */

  /* Module HplAtm128GeneralIOSlowPinP$5 */

  /* Module HplAtm128GeneralIOSlowPinP$6 */

  /* Module HplAtm128GeneralIOSlowPinP$7 */

  /* Module HplAtm128GeneralIOSlowPinP$8 */

  /* Module HplAtm128GeneralIOSlowPinP$9 */

  /* Module HplAtm128GeneralIOSlowPinP$10 */

  /* Module HplAtm128GeneralIOSlowPinP$11 */

  /* Module HplAtm128GeneralIOSlowPinP$12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  if (!strcmp(varname, "SimSchedulerBasicP$m_head"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_head[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_head[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$m_tail"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_tail[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_tail[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$m_next"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_next[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_next[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$sim_scheduler_event_pending"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$sim_scheduler_event"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$sim_scheduler_event[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$sim_scheduler_event[__nesc_mote]);
    return 0;
  }

  /* Module SimMoteP */
  if (!strcmp(varname, "SimMoteP$euid"))
  {
    *addr = (uintptr_t)&SimMoteP$euid[__nesc_mote];
    *size = sizeof(SimMoteP$euid[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$startTime"))
  {
    *addr = (uintptr_t)&SimMoteP$startTime[__nesc_mote];
    *size = sizeof(SimMoteP$startTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$isOn"))
  {
    *addr = (uintptr_t)&SimMoteP$isOn[__nesc_mote];
    *size = sizeof(SimMoteP$isOn[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$bootEvent"))
  {
    *addr = (uintptr_t)&SimMoteP$bootEvent[__nesc_mote];
    *size = sizeof(SimMoteP$bootEvent[__nesc_mote]);
    return 0;
  }

  /* Module TossimActiveMessageC */
  if (!strcmp(varname, "TossimActiveMessageC$buffer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC$buffer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC$buffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimActiveMessageC$bufferPointer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC$bufferPointer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC$bufferPointer[__nesc_mote]);
    return 0;
  }

  /* Module TossimPacketModelC */
  if (!strcmp(varname, "TossimPacketModelC$initialized"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$initialized[__nesc_mote];
    *size = sizeof(TossimPacketModelC$initialized[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$running"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$running[__nesc_mote];
    *size = sizeof(TossimPacketModelC$running[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$backoffCount"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$backoffCount[__nesc_mote];
    *size = sizeof(TossimPacketModelC$backoffCount[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$neededFreeSamples"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$neededFreeSamples[__nesc_mote];
    *size = sizeof(TossimPacketModelC$neededFreeSamples[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sending"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sending[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$transmitting"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$transmitting[__nesc_mote];
    *size = sizeof(TossimPacketModelC$transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sendingLength"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sendingLength[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sendingLength[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$destNode"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$destNode[__nesc_mote];
    *size = sizeof(TossimPacketModelC$destNode[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sendEvent"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sendEvent[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sendEvent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$error"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$error[__nesc_mote];
    *size = sizeof(TossimPacketModelC$error[__nesc_mote]);
    return 0;
  }

  /* Module CpmModelC */
  if (!strcmp(varname, "CpmModelC$outgoing"))
  {
    *addr = (uintptr_t)&CpmModelC$outgoing[__nesc_mote];
    *size = sizeof(CpmModelC$outgoing[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$requestAck"))
  {
    *addr = (uintptr_t)&CpmModelC$requestAck[__nesc_mote];
    *size = sizeof(CpmModelC$requestAck[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$receiving"))
  {
    *addr = (uintptr_t)&CpmModelC$receiving[__nesc_mote];
    *size = sizeof(CpmModelC$receiving[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$transmitting"))
  {
    *addr = (uintptr_t)&CpmModelC$transmitting[__nesc_mote];
    *size = sizeof(CpmModelC$transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$transmissionEndTime"))
  {
    *addr = (uintptr_t)&CpmModelC$transmissionEndTime[__nesc_mote];
    *size = sizeof(CpmModelC$transmissionEndTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$outstandingReceptionHead"))
  {
    *addr = (uintptr_t)&CpmModelC$outstandingReceptionHead[__nesc_mote];
    *size = sizeof(CpmModelC$outstandingReceptionHead[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$clearThreshold"))
  {
    *addr = (uintptr_t)&CpmModelC$clearThreshold[__nesc_mote];
    *size = sizeof(CpmModelC$clearThreshold[__nesc_mote]);
    return 0;
  }

  /* Module ActiveMessageAddressC */
  if (!strcmp(varname, "ActiveMessageAddressC$set"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC$set[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC$set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "ActiveMessageAddressC$addr"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC$addr[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC$addr[__nesc_mote]);
    return 0;
  }

  /* Module SerialActiveMessageC */
  if (!strcmp(varname, "SerialActiveMessageC$buffer"))
  {
    *addr = (uintptr_t)&SerialActiveMessageC$buffer[__nesc_mote];
    *size = sizeof(SerialActiveMessageC$buffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SerialActiveMessageC$bufferPointer"))
  {
    *addr = (uintptr_t)&SerialActiveMessageC$bufferPointer[__nesc_mote];
    *size = sizeof(SerialActiveMessageC$bufferPointer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SerialActiveMessageC$sendMsgPtr"))
  {
    *addr = (uintptr_t)&SerialActiveMessageC$sendMsgPtr[__nesc_mote];
    *size = sizeof(SerialActiveMessageC$sendMsgPtr[__nesc_mote]);
    return 0;
  }

  /* Module LedsP */

  /* Module Atm128AlarmAsyncP$0 */
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote]);
    return 0;
  }

  /* Module HplAtm128Timer0AsyncP */
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$inOverflow"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$inOverflow[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$inOverflow[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$lastZero"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$lastZero[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$lastZero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$oldScale"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$oldScale[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$oldScale[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$compare"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$compare[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$compare[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$overflow"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$overflow[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$overflow[__nesc_mote]);
    return 0;
  }

  /* Module AlarmToTimerC$0 */
  if (!strcmp(varname, "/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote]);
    return 0;
  }

  /* Module VirtualizeTimerC$0 */
  if (!strcmp(varname, "/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote]);
    return 0;
  }

  /* Module CounterToLocalTimeC$0 */

  /* Module ConstantSensorC$0 */

  /* Module QueryPropagationC */
  if (!strcmp(varname, "QueryPropagationC$r_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$r_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$r_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$bcast_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$bcast_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$bcast_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$r_sampling_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$r_sampling_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$r_sampling_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$s_sampling_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$s_sampling_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$s_sampling_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$ucast_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$ucast_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$ucast_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$s_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$s_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$s_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$serial_pkt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$serial_pkt[__nesc_mote];
    *size = sizeof(QueryPropagationC$serial_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sequence_number"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sequence_number[__nesc_mote];
    *size = sizeof(QueryPropagationC$sequence_number[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$send"))
  {
    *addr = (uintptr_t)&QueryPropagationC$send[__nesc_mote];
    *size = sizeof(QueryPropagationC$send[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$save"))
  {
    *addr = (uintptr_t)&QueryPropagationC$save[__nesc_mote];
    *size = sizeof(QueryPropagationC$save[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sampling_send"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sampling_send[__nesc_mote];
    *size = sizeof(QueryPropagationC$sampling_send[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sampling_save"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sampling_save[__nesc_mote];
    *size = sizeof(QueryPropagationC$sampling_save[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$number_Of_queries"))
  {
    *addr = (uintptr_t)&QueryPropagationC$number_Of_queries[__nesc_mote];
    *size = sizeof(QueryPropagationC$number_Of_queries[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$next"))
  {
    *addr = (uintptr_t)&QueryPropagationC$next[__nesc_mote];
    *size = sizeof(QueryPropagationC$next[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$count_contributed_nodes"))
  {
    *addr = (uintptr_t)&QueryPropagationC$count_contributed_nodes[__nesc_mote];
    *size = sizeof(QueryPropagationC$count_contributed_nodes[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$t0"))
  {
    *addr = (uintptr_t)&QueryPropagationC$t0[__nesc_mote];
    *size = sizeof(QueryPropagationC$t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$dt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$dt[__nesc_mote];
    *size = sizeof(QueryPropagationC$dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$start"))
  {
    *addr = (uintptr_t)&QueryPropagationC$start[__nesc_mote];
    *size = sizeof(QueryPropagationC$start[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$HoldTimer"))
  {
    *addr = (uintptr_t)&QueryPropagationC$HoldTimer[__nesc_mote];
    *size = sizeof(QueryPropagationC$HoldTimer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$query_pos"))
  {
    *addr = (uintptr_t)&QueryPropagationC$query_pos[__nesc_mote];
    *size = sizeof(QueryPropagationC$query_pos[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$minQuery"))
  {
    *addr = (uintptr_t)&QueryPropagationC$minQuery[__nesc_mote];
    *size = sizeof(QueryPropagationC$minQuery[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$expiredQuery"))
  {
    *addr = (uintptr_t)&QueryPropagationC$expiredQuery[__nesc_mote];
    *size = sizeof(QueryPropagationC$expiredQuery[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sendQuery"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sendQuery[__nesc_mote];
    *size = sizeof(QueryPropagationC$sendQuery[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$runningTime"))
  {
    *addr = (uintptr_t)&QueryPropagationC$runningTime[__nesc_mote];
    *size = sizeof(QueryPropagationC$runningTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$checkTimer"))
  {
    *addr = (uintptr_t)&QueryPropagationC$checkTimer[__nesc_mote];
    *size = sizeof(QueryPropagationC$checkTimer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$timerStartAt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$timerStartAt[__nesc_mote];
    *size = sizeof(QueryPropagationC$timerStartAt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$time4MeasurementStartAt"))
  {
    *addr = (uintptr_t)&QueryPropagationC$time4MeasurementStartAt[__nesc_mote];
    *size = sizeof(QueryPropagationC$time4MeasurementStartAt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$Hold_Sampling_Timer"))
  {
    *addr = (uintptr_t)&QueryPropagationC$Hold_Sampling_Timer[__nesc_mote];
    *size = sizeof(QueryPropagationC$Hold_Sampling_Timer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$minPeriod"))
  {
    *addr = (uintptr_t)&QueryPropagationC$minPeriod[__nesc_mote];
    *size = sizeof(QueryPropagationC$minPeriod[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sendTofather"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sendTofather[__nesc_mote];
    *size = sizeof(QueryPropagationC$sendTofather[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sensor_data"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sensor_data[__nesc_mote];
    *size = sizeof(QueryPropagationC$sensor_data[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$source_id"))
  {
    *addr = (uintptr_t)&QueryPropagationC$source_id[__nesc_mote];
    *size = sizeof(QueryPropagationC$source_id[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$sequence_number"))
  {
    *addr = (uintptr_t)&QueryPropagationC$sequence_number[__nesc_mote];
    *size = sizeof(QueryPropagationC$sequence_number[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$data_id"))
  {
    *addr = (uintptr_t)&QueryPropagationC$data_id[__nesc_mote];
    *size = sizeof(QueryPropagationC$data_id[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$s_data_id"))
  {
    *addr = (uintptr_t)&QueryPropagationC$s_data_id[__nesc_mote];
    *size = sizeof(QueryPropagationC$s_data_id[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$forwarder_id"))
  {
    *addr = (uintptr_t)&QueryPropagationC$forwarder_id[__nesc_mote];
    *size = sizeof(QueryPropagationC$forwarder_id[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$destination_id"))
  {
    *addr = (uintptr_t)&QueryPropagationC$destination_id[__nesc_mote];
    *size = sizeof(QueryPropagationC$destination_id[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$busy"))
  {
    *addr = (uintptr_t)&QueryPropagationC$busy[__nesc_mote];
    *size = sizeof(QueryPropagationC$busy[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$unicast_busy"))
  {
    *addr = (uintptr_t)&QueryPropagationC$unicast_busy[__nesc_mote];
    *size = sizeof(QueryPropagationC$unicast_busy[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$serial_busy"))
  {
    *addr = (uintptr_t)&QueryPropagationC$serial_busy[__nesc_mote];
    *size = sizeof(QueryPropagationC$serial_busy[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$TimeToMeasure"))
  {
    *addr = (uintptr_t)&QueryPropagationC$TimeToMeasure[__nesc_mote];
    *size = sizeof(QueryPropagationC$TimeToMeasure[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$PacketBuffer"))
  {
    *addr = (uintptr_t)&QueryPropagationC$PacketBuffer[__nesc_mote];
    *size = sizeof(QueryPropagationC$PacketBuffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$SamplingPacketBuffer"))
  {
    *addr = (uintptr_t)&QueryPropagationC$SamplingPacketBuffer[__nesc_mote];
    *size = sizeof(QueryPropagationC$SamplingPacketBuffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$AQQ"))
  {
    *addr = (uintptr_t)&QueryPropagationC$AQQ[__nesc_mote];
    *size = sizeof(QueryPropagationC$AQQ[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "QueryPropagationC$QuerySendersHistory"))
  {
    *addr = (uintptr_t)&QueryPropagationC$QuerySendersHistory[__nesc_mote];
    *size = sizeof(QueryPropagationC$QuerySendersHistory[__nesc_mote]);
    return 0;
  }

  /* Module AMQueueEntryP$0 */

  /* Module AMQueueImplP$0 */
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote]);
    return 0;
  }

  /* Module AMQueueEntryP$1 */

  /* Module AMQueueEntryP$2 */

  /* Module AMQueueImplP$1 */
  if (!strcmp(varname, "/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current"))
  {
    *addr = (uintptr_t)&/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[__nesc_mote];
    *size = sizeof(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue"))
  {
    *addr = (uintptr_t)&/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[__nesc_mote];
    *size = sizeof(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask"))
  {
    *addr = (uintptr_t)&/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[__nesc_mote];
    *size = sizeof(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[__nesc_mote]);
    return 0;
  }

  return -1;
}
/* Invoke static initialisers for mote '__nesc_mote' */

static void __nesc_nido_initialise(int __nesc_mote)
{
  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP$0 */

  /* Module HplAtm128GeneralIOPinP$1 */

  /* Module HplAtm128GeneralIOPinP$2 */

  /* Module HplAtm128GeneralIOPinP$3 */

  /* Module HplAtm128GeneralIOPinP$4 */

  /* Module HplAtm128GeneralIOPinP$5 */

  /* Module HplAtm128GeneralIOPinP$6 */

  /* Module HplAtm128GeneralIOPinP$7 */

  /* Module HplAtm128GeneralIOPinP$8 */

  /* Module HplAtm128GeneralIOPinP$9 */

  /* Module HplAtm128GeneralIOPinP$10 */

  /* Module HplAtm128GeneralIOPinP$11 */

  /* Module HplAtm128GeneralIOPinP$12 */

  /* Module HplAtm128GeneralIOPinP$13 */

  /* Module HplAtm128GeneralIOPinP$14 */

  /* Module HplAtm128GeneralIOPinP$15 */

  /* Module HplAtm128GeneralIOPinP$16 */

  /* Module HplAtm128GeneralIOPinP$17 */

  /* Module HplAtm128GeneralIOPinP$18 */

  /* Module HplAtm128GeneralIOPinP$19 */

  /* Module HplAtm128GeneralIOPinP$20 */

  /* Module HplAtm128GeneralIOPinP$21 */

  /* Module HplAtm128GeneralIOPinP$22 */

  /* Module HplAtm128GeneralIOPinP$23 */

  /* Module HplAtm128GeneralIOPinP$24 */

  /* Module HplAtm128GeneralIOPinP$25 */

  /* Module HplAtm128GeneralIOPinP$26 */

  /* Module HplAtm128GeneralIOPinP$27 */

  /* Module HplAtm128GeneralIOPinP$28 */

  /* Module HplAtm128GeneralIOPinP$29 */

  /* Module HplAtm128GeneralIOPinP$30 */

  /* Module HplAtm128GeneralIOPinP$31 */

  /* Module HplAtm128GeneralIOPinP$32 */

  /* Module HplAtm128GeneralIOPinP$33 */

  /* Module HplAtm128GeneralIOPinP$34 */

  /* Module HplAtm128GeneralIOPinP$35 */

  /* Module HplAtm128GeneralIOPinP$36 */

  /* Module HplAtm128GeneralIOPinP$37 */

  /* Module HplAtm128GeneralIOPinP$38 */

  /* Module HplAtm128GeneralIOPinP$39 */

  /* Module HplAtm128GeneralIOPinP$40 */

  /* Module HplAtm128GeneralIOPinP$41 */

  /* Module HplAtm128GeneralIOPinP$42 */

  /* Module HplAtm128GeneralIOPinP$43 */

  /* Module HplAtm128GeneralIOPinP$44 */

  /* Module HplAtm128GeneralIOPinP$45 */

  /* Module HplAtm128GeneralIOPinP$46 */

  /* Module HplAtm128GeneralIOPinP$47 */

  /* Module HplAtm128GeneralIOSlowPinP$0 */

  /* Module HplAtm128GeneralIOSlowPinP$1 */

  /* Module HplAtm128GeneralIOSlowPinP$2 */

  /* Module HplAtm128GeneralIOSlowPinP$3 */

  /* Module HplAtm128GeneralIOSlowPinP$4 */

  /* Module HplAtm128GeneralIOSlowPinP$5 */

  /* Module HplAtm128GeneralIOSlowPinP$6 */

  /* Module HplAtm128GeneralIOSlowPinP$7 */

  /* Module HplAtm128GeneralIOSlowPinP$8 */

  /* Module HplAtm128GeneralIOSlowPinP$9 */

  /* Module HplAtm128GeneralIOSlowPinP$10 */

  /* Module HplAtm128GeneralIOSlowPinP$11 */

  /* Module HplAtm128GeneralIOSlowPinP$12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  memset((void *)&SimSchedulerBasicP$m_head[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_head[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP$m_tail[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_tail[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP$m_next[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_next[__nesc_mote]);
  SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote] = FALSE;
  memset((void *)&SimSchedulerBasicP$sim_scheduler_event[__nesc_mote], 0, sizeof SimSchedulerBasicP$sim_scheduler_event[__nesc_mote]);

  /* Module SimMoteP */
  memset((void *)&SimMoteP$euid[__nesc_mote], 0, sizeof SimMoteP$euid[__nesc_mote]);
  memset((void *)&SimMoteP$startTime[__nesc_mote], 0, sizeof SimMoteP$startTime[__nesc_mote]);
  memset((void *)&SimMoteP$isOn[__nesc_mote], 0, sizeof SimMoteP$isOn[__nesc_mote]);
  memset((void *)&SimMoteP$bootEvent[__nesc_mote], 0, sizeof SimMoteP$bootEvent[__nesc_mote]);

  /* Module TossimActiveMessageC */
  memset((void *)&TossimActiveMessageC$buffer[__nesc_mote], 0, sizeof TossimActiveMessageC$buffer[__nesc_mote]);
  TossimActiveMessageC$bufferPointer[__nesc_mote] = &TossimActiveMessageC$buffer[__nesc_mote];

  /* Module TossimPacketModelC */
  TossimPacketModelC$initialized[__nesc_mote] = FALSE;
  TossimPacketModelC$running[__nesc_mote] = FALSE;
  memset((void *)&TossimPacketModelC$backoffCount[__nesc_mote], 0, sizeof TossimPacketModelC$backoffCount[__nesc_mote]);
  memset((void *)&TossimPacketModelC$neededFreeSamples[__nesc_mote], 0, sizeof TossimPacketModelC$neededFreeSamples[__nesc_mote]);
  TossimPacketModelC$sending[__nesc_mote] = (void *)0;
  TossimPacketModelC$transmitting[__nesc_mote] = FALSE;
  TossimPacketModelC$sendingLength[__nesc_mote] = 0;
  memset((void *)&TossimPacketModelC$destNode[__nesc_mote], 0, sizeof TossimPacketModelC$destNode[__nesc_mote]);
  memset((void *)&TossimPacketModelC$sendEvent[__nesc_mote], 0, sizeof TossimPacketModelC$sendEvent[__nesc_mote]);
  TossimPacketModelC$error[__nesc_mote] = 0;

  /* Module CpmModelC */
  memset((void *)&CpmModelC$outgoing[__nesc_mote], 0, sizeof CpmModelC$outgoing[__nesc_mote]);
  memset((void *)&CpmModelC$requestAck[__nesc_mote], 0, sizeof CpmModelC$requestAck[__nesc_mote]);
  CpmModelC$receiving[__nesc_mote] = 0;
  CpmModelC$transmitting[__nesc_mote] = 0;
  memset((void *)&CpmModelC$transmissionEndTime[__nesc_mote], 0, sizeof CpmModelC$transmissionEndTime[__nesc_mote]);
  CpmModelC$outstandingReceptionHead[__nesc_mote] = (void *)0;
  CpmModelC$clearThreshold[__nesc_mote] = -72.0;

  /* Module ActiveMessageAddressC */
  ActiveMessageAddressC$set[__nesc_mote] = FALSE;
  memset((void *)&ActiveMessageAddressC$addr[__nesc_mote], 0, sizeof ActiveMessageAddressC$addr[__nesc_mote]);

  /* Module SerialActiveMessageC */
  memset((void *)&SerialActiveMessageC$buffer[__nesc_mote], 0, sizeof SerialActiveMessageC$buffer[__nesc_mote]);
  SerialActiveMessageC$bufferPointer[__nesc_mote] = &SerialActiveMessageC$buffer[__nesc_mote];
  SerialActiveMessageC$sendMsgPtr[__nesc_mote] = (void *)0;

  /* Module LedsP */

  /* Module Atm128AlarmAsyncP$0 */
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote]);

  /* Module HplAtm128Timer0AsyncP */
  HplAtm128Timer0AsyncP$inOverflow[__nesc_mote] = 0;
  HplAtm128Timer0AsyncP$lastZero[__nesc_mote] = 0;
  HplAtm128Timer0AsyncP$oldScale[__nesc_mote] = AVR_CLOCK_OFF;
  memset((void *)&HplAtm128Timer0AsyncP$compare[__nesc_mote], 0, sizeof HplAtm128Timer0AsyncP$compare[__nesc_mote]);
  memset((void *)&HplAtm128Timer0AsyncP$overflow[__nesc_mote], 0, sizeof HplAtm128Timer0AsyncP$overflow[__nesc_mote]);

  /* Module AlarmToTimerC$0 */
  memset((void *)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote], 0, sizeof /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote]);
  memset((void *)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote], 0, sizeof /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote]);

  /* Module VirtualizeTimerC$0 */
  memset((void *)&/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote], 0, sizeof /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote]);

  /* Module CounterToLocalTimeC$0 */

  /* Module ConstantSensorC$0 */

  /* Module QueryPropagationC */
  memset((void *)&QueryPropagationC$r_pkt[__nesc_mote], 0, sizeof QueryPropagationC$r_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$bcast_pkt[__nesc_mote], 0, sizeof QueryPropagationC$bcast_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$r_sampling_pkt[__nesc_mote], 0, sizeof QueryPropagationC$r_sampling_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$s_sampling_pkt[__nesc_mote], 0, sizeof QueryPropagationC$s_sampling_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$ucast_pkt[__nesc_mote], 0, sizeof QueryPropagationC$ucast_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$s_pkt[__nesc_mote], 0, sizeof QueryPropagationC$s_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$pkt[__nesc_mote], 0, sizeof QueryPropagationC$pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$serial_pkt[__nesc_mote], 0, sizeof QueryPropagationC$serial_pkt[__nesc_mote]);
  memset((void *)&QueryPropagationC$sequence_number[__nesc_mote], 0, sizeof QueryPropagationC$sequence_number[__nesc_mote]);
  memset((void *)&QueryPropagationC$send[__nesc_mote], 0, sizeof QueryPropagationC$send[__nesc_mote]);
  memset((void *)&QueryPropagationC$save[__nesc_mote], 0, sizeof QueryPropagationC$save[__nesc_mote]);
  memset((void *)&QueryPropagationC$sampling_send[__nesc_mote], 0, sizeof QueryPropagationC$sampling_send[__nesc_mote]);
  memset((void *)&QueryPropagationC$sampling_save[__nesc_mote], 0, sizeof QueryPropagationC$sampling_save[__nesc_mote]);
  memset((void *)&QueryPropagationC$number_Of_queries[__nesc_mote], 0, sizeof QueryPropagationC$number_Of_queries[__nesc_mote]);
  memset((void *)&QueryPropagationC$next[__nesc_mote], 0, sizeof QueryPropagationC$next[__nesc_mote]);
  memset((void *)&QueryPropagationC$count_contributed_nodes[__nesc_mote], 0, sizeof QueryPropagationC$count_contributed_nodes[__nesc_mote]);
  memset((void *)&QueryPropagationC$t0[__nesc_mote], 0, sizeof QueryPropagationC$t0[__nesc_mote]);
  memset((void *)&QueryPropagationC$dt[__nesc_mote], 0, sizeof QueryPropagationC$dt[__nesc_mote]);
  memset((void *)&QueryPropagationC$start[__nesc_mote], 0, sizeof QueryPropagationC$start[__nesc_mote]);
  memset((void *)&QueryPropagationC$HoldTimer[__nesc_mote], 0, sizeof QueryPropagationC$HoldTimer[__nesc_mote]);
  memset((void *)&QueryPropagationC$query_pos[__nesc_mote], 0, sizeof QueryPropagationC$query_pos[__nesc_mote]);
  memset((void *)&QueryPropagationC$minQuery[__nesc_mote], 0, sizeof QueryPropagationC$minQuery[__nesc_mote]);
  memset((void *)&QueryPropagationC$expiredQuery[__nesc_mote], 0, sizeof QueryPropagationC$expiredQuery[__nesc_mote]);
  memset((void *)&QueryPropagationC$sendQuery[__nesc_mote], 0, sizeof QueryPropagationC$sendQuery[__nesc_mote]);
  memset((void *)&QueryPropagationC$runningTime[__nesc_mote], 0, sizeof QueryPropagationC$runningTime[__nesc_mote]);
  memset((void *)&QueryPropagationC$checkTimer[__nesc_mote], 0, sizeof QueryPropagationC$checkTimer[__nesc_mote]);
  memset((void *)&QueryPropagationC$timerStartAt[__nesc_mote], 0, sizeof QueryPropagationC$timerStartAt[__nesc_mote]);
  memset((void *)&QueryPropagationC$time4MeasurementStartAt[__nesc_mote], 0, sizeof QueryPropagationC$time4MeasurementStartAt[__nesc_mote]);
  memset((void *)&QueryPropagationC$Hold_Sampling_Timer[__nesc_mote], 0, sizeof QueryPropagationC$Hold_Sampling_Timer[__nesc_mote]);
  memset((void *)&QueryPropagationC$minPeriod[__nesc_mote], 0, sizeof QueryPropagationC$minPeriod[__nesc_mote]);
  memset((void *)&QueryPropagationC$sendTofather[__nesc_mote], 0, sizeof QueryPropagationC$sendTofather[__nesc_mote]);
  memset((void *)&QueryPropagationC$sensor_data[__nesc_mote], 0, sizeof QueryPropagationC$sensor_data[__nesc_mote]);
  memset((void *)&QueryPropagationC$source_id[__nesc_mote], 0, sizeof QueryPropagationC$source_id[__nesc_mote]);
  memset((void *)&QueryPropagationC$sequence_number[__nesc_mote], 0, sizeof QueryPropagationC$sequence_number[__nesc_mote]);
  memset((void *)&QueryPropagationC$data_id[__nesc_mote], 0, sizeof QueryPropagationC$data_id[__nesc_mote]);
  memset((void *)&QueryPropagationC$s_data_id[__nesc_mote], 0, sizeof QueryPropagationC$s_data_id[__nesc_mote]);
  memset((void *)&QueryPropagationC$forwarder_id[__nesc_mote], 0, sizeof QueryPropagationC$forwarder_id[__nesc_mote]);
  memset((void *)&QueryPropagationC$destination_id[__nesc_mote], 0, sizeof QueryPropagationC$destination_id[__nesc_mote]);
  QueryPropagationC$busy[__nesc_mote] = FALSE;
  QueryPropagationC$unicast_busy[__nesc_mote] = FALSE;
  QueryPropagationC$serial_busy[__nesc_mote] = FALSE;
  memset((void *)&QueryPropagationC$TimeToMeasure[__nesc_mote], 0, sizeof QueryPropagationC$TimeToMeasure[__nesc_mote]);
  memset((void *)&QueryPropagationC$PacketBuffer[__nesc_mote], 0, sizeof QueryPropagationC$PacketBuffer[__nesc_mote]);
  memset((void *)&QueryPropagationC$SamplingPacketBuffer[__nesc_mote], 0, sizeof QueryPropagationC$SamplingPacketBuffer[__nesc_mote]);
  memset((void *)&QueryPropagationC$AQQ[__nesc_mote], 0, sizeof QueryPropagationC$AQQ[__nesc_mote]);
  memset((void *)&QueryPropagationC$QuerySendersHistory[__nesc_mote], 0, sizeof QueryPropagationC$QuerySendersHistory[__nesc_mote]);

  /* Module AMQueueEntryP$0 */

  /* Module AMQueueImplP$0 */
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote] = 2;
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote]);
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote]);

  /* Module AMQueueEntryP$1 */

  /* Module AMQueueEntryP$2 */

  /* Module AMQueueImplP$1 */
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$current[__nesc_mote] = 1;
  memset((void *)&/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[__nesc_mote], 0, sizeof /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$queue[__nesc_mote]);
  memset((void *)&/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[__nesc_mote], 0, sizeof /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP$1$cancelMask[__nesc_mote]);

}
