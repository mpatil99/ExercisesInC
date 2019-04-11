#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gio/gio.h>

void print_hash(gpointer key, gpointer value, gpointer user_data){
    char *pkey = key;
    printf("%s: %i\n", pkey, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {
  GHashTable * gTable = g_hash_table_new (g_str_hash, g_str_equal);
  GScanner *gScanner = g_scanner_new(NULL);
  FILE * fp;
  gint file;

  fp = fopen ("text.txt", "r+");
  file = fileno(fp);
  g_scanner_input_file(gScanner, file);

  while(!g_scanner_eof(gScanner)){
    g_scanner_get_next_token(gScanner);
    if(gScanner->value.v_string){
      if(!g_hash_table_lookup(gTable, gScanner->value.v_string))
        g_hash_table_insert(gTable, g_strdup(gScanner->value.v_string), GINT_TO_POINTER(1));
      else
        g_hash_table_insert(gTable, g_strdup(gScanner->value.v_string), g_hash_table_lookup(gTable, gScanner->value.v_string)+1);
    }
  }
  g_hash_table_foreach(gTable, print_hash, NULL);
  return 0;
}
