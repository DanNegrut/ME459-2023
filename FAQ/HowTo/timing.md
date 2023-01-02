# High Precision Timing in C 


### The Problems With Standard Timers 
While the C standard library provides portable functions for nearly any platform, there are a few areas in which it may find itself lacking. The two available timing functions, `time()` and `clock()`, can have critical problems which affect their viability on certain systems.

`time()` has a resolution of 1 second. This isn't particularly useful for profiling and its tick source will often come from the RTC, whose accuracy may be insufficient for critical operations.

`clock()` provides a bit higher precision as it is _supposed_ to measure the CPU time of an application in ticks. The standardized behavior is to assume 1000000 ticks per second regardless of the actual value of the tick source, which may have a higher or lower accuracy depending on the implementation. On past OS versions of the Euler Cluster, this resolution has been observed to be as poor as **5 milliseconds**.

To improve on this, we recommend the use of a POSIX function, `clock_gettime`.


### `clock_gettime` Overview

```c
int clock_gettime(clockid_t, struct timespec*);
```

`clock_gettime` takes two arguments, a [clock source](#clock-sources) and a pointer to a [struct which will hold the timestamp](#struct-timespec).

> NOTE: POSIX functions are well standardized on Unix-alike systems, but they may not be available or may not behave exactly the same on Windows.


#### **Clock Sources**

The clock source can be one of several available clocks implemented by the operating system kernel. The following clocks are available on most Linux systems: 

- `CLOCK_REALTIME` - Gets the current system time in Unix format. 
- `CLOCK_MONOTONIC` - Gets the amount of time elapsed since "some unspecified point in the past". The advantage of this clock is that it is guaranteed to always count up. It is not changed if the system clock is adjusted, and it behaves in a sane fashion when the time is updated by the network.
- `CLOCK_PROCESS_CPUTIME_ID` - Measures the amount of CPU time consumed by the current process. May not reflect time elapsed while the process is put to sleep during I/O.
- `CLOCK_THREAD_CPUTIME_ID` - The same as `CLOCK_PROCESS_CPUTIME_ID`, except that it measures time consumed by the current thread of execution. 

> For profiling, it is typically best to use **`CLOCK_MONOTONIC`**. On most systems, this clock is fast, reliable, and accurate. 

#### **`struct timespec`**

The structure which contains the timestamp returned by `clock_gettime` is called `struct timespec` and looks like this:

```c
struct timespec {
	time_t tv_sec; // time in seconds
	long tv_nsec; // time in nanoseconds
};
```

Adding the two member values together (after converting them to the same units) will provide a complete human-readable timestamp.  


### Bringing it all together: _Timing Example_

The following example uses the `clock_gettime` guidelines above to perform a simple profiling exercise for some function `please_profile_me()`.

```c
#include <stdio.h>
#include <time.h>

// Assume this header defines some interesting function called please_profile_me();
#include "my_profiling_function.h"

#define NSEC_PER_SEC 1000000000

int main() {
	
	// Declare the timestamp structures 
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start); // start timing
	please_profile_me();
	clock_gettime(CLOCK_MONOTONIC, &end);   // stop timing

	// Calculate the time elapsed between the start and end timestamps
	time_t elapsed_sec = end.tv_sec - start.tv_sec;
	long elapsed_nsec = end.tv_nsec - start.tv_nsec;

	// Combine the values into a single human-readable duration 
	double elapsed_total = elapsed_sec + (double)elapsed_nsec / (double)NSEC_PER_SEC;

	printf("please_profile_me() took %g seconds\n", elapsed_total);
}
```

The output of this program would look something like this:

```
please_profile_me() took 1.2579244 seconds
```
 
