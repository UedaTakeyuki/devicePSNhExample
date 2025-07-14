# Bad Example of RPi device restriction.

## Simple way.
You can block running your application on unintentional devices as follow:

- Decide which RPi you want to grant your application running on. Then, confirm their PSN and register on your source code like [here](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L8C31-L8C47).

- The PSN of the device your application running on can be obtained by reading the file [/proc/device-tree/serial-number](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L7C31-L7C62)

- Compare **device PSN*** and ***granted PSN*** then run your logic if same.

## Why this simple solution isn’t working?
Now, even if your application is copied by a malicious third party, it will not run anywhere other than your RPi device.　It looks fine, it will effectively prevent the execution of copies made by **ordinary end users**. But for the **seasoned engineers**, it's different story. Let's take a look at the threats of this simple method.

### Sample project.
The sample project is available in this folder.
- [main.c](main.c): A source code of sample. This block running on the other device than the PSN is [00000000790f4c7c](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L8C31-L8C47).
- [Makefile](Makefile)

Make this project as follow:
```
make
```
Then a executable file ```main``` must be made. On the RPi with PSN is [00000000790f4c7c](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L8C31-L8C47), this executable file print out put as follows:

```
** Message: 22:11:05.906: Running on the valid device

** Message: 22:11:05.907: Running application main logic!
```

To say flank, PSN is [00000000790f4c7c](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L8C31-L8C47) is my RPi's, so you must see output as follow:

```
** Message: 22:11:05.906: Running on the illegal device
```

That's expected behavior. What is wrong?

### Binary Utilities.
Experienced engineers have the methods and tools to examine binary executable files.　One of these binary utilities is **strings** that print the strings of printable characters in files. Text literals in source code are the one of these printable strings.

Let's try **strings** command with the **main** file built above, then you will see as follow:

```
 $ strings main
/lib/ld-linux-armhf.so.3
libglib-2.0.so.0
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
g_log
g_file_get_contents
g_strcmp0
g_free
libc.so.6
exit
abort
__libc_start_main
GLIBC_2.4
/proc/device-tree/serial-number
00000000790f4c7c
Running on the valid device
Running on the illegal device
Running application main logic!
```

Look at the **fourth** and **fifth** lines from the **bottom**.　A string that looks like PSN and a file path to get it appeared. I won't go into detail here (I don't think I should explain how to do this), but the **file path can be easily spoofed**, so a malicious therd party can spoof the correct PSN to fool this check.

