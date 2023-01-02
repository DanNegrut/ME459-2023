# MATLAB on Euler

To use MATLAB on Euler, you must first load the `matlab` module.
```zsh
$ module load matlab
```

Here's an example of what that might look like in a Slurm script.

```zsh
#!/usr/bin/env zsh
#SBATCH your
#SBATCH slurm
#SBATCH flags

module load matlab

## Put the commands to launch your matlab script below ##
matlab -batch "run('mySuperCoolScript.m');"

## or, call a function defined in mySuperCoolFunction.m
matlab -batch "mySuperCoolFunction 'cool' 'arguments'"
```

