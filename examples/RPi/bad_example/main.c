#include <glib.h>

int main(int argc, char *argv[]){

  g_autofree gchar *psn; // RPi PSN
  gsize psn_len; // PSN length
  const gchar *psn_path    = "/proc/device-tree/serial-number";   // file path of psn
  const gchar *psn_granted = "00000000790f4c7c"; // RPi PSN granted to run

  // read device PSN
  g_file_get_contents (psn_path, &psn, &psn_len, NULL);
  if (g_strcmp0(psn, psn_granted) == 0){
    g_message("Running on the valid device\n");
  } else {
    g_message("Running on the illegal device\n");
    exit(1);
  }
  g_message("Running application main logic!\n");
}