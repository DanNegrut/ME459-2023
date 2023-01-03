# R on Euler _via Mamba_

For your homework, you may find that the default R installation on Euler is too old or is simply missing altogether. This brief guide will walk you through the steps of preparing a suitable R environment using Mamba. This process is very similar to the process for Python, so you can reference the Anaconda slides in Lecture 04 as well.

This environment will match what your TA is using for grading, so it is an excellent way to ensure the compatibility of your homework with the grader.


## 1) Getting Anaconda (but it's actually Mamba)

Anaconda is a distribution of the `conda` package manager for Python and R environments developed by Anaconda, Inc. It is a powerful tool capable of providing reproducible and well-defined environments, but its "freemium" licensing model can be troublesome. To remedy that, Euler provides [Mamba](https://github.com/mamba-org/mamba), an open source implementation of the `conda` package manager. 

Mamba is available as a module on Euler. Run the following commands in order to load the module and activate the `conda` environment.

```zsh
% module load mamba
% bootstrap_conda
```

## 2) Creating your Environment

> If you have already completed the steps in this guide once before, please skip ahead to **Section 3** _Activating Your Environment_. If not, continue reading.

The first time you use a conda environment, you will need to create a new environment. Run the following command to prepare an environment for this class.

```zsh
% conda create -n r459 r=4.0
```

You will be prompted to confirm the installation:
```
  ...
  xorg-xextproto     conda-forge/linux-64::xorg-xextproto-7.3.0-h7f98852_1002
  xorg-xproto        conda-forge/linux-64::xorg-xproto-7.0.31-h7f98852_1007
  xz                 conda-forge/linux-64::xz-5.2.5-h516909a_1
  zlib               conda-forge/linux-64::zlib-1.2.11-h516909a_1010
  zstd               conda-forge/linux-64::zstd-1.5.0-ha95c52a_0


Proceed ([y]/n)? 
```

Type `y` and press `Enter`. 

Mamba will download and install all of the packages needed to set up your environment. This can take some time, so please be patient.

## 3) Activating your Environment

In order to change from the (base) environment, enter the following command.

```zsh
% conda activate r459
```

> At this point, your prompt should look like this.
> 
> ```zsh
> (r459) [user@euler-login-2 ]~%
> ```
> If it does not, please close and reopen your shell and attempt these steps again.

Your conda environment is ready to go! If you close your shell, you will need to repeat steps **1** and **3**, so keep these instructions on hand.

---

## 4) Using your Environment in a Slurm Script

Once you've completed steps 1-3, you can activate your environment in a Slurm script simply by using the commands in steps **1** and **3**. 

Here's an example of what that might look like.

```zsh
#!/usr/bin/env zsh
#SBATCH your
#SBATCH slurm
#SBATCH flags

module load mamba
bootstrap_conda
conda activate r459

## Put the commands to launch your R script below ##
Rscript mySuperCoolScript.R
```











