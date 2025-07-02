#ifndef OPTION_H
#define OPTION_H

#include <glib.h>

#define APP_VERSION "1.0.0"

typedef struct{
    gchar *license_key;
} GcDevicePSNhCommandArgs;

GcDevicePSNhCommandArgs *gc_devicePSNh_GcDevicePSNhCommandArgs_new();
void gc_devicePSNh_GcDevicePSNhCommandArgs_free(GcDevicePSNhCommandArgs *args);

// Define the cleanup function for g_autoptr
G_DEFINE_AUTOPTR_CLEANUP_FUNC(GcDevicePSNhCommandArgs, gc_devicePSNh_GcDevicePSNhCommandArgs_free)

GcDevicePSNhCommandArgs *gc_devicePSNh_parse_commandline_args(int argc, char* argv[]);

#endif /* OPTION_H */