/*
Searches an internal array for the error number
errnum and returns a pointer to an error message string.
You need to declare macros containing arrays of error
messages for mac and linux operating systems. Error
descriptions are available in the original library.
Checking the current OS is carried out using directives.
*/

#include <stdio.h>

#include "s21_string.h"

#ifdef __APPLE__
// len(ERROR) == 107
#define ERROR                                                                  \
  {                                                                            \
    "Undefined error: 0", "Operation not permitted",                           \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full", "Unknown error: "                    \
  }
#elif ALPINE
#define ERROR                                                                  \
  {                                                                            \
    "No error information", "Operation not permitted",                         \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "I/O error", "No such device or address",   \
        "Argument list too long", "Exec format error", "Bad file descriptor",  \
        "No child process", "Resource temporarily unavailable",                \
        "Out of memory", "Permission denied", "Bad address",                   \
        "Block device required", "Resource busy", "File exists",               \
        "Cross-device link", "No such device", "Not a directory",              \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "No file descriptors available", "Not a tty", "Text file busy",        \
        "File too large", "No space left on device", "Invalid seek",           \
        "Read-only file system", "Too many links", "Broken pipe",              \
        "Domain error", "Result not representable",                            \
        "Resource deadlock would occur", "Filename too long",                  \
        "No locks available", "Function not implemented",                      \
        "Directory not empty", "Symbolic link loop", "No error information",   \
        "No message of desired type", "Identifier removed",                    \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "No error information", "Device not a stream", \
        "No data available", "Device timeout", "Out of streams resources",     \
        "No error information", "No error information",                        \
        "No error information", "Link has been severed",                       \
        "No error information", "No error information",                        \
        "No error information", "Protocol error", "Multihop attempted",        \
        "No error information", "Bad message",                                 \
        "Value too large for data type", "No error information",               \
        "File descriptor in bad state", "No error information",                \
        "No error information", "No error information",                        \
        "No error information", "No error information",                        \
        "No error information", "Illegal byte sequence",                       \
        "No error information", "No error information",                        \
        "No error information", "Not a socket",                                \
        "Destination address required", "Message too large",                   \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Not supported", "Protocol family not supported",                      \
        "Address family not supported by protocol", "Address in use",          \
        "Address not available", "Network is down", "Network unreachable",     \
        "Connection reset by network", "Connection aborted",                   \
        "Connection reset by peer", "No buffer space available",               \
        "Socket is connected", "Socket not connected",                         \
        "Cannot send after socket shutdown", "No error information",           \
        "Operation timed out", "Connection refused", "Host is down",           \
        "Host is unreachable", "Operation already in progress",                \
        "Operation in progress", "Stale file handle", "No error information",  \
        "No error information", "No error information",                        \
        "No error information", "Remote I/O error", "Quota exceeded",          \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service",                 \
        "Previous owner died", "State not recoverable", "No error information" \
  }
#else
// len(ERROR) == 133
#define ERROR                                                                  \
  {                                                                            \
    "Success", "Operation not permitted", "No such file or directory",         \
        "No such process", "Interrupted system call", "Input/output error",    \
        "No such device or address", "Argument list too long",                 \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource temporarily unavailable", "Cannot allocate memory",          \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Invalid cross-device link", \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "Too many open files in system",                   \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain",                     \
        "Numerical result out of range", "Resource deadlock avoided",          \
        "File name too long", "No locks available",                            \
        "Function not implemented", "Directory not empty",                     \
        "Too many levels of symbolic links", "Unknown error 41",               \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Unknown error 58", "Bad font file format", "Device not a stream",     \
        "No data available", "Timer expired", "Out of streams resources",      \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Bad message",             \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly",                               \
        "Invalid or incomplete multibyte or wide character",                   \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable", "Network dropped connection on reset",       \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale file handle", "Structure needs cleaning",                       \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Disk quota exceeded",     \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill",      \
        "Memory page has hardware error", "Unknown error "                     \
  }
#endif

char *s21_strerror(int errnum) {
  static char *err[] = ERROR;
  char resnum[MAX] = {0};
  static char ret_resnum[MAX];
  s21_memset(ret_resnum, 0, s21_strlen(ret_resnum));
#ifdef __APPLE__
  const int max_err = 107;
#elif ALPINE
  const int max_err = 132;
#else
  const int max_err = 134;
#endif
  if (errnum >= 0 && errnum < max_err) {
    return err[errnum];
  } else {
    s21_strncpy(resnum, err[max_err], s21_strlen(err[max_err]));
#ifndef ALPINE
    char num[MAX] = {0};
    int index = 0;
    if (errnum < 0) {
      num[index++] = '-';
      errnum *= -1;
    }
    int i = 0;
    int mirrow = errnum;
    for (i = 0; mirrow != 0; mirrow /= 10, i++)
      ;
    for (int j = i + index - 1; j >= index; --j) {
      num[j] = errnum % 10 + '0';
      errnum /= 10;
    }
    s21_strncat(resnum, num, s21_strlen(num));
#endif
    s21_strncpy(ret_resnum, resnum, s21_strlen(resnum));
  }
  return ret_resnum;
}
