#include <epi/generic_test.h>
#include <epi/test_failure.h>

#include <bitset>
#include <stdexcept>
#include <vector>
using namespace std;

int FindMissingElement(vector<int>::const_iterator stream_begin,
                       const vector<int>::const_iterator& stream_end) {
    const unsigned kNumBucket = 1 << 16;
    const unsigned kMaxVal = 1 << 16;
    array<unsigned, kNumBucket> buckets;

    for (auto iter = stream_begin; iter != stream_end; ++iter) {
        ++buckets[*iter >> 16];
    }

    unsigned target_bucket = kNumBucket;
    for (int i = 0; i < kNumBucket; ++i) {
        if (buckets[i] < kMaxVal) {
            target_bucket = i;
            break;
        }
    }
    assert(target_bucket != kNumBucket);

    bitset<kMaxVal> ips;
    for (auto iter = stream_begin; iter != stream_end; ++iter) {
        if (*iter >> 16 != target_bucket) continue;

        unsigned val = *iter & ((1 << 16) - 1);
        ips[val] = 1;
    }

    for (unsigned i = 0; i < kMaxVal; ++i) {
        if (ips[i]) continue;
        return (target_bucket << 16) | i;
    }

    return 0;
}

void FindMissingElementWrapper(const vector<int>& stream) {
    try {
        int res = FindMissingElement(cbegin(stream), cend(stream));
        if (find(stream.begin(), stream.end(), res) != stream.end()) {
            throw TestFailure(to_string(res) + " appears in stream");
        }
    } catch (invalid_argument&) {
        throw TestFailure("Unexpected no missing element exception");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"stream"};
    return GenericTestMain(args, "data.tsv", &FindMissingElementWrapper,
                           DefaultComparator{}, param_names);
}
