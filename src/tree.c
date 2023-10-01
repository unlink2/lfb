#include "tree.h"
#include <stdlib.h>
#include <string.h>

struct lfb_dirent *lfb_dirlst(const char *path, int max_depth,
                              const char **ignore) {
  struct lfb_dirent *ent = malloc(sizeof(struct lfb_dirent));
  memset(ent, 0, sizeof(struct lfb_dirent));

  return ent;
}

void lfb_dirent_free(struct lfb_dirent *trunk) {
  if (trunk->leaves) {
    for (size_t i = 0; i < trunk->leaves_len; i++) {
      lfb_dirent_free(trunk->leaves[i]);
    }
  }
  free(trunk);
}
