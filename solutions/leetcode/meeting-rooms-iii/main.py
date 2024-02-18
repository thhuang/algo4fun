class Solution:

    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()

        empty_rooms = list(range(n))
        occupied_rooms = []  # (end, room)

        usage = defaultdict(int)

        for start, end in meetings:
            while len(occupied_rooms) > 0 and occupied_rooms[0][0] <= start:
                _, room = heapq.heappop(occupied_rooms)
                heapq.heappush(empty_rooms, room)

            if len(empty_rooms) == 0:
                t, room = heapq.heappop(occupied_rooms)
                heapq.heappush(empty_rooms, room)

                duration = end - start
                start, end = t, t + duration

            room = heapq.heappop(empty_rooms)
            usage[room] += 1
            heapq.heappush(occupied_rooms, (end, room))

        max_count = 0
        result = 0
        for room, count in usage.items():
            if count > max_count or (count == max_count and room < result):
                result, max_count = room, count

        return result
