#ifndef TREE_H_
#define TREE_H_

#include <stddef.h>

enum lfb_deflags {
  LFB_DE_FILE = 1,
  LFB_DE_DIR = 2,
  LFB_DE_HLINK = 4,
  LFB_DE_SLINK = 8
};

struct lfb_dirent {
  struct lfb_dirent **leaves;
  size_t leaves_len;

  int fd;
  const char *path;
  enum lfb_deflags flags;
};

struct lfb_dirent* lfb_dirlst(const char *path, int max_depth,
                             const char **ignore);

void lfb_dirent_free(struct lfb_dirent *trunk);

#endif
