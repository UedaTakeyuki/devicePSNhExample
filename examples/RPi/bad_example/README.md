# Bad Example of RPi device restriction.

## Simple way.
You can block running your application on unintentional  devices as follow:

- Decide which RPi you want to grant your application running on. Then, confirm their PS and register on your source code like [here](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L8C31-L8C47).

- The PSN of the device your application running on can be obtained by reading the file [/proc/device-tree/serial-number](https://github.com/UedaTakeyuki/devicePSNhExample/blob/main/examples/RPi/bad_example/main.c#L7C31-L7C62)
