#include <stdint.h>
#include <stdio.h>
#include <climits>
#include <cassert>
#include <vector>
#include "util.hpp"

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    uint64_t x = provider.ConsumeIntegralInRange<uint64_t>(1, INT64_MAX);
    lsbll(x);

    return 0;
}