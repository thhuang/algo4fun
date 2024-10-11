class Solution:

    def smallestChair(self, times: List[List[int]], target_friend: int) -> int:
        friends = sorted([(l, r, i) for i, (l, r) in enumerate(times)])

        mx = 0
        unoccupied_chairs = [0]
        occupied_chairs = []

        for l, r, f in friends:
            while len(occupied_chairs) > 0 and occupied_chairs[0][0] <= l:
                _, c = heapq.heappop(occupied_chairs)
                heapq.heappush(unoccupied_chairs, c)

            if len(unoccupied_chairs) == 0:
                mx += 1
                unoccupied_chairs.append(mx)

            if f == target_friend:
                break

            c = heapq.heappop(unoccupied_chairs)
            heapq.heappush(occupied_chairs, (r, c))

        return unoccupied_chairs[0]
