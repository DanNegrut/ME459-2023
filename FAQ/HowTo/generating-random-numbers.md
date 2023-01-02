# Generating Random Numbers in C

## Introduction
The C standard library provides very simple pseudo-random integer generation functions called `srand` and `rand`. These functions can be quite limited ([see below](#caveats)), but they are widely available, and are still useful when performing tasks where the quality/distribution of random values isn't under high scrutiny.

```c
#include <stdlib.h>

void srand(unsigned int seed);
int rand();
```

## _Pseudo_-random Numbers

PRNGs (Pseudo-Random Number Generators) are algorithms which deterministically create numbers from which a given subset would _appear_ to be random. Such algorithms are typically seeded with some starting value which advances the generator by a number of steps before it is used to return numbers for programmatic use. Common seeds include `0` (the default state), the current time, or a number generated from a more sophisticated source of randomness (such as `/dev/urandom` on Linux). In standard C, the `srand` function is used for this purpose. The function only needs to be called once, before any calls to `rand`.


## Generating Values

Calls to `rand` return an integer in the range of `0` to `RAND_MAX` inclusive. `RAND_MAX` is guaranteed by the standard to be at least `32767`.


### Values larger than RAND_MAX

**Why this is difficult:** It might be tempting to add or multiply the result of `rand` until it reaches some desired magnitude, but this can cause problems with the distribution of the generated values. Consider what happens when two six-sided dice are rolled and added together, are all values equally likely? No, values closer to the middle turn up more likely than those near the extrema.

**One possible solution:** Consider treating the result as a random pattern of bits instead of a discrete value. For example, if `rand` returns an integral value such as `9283`, it could also be expressed in binary as a stream of bits `00000000000000000010010001000011` (an `int` is 32 bits on a typical Linux system). These bits can be combined to create a larger integer.

If RAND_MAX is at least `32767` (or 2^15 - 1), that leaves 15 random bits to work with. High-order bits from successive invocations of `rand` can be combined using bitwise operations to create a larger integer.

Here's an example function which returns 64 (pseudo-)random bits:

```cpp
unsigned long long really_big_rand() {
	unsigned long long many_bits = 0;

	for (int i = 0; i < sizeof(unsigned long long); i++) {
		// grab bits 7-14 by shifting them into the lowest position
		int bits_8 = (rand() >> 7) & 0xFF;

		// merge the bits into the return variable
		many_bits |= bits_8 << (8 * i);
	}

	return many_bits;
}
```

The returned value can then be reduced into the appropriate range without affecting the distribution of random values.

NOTE: The value of `REALLY_BIG_RAND_MAX` for the function above would be `18446744073709551615` (or 2^64 - 1)

### Floating point numbers

**Why this is difficult**: Rounding errors in the machine representation of floating point numbers and the limited number of integral values between `0` and `RAND_MAX` can lead to poor distributions of floating point values.

> NOTE: The following example doesn't do a lot to deal with the problems listed above, but expanding the number of random bits used to generate input values to this method can somewhat mitigate issues with distribution. Rounding errors, however, are a lot more complex and won't be addressed here.

**One possible solution**: 
Normalize the random values into a floating point value between 0 and 1.0, and multiply by a scalar to achieve the desired range.

```cpp
double floating_rand(double range_max) {

	double normalized = rand() / RAND_MAX;
	double value = normalized * range_max;

	return value;
}
```

### Ranges which don't begin with `0`

**Why this is difficult**: This case isn't particularly difficult except when it inherits the problems of other range or type adjustments.

**One possible solution**: Generate numbers in the range from `0` to `max - min` and then shift them by `min`.

The following example generalizes the floating point generator above to support arbitrary ranges.

```cpp
double range_floating_rand(double min, double max) {
	
	double normalized = rand() / RAND_MAX;

	// Calculate the magnitude of the normalized range
	double range = max - min;

	double value = normalized * range;

	// Shift the value back into the desired range
	value += min;

	return value;
}
```

### Caveats
Ignoring its unsuitability for cryptographic purposes (this is applicable to PRNGs in general), the implementation of the `rand` function in many C Standard Libraries can be problematic. An issue which affects all implementations is that `rand` is only guaranteed to be uniformly distributed in the rather small range of [0, 32767]. Furthermore, historical implementations (many of which are still in use) were built on Linear Congruential Generator algorithms with a tendency to produce distinguishable repeating patterns in the generation of lower-order bits. These characteristics can render the implementation unsuitable for scientific computation, which may require reliable distribution over a large range of values (among other qualities). 

For scientific computing, it is usually advisable to select an alternative PRNG library which is known to be suitable for the type of data generation used in the experiment.
