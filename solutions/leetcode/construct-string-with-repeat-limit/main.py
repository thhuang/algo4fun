class Solution:
    def repeatLimitedString(self, s: str, repeat_limit: int) -> str:
        payload = lambda ch, cnt: (-ord(ch), ch, cnt)

        pq = [payload(ch, cnt) for ch, cnt in Counter(s).items()]
        heapify(pq)

        result = []

        while len(pq) > 0:
            _, ch, cnt = heappop(pq)
            result.append(ch * min(cnt, repeat_limit))

            if cnt > repeat_limit and len(pq) > 0:
                _, ch_next, cnt_next = heappop(pq)
                result.append(ch_next)
                if cnt_next > 1:
                    heappush(pq, payload(ch_next, cnt_next - 1))
                heappush(pq, payload(ch, cnt - repeat_limit))

        return "".join(result)
