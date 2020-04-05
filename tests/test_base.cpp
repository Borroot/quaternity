#include <criterion/criterion.h>

Test(asserts, base) {
	cr_expect(strlen("Test") == 4, "Expected \"Test\" to have a length of 4.");
    cr_assert(strlen("") == 0);
}
