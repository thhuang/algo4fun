from sortedcontainers import SortedList
from collections import defaultdict
import heapq


class Twitter:

    class UserTweets:

        def __init__(self, tweetTimes: List[int]) -> None:
            self.tweetTimes = tweetTimes
            self.p = len(tweetTimes) - 1

        def front(self) -> int:
            return self.tweetTimes[self.p]

        def pop(self) -> None:
            self.p -= 1

        def empty(self) -> bool:
            return self.p < 0

        def __lt__(self, other) -> bool:
            return self.front() > other.front()

    def __init__(self):
        self.userTweetTimes = dict()
        self.tweets = list()
        self.followInfo = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.userTweetTimes:
            self.userTweetTimes[userId] = list()
        self.userTweetTimes[userId].append(len(self.tweets))
        self.tweets.append(tweetId)

    def getNewsFeed(self, userId: int) -> List[int]:
        result = list()

        pq = []
        self.followInfo[userId].add(userId)
        for u in self.followInfo[userId]:
            if u in self.userTweetTimes:
                heapq.heappush(pq, self.UserTweets(self.userTweetTimes[u]))

        while len(pq) > 0 and len(result) < 10:
            ut = heapq.heappop(pq)
            result.append(self.tweets[ut.front()])
            ut.pop()
            if not ut.empty():
                heapq.heappush(pq, ut)

        return result

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followInfo[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followInfo[followerId]:
            self.followInfo[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
