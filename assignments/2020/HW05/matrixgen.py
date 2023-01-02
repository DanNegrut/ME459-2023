#!/usr/bin/env python

###
### CSV Matrix Generator
###
### Copyright (c)2020 Colin Vanden Heuvel, University of Wisconsin - Madison
###

import sys, os
import numpy as np

def main():

	# If the number of arguments isn't right, print a hint message
	if len(sys.argv) != 3:
		print("Usage: matrixgen.py num_rows num_cols\n")
		sys.exit(1)

	# Parse incoming arguments
	num_rows = int(sys.argv[1])
	num_cols = int(sys.argv[2])

	# Create a matrix with values between -1.0 and
	# 1.0 using uniformly-distributed random values 
	rng = np.random.default_rng()
	m = 2 * rng.random((num_rows, num_cols)) - 1
	
	# Stringify the values into CSV
	csvpayload = ""
	for row in m:
		csvrow = ""
		for col in row:
			# Append a value followed by a comma
			csvrow += str(col) + ", "
		# Append the stringified row, stripping the trailing comma
		csvpayload += csvrow.rstrip(" ,") + "\n"
	
	# Write the payload to a file
	with open("matrix.csv", "w+") as f:
		f.write(csvpayload)

if __name__ == "__main__":
	main()
