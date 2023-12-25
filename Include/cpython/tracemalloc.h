#ifndef Py_TRACEMALLOC_H
#define Py_TRACEMALLOC_H
#ifdef __cplusplus
extern "C" {
#endif

#ifndef Py_LIMITED_API
/* Track an allocated memory block in the tracemalloc module.
   Return 0 on success, return -1 on error (failed to allocate memory to store
   the trace).

   Return -2 if tracemalloc is disabled.

   If memory block is already tracked, update the existing trace. */
PyAPI_FUNC(int) PyTraceMalloc_Track(
    unsigned int domain,
    uintptr_t ptr,
    size_t size);

/* Untrack an allocated memory block in the tracemalloc module.
   Do nothing if the block was not tracked.

   Return -2 if tracemalloc is disabled, otherwise return 0. */
PyAPI_FUNC(int) PyTraceMalloc_Untrack(
    unsigned int domain,
    uintptr_t ptr);
#endif  // !Py_LIMITED_API

#if !defined(Py_LIMITED_API) || Py_LIMITED_API+0 >= 0x030d0000
/* Trace PyObject when its reference count changes from 0 to 1.
   Return 0 on success.
   Return -1 on error (failed when a trace function is already set) */
PyAPI_FUNC(int) PyTrace_NewReference(int (*)(PyObject *));

/* Trace PyObject when its reference coun tchanges from 1 to 0.
   Return 0 on success.
   Return -1 on error (failed when a trace function is already set) */
PyAPI_FUNC(int) PyTrace_ForgetReference(int (*)(PyObject *));
#endif

#ifdef __cplusplus
}
#endif
#endif  // !Py_TRACEMALLOC_H
