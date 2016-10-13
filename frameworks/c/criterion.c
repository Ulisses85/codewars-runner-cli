#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/hooks.h>

// before running the tests, initialize
ReportHook(PRE_ALL)(struct criterion_test_set *tests) {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

//  before the test is run
ReportHook(PRE_SUITE)(struct criterion_suite_set *set) {
    printf("<DESCRIBE::>%s\n", set->suite.name);
}

//  before the test is run
ReportHook(PRE_TEST)(struct criterion_test *test) {
    printf("<IT::>%s\n",test->name);
}

// when an assertion is hit
ReportHook(ASSERT)(struct criterion_assert_stats *stats) {
    if (stats->passed) {
      puts("<PASSED::>Test Passed");
    } else {
      printf("<FAILED::>%s\n",stats->message);
    }
}

// when a test crashes unexpectedly
ReportHook(TEST_CRASH)(struct criterion_test_stats *stats) {
  puts("<FAILED::>Test crashes");
}

//  after a test ends
ReportHook(POST_TEST)(struct criterion_test_stats *stats) {
  printf("<COMPLETEDIN::>%f\n",stats->elapsed_time*1000);
}

//  after the test is run
ReportHook(POST_SUITE)(struct criterion_suite_stats *stats) {
    puts("<COMPLETEDIN::>");
}

