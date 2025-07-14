# Bad Example of RPi device restriction.

## Simple way.
You can block running your application on unintentional  devices as follow:

- Decide which RPi you want to grant your application running on. Then, confirm their PSN and register on your source code like [here](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L8C31-L8C47).

- The PSN of the device your application running on can be obtained by reading the file [/proc/device-tree/serial-number](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L7C31-L7C62)

- Compare **device PSN*** and ***granted PSN*** then run your logic if same.

## Why this simple solution isn’t working?
Now, even if your application is copied by a malicious third party, it will not run anywhere other than your RPi device.　It looks fine, it will effectively prevent the execution of copies made by **ordinary end users**. But for the **seasoned malicious third party**, it's different story. Let's take a look at the threats of this simple method.

### Sample project.
The sample project is available in this folder.
- [main.c](main.c)
