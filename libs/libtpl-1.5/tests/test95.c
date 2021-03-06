#include "tpl.h"
#include <stdio.h>

const char *filename="/tmp/test95.tpl";
int main() {
  tpl_node *tn;
  char *s1 = NULL, *s2 = "", *s3 = "hello";
  tn = tpl_map("sss", &s1, &s2, &s3);
  tpl_pack(tn,0);
  tpl_dump(tn,TPL_FILE,filename);
  tpl_free(tn);

  s1 = s2 = s3 = (char*)0x1; /* overwritten below */
  tn  = tpl_map("sss", &s1, &s2, &s3);
  tpl_load(tn,TPL_FILE,filename);
  tpl_unpack(tn,0);
  tpl_free(tn);
  printf("s1 %s\n", s1?s1:"NULL");
  printf("s2 %s\n", s2?s2:"NULL");
  printf("s3 %s\n", s3?s3:"NULL");
  return(0);
}

