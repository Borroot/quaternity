#include <criterion/criterion.h>

Test(asserts, verifier) {
	cr_expect(strlen("Hi") == 4, "Expected \"Test\" to have a length of 4.");
    cr_assert(strlen("") == 0);
    cr_assert(strlen("") == 0);
}
