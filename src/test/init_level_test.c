#include <criterion/criterion.h>
#include "fita.h"

map_t **init_maps(const char *path);

Test(init_level_test, null_path) {
    const char *path = NULL;

    cr_assert(init_maps(path) == NULL);
}