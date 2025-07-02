#include "option.h"
#define APP_VERSION "1.0.0"

GcDevicePSNhCommandArgs *gc_devicePSNh_GcDevicePSNhCommandArgs_new(){
  // allocate args and initialize.
  GcDevicePSNhCommandArgs *args = g_malloc(sizeof(GcDevicePSNhCommandArgs));
  args->license_key = NULL;

  return args;
}

void gc_devicePSNh_GcDevicePSNhCommandArgs_free(GcDevicePSNhCommandArgs *args){
  if (args->license_key == NULL){
    g_free(args->license_key);
  }
  g_free(args);
}

GcDevicePSNhCommandArgs *gc_devicePSNh_parse_commandline_args(int argc, char* argv[]){

  const gchar *usage_parameter_string = "Restrict your application running on this Raspberry Pi only.";

  g_autoptr(GOptionContext) context = g_option_context_new(usage_parameter_string);
  g_autoptr(GError) err = NULL;

  // allocate args and initialize.
  GcDevicePSNhCommandArgs *args = gc_devicePSNh_GcDevicePSNhCommandArgs_new();
  
  // define option entries.
  GOptionEntry entries[] = {
    { "license_key", 'l', 0, G_OPTION_ARG_STRING, &args->license_key, "Confirm the license_key and save device PSN on this application.", NULL },
    { NULL }
  };

  // set description.
  g_option_context_set_description(context, "Version:\n  " APP_VERSION);
  // add entries.
  g_option_context_add_main_entries(context, entries, NULL);

  // parse command line args
  if (!g_option_context_parse(context, &argc, &argv, &err)){
    g_debug("option parsing failed: %s\n", err->message);
    exit(1);
  }

  return args;
}