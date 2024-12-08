import bisect
from typing import List, Tuple


class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda e: e[1])

        result = 0

        index_max_values: List[Tuple[int, int]] = [(0, 0)]  # (index, max_value)

        for r, (start_time, end_time, value) in enumerate(events):
            l = (
                bisect.bisect_left(
                    index_max_values, start_time, key=lambda idx_value: idx_value[0]
                )
                - 1
            )
            result = max(result, index_max_values[l][1] + value)
            index_max_values.append((end_time, max(index_max_values[-1][1], value)))

        return result
