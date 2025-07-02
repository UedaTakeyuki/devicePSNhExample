#include "devicePSNh.h"
//#include "license.h"
#include "option.h"

int main(int argc, char *argv[]){
  // parse command line args
  g_autoptr(GcDevicePSNhCommandArgs) args = gc_devicePSNh_parse_commandline_args(argc, argv);

  // for test purpose
  /*
  g_autoptr(GError) error = NULL;
  g_autofree gchar *psn = gc_devicePSNh_get_device_psn(&error);
  if (error != NULL){
    g_warning ("Error at parsing JSON: %s\n", error->message);
    return 1;
  }
  g_print("PSN: %s\n", psn);

  g_autofree gchar *psk = gc_devicePSNh_get_product_secret_key();
  g_print("PSK: %s\n", psk);
  */

  // set application file name running on.
  gchar *thisfilename = argv[0];

  // is psn already set?
  bool is_psn_set = gc_devicePSNh_is_psn_saved();

  if (is_psn_set){
    // PSN already set message and exit.
    if (args->license_key != NULL){
      g_message("The device PSN is already set.");
      exit(1);
    }
    // confirm on the valid device or exit.
    if (gc_devicePSNh_is_on_the_valid_device()){
      g_message("Running on the valid device\n");
    } else {
      g_message("Running on the illegal device\n");
      exit(1);
    }
  } else {
    if (args->license_key != NULL){
      if (gc_devicePSNh_save_psn(thisfilename, args->license_key)){
        g_message("license confirmed and save device psn on this application\n");

        // Normal exit must necessary because the device PSN is just write on the application file,
        // but the running application is started the OLD file, not PSN updated file!
        exit(0);

      } else {
        g_message("license key invalid.\n");

        exit(1);
      }

    } else {
      // without --license_key option and PSN is still not set.
      // You can leave running main logic for convinience making and debug your application.
      // Of cource you can restrict running as your convenience.
      // Here, just leave running for example.
    }
  }

  // main logic
  g_message("Running application main logic!\n");

  return 0;
}
