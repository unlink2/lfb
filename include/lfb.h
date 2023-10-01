#ifndef lfbH__
#define lfbH__

#include <stdbool.h>

struct lfb_config {
  bool verbose;
  bool ignore_case;
};

int lfb_main(struct lfb_config *cfg);

#endif
