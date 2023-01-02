# Instructions on configuring debugger in Visual Studio Code

1. Install `gcc` and `gdb`
2. Install `C/C++` extension (one from `Microsoft`)
3. Navigate to the `DEBUG` tab and click on `create a launch.json file`, VS code will generate one with almost all the required information
4. Select an appropriate debugger (For example, you should choose `gdb` for WSL)
5. To configure the debugger settings in `launch.json`, you can edit the field of `program` with the path to the executable you want to debug, you can use something like
````sh
${workspaceFolder}/debugme
````
or
````sh
${workspaceFolder}/${fileBasenameNoExtension}
````
Note that the default varialbe name may be slightly different depending on your system.

`args` field has the command line argument you want to pass; if you set `stopAtEntry` to `true` the break point will be set automatically at the beginning of the main.

7. Now go to debugger tab and hit run, your output is in the console and you can see the variables on the left.
