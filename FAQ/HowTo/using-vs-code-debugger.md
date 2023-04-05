# Instructions on configuring debugger in Visual Studio Code

1. Install `gcc` and `gdb`
2. Install `C/C++` extension (one from `Microsoft`)
3. Use the `RUN` tab then `Start Debugging`. Select an appropriate debugger (For example, you should choose `gdb` for WSL). 
4. Click on `create a launch.json file`. If it is an empty file then click the `Add configuration...` button and select an appropriate configuration file template. VS code will generate one with almost all the required information.
5. To configure the debugger settings in `launch.json`, you can edit the field of `program` with the path to the executable you want to debug, you can use something like
````sh
${workspaceFolder}/debugme
````
or
````sh
${workspaceFolder}/${fileBasenameNoExtension}
````
Note that the default variable name may be slightly different depending on your system.

`args` field has the command line argument you want to pass; if you set `stopAtEntry` to `true` the break point will be set automatically at the beginning of the main.

You may need to have your executable compiled with `-g` (compiling with debugging info) option for the debugger to work properly.

7. Now go to debugger tab and hit run, your output is in the console and you can see the variables on the left.
